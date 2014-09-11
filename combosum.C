#include <set>
#include <iostream>
#include <string>
#include <sstream>

void findCombo(int n, int m, 
               std::set<int>& aux,
               std::set<std::string>& output)
{
  if(n <= 0 || m <= 0)
  {
    return;
  }
  
  std::set<int> aux1 = aux;
  if(n == m && aux1.find(n) == aux1.end())
  {
    aux1.insert(n);
    std::stringstream sstr;
    for(int i: aux1)
    {
      sstr<< i << ",";
    }
    output.insert(sstr.str());
  }

  aux1 = aux;
  findCombo(n-1, m, aux1, output);

  if(aux.find(1) == aux.end())
  {
    aux1 = aux;
    aux1.insert(1);
    findCombo(n, m-1, aux1, output);
  }

  if(m > n && aux.find(n) == aux.end())
  {
    aux1 = aux;
    aux1.insert(n);
    findCombo(n-1, m-n, aux1, output);
  }
}

int main()
{
  std::set<int> i;
  std::set<std::string> output;
  findCombo(30, 60, i, output);
  for(auto& s:output)
  {
    std::cout << s << std::endl;
  }
  return 0;
}
