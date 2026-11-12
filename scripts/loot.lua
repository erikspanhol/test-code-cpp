-- Loot table rolls used by game scripts.
local loot = {}

-- roll_loot returns one entry of `table` for a dice roll (any non-negative
-- integer). Every entry must be reachable.
function loot.roll_loot(table, roll)
  if #table == 0 then
    return nil
  end
  -- Lua arrays are 1-based: map roll onto 1..#table (a multiple of #table
  -- gives the last entry, keeping roll 1 -> first entry).
  return table[(roll - 1) % #table + 1]
end

return loot
