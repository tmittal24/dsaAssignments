#include <iostream>
using namespace std;

int countDistinctElements(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        // Check if arr[i] was already seen before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            count++;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total distinct elements: " << countDistinctElements(arr, n) << endl;

    return 0;
}