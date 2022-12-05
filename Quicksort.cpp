#include<iostream>
#include<utility>


using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int array[], int left, int right) {
    int counter;    //counter
    int pivotindex; // pivot index
    int firsthigh;  // divider position for pivot

    pivotindex = right; //select last element as pivot

    firsthigh = left;
    for (counter = left; counter < right; counter++) {
        if (array[counter] < array[pivotindex]) {
            swap(&array[counter], &array[firsthigh]);
            firsthigh++;
        }
    }
    swap(&array[pivotindex], &array[firsthigh]);

    return(firsthigh);
}

void quicksort(int array[], int left,int right) {
    int pivot;

    if (left < right) {
        pivot = partition(array,left,right);
        quicksort(array,left,pivot-1);
        quicksort(array,pivot+1,right);
    }
}

int main(void) {
    int arr[] = { 10, 7, 8, 9, 1, 5, 239 };
    int n = sizeof(arr) / sizeof(arr[0]);


    cout << "Unsorted array: \n";
    printarray(arr, n);

    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printarray(arr, n);
    return 0;
}