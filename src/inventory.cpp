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

bool Inventory::remove(const std::string& item, int quantity) {
    for (auto& entry : items_) {
        if (entry.first == item) {
            if (entry.second < quantity) {
                return false;
            }
            entry.second -= quantity;
            return true;
        }
    }
    return quantity <= 0;
}

int Inventory::count(const std::string& item) const {
    for (const auto& entry : items_) {
        if (entry.first == item) {
            return entry.second;
        }
    }
    return 0;
}
