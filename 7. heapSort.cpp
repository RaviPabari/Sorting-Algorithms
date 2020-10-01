#include <iostream>
using namespace std;

class Node{
    private:
    int value;
    int index;

    public:
    Node(){

    }
    Node(int a,int b){
        value = a;
        index = b;
    }

    void setValue(int a){
        value = a;
    }
    void setIndex(int a){
        index = a;
    }

    int getValue(){
        return this ->value;
    }
    int getIndex(){
        return this ->index;
    }

    int right(){
        int i = this -> index;
        return 2*i + 2;
    }
    int left(){
        int i = this -> index;
        return 2*i + 1;
    }
    int parent(){
        int i = this -> index;
        return i/2;
    }
};
void swap(Node &a,Node &b){
    int i = a.getValue();
    a.setValue(b.getValue());
    b.setValue(i);
}


void maxHeapify(Node *a,int index,int n)
//Creates a max heap at a particular index of an array
//Running time of O(lgn) as the maximum height of the node can be lgn(base 2 log)
{
    int l = a[index].left(); //index of the left child
    int r = a[index].right();//index of the right child
    int largest = 0;
    if((l < n) && (a[l].getValue() > a[index].getValue())){
        largest = l;
    }
    else{
        largest = index;
    }
    if( (r < n) && (a[r].getValue() > a[largest].getValue())){
        largest = r;
    }
    //largest contains the index of the largest of parent,left child and right child
    if(largest != index){
        swap(a[largest],a[index]);
        //The parent needs to be swapped as it does not contain the largest value
        maxHeapify(a,largest,n);
        //As the swapped element could violate maxHeapify property, a recursive call
    }
}

void buildMaxHeap(Node *a,int n)
//Build max heaps at each node in an array 
//Running time is O(n) i.e. linear time 
{
    int i = n/2;  
    // As half of the node in an array are at the leaf so they are already a max-heap
    while (i >= 0){
        maxHeapify(a,i,n);   
    // Run maxHeapify on the remaining nodes
        i -= 1;
    }
}


void heapsort(Node *a,int n)
//Sorts the array using buildMaxHeap and MaxHeapify
//Running time is O(nlgn)
{
    buildMaxHeap(a,n);
    //Converts an array into max heap. Thus, the largest element is root
    int i = n - 1;
    while (i >= 1)
    {
        swap(a[0],a[i]);
    // The largest element is at position 0 that is root of the maxHeap, so it is swapped to its right position
    //Now the array a[1...i] contains smallest i element and a[i+1.....n] are already in sorted form
        maxHeapify(a,0,i);
        i -= 1;
    }
    
}
int main(){
    int size;
    scanf("%d",&size);
    Node heap[size];
    int n;
    for(int i = 0; i < size;i++){
        scanf("%d",&n);
        heap[i].setIndex(i);
        heap[i].setValue(n);
    }
    heapsort(heap,size);
    printf("\n");
    for(int j = 0; j < size;j++){
        printf("%d ",heap[j].getValue());
    }
    printf("\n");
    return 0;
}
