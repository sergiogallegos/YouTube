(* This is a program to solve search and sort algorithms *)

let merge_sort arr =
  let rec merge_sort' arr =
    match arr with
    | [] -> []
    | [x] -> [x]
    | _ ->
      let mid = List.length arr / 2 in
      let left = List.take arr mid in
      let right = List.drop arr mid in
      merge (merge_sort' left) (merge_sort' right)
  and merge left right =
    match left, right with
    | [], _ -> right
    | _, [] -> left
    | x :: xs, y :: ys ->
      if x <= y then x :: merge xs right
      else y :: merge left ys
  in
  merge_sort' arr

let quick_sort arr =
  let rec quick_sort' arr =
    match arr with
    | [] -> []
    | [x] -> [x]
    | _ ->
      let pivot = List.hd arr in
      let left = List.filter (fun x -> x < pivot) arr in
      let right = List.filter (fun x -> x > pivot) arr in
      merge (quick_sort' left) (quick_sort' right)
  and merge left right =
    match left, right with
    | [], _ -> right
    | _, [] -> left
    | x :: xs, y :: ys ->
      if x <= y then x :: merge xs right
      else y :: merge left ys
  in
  quick_sort' arr

let linear_search arr target =
  let rec search i =
    if i >= List.length arr then None
    else if List.nth arr i = target then Some i
    else search (i + 1)
  in
  search 0

let binary_search arr target =
  let rec search low high =
    if low > high then None
    else
      let mid = (low + high) / 2 in
      match List.nth arr mid with
      | x when x = target -> Some mid
      | x when x < target -> search (mid + 1) high
      | _ -> search low (mid - 1)
  in
  search 0 (List.length arr - 1)

let bubble_sort arr =
  let rec bubble_sort' arr =
    match arr with
    | [] -> []
    | [x] -> [x]
    | _ ->
      let rec bubble_sort'' arr =
        match arr with
        | [] -> []
        | [x] -> [x]
        | x :: y :: xs ->
          if x <= y then x :: bubble_sort'' (y :: xs)
          else y :: bubble_sort'' (x :: xs)
      in
      let sorted = bubble_sort'' arr in
      merge (bubble_sort' sorted) (bubble_sort' [])
  in
  bubble_sort' arr

let insertion_sort arr =
  let rec insertion_sort' arr =
    match arr with
    | [] -> []
    | [x] -> [x]
    | x :: xs ->
      let rec insert x arr =
        match arr with
        | [] -> [x]
        | y :: ys ->
          if x <= y then x :: y :: ys
          else y :: insert x ys
      in
      let sorted = insert x (insertion_sort' xs) in
      merge (insertion_sort' sorted) (insertion_sort' [])
  in
  insertion_sort' arr

let selection_sort arr =
  let rec selection_sort' arr =
    match arr with
    | [] -> []
    | [x] -> [x]
    | x :: xs ->
      let min = List.fold_left min x xs in
      let sorted = min :: selection_sort' (List.filter ((<>) min) xs) in
      merge (selection_sort' sorted) (selection_sort' [])
  in
  selection_sort' arr

let () =
  let arr = [5; 3; 8; 4; 2; 7; 1; 6] in
  let sorted = selection_sort arr in
  print_endline (String.concat ", " (List.map string_of_int sorted))
