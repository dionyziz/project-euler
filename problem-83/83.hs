import Data.Maybe
import Data.List
import Data.List.Split
import qualified Data.Map as Map

type Coords = (Int, Int)
type Graph = Map.Map Coords Int

parse :: String -> (Coords, Graph)
parse contents = 
    let raw :: [[Int]]
        raw = transpose $ map (map read . splitOn ",") $ lines contents
        width = length raw
        height = length $ head raw
        graphX :: [(Int, [Int])]
        graphX = zip [0..] raw
        graphXY :: [((Int, Int), Int)]
        graphXY = concat $ map (\(x, vals) -> zip [(x, y)|y <- [0..]] vals) $ graphX
    in  ((width, height), Map.fromList graphXY)

neighbours :: Coords -> [Coords]
neighbours (x, y) = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]

bounded :: Coords -> Coords -> Bool
bounded size@(width, height) coords@(x, y) =
    and [x >= 0, y >= 0, x < width, y < height]

expandFrontier :: Coords -> Graph -> Graph -> Graph
expandFrontier size@(width, height) dp graph =
    let expandEdge :: Coords -> Int -> Int
        expandEdge coords@(x, y) val =
            let previousDistance :: Int
                previousDistance = fromJust $ Map.lookup coords dp
                allPaths :: [Int]
                allPaths = previousDistance:(map (val+) $ map (fromJust . ((flip Map.lookup) dp)) $ filter (bounded size) (neighbours coords))
            in  minimum allPaths
    in  Map.mapWithKey expandEdge graph

main = do
    contents <- getContents
    let ((width, height), graph) = parse contents
        infinity = 9999999
        topLeft = fromJust $ Map.lookup (0, 0) graph
        infiniteDistances :: Graph
        infiniteDistances = Map.fromList [((x, y), infinity) | x <- [0..width - 1], y <- [0..height - 1]]
        initDistances :: Graph
        initDistances = Map.insert (0, 0) topLeft infiniteDistances
        distances :: Graph
        distances = foldl (expandFrontier (width, height)) initDistances $ replicate (width * height) graph
    print $ fromJust $ Map.lookup (width - 1, height - 1) distances
