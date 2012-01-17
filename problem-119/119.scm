(define (itoa i)
        (if (= i 0)
            (list)
            (cons (itoa (/ i 10) (modulo i 10))))
