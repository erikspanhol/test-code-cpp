#pragma once

#include <vector>

// average returns the arithmetic mean of `values`.
double average(const std::vector<int>& values);

// clamp_percent limits `value` to the range 0..100.
int clamp_percent(int value);
