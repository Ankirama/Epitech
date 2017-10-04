-- this is a dummy IA
-- written by myself and me

-- goal: random direction, never put a bomb, never dodge a bomb, because he's dummy!

-- value from map
EMPTY, WALL, BOMB, PLAYER, BLOCK = 48, 49, 50, 51, 52

-- directions
UP, LEFT, DOWN, RIGHT, NONE = 0, 1, 2, 3, 5

function getElement(map, x, y, width)
   return string.byte(map, y * width + x + 1)
end

function isEmptyCell(map, x, y, sizeWindow)
   if x < 0 or y < 0 or
   x >= sizeWindow[1] or y >= sizeWindow[2] then
      return false
   elseif (getElement(map, x, y, sizeWindow[1])) == EMPTY then
      return true
   end
   return false
end

function isMovable(map, currentPos, sizeWindow)
   return (isEmptyCell(map, currentPos[1], currentPos[2] - 1, sizeWindow) or
	      isEmptyCell(map, currentPos[1], currentPos[2] + 1, sizeWindow) or
	      isEmptyCell(map, currentPos[1] - 1, currentPos[2], sizeWindow) or
	      isEmptyCell(map, currentPos[1] + 1, currentPos[2], sizeWindow))
end

function direction(map, currentPos, sizeWindow)
   local izi = 0
   local tmpX, tmpY = -1, -1
   if isMovable(map, currentPos, sizeWindow) == false then
      return NONE
   end
   while (isEmptyCell(map, tmpX, tmpY, sizeWindow) == false) do
      izi = math.random(0, 3)
      if izi == UP then
	 tmpY = currentPos[2] - 1
	 tmpX = currentPos[1]
      elseif izi == RIGHT then
	 tmpY = currentPos[2]
	 tmpX = currentPos[1] + 1
      elseif izi == DOWN then
	 tmpY = currentPos[2] + 1
	 tmpX = currentPos[1]
      else
	 tmpY = currentPos[2]
	 tmpX = currentPos[1] - 1
      end
   end
   return izi
end

-- map: current maze
-- x: current xPosition about current bot
-- y: current yPosition about current bot
-- width: width maze
-- height: height maze
-- return next move
function execute(map, x, y, width, height)
   local currentPos = {x, y}
   local sizeWindow = {width, height}
   return direction(map, currentPos, sizeWindow)
end
