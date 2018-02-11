factorial x = product [1..x] 
-- uses product which is a built in function of haskell to get the factorial 
-- takes the list of numbers 1 - x and takes the product of all of them 

 
fact x = if x < 1 then 1 else fact (x-1)*x
-- split the if and else into two statements 
f 0=1 
f x = x*f(x-1)  
 -- use higher order function 
factor x = foldl(*) 1 [1..x] 
-- takes the function foldl and performs the operation set in the parenthesis from the number defined after for all numbers within the list defined  

