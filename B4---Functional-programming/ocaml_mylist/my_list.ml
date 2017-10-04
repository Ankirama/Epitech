type 'a my_list =
  | Item of ('a * 'a my_list)
  | Empty
;;

let rec length = function
  | Item (_, my_list) -> 1 + length my_list
  | _ -> 0
;;

let hd = function
  | Item (e, _) -> e
  | _ -> raise (Failure "hd")
;;

let tl = function
  | Item (_, lst) -> lst
  | _ -> raise (Failure "tl")
;;

let nth lst n =
  if n < 0
  then raise (Invalid_argument "List.nth")
  else
  let rec nth_rec n = function
    | Item(e, _) when n == 0 -> e
    | Item(_, lst) -> nth_rec (n - 1) lst
    | _ -> raise (Failure "nth") in
  nth_rec n lst
;;

let rev lst =
  let rec rev_rec rev_lst = function
    | Item(e, lst) -> rev_rec (Item (e, rev_lst)) lst
    | _ -> rev_lst in
  rev_rec Empty lst
;;

let rec append lst1 lst2 =
  match lst1 with
    | Item(e, lst) -> Item(e, append lst lst2)
    | _ -> lst2
;;

let rev_append lst1 lst2 =
  append (rev lst1) lst2
;;

let rec flatten = function
  | Item(a, b) -> append a (flatten b)
  | _ -> Empty
;;

let rec iter f = function
  | Item (e, lst) -> f e ; iter f lst
  | _ -> ()
;;

let rec map f = function
  | Item (e, lst) -> Item(f e, map f lst)
  | _ -> Empty
;;

let rec fold_left f a = function
  | Item(e, lst) -> fold_left f (f a e) lst
  | _ -> a
;;

let rec for_all f = function
  | Item(e, lst) -> f e && for_all f lst
  | _ -> true
;;

let rec exists f = function
  | Item(e, lst) when f e = true -> true
  | Item(e, lst) -> f e || exists f lst
  | _ -> false
;;

(*== physicaly*)
let rec mem a = function
  | Item(e, lst) when a = e -> true
  | Item(e, lst) -> mem a lst
  | _ -> false
;;

let rec memq a = function
  | Item(e, lst) when a == e -> true
  | Item(e, lst) -> memq a lst
  | _ -> false
;;

let rec filter f = function
  | Item(e, lst) when f e = true -> Item(e, filter f lst)
  | Item(_, lst) -> filter f lst
  | _ -> Empty
;;

let rec mem_assoc a = function
  | Item((e, _), lst) when a = e -> true
  | Item (_, lst) -> mem_assoc a lst
  | _ -> false
;;

let rec assoc a = function
  | Item((e1, e2), lst) when a = e1 -> e2
  | Item(_, lst) -> assoc a lst
  | _ -> raise (Not_found)
;;

(*C'est caca mais je vois pas comment faire plus propre pour le moment*)
let split lst =
  let rec aux1 = function
    | Item((e,_), lst) -> Item(e, aux1 lst)
    | _ -> Empty in
    let rec aux2 = function
      | Item((_, e), lst) -> Item(e, aux2 lst)
      | _ -> Empty in
      let l1 = aux1 lst and l2 = aux2 lst in
  (l1, l2)
;;

let rec remove_assoc a = function
  | Item((e, _), lst) when e = a -> lst
  | Item((e1, e2), lst) -> Item((e1, e2), remove_assoc a lst)
  | _ -> Empty
;;

(* BONUS *)
let rec fold_right f a = function
  | Item(e, lst) -> f e (fold_right f a lst)
  | _ -> a
;;
(*
length : 'a my_list -> int
hd : 'a my_list -> 'a
tl : 'a my_list -> 'a my_list
nth : 'a my_list -> int -> 'a
rev : 'a my_list -> 'a my_list
append : 'a my_list -> 'a my_list -> 'a my_list
rev_append : 'a my_list -> 'a my_list -> 'a my_list
flatten : 'a my_list my_list -> 'a my_list
iter : ('a -> 'b) -> 'a my_list -> unit
map : ('a -> 'b) -> 'a my_list -> 'b my_list
fold_left : ('a -> 'b -> 'a) -> 'a -> 'b my_list -> 'a
for_all : ('a -> bool) -> 'a my_list -> bool
exists : ('a -> bool) -> 'a my_list -> bool
mem : 'a -> 'a my_list -> bool
memq : 'a -> 'a my_list -> bool
filter : ('a -> bool) -> 'a my_list -> 'a my_list
mem_assoc : 'a -> ('a * 'b) my_list -> bool
assoc : 'a -> ('a * 'b) my_list -> 'b
split : ('a * 'b) my_list -> 'a my_list * 'b my_list
remove_assoc : 'a -> ('a * 'b) my_list -> ('a * 'b) my_list
*)
