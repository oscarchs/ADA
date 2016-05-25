#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>
#include <time.h>
using namespace std;

//classic cut_rod
int Cut_Rod(int * p,int n){
    if (n <= 0)
	return 0;
    int q = numeric_limits<int>::min();
    for(int i=0; i < n; i++){
	q = max(q,p[i] + Cut_Rod(p,n-i-1));}
    return q;
}


//memoized_cut_rod
int q;
int Memoized_Cut_Rod_Aux(int * p,int n,int * r){

    if (r[n] >= 0)
        return r[n];
    if ( n==0 )
        q = 0;
    else{
        q = numeric_limits<int>::min();
        for (int i = 0; i < n ; i++)
            q = max(q,p[i] + Memoized_Cut_Rod_Aux(p,n-i-1,r));
    }
    r[n] = q;
    return q;
}
int Memoized_Cut_Rod(int * p,int n){
    int r[n];
    for (int i=0; i <= n ; i++ )
        r[i] = numeric_limits<int>::min();
    return Memoized_Cut_Rod_Aux(p,n,r);
}

//bottom_up cut rod
int Bottom_Up_Cut_Rod(int * p, int n){
    int *r = new int[n];
    r[0]=0;
    int q;
    for (int j=1; j<=n; j++) {
        q=numeric_limits<int>::min();
        for (int i=0; i<j; i++) {
            q=max(q, p[i]+r[j-i-1]);
        }
        r[j]=q;
    }
    return r[n];
}

//extended bottom up cut rod
pair<int*,int*> Extended_Bottom_Up_Cut_Rod(int * p,int n){
    int *r = new int[n];
    int *s = new int[n];
    r[0]=0;
    int q;
    for (int j=1; j<=n; j++) {
        q=numeric_limits<int>::min();
        for (int i=1; i<=j; i++){
            if ( q < p[i-1] + r[j-i-1] ){
                q = p[i-1] + r [j-i-1];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return make_pair(r,s);
}

void Print_Cut_Rod_Solution(int * p, int n) {
    pair<int*,int*> rs = Extended_Bottom_Up_Cut_Rod(p,n);
    while (n > 0){
        cout<<rs.second[n]<<" ";
        n = n - rs.second[n];
    }
}

int main(){
  int p[10] = {1,5,8,9,10,17,17,20,24,30};
 
    clock_t start1 = clock();
    Extended_Bottom_Up_Cut_Rod(p,1000);
    clock_t end1 = clock();
    float time1 = (float) (end1-start1) / CLOCKS_PER_SEC;
    cout << time1<<endl;
}
