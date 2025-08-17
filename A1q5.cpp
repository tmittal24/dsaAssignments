#include <iostream>
using namespace std;

int main() {
    int matrix[10][10];
    int rows, cols;

    // Input dimensions
    cout << "Enter number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    // Input matrix elements
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    // Display the matrix
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Calculate and display row sums
    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i << " sum = " << rowSum << endl;
    }

    // Calculate and display column sums
    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << j << " sum = " << colSum << endl;
    }

    return 0;
}