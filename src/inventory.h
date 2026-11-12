#pragma once

#include <string>
#include <utility>
#include <vector>

// Inventory counts items by name.
class Inventory {
public:
    void add(const std::string& item, int quantity);
    // Removes `quantity` of `item`. Returns false and leaves the count unchanged
    // when fewer than `quantity` are held; returns true on success.
    bool remove(const std::string& item, int quantity);
    int count(const std::string& item) const;

private:
    std::vector<std::pair<std::string, int>> items_;
};
