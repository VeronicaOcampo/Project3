#include <iostream>
#include "sorting.h"
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

void menu() {
    cout << "Sorting Algorithm Comparison\n";
    cout << "----------------------------\n";
    cout << "1. Compare randomly ordered data\n";
    cout << "2. Compare ascending ordered data\n";
    cout << "3. Compare descending ordered data\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void compareSorting(vector<int>& dataset) {
    double mergeDuration = 0;
    double quickDuration = 0;

    vector<int> datasetCopy;

    datasetCopy = dataset;
    mergeDuration += timer(mergeSort, datasetCopy, 0, datasetCopy.size() - 1);
    datasetCopy = dataset;
    quickDuration += timer(quickSort, datasetCopy, 0, datasetCopy.size() - 1);

    // formatting
    stringstream formattedDuration;
    formattedDuration << std::fixed << setprecision(5) << mergeDuration;

    cout << "Merge sort took " << formattedDuration.str() << " milliseconds.\n";

    formattedDuration.str("");
    formattedDuration.clear();
    formattedDuration << std::fixed << setprecision(5) << quickDuration;

    cout << "Quick sort took " << formattedDuration.str() << " milliseconds.\n";

    string res = (mergeDuration < quickDuration) ? "Merge sort was faster\n" : "Quick sort was faster\n";

    cout << res;
}


int main()
{
    // Seed random
    // srand(static_cast<unsigned int>(time(0)));

    string filename = "data.csv";

    int columnIndex = 0; // Read the 1st column (0-based indexing) there are 294021 lines in each column

    vector<int> column = readColumnFromCSV(filename, columnIndex);

    int choice;
    while(true) {
        menu();
        cin >> choice;

        if(choice == 1) {
            compareSorting(column);
        }
        else if(choice == 2) {
            vector<int> columnCopy = column;
            sort(columnCopy.begin(), columnCopy.end());
            compareSorting(columnCopy);
        }
        else if(choice == 3) {
            vector<int> columnCopy = column;
            sort(columnCopy.begin(), columnCopy.end(), std::greater<int>());
            compareSorting(columnCopy);

        }
        else if(choice == 4) {
            cout << "Thank you for using the Sorting Algorithm Comparison program.\n";
            return 0;
        }
        else {
            cout << "Invalid choice. Please enter a number 1-4.\n";
        }
        cout << endl;
    }
}
