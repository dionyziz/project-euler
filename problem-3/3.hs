factors :: Int -> [Int]

factors 1 = [1]
factors x =
    let factor = head $ filter ((== 0) . (mod x)) [2..]
    in factor:factors (x `div` factor)

maximum $ factors 600851475143
