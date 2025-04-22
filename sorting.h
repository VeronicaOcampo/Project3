#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include <future>
#include <thread>
#include <algorithm>

using namespace std;

void merge(vector<int>& array, int left, int mid, int right);
void mergeSort(vector<int>& array, int left, int right);

int splitArray(vector<int>& array, int startIndex, int endIndex);
void quickSort(vector<int>& array, int startIndex, int endIndex);

int randomizedPartition(vector<int>& array, int startIndex, int endIndex);
void randomizedQuickSort(vector<int>& array, int startIndex, int endIndex);

double timer(function<void(vector<int>&, int, int)> func, vector<int>& array, int startIndex, int endIndex);

vector<int> readColumnFromCSV(const std::string& filename, int columnIndex);


