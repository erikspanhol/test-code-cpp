#pragma once

#include <string>
#include <unordered_map>

// Inventory counts items by name.
class Inventory {
public:
    void add(const std::string& item, int quantity);
    // Removes up to `quantity` of `item`. Removing more than is held empties it.
    void remove(const std::string& item, int quantity);
    int count(const std::string& item) const;

private:
    // Hash map keyed by item name so lookups stay O(1) with many distinct items.
    std::unordered_map<std::string, int> items_;
};
