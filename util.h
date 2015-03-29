#pragma once

#include <stdint.h>

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

