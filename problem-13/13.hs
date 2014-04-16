main = do
    contents <- getContents
    putStrLn $ take 10 $ show $ sum ((map read (lines contents)) :: [Integer])
