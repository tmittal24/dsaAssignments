#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int arr[] = {1, 2, 5, 3, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    cout << "Number of inversions: " << count << endl;
    return 0;
}