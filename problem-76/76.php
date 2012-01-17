<?php
    define( 'MAX_N', 200 );

    $d = array();

    for ( $N = 1; $N <= MAX_N; ++$N ) {
        $d[ $N ] = array();
        for ( $K = 1; $K <= $N; ++$K ) {
            if ( $K > floor( $N / 2 ) ) {
                $d[ $N ][ $K ] = 0;
            }
            else {
                $d[ $N ][ $K ] = ( string )( floor( $N / 2 ) - $K + 1 );
                for ( $i = $K; $i <= floor( $N / 2 ); ++$i ) {
                    $d[ $N ][ $K ] = bcadd( $d[ $N ][ $K ], $d[ $N - $i ][ $i ] );
                }
            }
        }
    }

    echo $d[ MAX_N ][ 1 ] . "\n";
?>
