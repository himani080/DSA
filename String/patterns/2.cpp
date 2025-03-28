// * 
// * * 
// * * * 
#include<iostream>
using namespace std;
void nForest(int n) {
	// Write your code here.
	for(int i=n;i>=0;i--){
		for(int j=i;j<n;j++){
               cout<<"* ";
		}
		cout<<"\n";
	}
}

