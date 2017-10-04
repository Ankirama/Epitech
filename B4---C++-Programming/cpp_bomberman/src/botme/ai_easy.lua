-- this is an easy IA
-- written by myself and me

-- goal: random direction, if he can put a bomb, he will try it (random like, 1 / 3).
-- goal: if he puts a bomb then we will back to don't die by himself (it's not a dummy AI hehe).
-- goal: if he's in a danger area (a bomb near him), he will try to dodge it

-- default: don't care about its own bombs.. lel n00b

-- value from map
EMPTY, WALL, BOMB, PLAYER, BLOCK, PLAYER_BOMB = 48, 49, 50, 51, 52, 53

-- directions
UP, LEFT, DOWN, RIGHT, PUT, NONE = 0, 1, 2, 3, 4, 5

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

function getDirections(map, x, y, sizeWindow)
  local directions = {false, false, false, false}
  if (isEmptyCell(map, x, y - 1, sizeWindow)) == true then
    directions[UP + 1] = true
  end
  if (isEmptyCell(map, x + 1, y, sizeWindow)) == true then
    directions[RIGHT + 1] = true
  end
  if (isEmptyCell(map, x, y + 1, sizeWindow)) == true then
    directions[DOWN + 1] = true
  end
  if (isEmptyCell(map, x - 1, y, sizeWindow)) == true then
    directions[LEFT + 1] = true
  end
  return directions
end

function checkAround(map, x, y, sizeWindow, checkEmpty)
   local i, j = 1, 1
   retX, retY = 0, 0
   if checkEmpty and isEmptyCell(map, x, y, sizeWindow) == false then
      return -1, -1
   end
   while j < 3 and y - j >= 0 and getElement(map, x, y - j, sizeWindow[1]) ~= WALL and
   getElement(map, x, y - j, sizeWindow[1]) ~= BLOCK
    do
      if getElement(map, x, y - j, sizeWindow[1]) == BOMB then
	       retY = retY - j
         break
      end
      j = j + 1
   end
   j = 1
   while j < 3 and y + j < sizeWindow[2] and getElement(map, x, y + j, sizeWindow[1]) ~= WALL
   and getElement(map, x, y - j, sizeWindow[1]) ~= BLOCK do
      if getElement(map, x, y + j, sizeWindow[1]) == BOMB then
	       retY = retY + j
         break
      end
      j = j + 1
   end
   while i < 3 and x - i >= 0 and getElement(map, x - i, y, sizeWindow[1]) ~= WALL
   and getElement(map, x, y - j, sizeWindow[1]) ~= BLOCK do
      if getElement(map, x - i, y, sizeWindow[1]) == BOMB then
	       retX = retX - i
         break
      end
      i = i + 1
   end
   i = 1
   while i < 3 and x + i < sizeWindow[1] and getElement(map, x + i, y, sizeWindow[1]) ~= WALL
   and getElement(map, x, y - j, sizeWindow[1]) ~= BLOCK do
      if getElement(map, x + i, y, sizeWindow[1]) == BOMB then
	       retX = retX + i
         break
      end
      i = i + 1
   end
   return retX, retY
end

function isDirOk(map, x, y, sizeWindow)
  local i, j = checkAround(map, x, y, sizeWindow, true)
  if i == 0 and j == 0 then
    return true
  else
    return false
  end
end

function offensive(map, x, y, sizeWindow, directions)
  local operation = math.random(#directions + 1)
  if operation == #directions + 1 then
    return PUT
  else
    return directions[operation]
  end
end

function defensive(x, y, directions)
  if math.abs(x) > math.abs(y) then
    if (x < 0) then
      directions[LEFT + 1] = false
    else
      directions[RIGHT + 1] = false
    end
  else
    if y < 0 then
      directions[UP + 1] = false
    else
      directions[DOWN + 1] = false
    end
  end
  index = 1
  while index < #directions + 1 and directions[index] == false do
    index = index + 1
  end
  if index == #directions + 1 then
    return NONE
  else
    return index - 1
  end
end

function goal(map, x, y, sizeWindow)
  local index = 1
  local direction = {}
  local i, j = checkAround(map, x, y, sizeWindow, false)
  if i ~= 0 or j ~= 0 or getElement(map, x, y, sizeWindow[1]) == PLAYER_BOMB then
    dir = getDirections(map, x, y, sizeWindow)
    return defensive(i, j, dir)
  end
  if isDirOk(map, x - 1, y, sizeWindow) then
    direction[index] = LEFT
    index = index + 1
  end
  if isDirOk(map, x + 1, y, sizeWindow) then
    direction[index] = RIGHT
    index = index + 1
  end
  if isDirOk(map, x, y - 1, sizeWindow) then
    direction[index] = UP
    index = index + 1
  end
  if isDirOk(map, x, y + 1, sizeWindow) then
    direction[index] = DOWN
  end
  if #direction ~= 0 then
    return offensive(map, x, y, sizeWindow, direction)
  end
  return NONE
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
   return goal(map, x, y, sizeWindow)
end
