-- Loot table rolls used by game scripts.
local loot = {}

-- roll_loot returns one entry of `table` for a dice roll (any non-negative
-- integer). Every entry must be reachable.
function loot.roll_loot(table, roll)
  if #table == 0 then
    return nil
  end
  return table[roll % #table]
end

return loot
