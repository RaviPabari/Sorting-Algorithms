import java.util.*;
class QuickSortBest
{
    static int partition = 0;

    static void qsort(int a[], int left_index, int right_index)
    {
        int left, right, pivot;
        if(left_index >= right_index) return;
        left = left_index;
        right = right_index;
        pivot = a[(left_index + right_index) /2];
        partition++;
        while(left <= right) {
            while(a[left] < pivot) left++;
            while(a[right] > pivot) right--;
            if(left <= right) {
                swap(a,left,right);
                left++; right--;
		}
        qsort(a,left_index,right);
	    qsort(a,left,right_index);
	}
}

    static void swap(int a[], int i, int j)
    {
        int temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    public static void main(String args[]){
        QuickSortBest ob1 = new  QuickSortBest();
        SelectionSort ob = new SelectionSort();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Elements : ");
        int n = sc.nextInt();
        int arr[] = new int[n];

        Random r = new Random();
        for(int i = 0; i<n; i++){

            arr[i] = i+1;
        }
        System.out.println("\nTaking  Sorted array for best Case.\n");
        ob.printArray(arr);
        double start = System.nanoTime();
        ob1.qsort(arr,0,n-1);
        double end = System.nanoTime();
        System.out.print("\nSorted Array ===>");
        ob1.printArray(arr);
        System.out.println("\n Time taken for worst case = " + (end-start)/100000 + "Partion calls = " + ob1.partition );
    }
}
