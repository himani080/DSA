// 1
// 12
// 123
#include<iostream>
using namespace std;
void nTriangle(int n) {
	
	for(int i=0;i<n;i++){
		for(int j=1;j<i+2;j++){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}
