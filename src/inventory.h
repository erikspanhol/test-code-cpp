#pragma once

#include <string>
#include <utility>
#include <vector>

// Inventory counts items by name.
class Inventory {
public:
    void add(const std::string& item, int quantity);
    // Removes up to `quantity` of `item`. Removing more than is held empties it.
    void remove(const std::string& item, int quantity);
    int count(const std::string& item) const;

private:
    std::vector<std::pair<std::string, int>> items_;
};
