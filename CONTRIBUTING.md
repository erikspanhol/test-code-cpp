# Contributing

- Keep changes small and focused on one issue.
- C++ tests live in `tests/test_main.cpp` and use the `CHECK` macro defined there; add a
  `test_*` function and call it from `main`. Lua tests live in `tests/loot_test.lua`.
- Every bug fix comes with a test that fails before the fix and passes after it.
- Keep public headers in `src/` in sync with their `.cpp` files.
- Files in `src/stats.*` use Windows line endings (CRLF); keep them that way.
