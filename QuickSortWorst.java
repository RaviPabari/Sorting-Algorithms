import java.util.*;
class QuickSortWorst{
    int partition = 0;
    int partition(int arr[], int low, int high){
        partition++;
        int pivot = arr[low];
        int i = low;
        {
            for (int j=low+1; j<=high; j++)
            if (arr[j] <= pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i];
        arr[i] = arr[low];
        arr[low] = temp;
        return i;
    }

    void sort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            sort(arr, low, pi-1);
            sort(arr, pi+1, high);
        }
    }

    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    public static void main(String args[]){
        QuickSort ob1 = new  QuickSort();
        SelectionSort ob = new SelectionSort();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Elements : ");
        int n = sc.nextInt();
        int arr[] = new int[n];

        Random r = new Random();
        for(int i = 0; i<n; i++){

            arr[i] = i+1;
        }
        System.out.println("\nTaking Sorted array for Worst Case.\n");
        ob.printArray(arr);
        double start = System.nanoTime();
        ob1.sort(arr,0,n-1);
        double end = System.nanoTime();
        System.out.print("\nSorted Array ===>");
        ob1.printArray(arr);
        System.out.println("\n Time taken for worst case = " + (end-start)/100000 + "Partiton calls = " + ob1.partition);
    }
}
