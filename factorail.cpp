#include<iostream>
using namespace std ;
 int factorail(int  n ) {
     // base  case 
     if ( n == 1  ) {
        return 1 ;
     }
     // factorail recurion funtion 
     return n* factorail(n-1) ;
 }


int main() {
    int n ;
    cout<< "Enter number to find the factorail " ;
    cin>> n  ;
    int result = factorail(n ) ;
    cout<< "Factorail = "  << result ;
    return  0  ;
}