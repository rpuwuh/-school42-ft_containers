#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> test;
  for (int i = 1; i < 5; i++)
    test.push_back(std::to_string(i));

  std::cout << std::endl;
  std::cout << test.size() << std::endl;
  std::cout << test.capacity() << std::endl << std::endl;

  for (int i = 0; i < 10; i++)
    std::cout << test[i] << std::endl;
  
  std::cout << std::endl;
  std::cout << test.size() << std::endl;
  std::cout << test.capacity() << std::endl << std::endl;
  test.clear();
  test.front();

  std::cout << "im here" << std::endl;
}