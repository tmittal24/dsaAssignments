#include <iostream>
using namespace std;

void Transpose(int mat[][3], int transpose[][3], int size) {
    
    transpose[0][0] = mat[0][1]; 
    transpose[0][1] = mat[0][0]; 
    transpose[0][2] = mat[0][2]; 

 
    for (int i = 1; i < size; i++) {
        transpose[i][0] = mat[i][1]; 
        transpose[i][1] = mat[i][0];
        transpose[i][2] = mat[i][2]; 
    }
}

void bubble(int transpose[][3],int nonzero){
    for(int i=1;i<nonzero;i++){
        for(int j=1;j<nonzero-i+1;j++){
            if(transpose[j][0]>transpose[j+1][0]){
                swap(transpose[j][0],transpose[j+1][0]);
                swap(transpose[j][1],transpose[j+1][1]);
                swap(transpose[j][2],transpose[j+1][2]);
            }
        }
    }
}

int main() {
    int rows, cols, nonZero;
    cout << "Enter rows, cols, nonZero: ";
    cin >> rows >> cols >> nonZero;

    int mat[100][3], transpose[100][3]; 

    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nonZero;

    cout << "Enter nonZero values -> (row col value): \n";
    for (int i = 1; i <= nonZero; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    cout << "\nOriginal Matrix in triplet form:\n";
    for (int j = 0; j <= nonZero; j++) {
        for (int k = 0; k < 3; k++) {
            cout << mat[j][k] << "\t";
        }
        cout << endl;
    }

   
    Transpose(mat, transpose, nonZero + 1);

    cout << "\nTranspose Matrix in triplet form:\n";
    for (int r = 0; r <= nonZero; r++) {
        for (int s = 0; s < 3; s++) {
            cout << transpose[r][s] << "\t";
        }
        cout << endl;
    }
    bubble(transpose,6);
    cout << "\nTranspose Matrix in triplet form after sorting :\n";
    for (int x = 0; x <= nonZero; x++) {
        for (int y = 0; y < 3; y++) {
            cout << transpose[x][y] << "\t";
        }
        cout << endl;
    }
    

    return 0;
}
   