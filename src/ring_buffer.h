#pragma once

#include <cstddef>
#include <vector>

// RingBuffer keeps the most recent `capacity` values. Pushing into a full
// buffer drops the oldest value.
class RingBuffer {
public:
    explicit RingBuffer(std::size_t capacity);

    void push(int value);
    bool full() const;
    std::size_t size() const;
    // at(0) is the oldest value still kept.
    int at(std::size_t i) const;

private:
    std::vector<int> data_;
    std::size_t head_ = 0;  // next write position
    std::size_t count_ = 0;
};
