module Door: sig
  type position
  type state
  type door

  val create      : position -> state -> door
  val getState    : door -> state
  val setState    : door -> state -> door
  val getPosition : door -> position
  val setPosition : door -> position -> door
  val isOpen      : door -> bool
end;;

module Case: sig
  type case

  val create      : int -> case
  val getDoor     : case -> Door.position -> Door.door
  val isDoorsOpen : case -> Door.position list -> bool
  val openDoor    : case -> Door.position -> case
  val getValue    : case -> int
  val setValue    : case -> int -> case
end;;

module Labyrinth: sig

  type labyrinth
  val changeNumber  : labyrinth -> int -> int -> labyrinth
  val openDoor      : labyrinth -> int -> int -> int -> labyrinth
  val create        : int -> int -> labyrinth
  val print         : labyrinth -> int -> int -> unit
  val solve         : labyrinth -> int -> int -> labyrinth
end;;
