#include<iostream>
using namespace std  ;
int linearSearch( int *arr ,int  num , int size  , int count=0   ) {
  if (  size == count) return false  ;
  if ( arr[count] == num) return true ;
   linearSearch( arr ,num , size , count+1 ) ;

}

int main() {
    int arr[]  =  {10 ,1,23,5,6,9,6,10} ;
    int size  = sizeof(arr) / sizeof(arr[0]) ;
    int num  ;
    cout<<"Enter number to be searched " ;
    cin>> num ;
    bool ans = linearSearch( arr , num , size , 0  ) ;
    
    if(!ans) {
        cout<<"Not fount " ;
    }else {
        cout<<"Found " ;
    }
    return  0 ;
}