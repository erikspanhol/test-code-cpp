# test-code-cpp

A tiny, made-up C++ and Lua code base used as a sandbox for testing an AI code-support
agent. Nothing here is real product code.

- `src/ring_buffer.*` — a fixed-size ring buffer of ints.
- `src/inventory.*` — item counts for a player inventory.
- `src/stats.*` — small statistics helpers.
- `scripts/loot.lua` — loot table rolls used by game scripts.

```bash
cmake -S . -B build && cmake --build build && ctest --test-dir build
lua tests/loot_test.lua
```
