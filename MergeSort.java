import java.util.*;
class MergeSort{
    double number_of_merge_calls = 0;
    void merge(double arr[], int l, int m, int r){
        number_of_merge_calls++;
        int n1 = m - l + 1;
        int n2 = r - m;
        double L[] = new double [n1];
        double R[] = new double [n2];
        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2){
            if (L[i] >= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void sort(double arr[], int l, int r){
        if (l < r){
            int m = (l+r)/2;
            sort(arr, l, m);
            sort(arr , m+1, r);
            merge(arr, l, m, r);
        }
    }
    static void printArray(double arr[]){
        int n = arr.length;
        for (int i=0; i<n; ++i)
        System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]){
        MergeSort ob = new  MergeSort();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Elements : ");
        int n = sc.nextInt  ();
        double arr[] = new double[n];

        Random r = new Random();
        for(int i = 0; i<n; i++){

            arr[i] = r.nextDouble   ();
        }
        System.out.print("\nEntered Array ===>");
        ob.printArray(arr);
        MergeSort ob1 = new  MergeSort();
        double start = System.nanoTime();
        ob1.sort(arr,0,n-1);
        double end = System.nanoTime();
        System.out.print("\nSorted Array ===>");
        ob1.printArray(arr);
        System.out.println("\nNumber of Merge Calls = " + ob1.number_of_merge_calls);
        System.out.println("\n Time taken = " + (end-start)/100000 + "ms");
    }
}
