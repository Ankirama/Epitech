module Door = struct
  type position = Top | Bot | Left | Right | None;;
  type state    = Open | Close;;
  type door     = (position * state);;

  let create (position : position) (state : state) = (position, state)

  let getState (door : door) = match door with
    | (_, state) -> state
  ;;

  let setState (door : door) (newState : state) = match door with
    | (position, _) -> position, newState
  ;;

  let getPosition (door : door) = match door with
    | (position, _) -> position
  ;;

  let setPosition (door : door) (newPosition : position) = match door with
    | (_, state) -> newPosition, state
  ;;

  let isOpen (door : door) = match door with
    | (_, state) -> if state == Open
                  then true
                  else false
  ;;

end;;

module Case = struct
  exception Door_not_found;;
  type case = int * (Door.door list);;

  let create value = value, (Door.Left, Door.Close)::(Door.Right, Door.Close)::(Door.Top, Door.Close)::(Door.Bot, Door.Close)::[]
  ;;

  let getDoor (case : case) position =
    let rec aux position = function
      | [] -> raise Door_not_found
      | door::queue ->  if (Door.getPosition door) == position
                        then door
                        else aux position queue
    in match case with
      | (_, doors) -> aux position doors
  ;;

  let isDoorsOpen (case : case) (doors : Door.position list) =
    let rec aux case = function
      | [] -> true
      | position::queue -> (Door.getState (getDoor case position) == Door.Open) && aux case queue
    in aux case doors
  ;;

  let openDoor (case : case) position =
    let rec aux position = function
      | [] -> raise Door_not_found
      | door::queue ->  if (Door.getPosition door ) == position
                        then (position, Door.Open)::queue
                        else door::(aux position queue)
    in match case with
      | (value, doors) -> value, (aux position doors)
  ;;

  let getValue (case : case) = match case with
    | (value, _) -> value
  ;;

  let setValue (case : case) newValue = match case with
    | (_, doors) -> (newValue, doors)
  ;;


end;;

module Labyrinth = struct
  type labyrinth = Case.case array;;

let changeNumber (maze : labyrinth) newNb oldNb =
  Array.map (fun c -> if (Case.getValue c) == oldNb
                      then (match c with
                        | (_, doors) -> newNb, doors)
                      else c) maze
;;

let shuffle d =
  let nd = List.map (fun c -> (Random.bits (), c)) d in
  let sond = List.sort compare nd in
  List.map snd sond

let openDoor maze width height index =
  let randomDoor case doorsList nb =
    let shuffleList = shuffle doorsList
    in let rec aux = function
      | [] -> Door.None
      | position::queue -> if (Door.getState (Case.getDoor case position) == Door.Open)
                          then aux queue
                          else position
  in aux shuffleList
  in let first_line =  if index == 0
                        then randomDoor maze.(index) (Door.Right::Door.Bot::[]) 2
                        else if index == width - 1
                        then randomDoor maze.(index) (Door.Left::Door.Bot::[]) 2
                        else randomDoor maze.(index) (Door.Left::Door.Right::Door.Bot::[]) 3
  in let last_line =  if index == (height - 1) * width
                      then randomDoor maze.(index) (Door.Right::Door.Top::[]) 2
                      else if index == (height - 1) * width + (height - 1)
                      then randomDoor maze.(index) (Door.Left::Door.Top::[]) 2
                      else randomDoor maze.(index) (Door.Left::Door.Right::Door.Top::[]) 3
  in let normal_line =  if index mod width == 0
                        then randomDoor maze.(index) (Door.Top::Door.Bot::Door.Right::[]) 3
                        else if index mod width == width - 1
                        then randomDoor maze.(index) (Door.Top::Door.Bot::Door.Left::[]) 3
                        else randomDoor maze.(index) (Door.Top::Door.Bot::Door.Left::Door.Right::[]) 4
  in let rec openDoors index =
    let randomPosition =
      if index < width
      then first_line
      else if index / width == height - 1
      then last_line
      else normal_line
    in if randomPosition == Door.None
       then maze
       else (match (Case.getDoor (maze.(index)) randomPosition) with
      | (_, state) -> if state == Door.Open
                      then openDoors index
                      else (Array.set maze index (Case.openDoor (maze.(index)) randomPosition);
                      match (randomPosition) with
                        | Door.None -> maze
                        | Door.Top -> let min = index - width
                                      in maze.(min) <- Case.openDoor maze.(min) Door.Bot;
                                      changeNumber maze (Case.getValue maze.(index)) (Case.getValue maze.(min))
                        | Door.Bot -> let max = index + width
                                      in maze.(max) <- Case.openDoor maze.(max) Door.Top;
                                      changeNumber maze (Case.getValue maze.(index)) (Case.getValue maze.(max))
                        | Door.Left ->  let left = index - 1
                                        in maze.(left) <- Case.openDoor maze.(left) Door.Right;
                                        changeNumber maze (Case.getValue maze.(index)) (Case.getValue maze.(left))
                        | Door.Right -> let right = index + 1
                                        in maze.(right) <- Case.openDoor maze.(right) Door.Left;
                                        changeNumber maze (Case.getValue maze.(index)) (Case.getValue maze.(right))
                            ))
  in openDoors index
;;

let create width height = Array.init (width * height) (fun i -> Case.create i)
;;

let print maze (width : int) (height : int) =
  let draw_wall index position symb default =
    if Door.getState (Case.getDoor maze.(index) position) == Door.Close
    then print_string symb
    else print_string default
  in let rec draw_line1 index =
      draw_wall index Door.Top "---" "   ";
      if index mod width == width - 1
      then print_endline ""
      else draw_line1 (index + 1)
  in let rec draw_line2 index =
    draw_wall index Door.Left "|" " ";
    (match maze.(index) with
      | (value, _) -> print_char ' ');
    draw_wall index Door.Right "|" " ";
    if index mod width == width - 1
    then print_endline ""
    else draw_line2 (index + 1)
  in let rec draw_line3 index =
    draw_wall index Door.Bot "---" "   ";
    if index mod width == width - 1
    then print_endline ""
    else draw_line3 (index + 1)
  in let rec draw index =
    if index < (width * height)
    then (draw_line1 index; draw_line2 index; draw_line3 index; draw (index + width))
  in draw 0
;;

let checkOk maze size =
  let rec aux maze size nb =
    if size == 0
    then nb == Case.getValue maze.(size)
    else if nb != Case.getValue maze.(size)
    then false
    else true && aux maze (size - 1) nb
  in aux maze size (Case.getValue maze.(0))
;;

let solve maze width height =
  let rec create_list size =
    if size == 0
    then []
    else (size - 1)::(create_list (size - 1))
  in let mazeID = shuffle (create_list (width * height))
  in let rec aux maze = function
    | [] -> maze
    | casePosition::queue -> aux (openDoor maze width height casePosition) queue
  in aux maze mazeID
;;


end;;
