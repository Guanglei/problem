#include <iostream>
#include <vector>

#include "util.h"

void rotate(std::vector<int>& numbers, int size, int k)
{
  reverse(numbers, 0, size-1);  
  reverse(numbers, 0, k-1);
  reverse(numbers, k, size-1);
}

int main()
{
  while(true)
  {
    int size = 0;
    int k = 0;
    std::vector<int> numbers;

    std::cin >> size >> k;

    if(size <= 0)
    {
      std::cerr << "size should be greater than zero" << std::endl;
      continue;
    }

    if(k > size)
    {
      k %= size;
    }

    for(int i=0; i<size; ++i)
    {
      int input;
      std::cin >> input;
      numbers.push_back(input);
    }
    
    std::cout << "before rotate: ";
    printList(numbers, size, std::cout);
    std::cout << std::endl;
    
    if(k > 0)
    {
      rotate(numbers, size, k);
    }
  
    std::cout << "after rotate: ";
    printList(numbers, size, std::cout);
    std::cout << std::endl;
  }

  return 0;
}
