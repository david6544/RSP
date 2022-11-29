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


int main(void) {
    int *array = new int[3];
    int size = 3;
    
    for (int i = 0; i < 49; i++) {
        //cout << array << endl;
        if (i == size) {
           array = doubleA(array,&size);
            array[i] = i;
        } else {
            array[i] = i;
        }
    }

    /*
    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    */
}
