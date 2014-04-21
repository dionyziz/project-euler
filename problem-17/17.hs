say :: Int -> String

say n
    | n <= 13 =
      ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
           "eleven", "twelve", "thirteen"]!!n
    | n == 15 = "fifteen"
    | n == 18 = "eighteen"
    | n < 20 = say (n - 10) ++ "teen"
    | n < 100 && n `mod` 10 == 0 =
      ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
      !!((n `div` 10) - 2)
    | n < 100 = say (n - (n `mod` 10)) ++ "-" ++ say (n `mod` 10)
    | n == 1000 = "one thousand"
    | otherwise = say (n `div` 100) ++ " hundred" ++ (if null tens then "" else " and " ++ tens)
      where tens = say (n `mod` 100)

numlen = length . filter (`elem` ['a'..'z']) . say

sum $ map numlen [1..1000]
