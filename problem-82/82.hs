import Data.List
import Data.List.Split

foldCol :: [Int] -> [Int] -> [Int]
foldCol dp col = reverse $ foldl (walk dp col) [] $ zip col [0..]

walk :: [Int] -> [Int] -> [Int] -> (Int, Int) -> [Int]
walk dp col acc target@(end, i) = (minimum $ map (path col target) $ zip dp [0..]):acc

path :: [Int] -> (Int, Int) -> (Int, Int) -> Int
path col (end, i) (start, j) = start + (sum $ subarray i j col)

subarray :: Int -> Int -> [Int] -> [Int]
subarray i j l
    | i <= j = take (1 + j - i) $ drop i l
    | j < i  = subarray j i l

main = do
    contents <- getContents
    let input = map (map read . splitOn ",") $ lines contents :: [[Int]]
    print $ minimum $ foldl1 foldCol $ transpose input
