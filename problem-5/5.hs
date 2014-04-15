head $ foldr (\x -> filter (\y -> y `mod` x == 0)) [1..] [1..20]
