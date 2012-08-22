<?php
    mysql_connect( 'localhost', 'dionyziz', 'password' ) or die( 'Connection failure' );
    mysql_select_db( 'dionyziz_euler' ) or die( 'Invalid database' );

    define( 'N', 64000000 );
    define( 'K', 1000 );

    $base = 'INSERT INTO problem_211 ( n, sigma ) VALUES ';

    for ( $i = 0; $i < N; $i += K ) {
        $sql = array();
        for ( $j = 0; $j < K; ++$j ) {
            $sql[] = '( ' . ( $i + $j ) . ', 0 )';
        }
        mysql_query( $base . implode( ', ', $sql ) ) or die( mysql_error() );
    }
?>
