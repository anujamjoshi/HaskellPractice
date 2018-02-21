import Data.List
isPalindrome x = x == reverse x
mmult a b = [ [ sum $ zipWith (*) ar bc | bc <- (transpose b) ] | ar <- a ]
main = do
          print $ isPalindrome  "abcd"
          let test = [[1, 2],[3, 4]] `mmult` [[-3, -8, 3], [-2,  1, 4]]
          print $ test 