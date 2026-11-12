#include "ring_buffer.h"

#include <stdexcept>

RingBuffer::RingBuffer(std::size_t capacity) : data_(capacity) {
    if (capacity == 0) {
        throw std::invalid_argument("capacity must be positive");
    }
}

void RingBuffer::push(int value) {
    data_[head_] = value;
    head_ = (head_ + 1) % data_.size();
    if (!full()) {
        ++count_;
    }
}

bool RingBuffer::full() const {
    return count_ > data_.size();
}

std::size_t RingBuffer::size() const {
    return count_;
}

int RingBuffer::at(std::size_t i) const {
    if (i >= count_) {
        throw std::out_of_range("index past the end of the buffer");
    }
    std::size_t oldest = (head_ + data_.size() - count_) % data_.size();
    return data_[(oldest + i) % data_.size()];
}
