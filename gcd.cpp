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

// ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️
// second approach 
// #include <iostream>
// #include <numeric> // Required for std::gcd

// int main() {
//     int num1, num2;
//     std::cout << "Enter two numbers: ";
//     std::cin >> num1 >> num2;
    
//     // Using std::gcd to find the GCD of num1 and num2
//     std::cout << "GCD of " << num1 << " and " << num2 << " is " << std::gcd(num1, num2) << std::endl;
//     return 0;
// }
