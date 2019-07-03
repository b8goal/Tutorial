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
int main(int argc, char* argv[])
{
  //  Create new object in the heap memory
  std::shared_ptr<std::string> new_data = std::make_shared<std::string>("Hello, world!");
  std::shared_ptr<std::string> ref_data = new_data;

  std::cout << "new_data's address: " << new_data << std::endl;
  std::cout << "ref_data's address: " << ref_data << std::endl;
  
  std::cout << "new_data's value:" << *new_data << std::endl;
  std::cout << "ref_data's value:" << *ref_data << std::endl;

  //  I don't care about how to free the new_data memory that was allocated heap memory using the malloc function.

  return 0;
}
