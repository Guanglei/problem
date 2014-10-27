/*
According to many researches, people can stand on a bus for several hours, but waiting for a bus for more than 30 minutes at a bus station can make us exhausted. The Chef is a perfect example for this fact. He always tries to reduce the longest period of time of waiting for a bus. Therefore, optimizing the traveling plan for him is far from an easy task.

Let's consider the bus system with N bus stations (numbered from 1 to N) and M buses (numbered from 1 to M). Each bus is represented by 4 integer numbers U, V, S, E which means it will start at the bus station U at the time S and arrive at the bus station V at the time E with no intermediate bus stations. If passenger arrives at the bus station U at the time X ≤ S, he has to wait for S − X units of time to catch this bus. Note, that if he arrives at the bus station U exactly at time S he can catch this bus with no waiting time.

The Chef starts at the time 0 in the bus station 1, and he wants to arrive at the bus station N in a way that the longest period that he spends for waiting for a bus is as small as possible. Besides, he must be at the bus station N before or at the time T for a specially important meeting. Note, that he may wait for a meeting if he arrives at the bus station N early but that period is not our concern here, since he doesn't wait for any bus at that time.
Input

The first line of the input contains three space-separated integers N, T and M, denoting the number of bus stations, the deadline for coming to bus station N and the number of buses, respectively. Each of the following M lines contains four space-separated integers U, V, S, E, the parameters of the current bus as described in the problem statement.
Output

If Chef cannot arrive at the bus station N before or at the time T, output -1. Otherwise, output the maximum period of time he has to wait for a bus in the optimal traveling plan.

Example

Input:
5 10 5
1 2 1 2
1 5 3 4
2 4 4 5
2 5 5 6
4 5 6 7

Output:
2

Explanation

There are three different traveling plans:
bus 1 → bus 3 → bus 5. His waiting time for each bus is 1, 2, 1, respectively.
bus 2. His waiting time is 3.
bus 1 → bus 4. His waiting time for each bus is 1, 3, respectively.

*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Bus
{
  int sStop;
  int eStop;
  int sTime;
  int eTime;
};

typedef std::vector<Bus> BusList;

void parseInput(std::istream& in, BusList& buses, int& numStops, int& timeLimit)
{
  int numBuses;
  in >> numStops >> timeLimit >> numBuses;
  for(int i = 1; i <= numBuses; ++i)
  {
    Bus b;
    in >> b.sStop >> b.eStop >> b.sTime >> b.eTime;
    
    if(b.eTime <= timeLimit)
    {
      buses.push_back(b);
    }
  }
}

int g_maxWaitTime = 0;
void printMaxTime(Bus* b, Bus* lastBus, int lastEndTime, int sStop, int lastStop, int& maxWaitTime)
{
  while(b->sStop != sStop && b != lastBus)
  {
    ++b;
  }
  
  if(b->sStop != sStop)
  {
    return;
  }

  if(sStop == 1)
  {
    maxWaitTime = 0;
  }
  
  while(b->sStop == sStop)
  {
    int waitTime = b->sTime-lastEndTime;
    if(waitTime > maxWaitTime)
    {
      maxWaitTime = waitTime;
    }

    if(b->eStop == lastStop)
    {
      if( g_maxWaitTime == 0 || maxWaitTime < g_maxWaitTime)
      {
        g_maxWaitTime = maxWaitTime;
      }
      return;
    }
    else if(b != lastBus)
    {
      printMaxTime(b, lastBus, b->eTime, b->eStop, lastStop, maxWaitTime);
      ++b;
    }
    else
    {
      break;
    }
  }
}

int main()
{

  BusList buses;
  int numStops, timeLimit;

  parseInput(std::cin, buses, numStops, timeLimit);
  std::sort(buses.begin(), buses.end(), 
              [](const Bus& l, const Bus& r)
              {
                return l.sStop < r.sStop || l.sStop == r.sStop && l.eStop < r.eStop;
              });
  
  int waitTime;
  printMaxTime(&buses[0], &buses[buses.size()-1], 0, 1, numStops, waitTime);
  std::cout << g_maxWaitTime << std::endl;

  return 0;
}
