#include <cstdio>
#include <cstdlib>

#include "inventory.h"
#include "ring_buffer.h"
#include "stats.h"

static int failures = 0;

#define CHECK(cond)                                                   \
    do {                                                              \
        if (!(cond)) {                                                \
            std::printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
            ++failures;                                               \
        }                                                             \
    } while (0)

static void test_ring_buffer_keeps_order() {
    RingBuffer rb(3);
    rb.push(1);
    rb.push(2);
    CHECK(rb.size() == 2);
    CHECK(rb.at(0) == 1);
    CHECK(rb.at(1) == 2);
    CHECK(!rb.full());
}

static void test_inventory_counts() {
    Inventory inv;
    inv.add("arrow", 10);
    inv.add("arrow", 5);
    CHECK(inv.count("arrow") == 15);
    inv.remove("arrow", 20);
    CHECK(inv.count("arrow") == 0);
    CHECK(inv.count("bow") == 0);
}

static void test_inventory_many_items() {
    Inventory inv;
    const int kItems = 20000;
    for (int i = 0; i < kItems; ++i) {
        inv.add("item" + std::to_string(i), i);
    }
    for (int i = 0; i < kItems; ++i) {
        inv.add("item" + std::to_string(i), 1);
    }
    CHECK(inv.count("item0") == 1);
    CHECK(inv.count("item19999") == 20000);
    inv.remove("item500", 100);
    CHECK(inv.count("item500") == 401);
    inv.remove("missing", 1);
    CHECK(inv.count("missing") == 0);
}

static void test_stats() {
    CHECK(average({2, 4}) == 3.0);
    CHECK(clamp_percent(150) == 100);
    CHECK(clamp_percent(-5) == 0);
}

int main() {
    test_ring_buffer_keeps_order();
    test_inventory_counts();
    test_inventory_many_items();
    test_stats();
    if (failures == 0) {
        std::printf("all tests passed\n");
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
