let fac = 1:zipWith (*) fac [1..]
sum ((map read $ map (:[]) $ show (fac!!100)) :: [Int])
