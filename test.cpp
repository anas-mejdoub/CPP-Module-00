#include <iostream>
#include "t.hpp"

Test::Test()
{
    std::cout << "an obj will be created\n";
    i = 0;
}

void Test::plus_one()
{
    i++;
}

int main()
{
    Test obj;

    obj.plus_one();
    obj.plus_one();
    Test obj2;
    obj2 = obj;
    obj2.plus_one();
    obj2.i = 99;
    std::cout << "obj2 is " << obj2.i << "\n";
    std::cout << "obj is " << obj.i;
}