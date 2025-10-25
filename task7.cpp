/*
* EECS 348 Lab 9 Task 2
* Matrix Operations
* Update matrix rows and display the result
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

void update_matrix(int row_index, int col_index, int new_value, vector<vector<int>>& matrix){
    matrix[row_index][col_index] = new_value;
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
    int row_index;
    int col_index;
    int new_value;
    char user_matrix;
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

    while(1){
        cout << "Enter a row-index: ";
        if (!(cin >> row_index)){
            cout << "Invalid row-index. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        } 
        if(row_index < 0 or row_index >= n ){
            cout << "Invalid row-index. Please enter an index within the matrix bounds." << endl;
        } else {
            break;
        }
    }

    while(1){
        cout << "Enter a column-index: ";
        if (!(cin >> col_index)){
            cout << "Invalid column-index. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if(col_index < 0 or col_index >= n ){
            cout << "Invalid column-index. Please enter an index within the matrix bounds." << endl;
        } else {
            break;
        }
    }

    while(1){
        cout << "Enter a new value: ";
        if(cin >> new_value){
            break;
        } else {
            cout << "Invalid new value. Please enter an number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    while(1){
        cout << "Which matrix would you like to update? Enter A or B: ";
        cin >> user_matrix;
        if(toupper(user_matrix) == 'A'){
            update_matrix(row_index, col_index, new_value, matrix_a);
            print_matrix(matrix_a);
            break;
        } else if(toupper(user_matrix) == 'B'){
            update_matrix(row_index, col_index, new_value, matrix_b);
            print_matrix(matrix_b);
            break;
        } else {
            cout << "Invalid matrix selection. Please try again." << endl;
        }
    }
    
    return 0;
}

