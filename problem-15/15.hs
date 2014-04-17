nextRow :: [Integer] -> [Integer]
nextRow = reverse . foldl (\acc@(a:as) x -> (a + x):acc) [1] . tail

countRow :: Int -> [Integer] -> [Integer]
countRow n dp = (iterate nextRow dp)!!(n - 1)

routes :: Int -> Integer
routes n = last $ countRow n $ take n $ repeat 1

routes 21
