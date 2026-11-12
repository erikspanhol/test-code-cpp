package.path = "scripts/?.lua;" .. package.path
local loot = require("loot")

local function check(cond, msg)
  if not cond then
    error("FAIL: " .. msg, 2)
  end
end

check(loot.roll_loot({}, 3) == nil, "empty table gives nil")
check(loot.roll_loot({"sword", "shield", "potion"}, 1) == "sword", "roll 1 gives the first entry")
check(loot.roll_loot({"sword", "shield", "potion"}, 3) == "potion", "roll 3 gives the last entry")
for roll = 0, 30 do
  check(loot.roll_loot({"sword", "shield", "potion"}, roll) ~= nil, "roll " .. roll .. " gives an item")
end

print("loot tests passed")
