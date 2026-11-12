package.path = "scripts/?.lua;" .. package.path
local loot = require("loot")

local function check(cond, msg)
  if not cond then
    error("FAIL: " .. msg, 2)
  end
end

check(loot.roll_loot({}, 3) == nil, "empty table gives nil")
check(loot.roll_loot({"sword", "shield", "potion"}, 1) == "sword", "roll 1 gives the first entry")

local items = {"sword", "shield", "potion"}
check(loot.roll_loot(items, 3) == "potion", "roll 3 gives an item")
check(loot.roll_loot(items, 6) == "potion", "roll 6 gives an item")
for roll = 0, 30 do
  check(loot.roll_loot(items, roll) ~= nil, "roll " .. roll .. " gives an item")
end

print("loot tests passed")
