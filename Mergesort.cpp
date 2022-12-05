#include<iostream>

using namespace std;


void merge(int array[], int low, int middle, int high) {
    auto subArrayOne = middle - low + 1;
    auto subArrayTwo = middle - low + 1;


    //create sub arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    
    //copying data from main array into sub arrays
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[low + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[middle + 1 + j];


    //creating initial indexes for the sub arrays and merged array
    auto indexofSubArrayOne = 0,
         indexofSubArrayTwo = 0;
    int indexofMergedArray = low;
     

    // merge temporary arrays back into array[]
    while (indexofSubArrayOne < subArrayOne && indexofSubArrayTwo < subArrayTwo) {
        if (leftArray[indexofSubArrayOne] <= rightArray[indexofSubArrayTwo]) {
            array[indexofMergedArray] = leftArray[indexofSubArrayOne];
            indexofSubArrayOne++;
        } else {
            array[indexofMergedArray] = rightArray[indexofSubArrayTwo];
            indexofSubArrayTwo++;
        }
        indexofMergedArray++;
    }

    //copy any remaining elements of left[]
    while (indexofSubArrayOne < subArrayOne) {
        array[indexofMergedArray] = leftArray[indexofSubArrayOne];
        indexofSubArrayOne++;
        indexofMergedArray++;
    }

    //copy any remaining elements of right[]
    while (indexofSubArrayTwo < subArrayTwo) {
        array[indexofMergedArray] = rightArray[indexofSubArrayTwo];
        indexofSubArrayTwo++;
        indexofMergedArray++;
    }

    //delete these arrays
    delete[] leftArray;
    delete[] rightArray;
}

void printarray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void mergesort(int array[], int low, int high) {

    if(low >= high) {
        return;
    }

    auto middle = low + (high - low) / 2;
    mergesort(array,low,middle);
    mergesort(array,middle+1,high);
    merge(array,low,middle,high);
}


int main(void) {
    int arr[] = { 12, 11, 13, 5, 6, 7, 333, 23, 4, 1, 8, 10 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printarray(arr, arr_size);
 
    mergesort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printarray(arr, arr_size);
    return 0;
}