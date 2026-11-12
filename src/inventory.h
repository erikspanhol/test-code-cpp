#pragma once

#include <string>
#include <utility>
#include <vector>

// Inventory counts items by name.
class Inventory {
public:
    void add(const std::string& item, int quantity);
    // Removes `quantity` of `item` and returns true. If fewer than `quantity`
    // are held, leaves the count unchanged and returns false.
    bool remove(const std::string& item, int quantity);
    int count(const std::string& item) const;

private:
    std::vector<std::pair<std::string, int>> items_;
};
