#include<iostream>
#include<algorithm>
using namespace std  ;
bool prime(int num) {
   //  int count =  0  ;
    for(int i= 2  ; i<= num/2 ; i++){

      if ( num  % i == 0 ){
        // count ++  ;
        return false ;
      }
      
    }
    return true  ; 
}

 int gcd( int a , int b ) {
    return __gcd( a , b ) ;
 }
int main() {
    int num   ;
    cout<<"Enter number to check number is prime or not  " ;
    cin>>num  ;
    bool ans = prime(num) ;
    if (ans) {
        cout<<"Prime number \n" ;
    }
    else {
        cout<< "Not prime number\n " ;
    }

     int result = gcd( 10 ,20 ) ;
     cout<<"Gsc of two number " << result  ; 
    return  0  ;
} 