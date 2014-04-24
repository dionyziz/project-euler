import Data.List.Split

foldRow :: [Int] -> [Int] -> [Int]
foldRow (d:ds) (e:es) = reverse $ foldl foldCol [e + d] $ zip ds es

foldCol :: [Int] -> (Int, Int) -> [Int]
foldCol (a:as) (dp, elem) = (min a dp) + elem:a:as

main = do
    contents <- getContents
    let input = map (map read . splitOn ",") $ lines contents :: [[Int]]
    print $ last $ foldl foldRow (scanl1 (+) $ head input) $ tail input
