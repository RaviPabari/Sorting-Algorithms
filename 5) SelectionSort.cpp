//The idea is to select the minimun from the array and place it at the begning and increment the counter so it gets sorted in ascending

#include<iostream>
using namespace std;

void swap(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void SelectSort(int A[],int n){
	int i,j,min;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(A[j] < A[i]){
				min = j;
			}
		}
		swap(&A[i],&A[min]);
	}
}

void Display(int A[],int n){
	for(int i=0;i<n;i++){
		cout << A[i] << " " ;
	}
}

int main(){
	int n;
	cin  >> n;
	int A[n];
	for(int i=0;i<n;i++){
		cin >>A[i];
	}
	SelectSort(A,n);
	Display(A,n);
	return 0;
}
