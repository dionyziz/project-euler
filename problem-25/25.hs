let fib = 1:1:zipWith (+) (tail fib) fib
1 + length (takeWhile ((<1000) . length . show) fib)
