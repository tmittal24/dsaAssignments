#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], result[10][10];
    int rowA, colA, rowB, colB;

    // Input dimensions for Matrix A
    cout << "Enter rows and columns for Matrix A: ";
    cin >> rowA >> colA;

    // Input dimensions for Matrix B
    cout << "Enter rows and columns for Matrix B: ";
    cin >> rowB >> colB;

    // Check if multiplication is possible
    if (colA != rowB) {
        cout << "Matrix multiplication not possible! (Columns of A must equal rows of B)\n";
        return 0;
    }

    // Input elements for Matrix A
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // Input elements for Matrix B
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    // Initialize result matrix to 0
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display result
    cout << "Resultant Matrix (A x B):\n";
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}