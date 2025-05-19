#include <iostream>
#include <iomanip>  // for setw

using namespace std;

int main() {
    int rows, cols;

    // Input table dimensions from the user
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Create a dynamic 2D array
    int** table = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        table[i] = new int[cols];
    }

    // Fill the table with values
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            table[i][j] = (i + 1) * (j + 1);  // just an example: multiplication table
        }
    }

    // Output the table
    cout << "\nGenerated Table:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << table[i][j];  // setw(5) sets a width of 5 for each printed value
        }
        cout << endl;
    }

    // Free the allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] table[i];
    }
    delete[] table;

    return 0;
}
