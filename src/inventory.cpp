#include "inventory.h"

#include <algorithm>

void Inventory::add(const std::string& item, int quantity) {
    items_[item] += quantity;
}

void Inventory::remove(const std::string& item, int quantity) {
    auto it = items_.find(item);
    if (it != items_.end()) {
        it->second = std::max(0, it->second - quantity);
    }
}

int Inventory::count(const std::string& item) const {
    auto it = items_.find(item);
    return it != items_.end() ? it->second : 0;
}
