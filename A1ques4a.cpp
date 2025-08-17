#include<iostream>
using namespace std;
 void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
 void reversearr(int arr[],int size){
   
    for(int i=0;i<size/2;i++){
          int start=i;
    int end=size-1-i;
    swap(arr[start],arr[end]);


    }
    
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    int brr[5]={1,2,3,4,5};
    reversearr(brr,5);
    printarr(brr,5);
    
}