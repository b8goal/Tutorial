/**
 * @file test.cpp
 * @author Mansoo (mansoo.kim@stradvision.com)
 * @brief This is a sample code for the smart pointer.
 * @version 1.0
 * @date 2019-07-03
 * 
 * @copyright Copyright (c) 2019 Stradvision. All rights reserved.
 * 
 */
#include <iostream>
#include <memory>
#include <string>

/**
 * @brief How to build this source: g++ test.cpp -std=c++11 -o test
 * 
 */

class Particle
{
public:
  Particle()
  {
    std::cout << "Particle creates, " << std::endl;
  }
  ~Particle()
  {
    std::cout << "Particle deletes, " << std::endl;
  }
  int m_nID;
};

void func1(const std::shared_ptr<std::string> data)
{
  std::cout << "Here is in func1." << std::endl;
  std::cout << "data's address: " << data << std::endl;
  std::cout << "data's value:" << data->c_str() << std::endl;

  *data = "func1: data1";
}

void func2(std::shared_ptr<std::string> &data)
{
  std::cout << "Here is in func2." << std::endl;
  std::cout << "data's address: " << data << std::endl;
  std::cout << "data's value:" << data->c_str() << std::endl;

  *data = "func2: data2";
}

void func3(std::shared_ptr<Particle> data)
{
  std::cout << "shared_ptr - use dynamic array" << std::endl;
  data.get()[0].m_nID = 88;
  data.get()[1].m_nID = 99;
  std::cout << data.get()[0].m_nID << ", " << data.get()[1].m_nID << std::endl;
}

int main(int argc, char *argv[])
{
  //  Create new object in the heap memory
  std::shared_ptr<std::string> new_data = std::make_shared<std::string>("Hello, world!");
  std::shared_ptr<std::string> ref_data = new_data;

  std::cout << "new_data's address: " << new_data << std::endl;
  std::cout << "ref_data's address: " << ref_data << std::endl;

  std::cout << "new_data's count: " << new_data.use_count() << std::endl;
  std::cout << "ref_data's count: " << ref_data.use_count() << std::endl;

  func1(ref_data);
  func2(new_data);

  std::shared_ptr<std::string> tmp_data = std::make_shared<std::string>("Temporary Data");

  std::cout << "*****************************" << std::endl;
  std::cout << "new_data's value: " << *new_data << std::endl;
  std::cout << "ref_data's value: " << *ref_data << std::endl;
  std::cout << "tmp_data's value: " << *tmp_data << std::endl;

  std::cout << "new_data's address: " << new_data.get() << std::endl;
  std::cout << "ref_data's address: " << ref_data << std::endl;
  std::cout << "tmp_data's address " << tmp_data << std::endl;

  ref_data.swap(tmp_data);

  std::cout << "new_data's value: " << *new_data << std::endl;
  std::cout << "ref_data's value: " << *ref_data << std::endl;
  std::cout << "tmp_data's value: " << *tmp_data << std::endl;

  // Unrelated shared_ptrs are never equal.
  std::cout << "new_data > ref_data = " << std::boolalpha << (new_data > ref_data) << std::endl;
  std::cout << "new_data < ref_data = " << std::boolalpha << (new_data < ref_data) << std::endl;
  std::cout << "new_data == ref_data = " << std::boolalpha << (new_data == ref_data) << std::endl;
  std::cout << "*****************************" << std::endl;

  new_data.reset();
  ref_data.reset();

  std::cout << "new_data's count: " << new_data.use_count() << std::endl;
  std::cout << "ref_data's count: " << ref_data.use_count() << std::endl;

  //  I don't care about how to free the new_data memory that was allocated heap memory using the malloc function.

  std::shared_ptr<Particle> ParticlePtr(new Particle[2], std::default_delete<Particle[]>());
  func3(ParticlePtr);

  return 0;
}
