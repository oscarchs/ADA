#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;
#define MINUS_INFINITY -99999


int fmsa_bruteforce(int *A,int l,int h){
    int left = l;
    int right = h;
    int sum = MINUS_INFINITY;
    for(int i=l ;i<h;i++){
        int current_sum=0;
        for(int j=i;j<h;j++){
            current_sum += A[j];
            if(sum < current_sum) sum = current_sum;
        }
    }
    return sum;
}


int find_max_crossing_subarray(int *A,int low,int mid, int high){
    int left_sum = MINUS_INFINITY;
    int sum=0;
    for (int i=mid;i>low;i--){
        sum = sum + A[i];
        if (sum > left_sum){
            left_sum = sum;
        }
    }
    int right_sum = MINUS_INFINITY;
    sum = 0;
    for (int j=mid+1;j<high;j++){
        sum = sum + A[j];
        if (sum > right_sum){
            right_sum=sum;
        }
    }
    
    return left_sum + right_sum;
}

int find_maximum_subarray(int *A,int low,int high){
    if(high == low){
        return fmsa_bruteforce(A,low,high);
    //return A[low]; 
    }
    int mid = (low+high)/2;
    int left_sum = find_maximum_subarray(A,low,mid);
    int right_sum = find_maximum_subarray(A,mid+1,high);
    int cross_sum = find_max_crossing_subarray(A,low,mid,high);
 
    if (left_sum >= right_sum && left_sum >= cross_sum)
        return left_sum;
    if (right_sum > left_sum && right_sum >= cross_sum)
        return right_sum;
    else
        return cross_sum;
}

int main(){
   int *A = new int[100];
   for(int i =0; i < 100;i++){
     A[i] = rand()%100;
    }
   for(int j=0;j <100;j++) cout << A[j]<<",";
   int max_sum = find_maximum_subarray(A, 0, 99);
   cout<< max_sum<<endl;
   return 0;

}


