#pragma once

#include <stdint.h>
#include <utility>

inline void printIntByBin(uint32_t i, std::ostream& out)
{
	for(int j=31; j>=0; --j)
	{
		if(i & (1<<j))
		{
			out << 1;
		}
		else
		{
			out << 0;
		}
	}
}

template<typename T, typename ostream_t>
inline void printList(const T& array, int s, ostream_t& o)
{
  for(int i=0; i<s; ++i)
  {
    o << array[i] << " ";
  }
}

template<typename T>
inline void reverse(T& array, int s, int e)
{
  for(; s < e; ++s, --e)
  {
    std::swap(array[s], array[e]);
  }
}
