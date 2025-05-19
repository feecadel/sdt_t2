#include <iostream>
#include <iomanip>   // for setw
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time
#include <algorithm> // for sort

using namespace std;

int main() {
    int rows, cols;

    // Ask user for table size
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Seed the random number generator
    srand(time(0));

    // Create a dynamic 2D array
    int** table = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        table[i] = new int[cols];
    }

    // Fill table with random numbers from 0 to 99
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            table[i][j] = rand() % 100;
        }
    }

    // Display unsorted table
    cout << "\nUnsorted Table:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << table[i][j]; // setw sets the width of each printed number
        }
        cout << endl;
    }

    // Step 1: Flatten table into a 1D array
    int size = rows * cols;
    int* flat = new int[size];
    int index = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            flat[index++] = table[i][j];

    // Step 2: Sort the flat array
    sort(flat, flat + size);

    // Step 3: Copy sorted values back into the 2D table
    index = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            table[i][j] = flat[index++];

    // Display sorted table
    cout << "\nSorted Table:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << table[i][j];
        }
        cout << endl;
    }

    // Free allocated memory
    delete[] flat;
    for (int i = 0; i < rows; ++i)
        delete[] table[i];
    delete[] table;

    return 0;
}
