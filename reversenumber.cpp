#include<iostream>
using namespace std  ;

int reverse( int &num ) {
    int sum = 0  ;
    int  m , r  ;
    m = num ; 
    while (  m !=  0  ) {
        r = m%10  ;
        sum  = (10*sum  ) + r ;
        m = m/ 10  ;

    }
     return sum  ;
}
int main() {
    int num  ;
    cout<<"Enter number to reverse " ;
    cin>> num  ;
       int ans  = reverse( num ) ;
       cout<<"reverse  number is " << ans  ;
       return 0  ;
}