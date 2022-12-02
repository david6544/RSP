#include<iostream>
#include<climits>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



class Heap {
   
public:
    int *arr; //pointer to array of elements
    int capacity; // total capacity
    int size; //current size

    Heap(int capacity);

    void MinHeapify (int ); //heapify subtree with the root at any given index

    int pq_parent(int i); // return parent of node i
    int pq_left(int i); // return left child of node i
    int pq_right(int i); // return right child of node i

    int extractMin(); // extract smallest element

    void decreaseKey(int i, int newval); //Decreases key val of index i to newval

    void deletekey(int i); // Deletes a key at i

    void insertkey(int k); // inserts a key k

    int getmin(){return arr[0];} //returns minimum key from min heap

    void maxheapify(int arr[], int size, int root);
    void heapsort(int arr[], int size);
    void print(int arr[], int size);
};

Heap::Heap(int cap){
    size = 0;
    capacity = cap;
    arr = new int[capacity];
}

void Heap::MinHeapify(int n){
   
   int l = pq_left(n);
   int r = pq_right(n);
   int smallest = n;

   if (l < size && arr[l] < arr[n])
        smallest = l;
   if (r < size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != n) {
        swap(&arr[n], &arr[smallest]);
        MinHeapify(smallest);
    }

}

int Heap::pq_parent(int i){
    return (i-1)/2;
}

int Heap::pq_left(int i){
    return (2*i +1);    
}

int Heap::pq_right(int i){
    return (2*i +2);    
}

int Heap::extractMin(){
    if (size <= 0) {
        return INT_MAX;
    } else if (size == 1) {
        size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size-1];
    size--;
    MinHeapify(0);
    return root;
}

void Heap::decreaseKey(int i, int newval){
    arr[i] = newval;
    while (i != 0 && arr[pq_parent(i)] > arr[i]) {
        swap(&arr[i], &arr[pq_parent(i)]);
        i = pq_parent(i);
    }
}

void Heap::deletekey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

void Heap::insertkey(int k){
    if (size == capacity) {
        cout << "Warning: priority queue overflow" << endl;
        return;
    }

    size++;
    int i = size-1;
    arr[i] = k;

    while (i != 0 && arr[pq_parent(i)] > arr[i]) {
        swap(&arr[i], &arr[pq_parent(i)]);
        i = pq_parent(i);
    }
}

void Heap::maxheapify (int arr[], int size, int root) {
    int largest = root;
    int l = (2*root) + 1;
    int r = (2*root) + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != root) {
        swap(arr[root],arr[largest]);
        maxheapify(arr,size,largest);
    }
}

void Heap::heapsort(int arr[], int size) {
    //print(arr,size);
    for (int i = (size/2 - 1); i >= 0; i--) {
        maxheapify(arr, size, i);
        //print(arr,size);
    }
    
    for (int i = (size - 1); i > 0 ; i--) {
        swap(arr[0],arr[i]);
        //print(arr,size);
        maxheapify(arr,i,0);
        //print(arr,size);
    }
    
}

void Heap::print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Heap h(11);
    h.insertkey(3);
    h.insertkey(2);
    h.deletekey(1);
    h.insertkey(15);
    h.insertkey(5);
    h.insertkey(4);
    h.insertkey(45);
    /* cout << h.extractMin() << " ";
    cout << h.getmin() << " "; */
    h.decreaseKey(2, 1);
    //cout << h.getmin() << endl;

    h.print(h.arr, h.size);

    h.heapsort(h.arr, h.size);
 
    cout << "Sorted array is \n";
    h.print(h.arr, h.size);

    return 0;
}
