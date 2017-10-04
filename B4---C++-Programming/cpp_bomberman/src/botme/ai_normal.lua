-- this is a normal IA but kinda stupid don't worry
-- written by myself and me

-- goal: win.
-- goal: find closer foe, A star (maybe) to find best way to kill him.
-- goal: if close to his ennemy, he will try to put some bombs, can become a kamikaze
-- goal: like ai_easy, if bomb near him, he will try to dodge it

-- value from map
EMPTY, WALL, BOMB, PLAYER, BLOCK, PLAYER_BOMB = 48, 49, 50, 51, 52, 53

-- directions + actions (put = put a bomb, isn't it obvious naab?)
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
   local retX, retY = 0, 0
   if checkEmpty and isEmptyCell(map, x, y, sizeWindow) == false then
      return -1, -1
   end
   while j < 3 and y - j >= 0 and getElement(map, x, y - j, sizeWindow[1]) ~= WALL
   and getElement(map, x, y - j, sizeWindow[1]) ~= BLOCK do
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

function randomPosition(map, x, y, sizeWindow)
  local direction = {}
  local index = 1
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
  local operation = math.random(0, #direction + 1)
  if operation == #direction + 1 then
    return PUT
  else
    return direction[operation]
  end
end

function defensive(x, y, directions)
  if math.abs(x) > math.abs(y) and x ~= y then
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
  local index = 1
  while index < #directions + 1 and directions[index] == false do
    index = index + 1
  end
  if index == #directions + 1 then
    return NONE
  else
    return index - 1
  end
end

function convPosition(x, y, i, j)
  if x - 1 == i and y == j then
    return LEFT
  elseif x + 1 == i and y == j then
    return RIGHT
  elseif y - 1 == j and x == i then
    return UP
  elseif y + 1 == j and x == i then
    return DOWN
  else
    return NONE
  end
end

function isDirOk(map, x, y, sizeWindow)
  local i, j = checkAround(map, x, y, sizeWindow, true)
  if i == 0 and j == 0 then
    return true
  else
    return false
  end
end

function offensive(map, x, y, sizeWindow)
  local i, j, found = nearest_ennemy(map, x, y, sizeWindow)
  if found == true then
    local path = a_star(map, {x, y}, {i, j}, sizeWindow)
    if #path == 0 then
      return randomPosition(map, x, y, sizeWindow)
    end
    if #path < 2 or getElement(map, path[1][1], path[1][2], sizeWindow[1]) == BLOCK then
      return PUT
    else
      return convPosition(x, y, path[1][1], path[1][2])
    end
  else
    return randomPosition(map, x, y, sizeWindow)
  end
end

--choose "best" strategy
function goal(map, x, y, sizeWindow)
  local i, j = checkAround(map, x, y, sizeWindow, false)
  if i ~= 0 or j ~= 0 or getElement(map, x, y, sizeWindow[1]) == PLAYER_BOMB then
    return defensive(i, j, getDirections(map, x, y, sizeWindow))
  end
  return offensive(map, x, y, sizeWindow)
end

-- try to find an ennemy near the current position
function nearest_ennemy(map, x, y, sizeWindow)
  local i = x - 2
  local cout = -1
  local position = {0, 0}
  while i < x + 2 and i < sizeWindow[1] do
    if i >= 0 then
      local j = y - 2
      while j < y + 2 and j < sizeWindow[2] do
        if j >= 0 and (i == x and j == y) == false then
          if getElement(map, i, j, sizeWindow[1]) == PLAYER then
            local tmpCout = dist(i, j, x, y)
            if cout == -1 or cout > tmpCout then
              cout = tmpCout
              position[1] = i
              position[2] = j
            end
          end
        end
        j = j + 1
      end
    end
    i = i + 1
  end
  if cout == -1 then
    return 0, 0, false
  else
    return position[1], position[2], true
  end
end

--------------------------------------------------------
-- A STAR
-- by myself (joke, I found it on youporn!!
-- Err no! It was another one but ... I can't tell ya haha).
-- (github.com/ankirama ?)
--------------------------------------------------------

COUT_G, COUT_H, COUT_F, PARENT, CURRENT = 1, 2, 3, 4, 5

OPEN_LIST, CLOSE_LIST = 1, 2
BEGIN, GOAL = 1, 2

function dist(x1, y1, x2, y2)
  return math.sqrt(math.pow(x2 - x1, 2) + math.pow(y2 - y1, 2))
end

function get_node(list, x, y)
  local i = 1
  while i < #list + 1 and
  (list[i][CURRENT][1] == x and list[i][CURRENT][2] == y) == false do
    i = i + 1
  end
  if i == #list + 1 then
    return -1
  else
    return i
  end
end

function already_in(position, list)
  local i = 1
  while i < #list + 1 and
  (list[i][CURRENT][1] == position[1] and list[i][CURRENT][2] == position[2]) == false do
      i = i + 1
  end
  return i < #list + 1
end

-- parametres de mort... :
-- map: ben la map askip'
-- positions: 2 vecteurs(x,y): BEGIN, GOAL
-- sizeWindow: vecteur size -> sizeWindow[1] = width, sizeWindow[2] = height
-- doubleFists: opened list(doubleFists[1]) + closed list(doubleFists[2])
function add_adj_cell(map, positions, sizeWindow, doubleFists)
  local tmp = {0, 0, 0, {0, 0}, {0, 0}}
  local i = positions[BEGIN][1] - 1
  while i <= positions[BEGIN][1] + 1 do
    if i >= 0 and i < sizeWindow[1] then
      local j = positions[BEGIN][2] - 1
      while j <= positions[BEGIN][2] + 1 do
        if j >= 0 and j < sizeWindow[2] and
        (i == positions[BEGIN][1] and j == positions[BEGIN][2]) == false and
        getElement(map, i, j, sizeWindow[1]) ~= WALL then
          local tmpPosition = {i, j}
          tmp[CURRENT] = tmpPosition
          if already_in(tmpPosition, doubleFists[CLOSE_LIST]) == false then
            tmp[COUT_G] = doubleFists[CLOSE_LIST]
            [get_node(doubleFists[CLOSE_LIST], positions[BEGIN][1], positions[BEGIN][2])][COUT_G]
            + dist(i, j, positions[BEGIN][1], positions[BEGIN][2])
            tmp[COUT_H] = dist(i, j, positions[GOAL][1], positions[GOAL][2])
            tmp[COUT_F] = tmp[COUT_G] + tmp[COUT_H]
            tmp[PARENT] = positions[BEGIN]
            if already_in(tmpPosition, doubleFists[OPEN_LIST]) == true then
              local idx = get_node(doubleFists[OPEN_LIST], tmpPosition[1], tmpPosition[2])
              if tmp[COUT_F] < doubleFists[OPEN_LIST][idx][COUT_F] then
                table.remove(doubleFists[OPEN_LIST], idx)
                table.insert(doubleFists[OPEN_LIST], tmp)
              end
            else
              table.insert(doubleFists[OPEN_LIST], tmp)
            end
          end
        end
        j = j + 1
      end
    end
    i = i + 1
  end
end

function best_node(list)
  local i = 2
  b_coutf = list[1][COUT_F]
  tmpPosition = list[1][CURRENT]
  while i < #list + 1 do
    if list[i][COUT_F] < b_coutf then
      b_coutf = list[i][COUT_F]
      tmpPosition = list[i][CURRENT]
    end
    i = i + 1
  end
  return tmpPosition
end

function add_closed_list(doubleFists, position)
  local nodeIdx = get_node(doubleFists[OPEN_LIST], position[1], position[2])
  table.insert(doubleFists[CLOSE_LIST], doubleFists[OPEN_LIST][nodeIdx])
  table.remove(doubleFists[OPEN_LIST], nodeIdx)
end

function find_path(doubleFists, positions, begin)
  local nodeIdx = get_node(doubleFists[CLOSE_LIST], positions[GOAL][1], positions[GOAL][2])
  local path = {}
  local n = positions[GOAL]
  local prev = doubleFists[CLOSE_LIST][nodeIdx][PARENT]
  table.insert(path, 1, n)
  while (prev[1] == begin[PARENT][1] and prev[2] == begin[PARENT][2]) == false do
    n = prev
    table.insert(path, 1, n)
    nodeIdx = get_node(doubleFists[CLOSE_LIST],
    doubleFists[CLOSE_LIST][nodeIdx][PARENT][1],
    doubleFists[CLOSE_LIST][nodeIdx][PARENT][2])
    prev = doubleFists[CLOSE_LIST][nodeIdx][PARENT]
  end
  return path
end

function a_star(map, positionBegin, positionGoal, sizeWindow)
  local start = {0, 0, 0, positionBegin, positionBegin}
  local current = positionBegin
  local opened_list = {start}
  local closed_list = {}
  add_closed_list({opened_list, closed_list}, current)
  add_adj_cell(map, {current, positionGoal}, sizeWindow, {opened_list, closed_list})
  while (current[1] == positionGoal[1] and current[2] == positionGoal[2]) == false
  and #opened_list ~= 0 do
    current = best_node(opened_list)
    add_closed_list({opened_list, closed_list}, current)
    add_adj_cell(map, {current, positionGoal}, sizeWindow, {opened_list, closed_list})
  end
  if current[1] == positionGoal[1] and current[2] == positionGoal[2] then
    path = find_path({opened_list, closed_list}, {positionBegin, positionGoal}, start)
    if #path > 0 then
      return path
    end
  end
  return {}
end

--------------------------------------------------------
-- A STAR END
-- Sorry, i can't continue like that, I have to leave you cya
--------------------------------------------------------

-- map: current maze
-- x: current xPosition about current bot
-- y: current yPosition about current bot
-- width: width maze
-- height: height maze
-- return next move
function execute(map, x, y, width, height)
  return goal(map, x, y, {width, height})
end
