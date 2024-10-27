#include<iostream>
using namespace std ;
 int factoril (int n   ) ; // prototype 
int  factoril1( int m ) {
     return m * factoril(m-1) ;
   }
 int factoril( int n  ) {
    if ( n == 1  ) {
        return 1 ;
    }
     factoril1( n ) ;
 }

int main() {
    int n  =    5  ;
    int result = factoril( n ) ;
    cout<< result  ;
    return 0  ;
}
