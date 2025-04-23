This C++ project compares the performance of three sorting algorithms:
- Merge Sort
- Quick Sort (Last Element Pivot)
- Quick Sort (Randomized Pivot)

The goal was to see how the three algorithms responded under three different conditions:
- Randomly ordered data
- Ascending ordered data
- Descending ordered data

We used a dataset of housing prices from a .csv file and output execution time in milliseconds (ms) for each algorithm.

To run the project you need:
- a C++ compiler, i.e. GCC (used by the team)
- CMake (if building via CLion or the terminal)
- C++17 support (used by team, recommended)
- IDE, i.e. CLion (used by team)
- Make sure to remove any headers or make sure the program skips it

  **Ensure that all the following files are in the same directory:**
- main.cpp
- implementSort.cpp
- sorting.h
- data.csv
   - The file should contain numeric price data in the second column.
