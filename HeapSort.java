import java.util.*;
public class HeapSort{
    public void sort(int arr[]){
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i=n-1; i>=0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }
    void heapify(int arr[], int n, int i){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;
        if (largest != i){
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }
    static void printArray(int arr[]){
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    public static void main(String args[]){
        SelectionSort ob = new  SelectionSort();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Elements : ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        Random r = new Random();
        for(int i = 0; i<n; i++){

            arr[i] = i+1;
        }
        ob.revsort(arr);
        System.out.println("\nTaking Reverse Sorted array for Worst Case.\n");
        ob.printArray(arr);
        HeapSort ob1 = new HeapSort();
        double start = System.nanoTime();
        ob1.sort(arr);
        double end = System.nanoTime();
        System.out.print("\nSorted Array ===>");
        ob1.printArray(arr);
        System.out.println("\n Time taken for worst case = " + (end-start)/100000 + "ms");
        HeapSort ob2 = new HeapSort();
        System.out.println("\nTaking previously Sorted array for best Case.\n");
        start = System.nanoTime();
        ob2.sort(arr);
        end = System.nanoTime();
        System.out.print("\nSorted Array ===>");
        ob2.printArray(arr);
        System.out.println("\n Time taken for best case = " + (end-start)/100000 + "ms");
    }
}
