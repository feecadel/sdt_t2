#include <iostream>
#include <iomanip>   // for setw
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time

using namespace std;

int main() {
    int rows, cols;

    // Input table dimensions from the user
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Seed the random number generator with the current time
    srand(time(0));

    // Create a dynamic 2D array
    int** table = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        table[i] = new int[cols];
    }

    // Fill the table with random values from 0 to 99
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            table[i][j] = rand() % 100;  // random number from 0 to 99
        }
    }

    // Output the table
    cout << "\nRandom Table:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << table[i][j];  // set column width
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
