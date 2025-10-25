/*
* EECS 348 Lab 9 Task 2
* Matrix Operations
* Get the sum of matrix diagonal elements
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

int diagonal_sum(const vector<vector<int>>& matrix){
    int sum = 0;
    int column_index = 0;
    for (size_t i = 0; i < matrix.size(); i++){
        sum += matrix[i][column_index];
        column_index += 1;
    }
    column_index = matrix.size()-1;
    for (size_t i = 0; i < matrix.size(); i++){
        sum += matrix[i][column_index];
        column_index -= 1;

    }
    return sum;
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
    char user_matrix;
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

    while(1){
        cout << "Which matrix would you like to perform the operation on? Enter A or B: ";
        cin >> user_matrix;
        if(toupper(user_matrix) == 'A'){
            cout << "Diagonal sum: " << diagonal_sum(matrix_a);
            break;
        } else if (toupper(user_matrix) == 'B'){
            cout << "Diagonal sum: " << diagonal_sum(matrix_b);
            break;
        } else {
            cout << "Invalid matrix selection. Please try again.";
        }
    }

    return 0;
}