#include "sorting.h"

void merge(vector<int>& array, int left, int mid, int right) {
    int leftHalf = mid - left + 1;
    int rightHalf = right - mid;
    vector<int> leftArray(leftHalf);
    vector<int> rightArray(rightHalf);
    for(int i = 0; i < leftHalf; ++i) {
        leftArray[i] = array[left + i];
    }
    for(int j = 0; j < rightHalf; ++j) {
        rightArray[j] = array[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < leftHalf && j < rightHalf) {
        if(leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        }
        else {
            array[k++] = rightArray[j++];
        }
    }
    while(i < leftHalf) {
        array[k++] = leftArray[i++];
    }
    while(j < rightHalf) {
        array[k++] = rightArray[j++];
    }
}

void mergeSort(vector<int>& array, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int splitArray(vector<int>& array, int startIndex, int endIndex) {
    int pivot = array[endIndex];
    int i = startIndex - 1;
    for(int j = startIndex; j < endIndex; ++j) {
        if(array[j] < pivot) {
            ++i;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[endIndex]);
    return i + 1;
}

void quickSort(vector<int>& array, int startIndex, int endIndex) {
    if(startIndex < endIndex) {
        int pivotIndex = splitArray(array, startIndex, endIndex);
        quickSort(array, startIndex, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, endIndex);
    }
}

double timer(function<void(vector<int>& array, int, int)> func, vector<int>& array, int startIndex, int endIndex) {
    auto start = std::chrono::high_resolution_clock::now();

    func(array, startIndex, endIndex);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    return duration.count();
}