//SORT ARRAY USNING  SORT FUNTION 
#include<bits/stdc++.h>
using namespace std ;

void aarray_sort (vector<int> &arr  ) {
    sort(arr.begin() , arr.end() , greater<int>()) ; 
   for(int i : arr ) {
    cout << i << " " ;
   }
}
int main() {
    vector <int>arr   = { 1,2,3,5,7,8,9,6,10 } ;
    
    aarray_sort(arr) ;
    return 0 ;
}
