#include <iostream>
using namespace std;

void max_heapify(int A[], int i, int n){
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&A[l]>A[i])
       largest=l;
    else
       largest=i;
    if((r<=n)&&(A[r]>A[largest]))
       largest=r;
    if(largest!=i){
         loc=A[i];
         A[i]=A[largest];
         A[largest]=loc;
         max_heapify(A, largest,n);
    }
}
void build_max_heap(int A[], int n){
    for(int k = n/2; k > 0; k--){
        max_heapify(A, k, n);
    }
}
void heapsort(int A[], int n){
    build_max_heap(A,n);
    int i, temp;
    for (i = n; i >= 2; i--){
        temp = A[i];
        A[i] = A[1];
        A[1] = temp;
        max_heapify(A,1,i-1);
    }
}

int main(){
    //int A[11] = {3,5,1,7,8,44,117,2,146,15,100};
    int A[4] = {2,3,8,1};
    heapsort(A,4);
 //   for (int i = 0; i < 11; i++){
   //     cout<<A[i]<<endl;
  //  }
}