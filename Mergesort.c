#include <stdio.h>
#include <stdlib.h>

// L = List of elements
/* It follows the Divide and Conquer approach. 
It works by recursively dividing the input array into two halves, 
recursively sorting the two halves 
and finally merging them back together to obtain the sorted array.*/


// Start = l
// Mid   = m
// End   = r
void Merge(int L[], int start, int mid, int end);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);


//############# Main #############//
int main(void){
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9, };
  int L_size = sizeof(L) / sizeof(L[0]);

  printf("\nGiven list: \n");
  printList(L, L_size);

  MergeSort(L, 0, L_size - 1);

  printf("The sorted list: \n");
  printList(L, L_size);
  return 0;
}


//############# Merge #############//
//             L          l         m        r
void Merge(int L[], int start, int mid, int end){
   int i;     // Position i venstre array L1.
   int j;     // Position i højre array L1.
   int k;     // Position i det originale array L.

  int n1 = mid - start + 1; // Venstre side.
  int n2 = end - mid;       // Højre side.

  int L1[n1], L2[n2]; // Midlertidige arrays.

// Kopier data til de midlertidige arrays.
  for (i = 0; i < n1; i++)
        L1[i] = L[start + i];

  for (j = 0; j < n2; j++)
        L2[j] = L[mid + 1 + j];

//Resetter dem:
  i = 0; j = 0; k = start;

// FORSTÅ DETTE: Merge the temporary arrays back into arr[left..right]
  while (i < n1 && j < n2){ 
    if(L1[i] <= L2[j]){
      L[k] = L1[i];
        i++; 
    } 
    else {
      L[k] = L2[j];
        j++;
    }
    k++;
  }
  // FORSTÅ DETTE: Copy the remaining elements of leftArr[], if any
  while (i < n1) {
    L[k] = L1[i];
      i++;
      k++;
  } 
  // FORSTÅ DETTE: Copy the remaining elements of rightArr[], if any
  while (j < n2) {
      L[k] = L2[j];
        j++;
        k++;
  }
}



//############# Mergesort #############//
//                 L          l         r
void MergeSort(int L[], int start, int end){
  if(start < end){
     int mid = (end+start)/2;
     MergeSort(L, start, mid);
     MergeSort(L, mid + 1, end);

     Merge(L, start, mid, end);
  }
}


//############# Printlist #############//
void printList(int L[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", L[i]);
  printf("\n");
}