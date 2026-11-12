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

static void test_ring_buffer_drops_oldest_when_full() {
    RingBuffer rb(3);
    for (int v : {1, 2, 3, 4}) {
        rb.push(v);
    }
    CHECK(rb.full());
    CHECK(rb.size() == 3);
    CHECK(rb.at(0) == 2);
    CHECK(rb.at(1) == 3);
    CHECK(rb.at(2) == 4);
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

static void test_stats() {
    CHECK(average({2, 4}) == 3.0);
    CHECK(clamp_percent(150) == 100);
    CHECK(clamp_percent(-5) == 0);
}

int main() {
    test_ring_buffer_keeps_order();
    test_ring_buffer_drops_oldest_when_full();
    test_inventory_counts();
    test_stats();
    if (failures == 0) {
        std::printf("all tests passed\n");
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
