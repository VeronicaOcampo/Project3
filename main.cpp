#include <iostream>
#include "sorting.h"

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
