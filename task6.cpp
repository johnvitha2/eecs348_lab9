/*
* EECS 348 Lab 9 Task 2
* Matrix Operations
* Swap matrix columns and display the result
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
#include <algorithm>
#include <cctype>
using namespace std;

void col_swap(int col1_index, int col2_index, vector<vector<int>>& matrix){
    for (size_t i = 0; i < matrix.size(); i++){
        swap(matrix[i][col1_index], matrix[i][col2_index]);
    }
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
    int col1_index;
    int col2_index;
    char user_matrix;
    cout << "Enter a file: ";
    cin >> filename;

    ifstream file(filename);

    if(!file){
        cout << "Error: File could not be opened." << endl;
        return 1;
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

    while(1){
        cout << "Enter the first column-index: ";
        cin >> col1_index;
        if(col1_index < 0 or col1_index >= n ){
            cout << "Invalid column-index. Please try again.";
        } else {
            break;
        }
    }
    while(1){
        cout << "Enter the second column-index: ";
        cin >> col2_index;
        if(col2_index < 0 or col2_index >= n ){
            cout << "Invalid column-index. Please try again.";
        } else {
            break;
        }
    }

    while(1){
        cout << "Which matrix would you like to perform the operation on? Enter A or B: ";
        cin >> user_matrix;
        if(toupper(user_matrix) == 'A'){
            col_swap(col1_index, col2_index, matrix_a);
            print_matrix(matrix_a);
            exit(1);
        } else if (toupper(user_matrix) == 'B'){
            col_swap(col1_index, col2_index, matrix_b);
            print_matrix(matrix_b);
            exit(1);
        } else {
            cout << "Invalid matrix selection. Please try again.";
        }
    }

    return 0;
}