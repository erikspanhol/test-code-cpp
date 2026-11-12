-- Loot table rolls used by game scripts.
local loot = {}

-- roll_loot returns one entry of `table` for a dice roll (any non-negative
-- integer). Every entry must be reachable.
function loot.roll_loot(table, roll)
  if #table == 0 then
    return nil
  end
  -- Lua arrays are 1-based; map rolls onto 1..#table. Lua's % always
  -- returns a non-negative result here, so roll 0 maps to the last entry.
  return table[(roll - 1) % #table + 1]
end

return loot
