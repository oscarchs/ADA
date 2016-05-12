#include <iostream>
#include <vector>

using namespace std;

void prt(vector<int>& arr, string msg = "") {
	cout << msg << " ";
	for  (auto i: arr) {
		cout << i << " ";
	}
	cout << endl;
}

void LongestSubsection(vector<int>& D) {
	vector< vector<int> > L(D.size());
   L[0].push_back(D[0]);
	for (int i=1; i<D.size(); i++) {
		for(int j=0; j<i; j++) {
			if ( (D[j] < D[i]) && ( L[i].size() < L[j].size() ) ) {
				L[i] = L[j];
			}
		}
      L[i].push_back(D[i]);
	}
	for (auto x: L) {
		prt(x);
	}
}

int main() {
	int a[] = {12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15,100,2323};
	vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    //prt(arr, "Data In:");
	for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
	}
	cout<<endl;

	LongestSubsection(arr);

	return 0;
}
