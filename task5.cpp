/*
* EECS 348 Lab 9 Task 2
* Matrix Operations
* Swap matrix rows and display the result
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
using namespace std;


void row_swap(int row1_index, int row2_index, vector<vector<int>>& matrix){
    swap(matrix[row1_index], matrix[row2_index]);
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
    int row1_index;
    int row2_index;
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
        cout << "Enter the first row-index: ";
        if (!(cin >> row1_index)){
            cout << "Invalid row-index. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if(row1_index < 0 or row1_index >= n ){
            cout << "Invalid row-index. Please enter an index within the matrix bounds." << endl;
        } else {
            break;
        }
    }

    while(1){
        cout << "Enter the second row-index: ";
        if (!(cin >> row2_index)){
            cout << "Invalid row-index. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if(row2_index < 0 or row2_index >= n ){
            cout << "Invalid row-index. Please enter an index within the matrix bounds." << endl;
        } else {
            break;
        }
    }

    while(1){
        cout << "Which matrix would you like to perform the operation on? Enter A or B: ";
        cin >> user_matrix;
        if(toupper(user_matrix) == 'A'){
            row_swap(row1_index, row2_index, matrix_a);
            print_matrix(matrix_a);
            break;
        } else if (toupper(user_matrix) == 'B'){
            row_swap(row1_index, row2_index, matrix_b);
            print_matrix(matrix_b);
            break;
        } else {
            cout << "Invalid matrix selection. Please try again." << endl;
        }
    }

    return 0;
}

