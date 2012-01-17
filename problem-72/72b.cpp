#include <cstdio>
#include <map>

using namespace std;

typedef pair< int, int > interval
map< interval, int >, int > memo;

int count( interval range ) {
    int t;
    map< interval, int >::iterator it;

    if ( range.second < range.first ) {
        t = range.second;
        range.second = range.first;
        range.first = t;
    }
    it = memo.find( range );
    if ( it == memo.end() ) {
    }
}

int main() {
    return 0;
}
