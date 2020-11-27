#pragma once
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <random>
#include <cctype>

// template functions example
template <typename myTimesTwo_T>
void timesTwo(myTimesTwo_T val)
{
    std::cout << 2 * val << std::endl;
}
template <typename T>
void add(T val1, T val2)
{
    std::cout << val1 + val2 << std::endl;
}
template <typename T>
void max(T val1, T val2)
{
    std::cout << ((val1 < val2) ? val2 : val1) << std::endl;
}

// template class example
template <typename T, typename U>
class Person
{
public:
    T height;
    U weight;
    static int n_people;
    Person(T h, U w)
    {
        height = h;
        weight = w;
        n_people++;
    }

    void getData()
    {
        std::cout << "H: " << height
                  << " W: " << weight
                  << std::endl;
    }
};

// this to handle the static int declaration in the template class
template <typename T, typename U> 
int Person<T, U>::n_people;

int main()
{
    // omg works with different types
    timesTwo(1.2);
    timesTwo(5);
    add(1, -1);
    max(1.7, 1.777777);

    Person<double, int> Mario(180.4, 80);
    Mario.getData();

    std::cout << Mario.n_people << std::endl;

    return 0;
}
