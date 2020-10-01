#include<iostream>
#include<math.h>
using namespace std;

void InsertionSort(int A[],int n){
	int x,i,j;							//Time Complexity = O(n^2)
	for(i=1;i<n;i++){
		j=i-1;
		x = A[i];
		while(j>-1 && A[j]>x){
			A[j+1] = A[j];
			j=j-1;
		}
		A[j+1] = x;
	}
}

int main(){
	int n=5;
	int A[5]={43,23,125,87,32};
	InsertionSort(A,n);
	for(int i=0;i<n;i++){
		cout << A[i] << endl;
	}
	return 0;
}
