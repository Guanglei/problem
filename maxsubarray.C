/***********************************
 * give a array find the sub array *
 * which produce the max sum       *
 * ********************************/

#include <iostream>
#include <vector>
#include <limits>

typedef std::pair<int, int> SubArray;
typedef std::vector<int> Array;

//O(n*n)
SubArray test(const Array& array)
{
  SubArray ret;
  
  bool init = false;
  int maxsum;

  int size = array.size();
  for(int i = 0; i < size; ++i)
  {
    int sum = 0;
    for (int j = i; j < size; ++j)
    {
      sum += array[j];

      if(!init)
      {
        init = true;
        maxsum = sum;
        ret.first = i;
        ret.second = j;
        continue;
      }
      else if(sum > maxsum)
      {
        maxsum = sum;
        ret.first = i;
        ret.second = j;
      }
    }
  }

  return ret;
}

//O(n)
SubArray quickOne(const Array& array)
{
  if(array.empty())
  {
    return std::make_pair(-1,-1);
  }
  
  int maxsum = std::numeric_limits<int>::min();
  int sum = 0;
  int size = array.size();
  int start = 0;
  SubArray ret;
  
  for(int i=0; i<size; ++i)
  {
    sum += array[i];
    if(sum > maxsum)
    {
      ret.first = start;
      ret.second = i;
      maxsum = sum;
    }

    if(sum < 0)
    {
      sum = 0;
      start = i+1;
    }
  }

  return ret;
}

int main()
{
  Array a = {1, -2, 3, 10, -4, 7, 2, -5};
  SubArray r = test(a);
  std::cout << r.first << " " << r.second << std::endl;

  r = quickOne(a);
  std::cout << r.first << " " << r.second << std::endl;
  return 0;
}
