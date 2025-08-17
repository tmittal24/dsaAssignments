#include <iostream>
using namespace std;

int main() {
    int matrix[10][10], transpose[10][10];
    int rows, cols;

    // Input matrix size
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    // Input elements of the matrix
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    // Display original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Find transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Display transpose matrix
    cout << "\nTranspose of the Matrix:\n";
    for (int i = 0; i < cols; i++) {      // Note: rows and cols are switched
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}