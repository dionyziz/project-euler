fib = 1:zipWith (+) fib (1:fib)
sum $ filter even $ takeWhile (<4000000) fib
