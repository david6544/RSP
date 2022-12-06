#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;
typedef valarray<cd> CArray;

vector<cd> fft(vector<cd>& vec) {
    int size = vec.size();

    if (size == 1) {
        return vector<cd>(1,vec[0]);
    }

    //to store n complex nth roots of unity
    vector<cd> comp(size);
    for (int i = 0; i < size; i++) {
        double alpha = -2 * M_PI * i / size;
        comp[i] = cd(cos(alpha),sin(alpha));
    }

    vector<cd> EvenV(size/2), OddV(size/2);

    for (int i = 0; i < size/2; i++) {
        EvenV[i] = vec[i * 2];
        OddV[i] = vec[i * 2 + 1];
    }

    vector<cd> fEven = fft(EvenV);
    vector<cd> fOdd = fft(OddV);

    vector<cd> finalV(size);

    for (int k = 0; k < size/2; k++) {
        finalV[k] = fEven[k] + comp[k] * fOdd[k];
        finalV[k + size/2] = fEven[k] - comp[k] * fOdd[k];
    }

    return finalV;
}

vector<cd> multiply(vector<cd> A, vector<cd> B) {
    int sizeA = A.size();
    int sizeB = B.size();

    vector<cd> C(sizeB);

    if (sizeA == sizeB) {
        for (int i = 0; i < sizeA; i++) {
          C[i] =  A[i] * B[i];
        }
    }

    return C;
}



int main(void) {

    vector<cd> PolyA{0,0,0,3,2,6};
    vector<cd> PolyB{0,0,0,4,3,2};

    vector<cd> A = fft(PolyA);
    vector<cd> B = fft(PolyB);


    for (int i = 0; i < 4; i++)
        cout << A[i] << endl;

    for (int i = 0; i < 4; i++)
        cout << B[i] << endl;

    cout << endl;
    vector<cd> C = multiply(A,B);

    for (int i = 0; i < 4; i++)
        cout << C[i] << endl;

    /* vector<cd> a{9, -10, 7, 6};
    vector<cd> b = fft(a);
    for (int i = 0; i < 4; i++)
        cout << b[i] << endl; */
 
    return 0;
}