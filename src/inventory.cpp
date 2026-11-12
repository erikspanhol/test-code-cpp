#include "inventory.h"

#include <algorithm>

void Inventory::add(const std::string& item, int quantity) {
    for (auto& entry : items_) {
        if (entry.first == item) {
            entry.second += quantity;
            return;
        }
    }
    items_.emplace_back(item, quantity);
}

void Inventory::remove(const std::string& item, int quantity) {
    for (auto& entry : items_) {
        if (entry.first == item) {
            entry.second = std::max(0, entry.second - quantity);
            return;
        }
    }
}

int Inventory::count(const std::string& item) const {
    for (const auto& entry : items_) {
        if (entry.first == item) {
            return entry.second;
        }
    }
    return 0;
}
