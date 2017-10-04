let check_int str =
  Str.string_match (Str.regexp ("[1-9][0-9]+")) str 0 ||
  Str.string_match (Str.regexp ("[1-9]$")) str 0

let check_float str =
  Str.string_match (Str.regexp ("[1-9][0-9]+")) str 0 ||
  Str.string_match (Str.regexp ("[1-9][0-9]+.[0-9]+")) str 0 ||
  Str.string_match (Str.regexp ("[1-9]$")) str 0

let calc_var p e s =
  let tmp = s /. 100.0
  in let var = tmp *. (1.0 -. tmp)
  in var /. e *. (p -. e) /. (p -. 1.0)

let print_result p e s variance amp_95 amp_99 =
  Printf.printf "taille de la population :\t %.0f\n" p;
  Printf.printf "taille de l'echantillon :\t %.0f\n" e;
  Printf.printf "resultat du sondage :\t \t %.2f\n" s;
  Printf.printf "variance estimee : \t \t %.6f\n" variance;
  Printf.printf "intervalle de confiance a 95%% : [%.2f%% ; %.2f%%]\n" (s -. amp_95) (s +. amp_95);
  Printf.printf "intervalle de confiance a 99%% : [%.2f%% ; %.2f%%]\n" (s -. amp_99) (s +. amp_99)


let run_cal p e s =
  let variance = calc_var p e s
  in let amp_95 = 1.96 *. (sqrt  variance) *. 100.0
  in let amp_99 = 2.58 *. (sqrt  variance) *. 100.0
  in print_result p e s variance amp_95 amp_99

let check_arg len argv =
  let usage_msg = "Usage : ./209sondage population echantillon sondage"
  in if len != 4 || check_int (Array.get argv 0) == false
    || check_int (Array.get argv 1) == false ||
    check_float(Array.get argv 2) == false
  then print_endline usage_msg
  else let p = float_of_string (Array.get argv 0)
  in let e = float_of_string (Array.get argv 1)
  in let s = float_of_string (Array.get argv 2)
  in if (p < s)
  then print_endline "Error : population inferior to echantillon!"
  else if (p <= 1.0 || e <= 1.0)
  then print_endline "Error : population and echantillon must be > 1 !"
  else if (s < 0.0)
  then print_endline "Error : sondage must be > 0 !"
  else run_cal p e s

let main () =
  let len = (Array.length Sys.argv)
  in let argv = (Array.sub Sys.argv 1 (len -1))
  in check_arg len argv

let () = main ()
