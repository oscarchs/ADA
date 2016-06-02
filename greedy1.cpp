#include <iostream>
#include <vector>
using namespace std;

int a[11];
int count = 0;

void Recursive_Activity_Selector(int *s,int *f,int k, int n){
    int m = k + 1;
    while( m <= n && s[m] < f[k] ){
	m += 1;
    }

    if( m <= n ){
	a[count ++] = m;
        Recursive_Activity_Selector(s,f,m,n);}
    else
	return;
}




void Iterative_Activity_Selector(int *s,int *f){
    int n = 11;
    a[0] = 0;
    int k = 1;
    int count = 1;
    for ( int m = 1 ; m < n ; m++ ){
        if ( s[m] >= f[k] ){
  	    a[count ++] = m;
	    k = m;
        }
    }
    return;     
}


int main(){
    
    int s[11] = {1,3,0,5,3,5,6,8,8,2,12};
    int f[11] = {4,5,6,7,9,9,10,11,12,14,16};
    //Recursive_Activity_Selector(s,f,0,11);
    Iterative_Activity_Selector(s,f);
    for( int i =0; i < 11; i ++) cout << a[i]<<" ";
    return 0;
}
