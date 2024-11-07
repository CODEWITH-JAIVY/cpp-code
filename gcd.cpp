#include<iostream> 
#include<algorithm>
using namespace  std  ;
 int solutionGCd ( int a , int b ) {
    return __gcd ( a ,b ) ;
 }

int main() {
    int a  , b  ;
    cout<<"Enter two number to find the numebr of gcd " ;
    cin>> a >> b  ; 
     int ans = solutionGCd ( a , b ) ;
     cout<<"GCd of two numerb is " << ans ;

     return  0  ;
}