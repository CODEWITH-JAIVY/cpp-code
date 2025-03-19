/*Sort an Array
Implement Bubble Sort or Insertion Sort to sort an array.
Example:
Input: [5, 2, 9, 1] → Output: [1, 2, 5, 9]*/
#include<iostream>
#include<algorithm>
using namespace std  ;

// using bubble sort 
int sortAray (int *arr , int size  ) {
   for ( int i  =0  ; i< size-1  ; i++ ) {
    for(int j  = i+1 ; j < size  ; j++) {
        if(arr[j] < arr[i]) {
            swap(arr[i] , arr[j]) ;
        }

    }
   }
}
int main  () {
    int arr[] = { 3,2,1,6,5,4} ;
    int size  = sizeof(arr) / sizeof(arr[0]) ;
    sortAray(arr , size ) ;
    for(int i  =0  ; i< size ; i++ ) {
        cout<< arr[i] << " " ;
    }
    cout<< endl  ;
     return  0  ;  
}