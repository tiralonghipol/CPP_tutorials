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

double multiplyByTwo(double num)
{
    return 2 * num;
}
// doMath receives a function with its attributes, a number,
// and return the result using the passed function
double doMath(std::function<double(double)> func, double num)
{
    return func(num);
}

double multiplyByThree(double num)
{
    return 3 * num;
}

bool isOdd(int num)
{
    if (num % 2 == 0)
        return false;
    else
        return true;
}
std::vector<int> changeList(std::vector<int> list, std::function<bool(int)> func)
{
    std::vector<int> odds;
    for (auto id : list)
    {
        if (func(id))
        {
            odds.push_back(id);
        }
    }
    return odds;
}
int changeCountHeads(std::vector<int> list, std::function<bool(int)> func)
{
    int num_of_heads = 0;
    for (auto id : list)
    {
        if (func(id))
        {
            num_of_heads++;
        }
    }
    return num_of_heads;
}
int main()
{
    // assign a function to a variable
    auto timesTwo = multiplyByTwo;
    std::cout << timesTwo(3) << std::endl;
    // pass a function to another function
    std::cout << doMath(timesTwo, 2) << std::endl;
    // store two functions in a vector
    std::vector<std::function<double(double)>> funcs(2);
    funcs[0] = multiplyByTwo;
    funcs[1] = multiplyByThree;
    // print the result accessing by reference
    std::cout << funcs[0](1.5) << std::endl;
    std::cout << funcs[1](2) << std::endl;

    // ------------ problem 1 ----------- //
    // std::vector<int> listOfNums{1, -1, 2, 3, -2, 7, 2, -3, -5};
    // std::vector<int> listOfOdds = changeList(listOfNums, isOdd);
    // std::cout << "List of nums:\n";
    // for (auto id : listOfNums)
    // {
    //     std::cout << id << " ";
    // }
    // std::cout << "\n";
    // std::cout << "List of odds:\n";
    // for (auto id : listOfOdds)
    // {
    //     std::cout << id << " ";
    // }
    // std::cout << "\n";
    // ------------ problem 2 ----------- //
    // size_t N = 8;
    // std::vector<int> headOrTail;
    // // shuffle random generator
    // std::mt19937 rng(std::random_device{}());
    // std::uniform_int_distribution<int> d(0, 1);
    // std::generate_n(std::back_inserter(headOrTail), N, [&]() { return d(rng); });
    // for (auto id : headOrTail)
    // {
    //     std::cout << id << " ";
    // }
    // std::cout << "\n";

    // int heads = changeCountHeads(headOrTail, isOdd);
    // std::cout << "Heads: " << heads
    //           << " Tails: " << N - heads << "\n";

    return 0;
}
