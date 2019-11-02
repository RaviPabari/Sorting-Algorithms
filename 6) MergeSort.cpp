#include<iostream>
using namespace std;

void Merge(int A[],int p,int q,int r){

	/*
	Assumes A to be a list and p,q and r an int
  	merges the sorted sub-lists into the single list A 
  	*/
  
	int i,j,k;
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1],R[n2+1];
	for(i=0;i<n1;i++){
		L[i] = A[p+i];
	}
	for(j=0;j<n2;j++){
		R[j] = A[q+j+1];
	}
	//L[n1+1] = INT_MAX;
	//R[n2+1] = INT_MAX;
	i=0;
	j=0;
	for(k=p;k<=r;k++){
  
		/*
		what if the the first list becomes empty,then we have to copy the remaining
	  	elements from the second list to the sorted list...so this is the condition for that :)
		*/
    
		if(i==n1){				
			while(j<n2){		
				A[k] = R[j];
				j++;
				k++;
			}
			break;
		}
		if(j==n2){
			while(i<n1){
				A[k] = L[i];
				i++;
				k++;
			}
			break;
		}
		if(L[i]<R[j]){
			A[k]=L[i];
			i++;
		}else{
			A[k]=R[j];
			j++;
		}
	}
}

void Sort(int A[],int p,int r){

	/*
	Divides A in subsequences , sorts them and then
  	merges sorted subsequences into A
	*/
 
	if(p<r){
		int q = (p+r)/2;
		Sort(A,p,q);
		Sort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

void Display(int A[],int n){
	int i;
	cout << "Sorted Array :" << endl;
	for(i=0;i<n;i++){
		cout << A[i] << endl;
	}
}

int main(){
	cout  << "Enter the size of array :" << endl;
	int n;
	cin >> n;
	int A[n];
	cout << "Enter the elements :" << endl;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int p,r;
	p=0,r=n-1;
	Sort(A,p,r);
	Display(A,n);
 	return 0;
}
