#include <iostream>
using namespace std;

int main(){
    int arr[] = {2,4,3,7,5,8,5};
    int x = sizeof(arr)/sizeof(int);
    int count = 0;

    for (int i = 0;i<x-1;i++){
        for (int j =i+1;j<x;j++){
            if (arr[i]-arr[j]==2 || arr[j]-arr[i]==2){
                count++;

            }
        }

    }
    cout<<count<<endl;

}