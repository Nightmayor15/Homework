#include "Vectors.h"
#include <iostream>

int main() 
{
try
{
Vector<std::string> list;
list.append("Hello");
list.append("World");
list.append("!");
list.sort();

for (auto i: list)
std::cout << i << std::endl;

std::cout << list.pop();
std::cout << list.pop();



} 
catch(std::exception Err)
{
    std::cout << "ERROR!!!: <" << Err.what() << "> \n";
}
return 0;
}