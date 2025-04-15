#include <iostream>
#include "sorting.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


std::vector<std::string> readColumnFromCSV(const std::string& filename, int columnIndex) {
    std::vector<std::string> columnData;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        int currentIndex = 0;

        while (std::getline(ss, cell, ',')) {
            if (currentIndex == columnIndex) {
                columnData.push_back(cell);
                break;
            }
            currentIndex++;
        }
    }

    return columnData;
}
void menu() {
    cout << "Sorting Algorithm Comparison\n";
    cout << "----------------------------\n";
    cout << "1. Merge Sort\n";
    cout << "2. Quick Sort\n";
    cout << "3. Compare Both Algorithms\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{

    std::string filename = "data.csv";
    int columnIndex = 0; // Read the 1st column (0-based indexing) there are 294021 lines in each column

    std::vector<std::string> column = readColumnFromCSV(filename, columnIndex);


    int choice;
    while(true) {
        menu();
        cin >> choice;
        if(choice == 1) {
            //run merge sort
        }
        else if(choice == 2) {
            //run quick sort
        }
        else if(choice == 3) {
            //compare the algorithms
        }
        else if(choice == 4) {
            return 0;
        }
        else {
            cout << "Invalid choice. Please enter a number 1-4.\n";
        }
        cout << endl;
    }
}
