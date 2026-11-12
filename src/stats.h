#pragma once

#include <vector>

// average returns the arithmetic mean of `values`, or 0.0 if `values` is empty.
double average(const std::vector<int>& values);

// clamp_percent limits `value` to the range 0..100.
int clamp_percent(int value);
