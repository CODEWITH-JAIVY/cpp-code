#include<iostream>
using namespace std ;

 int factoril( int m  ) {
    if ( n == 1  ) {
        return 1 ;
    }
     return m * factoril(m-1) ;
 }

int main() {
    int n  =    5  ;
    int result = factoril( n ) ;
    cout<< result  ;
    return 0  ;
}
