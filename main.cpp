#include <iostream>
#include "sorting.h"
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>


void menu() {
    cout << "Sorting Algorithm Comparison\n";
    cout << "----------------------------\n";
    cout << "1. Merge Sort\n";
    cout << "2. Quick Sort\n";
    cout << "3. Compare execution times\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{

    std::string filename = "data.csv";
    int columnIndex = 0; // Read the 1st column (0-based indexing) there are 294021 lines in each column

    std::vector<int> column = readColumnFromCSV(filename, columnIndex);

    int choice;
    while(true) {
        menu();
        cin >> choice;
        if(choice == 1) {
            mergeSort(column, 0, column.size() - 1);
        }
        else if(choice == 2) {
            quickSort(column, 0, column.size() - 1);
        }
        else if(choice == 3) {
            double mergeDuration = 0;
            double quickDuration = 0;

            vector<int> datasetCopy;

            // measure the duration 10 times for a more accurate result
            for(int i = 0; i < 10; i++) {
                datasetCopy = column;
                mergeDuration += timer(mergeSort, datasetCopy, 0, datasetCopy.size() - 1);
                datasetCopy = column;
                quickDuration += timer(quickSort, datasetCopy, 0, datasetCopy.size() - 1);
            }

            // take the average of the 10 runs
            mergeDuration /= 10;
            quickDuration /= 10;

            // formatting
            std::stringstream formattedDuration;
            formattedDuration << std::fixed << setprecision(5) << mergeDuration;

            cout << "Merge sort took " << formattedDuration.str() << " milliseconds.\n";

            formattedDuration.str("");
            formattedDuration.clear();
            formattedDuration << std::fixed << setprecision(5) << quickDuration;

            cout << "Quick sort took " << formattedDuration.str() << " milliseconds.\n";

            string res = (mergeDuration < quickDuration) ? "Merge sort was faster\n" : "Quick sort was faster\n";


            cout << res;
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
