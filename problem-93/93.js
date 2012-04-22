var permuter = require( './next-permutation.js' ).permutationGenerator;
var parens = [
    '(_ _) (_ _)', '((_ _) _) _', '(_ (_ _)) _', '_ ((_ _) _)', '_ (_ (_ _))'
];
var operators = [ '+', '-', '*', '/' ];
var maxn = 0;

for ( var a = 0; a < 7; ++a ) {
    for ( var b = a + 1; b < 8; ++b ) {
        for ( var c = b + 1; c < 9; ++c ) {
            for ( var d = c + 1; d < 10; ++d ) {
                var reachable = [];

                for ( var opcode = 0; opcode < 4 * 4 * 4; ++opcode ) {
                    var o = opcode;
                    var op1 = o % 4;
                    o -= o % 4;
                    o /= 4;
                    var op2 = o % 4;
                    o -= o % 4;
                    o /= 4;
                    var op3 = o;

                    for ( var i = 0; i < parens.length; ++i ) {
                        seq = [ a, b, c, d ];

                        do {
                            var exp = parens[ i ]
                                    .replace( ' ', operators[ op1 ] )
                                    .replace( ' ', operators[ op2 ] )
                                    .replace( ' ', operators[ op3 ] )
                                    .replace( '_', seq[ 0 ] ).replace( '_', seq[ 1 ] )
                                    .replace( '_', seq[ 2 ] ).replace( '_', seq[ 3 ] )
                            var val = eval( exp );
                            // console.log( exp );
                            if ( Math.floor( val ) == val && val >= 1 ) {
                                if ( typeof reachable[ val ] == 'undefined' ) {
                                    reachable[ val ] = true;
                                }
                            }
                        } while ( ( seq = permuter.getNextSequence( seq ) ) != null );
                    }
                }
                for ( var i = 1; ; ++i ) {
                    if ( typeof reachable[ i ] == 'undefined' ) {
                        if ( i - 1 > maxn ) {
                            console.log( '' + a + b + c + d + ' yields maximum of ' + ( i - 1 ) );
                            maxn = i - 1;
                        }
                        break;
                    }
                }
            }
        }
    }
}
