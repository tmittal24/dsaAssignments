#include<iostream>
using namespace std;

int delDup(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            
            for (int k = i; k < size - 1; k++) {
                arr[k] = arr[k + 1];
            }
            size--; // Reduce size
            i--;    // Check current index again
        }
    }

    // Print array
    for (int j = 0; j < size; j++) {
        cout << arr[j] << " ";
    }
    cout << endl;

    return size; // return new size
}

int main() {
    int arr[8] = {1, 1, 2, 3, 4, 4, 5, 5};
    int newSize = delDup(arr, 8);
}

    


