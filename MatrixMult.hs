import Control.Exception
import Formatting
import Formatting.Clock
import System.Clock
import Data.List


--utilizing the function tranpose that comes with the List import 
-- this function takes in two parameters the matrix a and b and returns the product of a and b 
mmult:: Num a => [[a]] -> [[a]] -> [[a]]
mmult a _ = []
mmult _ b = []
mmult a b = [ [ sum $ zipWith (*) ar bc | bc <- (transpose b) ] | ar <- a ]


main =
  do start <- getTime Monotonic
     -- print $[[1, 2],[3, 4]] `mmult` [[-3, -8, 3], [-2,  1, 4]]
     print $ mmult [[1, 2,3,4,5],[6,7,8,9,10], [11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]] [[1, 2,3,4,5],[6,7,8,9,10], [11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
     end <- getTime Monotonic
     fprint (timeSpecs ) start end
     putStrLn $ ""