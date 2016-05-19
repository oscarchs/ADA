#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int q = 0;
int Memoized_Cut_Rod_Aux(int * p,int n,int * r){

    if (r[n] >= 0)
        return r[n];
    if ( n==0 )
        q = 0;
    else{
        q = numeric_limits<int>::min();
        for (int i = 1; i < n ; i++)
            q = max(q,p[i] + Memoized_Cut_Rod_Aux(p,n-i,r));
    }
    r[n] = q;
    return q;
}
int Memoized_Cut_Rod(int * p,int n){
    int r[n];
    for (int i=0; i < n ; i++ )
        r[i] = numeric_limits<int>::min();
    return Memoized_Cut_Rod_Aux(p,n,r);
}
int main(){
  int p[10] = {1,5,8,9,10,17,17,20,24,30};
  int n = 4;
  cout << Memoized_Cut_Rod(p,n);
}
