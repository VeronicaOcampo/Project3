#include "sorting.h"

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
    double randomQuickDuration = 0;


    vector<int> mergeCopy = dataset;
    vector<int> quickCopy = dataset;
    vector<int> randomQuickCopy = dataset;


    mergeDuration = timer(mergeSort, mergeCopy, 0, mergeCopy.size() - 1);
    randomQuickDuration = timer(randomizedQuickSort, randomQuickCopy, 0, randomQuickCopy.size() - 1);
    //FIX: PROGRAM HANGS ON THE FOLLOWING LINE WHEN PROCESSING SORTED LISTS
    quickDuration = timer(quickSort, quickCopy, 0, quickCopy.size() - 1);


    // formatting
    stringstream formattedDuration;
    formattedDuration << std::fixed << setprecision(5) << mergeDuration;

    cout << "Merge sort took " << formattedDuration.str() << " milliseconds.\n";

    if(quickDuration == -1.0) {
        cout << "Quick sort (pivot = last element in subarray) took 3 or more seconds to execute.\n";
    } else{
        formattedDuration.str("");
        formattedDuration << std::fixed << setprecision(5) << quickDuration;
        cout << "Quick sort (pivot = last element in subarray) took " << formattedDuration.str() << " milliseconds.\n";
    }

    formattedDuration.str("");
    formattedDuration << std::fixed << setprecision(5) << randomQuickDuration;

    cout << "Quick sort (pivot = randomized) took " << formattedDuration.str() << " milliseconds.\n";


    double min = std::min({mergeDuration, quickDuration, randomQuickDuration});
    if(min == mergeDuration) {
        cout << "Merge sort was faster\n";
    }
    if(min == quickDuration) {
        cout << "Quick sort with last element pivot was faster\n";
    }
    if(min == randomQuickDuration) {
        cout << "Quick sort with randomized pivot was faster\n";
    }
}


int main()
{
    srand(static_cast<unsigned int>(time(0)));

    string filename = "data.csv";

    int columnIndex = 1; // Read the 1st column (0-based indexing) there are 294021 lines in each column

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
