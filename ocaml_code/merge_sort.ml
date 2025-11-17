let rec merge left right =
  match (left, right) with
  | [], r -> r
  | l, [] -> l
  | x :: xs, y :: ys ->
      if x <= y then x :: merge xs right
      else y :: merge left ys

let rec merge_sort = function
  | [] -> []
  | [x] -> [x]
  | lst ->
      let rec split l acc1 acc2 =
        match l with
        | [] -> (acc1, acc2)
        | x :: xs -> split xs acc2 (x :: acc1)
      in
      let left, right = split lst [] [] in
      merge (merge_sort left) (merge_sort right)

(* Run example *)
let () =
  let data = [38; 27; 43; 3; 9; 82; 10] in
  let sorted = merge_sort data in
  List.iter (fun x -> Printf.printf "%d " x) sorted;
  print_newline ()
