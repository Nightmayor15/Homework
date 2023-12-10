#include "Vectors.h"
#include <iostream>

int main() 
{
try
{
Vector<int> list;
list.append(1);
list.append(5);
list.append(3);
list.sort();
//list.clear();

//std::cout << list;

for (auto i: list)
std::cout << i << std::endl;


} 
catch(std::exception Err)
{
    std::cout << "ERROR!!!: <" << Err.what() << "> \n";
}
return 0;
}