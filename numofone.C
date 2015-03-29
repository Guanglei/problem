#include <iostream>
#include <stdint.h>

int map[16] = {
	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

int howManyOnes(uint8_t i)
{
	return (map[i>>4]) + (map[i&0x0f]);
}


int howManyOnes(uint16_t i)
{
	uint8_t highhalf = i >> 8;
	uint8_t lowhalf = i;
	int ret = 0;
	if(highhalf > 0)
	{
		ret += howManyOnes(highhalf);
	}
	if(lowhalf > 0)
	{
		ret += howManyOnes(lowhalf);
	}
	return ret;
}

int howManyOnes(uint32_t i)
{
	uint16_t highhalf = i >> 16;
	uint16_t lowhalf = i;
	int ret = 0;
	if(highhalf > 0)
	{
		ret += howManyOnes(highhalf); 
	}

	if(lowhalf > 0)
	{
		ret += howManyOnes(lowhalf);
	}
	
	return ret;
}

void printIntByBin(uint32_t i, std::ostream& out)
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

int main()
{
	while(true)
	{
		uint32_t input;
		std::cin >> input;
		std::cout << "the input in bin is ";
		printIntByBin(input, std::cout);
		std::cout << std::endl;
		std::cout << "number of 1 is " 
			      << howManyOnes(input) << std::endl;
	}

	return 0;
}
