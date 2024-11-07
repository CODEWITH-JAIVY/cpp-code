#include<iostream>
#include<algorithm>
using namespace std  ;
bool prime(int num) {
   //  int count =  0  ;
    for(int i= 2  ; i<= num/2 ; i++){
 // for( int i = 1  ; i< num  ; i++ ) {  // alsp this for loop is valid  for this funtion 
       
      if ( num  % i == 0 ) 
        return false ;
      }
    }
    return true  ; 
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
    return  0  ;
} 
