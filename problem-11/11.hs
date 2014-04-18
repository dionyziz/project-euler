import Data.List

main = do
    contents <- getContents
    let nums = map (map read) $ map words $ lines contents :: [[Int]]
        fours = concat . map (map $ take 4) . map (scanr (:) [])
        horizontal = fours nums
        vertical = fours $ transpose nums
        lines = scanr (:) [] nums
        findDiagonals = transpose . zipWith (\n xs -> (iterate tail xs)!!n) [0..]
        diagonalFours = map (take 4) . concat . map findDiagonals
        diagonalM = diagonalFours $ lines
        diagonalm = diagonalFours $ map (map reverse) lines

    print $ maximum $ map product $ concat [horizontal, vertical, diagonalM, diagonalm]
