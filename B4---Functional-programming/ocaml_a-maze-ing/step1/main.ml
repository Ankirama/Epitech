let check_int str =
  Str.string_match (Str.regexp ("[1-9][0-9]+")) str 0 ||
  Str.string_match (Str.regexp ("[1-9]$")) str 0

let check_arg len argv =
  let usage_msg = "Usage: ./step1 [widht: 10-100] [height: 10-100]"
  in if len != 3 || check_int (Array.get argv 0) == false
    || check_int (Array.get argv 1) == false
  then print_endline usage_msg
  else let width = int_of_string (Array.get argv 0)
  in let height = int_of_string (Array.get argv 1)
  in if (width < 10 || height > 100 || height < 10 || height > 100)
  then print_endline usage_msg
  else (let maze = Labyrinth.Labyrinth.create width height
        in let mazeSolved = Labyrinth.Labyrinth.solve maze width height
        in Labyrinth.Labyrinth.print mazeSolved width height)

let main () =
  let len = (Array.length Sys.argv)
  in let argv = (Array.sub Sys.argv 1 (len -1))
  in check_arg len argv

let () = main ()
