package.path = "scripts/?.lua;" .. package.path
local loot = require("loot")

local function check(cond, msg)
  if not cond then
    error("FAIL: " .. msg, 2)
  end
end

check(loot.roll_loot({}, 3) == nil, "empty table gives nil")
check(loot.roll_loot({"sword", "shield", "potion"}, 1) == "sword", "roll 1 gives the first entry")

print("loot tests passed")
