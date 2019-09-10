#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char str[5][10],temp[10];
	int i,j,k;
	cout << "Enter 5 names to sort them in dictionary order " << endl;
	for(i=0;i<5;i++){
		cin >> str[i] ;
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			k = strcmp(str[j],str[j+1]);
			if(k>0){
				strcpy(temp,str[j]);a
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	cout <<endl << "Names sorted in Dictionary order :" << endl;
	for(i=0;i<=5;i++){
		cout << str[i] <<endl ;
	}
	return 0;
}
