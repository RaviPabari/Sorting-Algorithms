#include<iostream>
using namespace std;

void swap(int *x,int *y){	                	//fun to swap two values
	int temp;
	temp = *x;
	*x=*y;
	*y=temp;
}

int partition(int A[],int l, int h){  
	int pivot = A[l];                     
	int i=l,j=h;
	do{                                     	// Main Algo;
		do{
			i++;
		}while(A[i]<=pivot);
		do{
			j--;
		}while(A[j]>pivot);
		if(i<j){
			swap(&A[i],&A[j]);
		}
	}while(i<j);
	
	swap(&A[l],&A[j]);
	return j;                                 	//returning the position from where partitions will be done;
}

void QuickSort(int A[],int l , int h){      		//recursive function;
	int j;
	if(l<h){			                // to check there are atleast two elements;
		j=partition(A,l,h);                     
		QuickSort(A,l,j);                       // Sorting the left partition recursively;
		QuickSort(A,j+1,h);			// Sorting the right partition recursively;
	}
}

int main(){
	int A[]={43,23,65,234,67,123,68,21,76,76,INT_MAX},n=11,i;       //INT_MAX is the biggest number in int data type
	QuickSort(A,0,10 );                                             //low = 0, high = INT_MAX
	for(i=0;i<10;i++){
		cout << A[i] << " ";
	}
	return 0;
}
