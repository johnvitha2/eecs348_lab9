/*
* EECS 348 Lab 9 
* Matrix Operations
* Collaborators: None
* Sources: None
* Author: John Vitha
* KU ID: 3158626
* Creation date: 10/24/2025
*/

/*
1. Read values from a file into the matrix:
Implement a function to load matrix data from a user-specified file (you can use fstream/ifstream). The first line of the file should contain an integer N indicating the size of the matrices, followed by two N × N matrices. After reading the file, print the matrices with proper formatting, such as aligned columns. Note that N can be any valid positive integer.

2. Add two matrices and display the result:
Implement a function that adds two matrices (you can use vector, i.e., the dynamic array, to store the matrix) and displays the resulting matrix.

3. Multiply two matrices and display the result:
Implement a function that multiplies two matrices and displays the resulting matrix.

Please refer to the link for the matrix multiplication: https://www.mathsisfun.com/algebra/matrix-multiplying.html

4. Get the sum of matrix diagonal elements:
Implement a function to calculate and display the sum of the main and secondary diagonal elements of a matrix.

5. Swap matrix rows and display the result:
Implement a function that takes a matrix and two-row indices as input (with indexing starting at 0). If both indices are within valid bounds, swap the specified rows and output the resulting matrix.

6. Swap matrix columns and display the result:
Implement a function that takes a matrix and two-column indices as input (with indexing starting at 0). If both indices are within valid bounds, swap the specified rows and output the resulting matrix.

7. Update matrix rows and display the result:
Implement a func
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int matrix_sum(int n, vector<vector<int>> matrix_a, vector<vector<int>> matrix_b){
    vector<vector<int>> sum_matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j <n; j++){
            sum_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
    return sum_matrix;
}

int matrix_product(int n, vector<vector<int>> matrix_a, vector<vector<int>> matrix_b){
    vector<vector<int>> product_matrix(n, vector<int>(n));
    for (int i 0; i < n; i++){
        for (int j = 0; i < n; j++){ // nested loop to get index of element in product matrix
            // another nested loop to get row*col
            for (int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    row
                }
            }
        }
    }
}

int main(){
    string filename;
    cout << "Enter a file: ";
    cin >> filename;

    ifstream file(filename);

    if(!file){
        cout << "Error: File could not be opened." << endl;
        return 1;
    }

    string line;
    getline(file, line);
    int n = stoi(line);
    vector<vector<int>> matrix_a(n, vector<int>(n));
    vector<vector<int>> matrix_b(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        getline(file, line);
        istringstream iss(line);
        for (int j = 0; j < n; j++){
            iss >> matrix_a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        getline(file, line);
        istringstream iss(line);
        for(int j = 0; j < n; j++){
            iss >> matrix_b[i][j];
        }
    }

    file.close();
    return 0;
}
