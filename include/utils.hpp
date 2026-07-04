// print.hpp
#pragma once

#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& v) {
    for (const auto& x : v)
        std::cout << x << ' ';
    std::cout << '\n';
}