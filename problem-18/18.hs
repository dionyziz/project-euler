next :: [Int] -> [Int] -> [Int]
next dp line = (head dp1):(zipWith max (tail dp1) (init dp2)) ++ [last dp2]
        where dp1 = zipWith (+) dp line
              dp2 = zipWith (+) dp (tail line)

main = do
    contents <- getContents
    let input = (map (map read) $ map words $ lines contents) :: [[Int]]
        dp = foldl1 next input
    print $ maximum dp
