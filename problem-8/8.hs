main = do
    contents <- getContents
    let numbers = map read $ concat $ map (map (:[])) (lines contents) :: [Int]
    print $ maximum $ map (product . take 5) $ scanr (:) [] numbers
