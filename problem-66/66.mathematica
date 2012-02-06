For [
    d = 2;
    maxx = 0;
    bestd = 0,
    d <= 1000,
    d++,
    If[
        IntegerQ[ Sqrt[ d ] ],
        Print[ d, ": No solutions" ],
        For[
            t = 1;
            x = 0;
            y = 0,
            x^2 - d*y^2 != 1,
            t++,
            c = Convergents[ Sqrt[ d ], t ][[ t ]];
            x = Numerator[ c ];
            y = Denominator[ c ]
        ];
        If[
            x > maxx,
            maxx = x;
            bestd = d
        ]
    ]
]
Print[ bestd ]
