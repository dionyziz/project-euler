<?php
    function combos( $digits, $choose ) {
        if ( $choose == 1 ) {
            return range( 0, $digits - 1 );
        }

        $ret = array();
        for ( $i = $digits; $i >= $choose; ++$i ) {
            $innercombos = combos( $i, $choose - 1 );
            foreach ( $innercombos as $combo ) {
                $ret[] = array_merge( array( $i ), $combo );
            }
        }
        return $ret;
    }
    var_dump( combos( 2, 2 ) );
    die(); 

    function replace( $prime, $numberofdigits ) {

    }

    $primes = array( 2 => true );
    for ( $p = 3; $p < 100000; $p += 2 ) {
        $isprime = true;
        $sqrt = sqrt( $p );
        foreach ( $primes as $q => $dummy ) {
            if ( $q > $sqrt ) {
                break;
            }
            if ( $p % $q == 0 ) {
                $isprime = false;
                break;
            }
        }
        if ( $isprime ) {
            $primes[ $p ] = true;
            echo "$p\n";
        }
    }
?>
