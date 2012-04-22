u[ n_ ] := Sum[ ( -1 )^i * n^i, { i, 0, 10 } ]
l = {};
s = 0;
Do[
    l = Append[ l, u[ i ] ];
    s = s + InterpolatingPolynomial[ l, x ] /. x -> ( i + 1 ),
    { i, 10 }
];
Print[ s ]
