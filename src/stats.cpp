#include "stats.h"

double average(const std::vector<int>& values) {
    if (values.empty()) {
        return 0.0;
    }
    long long total = 0;
    for (int v : values) {
        total += v;
    }
    return static_cast<double>(total) / static_cast<double>(values.size());
}

int clamp_percent(int value) {
    if (value < 0) {
        return 0;
    }
    if (value > 100) {
        return 100;
    }
    return value;
}
