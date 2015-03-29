#include <iostream>

#include "util.h"

uint32_t revertBits(uint32_t i)
{
	int ret = 0;
	for(int k=0; k<=15; ++k)
	{
		int hoffset = 31-k;
		bool hbit = i & (1<<hoffset);		
		bool lbit = i & (1<<k);		
		
		if(hbit == lbit)
		{
			ret |= hbit << hoffset;
			ret |= lbit << k;
		}
		else
		{
			ret |= ((hbit ^ lbit ^ hbit) << hoffset);
			ret |= ((lbit ^ hbit ^ lbit) << k);
		}
	}
	return ret;
}


int main()
{
	while(true)
	{
		uint32_t input;
		std::cin >> input;
		std::cout << "the input in bin is ";
		printIntByBin(input, std::cout);
		std::cout << std::endl;
		uint32_t res = revertBits(input);
		std::cout << "after revert is ";
		printIntByBin(res, std::cout);
		std::cout << " (" << res <<")" <<  std::endl;
	}
	
	return 0;
}


