#include <iostream>
using namespace std;

int main() {
    int arr[6] = {4, 6, 2, 8, 2, 0};
    int n = 6; 

    for (int i = 0; i < n - 1; i++) { 
        if (arr[i] == 2) {
            
            for (int j = n - 2; j > i; j--) {
                arr[j + 1] = arr[j];
            }
            arr[i + 1] = 2; 
            i++;            
        }
    }

    
    for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
    return 0;
}