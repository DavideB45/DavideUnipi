(*contyrollo uguaglianza*)
let same a b =
    a = b;;(*funziona con qualunque cosa*)

(*------------------------------------------------------------------------------4*)
(*calcola la lunghezza di una lista*)
let lenght list = 
    let rec aux i = function
    |[] -> i
    |_::t -> aux (i+1) t
  in aux 0 list;;


(*------------------------------------------------------------------------------5*)
(*rivolta una lista*)
let reverse list =
    let rec aux l = function
    |[] -> l
    |h::t -> aux (h::l) t
  in aux [] list;;
  

(*------------------------------------------------------------------------------6*)
(*palindrome check*)
let ispal list =

      let rec aux l = function
          |[] -> l
          |h::t -> aux (h::l) t
      in  
      let rev = aux [] list
      in
      rev = list;;
      
      
(*------------------------------------------------------------------------------7*)
(*Flatten a nested list structure*)
(*need to rest*)


(*------------------------------------------------------------------------------8*)
(*Eliminate consecutive duplicates of list elements*)
let rec compress = function
    |[]->[]
    |[t]->[t]
    |h::m::t ->
        if h = m
            then compress (m::t)
            else h::compress (m::t);;
            (*lo ho fatto al primo tentativo*)
            (*ora mi si e' ribaltato lo schermo*)
            (*sono le 7:10 cercare un collegamento*)
            
            
(*------------------------------------------------------------------------------9*)
(*Pack consecutive duplicates of list elements into sublists*)


    let rec bros list =
    match list with
        |[] -> []
        |[a] -> [a]
        |h::m::t -> 
        if h = m 
            then h::bros (m::t) 
            else [h]

    let rec rembros = function
        |[] -> []
        |[a] -> [a]
        |h::m::t ->
            if h = m
            then rembros (m::t)
            else m::t
let group list =         
    let rec aux m = function
        |[] -> m
        |[a] -> [a]::m
        |a::b::tail -> 
            if a = b  
                then aux ((bros (a::b::tail))::m) (rembros (b::tail))
                else aux ([a]::m) (rembros (b::tail))          
        in aux [] list;;
        (*funziona quasi toglie le cose diverse*)
        (*forse ora va*)
            
(*------------------------------------------------------------------------------prova funzionale*)
let rec c = function
    (*t = a::_*)
  	a::(b:: _ as t) -> 
  	    if a = b 
  	        then c t 
  	        else a::c t
    |s -> s;;

c [1;2;2;1;3];;
1;2;1;3; 
            
let a list =
    match list with
  	a::(b::_ as t) -> t;;      
            
(*------------------------------------------------------------------------------reozione copie*)
let copyremove  list =
    let rec singleremove n = function
        |[] -> []
        |h::t -> 
            if h = n
                then singleremove n t
                else h::singleremove n t
     in
     let rec auxremove = function
        |[]->[]
        |h::t -> h::auxremove (singleremove h t)
     in
     auxremove list;;
            
(*------------------------------------------------------------------------------26*)  
(*Generate the combinations of K distinct objects chosen from the N elements of a list.*)
let mat l =
    let rec g k n=
        match k with 
        [] -> []
        |h::t -> [n;h]::g t n
    in
    let rec f = function
        []-> []
        |h::t-> (g t h) :: f t
    in f l;;
     
(*------------------------------------------------------------------------------35*)
(*Determine the prime factors of a given positive integer*)
let factorino a =
    let rec aux n lixt divisor=
        if n = 1
        then lixt 
        else if not(n mod divisor <> 0)
            then aux (n/divisor) (divisor::lixt) divisor
            else aux n lixt (divisor+1)
     in aux a [] 2;;


(*------------------------------------------------------------------------------prove dal passato*)
(*verificare che fa/dire il tipo*)
 let rec filter test l =
    match l with
     [] -> []
     | h::t -> if (test h) then h::(filter test t)
            else filter test t;;            
            

(*------------------------------------------------------------------------------*)
(*what does it do?*)            
let p l =
    let rec aux curr acc = function
    |[]->[]
    |[x]->(x::curr)::acc
    |a::(b::_ as t)->
        if a = b
            then aux (a::curr) acc t
            else aux [] ((a::curr)::acc) t in
    aux [] [] l;;          
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
