#include <iostream>

using namespace std;

void insertsort(int * A, int asize){
    int key,i;
    for(int j=1;j < asize;j++){
        key = A[j];
        i = j-1;
        while(i >= 0 and A[i] > key){
            swap(A[i+1],A[i]);
            i = i-1;
        }
    }

}

int main()
{
    int * A;
    A = new int[10];
    int j = 10;
    for(int i=0;i<10;i++){
        A[i] = j;
        j--;

    }
    A[5]=200;
    for(int i=0;i<10;i++){
        cout << A[i]<< "  ";

    }
    insertsort(A,10);

    cout << endl;

    for(int i=0;i<10;i++){
        cout << A[i]<< "  ";

    }
    return 0;
}
