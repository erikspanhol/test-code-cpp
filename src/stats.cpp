#include "stats.h"

double average(const std::vector<int>& values) {
    int total = 0;
    for (int v : values) {
        total += v;
    }
    return total / values.size();
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
