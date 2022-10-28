
// C++ Code for Comb Sort
/*The process of performing the comb sort is given as follows -

STEP 1 START

STEP 2 Calculate the gap value if gap value==1 goto step 5 else goto step 3

STEP 3 Iterate over data set and compare each item with gap item then goto step 4.

STEP 4 Swap the element if require else goto step 2

STEP 5 Print the sorted array.

STEP 6 STOP
 */
#include <iostream>
using namespace std;
// function to update gap value
int updateGap(int gap)
{
// Shrink gap by the shrink factor
  gap = (gap * 10) / 13;
  if (gap < 1)
    return 1;
  else
    return gap;
}
// Function to sort arr[] using Comb Sort
void combSort(int arr[], int n)
{
  // initialize gap
  int gap = n;
  // Initialize swapped as true to make sure that the loop runs
  bool swapped = true;
  while (gap > 1 || swapped == true)
  {
    // Update gap value
    gap = updateGap(gap);
    swapped = false;
    // Compare all elements with current gap
    for (int i = 0; i < (n - gap); i++)
    {
      int temp;
      if (arr[i] > arr[i + gap])
      {
        // Swap arr[i] and arr[i+gap]
        temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        swapped = true;
      }
    }
  }
}
// Driver function
int main() {
  int arr[10] = {6, 2, 1, 83, 4, -20, 25, -4, 27, 0};
  int n = 10;
  combSort(arr, n);
  cout << "Sorted array" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

