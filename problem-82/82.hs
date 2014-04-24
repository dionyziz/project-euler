import Data.List
import Data.List.Split

foldCol :: [Int] -> [Int] -> [Int]
foldCol dp col = reverse $ foldl walk [] $ zip col [0..]
    where walk :: [Int] -> (Int, Int) -> [Int]
          walk acc target@(end, i) =
              let path :: (Int, Int) -> Int
                  path (start, j) = start + (sum $ subarray i j col)
              in  (minimum $ map path $ zip dp [0..]):acc

subarray :: Int -> Int -> [Int] -> [Int]
subarray i j l
  | i <= j = take (1 + j - i) $ drop i l
  | j < i  = subarray j i l

main = do
    contents <- getContents
    let input = map (map read . splitOn ",") $ lines contents :: [[Int]]
    print $ minimum $ foldl1 foldCol $ transpose input
