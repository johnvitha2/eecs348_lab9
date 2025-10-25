/*
* EECS 348 Lab 9 Task 2
* Matrix Operations
* Multiply two matrices and display the result
* Read values from a file into the matrix
* Collaborators: None
* Sources: None
* Author: John Vitha
* KU ID: 3158626
* Creation date: 10/24/2025
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> matrix_product(const vector<vector<int>>& matrix_a, const vector<vector<int>>& matrix_b){
    size_t n = matrix_a.size();
    vector<vector<int>> product_matrix(n, vector<int>(n));
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){ 
            product_matrix[i][j] = 0;
            for (size_t k = 0; k < n; k++){
                product_matrix[i][j] += matrix_a[i][k]*matrix_b[k][j];
            }
        }
    }
    return product_matrix;
}

void print_matrix(const vector<vector<int>>& matrix){
    for (size_t i = 0; i < matrix.size(); i++){
        for (size_t j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    string filename;
    ifstream file;
    while(1){
        cout << "Enter a file: ";
        cin >> filename;
        file.open(filename);
        if(file) break;
        cout << "Invalid file. Please try again." << endl;
    }

    string line;
    int n;
    file >> n;
    while (getline(file, line)) {
        if (!line.empty()) {
            break;
        }  
    }

    vector<vector<int>> matrix_a(n, vector<int>(n));
    vector<vector<int>> matrix_b(n, vector<int>(n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            file >> matrix_a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            file >> matrix_b[i][j];
        }
    }

    file.close();

    cout << "Product of the two matrices: " << endl;
    print_matrix(matrix_product(matrix_a, matrix_b));

    return 0;
}
