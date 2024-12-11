#include "templates.hpp"
#include <iostream>
#include <exception>

template <typename T>
T max(T x, T y) {
	if (x > y) return x;
	if (y > x) return y;
	else throw std::runtime_error("Both inputs are equal");
}