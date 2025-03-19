/*Palindrome Number
Check if a given number is a palindrome (reads the same forward and backward).
Example:
Input: 121 → Output: "Palindrome"*/

#include<iostream>
using namespace std ;

bool Ispalindrom( int num ) {
 int sum =0  ;
 int rem  ;
 int tem = num  ;
 while ( num > 0 ) {
    rem  = num %10  ;
    sum  = sum *10 +rem   ;
    num = num / 10  ;
 }
 if ( sum == tem ) {
    return true ;  
 }else {
    return false  ; 
 }

}
int main () {
    int num  ;
    cout<<"Enter number to cheack number is palindrom or not  " ;
    cin >> num  ;
    bool result = Ispalindrom(num) ;
    cout<< result  ; 
    if(result) {
        cout<<"Number is palindrom" ;
    }else{
        cout<< "Number is not palindrom " ;
    }
    return  0  ;  
}