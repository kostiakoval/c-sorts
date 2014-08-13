//
//  Jesse Squires
//  http://www.jessesquires.com
//
//  GitHub
//  https://github.com/jessesquires/c-sorts
//
//  Copyright (c) 2014 Jesse Squires
//

#include <stdlib.h>

void swap(uint32_t *x, uint32_t *y)
{
    if (x == y) {
        return;
    }
    
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

int compareMyType (const void * a, const void * b)
{
    if ( *(uint32_t*)a < *(uint32_t*)b ) {
        return -1;
    }
    
    if ( *(uint32_t*)a > *(uint32_t*)b ) {
        return 1;
    }
    
    return 0;
}

void csort(uint32_t arr[], unsigned int count)
{
    qsort(arr, count, sizeof(uint32_t), compareMyType);
}

void selectionSort(uint32_t arr[], unsigned int count)
{
    unsigned int minIndex = 0;
    
    for (unsigned int i = 0; i < count - 1; i++) {
        minIndex = i;
        
        for (unsigned int j = i + 1; j < count; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void insertionSort(uint32_t arr[], unsigned int count)
{
    for (unsigned int i = 1; i < count; i++) {
        unsigned int j = i;
        uint32_t target = arr[i];
        
        while (j > 0 && target < arr[j - 1]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
        arr[j] = target;
    }
}

void heapSort(uint32_t arr[], unsigned int count)
{
    
}

unsigned int partition(uint32_t arr[], unsigned int left, unsigned int right)
{
    unsigned int i = left;
    unsigned int j = right;
    uint32_t pivot = arr[(left + right) / 2];
    
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        
        while (j > 0 && arr[j] > pivot) {
            j--;
        }
        
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            
            if (j > 0) {
                j--;
            }
        }
    }
    return i;
}

void quick_sort(uint32_t arr[], unsigned int left, unsigned int right)
{
    unsigned int index = partition(arr, left, right);
    
    if (left < index - 1) {
        quick_sort(arr, left, index - 1);
    }
    
    if (index < right) {
        quick_sort(arr, index, right);
    }
}

void quickSort(uint32_t arr[], unsigned int count)
{
    quick_sort(arr, 0, count - 1);
}
