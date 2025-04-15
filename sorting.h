#pragma once
#include <vector>
#include <chrono>
#include <functional>

using namespace std;

void merge(vector<int>& array, int left, int mid, int right);
void mergeSort(vector<int>& array, int left, int right);

int splitArray(vector<int>& array, int startIndex, int endIndex);
void quickSort(vector<int>& array, int startIndex, int endIndex);

double timer(function<void(vector<int>&, int, int)> func, vector<int>& array, int startIndex, int endIndex);


