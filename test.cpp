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
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std::chrono;

/**
 * @brief How to build this source: g++ test.cpp -std=c++11 -o test
 * 
 */

class Particle
{
public:
  Particle()
  {
    std::cout << "Particle creates. " << std::endl;
  }
  Particle(int ID)
  {
    ID_ = ID;
    std::cout << "Particle " << ID_ << " creates. " << std::endl;
  }
  ~Particle()
  {
    std::cout << "Particle " << ID_ << " deletes." << std::endl;
  }
  int ID_;
  std::shared_ptr<Particle> circular_;
};

struct compare
{
	int key;
	compare(int const &i): key(i) { }

	bool operator()(int const &i)
	{
		return (i == key);
	}
};

void show_message(const std::string& title, bool found, high_resolution_clock::time_point t1, high_resolution_clock::time_point t2)
{
  std::cout << title << std::endl;

	if (found)
		std::cout << "Element found" << std::endl;
	else
		std::cout << "Element not found" << std::endl;

  std::cout << "Duration: " << duration_cast<microseconds>( t2 - t1 ).count() << std::endl;
  std::cout << "----------------------" << std::endl;
}

void algorithm_test()
{
	std::vector<int> v = { 4, 7, 5, 2, 6, 9 };
	int key = rand() % 4;
	
	for (int i = 0; i < 9000; i++)
		v.push_back(rand() % 3000);
	
	high_resolution_clock::time_point t1;
	
	bool found = false;
	t1 = high_resolution_clock::now();
		
	for (auto it : v) {
		if (it == key) {
			found = true;
			break;
		}
  }

  show_message("Don't use the algorithm...", found, t1, high_resolution_clock::now());
	
	found = false;
	t1 = high_resolution_clock::now();
	
	if (std::find(v.begin(), v.end(), key) != v.end())
		found = true;

	show_message("Use std::find", found, t1, high_resolution_clock::now());
	
	found = false;
	t1 = high_resolution_clock::now();
	
	if (!std::none_of(v.begin(), v.end(), compare(key)))
		found = true;

	show_message("Use std::none_of", found, t1, high_resolution_clock::now());

	std::sort(v.begin(), v.end());
	
	found = false;
	t1 = high_resolution_clock::now();
	
	if (std::binary_search(v.begin(), v.end(), key))
		found = true;

	show_message("Use std::binary_search", found, t1, high_resolution_clock::now());
}

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
  data.get()[0].ID_ = 88;
  data.get()[1].ID_ = 99;
  std::cout << data.get()[0].ID_ << ", " << data.get()[1].ID_ << std::endl;
}

void func4(std::shared_ptr<Particle> data1, std::shared_ptr<Particle> data2)
{
  data1->circular_ = data2;
  data2->circular_ = data1;

  std::cout << "data1's ID: " << data1->circular_ << std::endl;
  std::cout << "data2's ID: " << data2->circular_ << std::endl;
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

  algorithm_test();

  algorithm_test();

  //  I don't care about how to free the new_data memory that was allocated heap memory using the malloc function.

  std::shared_ptr<Particle> ParticlePtr(new Particle[2], std::default_delete<Particle[]>());
  func3(ParticlePtr);

  // Even if the program is terminated, the object created by the circular reference is not destroyed
  
  std::cout<<std::endl;
  std::shared_ptr<Particle> ParticlePtr1(new Particle(1));
  {
    std::shared_ptr<Particle> ParticlePtr2(new Particle(2));
    func4(ParticlePtr1, ParticlePtr2);
  }
  std::cout << "data1's ID: " << ParticlePtr1->ID_ << std::endl;

  return 0;
}