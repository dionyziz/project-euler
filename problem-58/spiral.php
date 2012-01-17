<?php
    global $primes;

    $primes = array(
        2 => true, 3 => true
    );

    function is_prime( $p ) {
        static $maxp = 3;
        global $primes;

        $sqr = sqrt( $maxp );
        while ( $maxp < $p ) {
            $res = false;
            $maxp += 2;
            $prime = true;
            $sqr += 2;
            foreach ( $primes as $prime => $_ ) {
                if ( $prime > $sqr ) {
                    break;
                }
                if ( $maxp % $prime == 0 ) {
                    $prime = false;
                    break;
                }
            }
            if ( $prime ) {
                $primes[ $maxp ] = true;
            }
        }
        return isset( $primes[ $p ] );
    }

/*
    var_dump( is_prime( 3 ) );
    var_dump( is_prime( 5 ) );
    var_dump( is_prime( 7 ) );
    var_dump( is_prime( 13 ) );
    var_dump( is_prime( 100 ) );
    var_dump( is_prime( 103 ) );
    exit;
*/

    function solve() {
        $current = 1;
        $side = 2;
        $percentage = 100;
        $primes = 3;
        $total = 5;
        do {
            $side += 2;
            for ( $q = 0; $q < 4; ++$q ) {
                $current += $side;
                if ( is_prime( $current ) ) {
                    ++$primes;
                }
                ++$total;
            }
            echo "\rCalculating... Ratio at " . 100 * ( $primes / $total ) . "%";
            if ( $total > 10 * $primes ) {
                echo "\nSide " . ( $side + 1 ) . " has $primes primes and $total in total.\n";
                echo "Its ratio is " . 100 * ( $primes / $total ) . "%.\n";
                exit;
            }
        } while ( true );
    }

    solve();
?>
