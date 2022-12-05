#include<iostream>

using namespace std;

int* doubleA(int *Array, int *size) {
    int newsize =  (*size)*2;
    int *array = new int[newsize];
    //cout << array << endl;

    for (int i = 0; i < *size; i++){
        array[i] = Array[i];
    }

    *size = (*size)*2;

    return array;
    
}

int binary_search(int *Array, int key, int low, int high) {
    int middle;

    if (low > high) {
        return -1;
    }

    middle = (low+high) /2;

    if (Array[middle] == key) {
        return(middle);
    }

    if (Array[middle] > key) {
        return(binary_search(Array,key,low,middle-1));
    } else {
        return(binary_search(Array,key,middle+1,high));
    }
}


int main(void) {
    int *array = new int[3];
    int size = 3;
    
    for (int i = 0; i < 48; i++) {
        //cout << array << endl;
        if (i == size) {
           array = doubleA(array,&size);
            array[i] = i;
        } else {
            array[i] = i;
        }
    }

    cout << size << endl;
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    cout << binary_search(array, 32, 0, 48) << endl;
    cout << array[binary_search(array, 32, 0, 48)] << endl;


}
