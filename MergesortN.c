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
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
  int L_size = sizeof(L) / sizeof(L[0]);

  printf("\nGiven list: \n");
  printList(L, L_size);

  MergeSort(L, 0, L_size - 1); //0 og L_size anses senere som L, start og end.

  printf("The sorted list: \n");
  printList(L, L_size);
  return 0;
}


//############# Merge #############//
//             L          l         m        r
void Merge(int L[], int start, int mid, int end){
   int i;     // Position i venstre midlertidige array L1.
   int j;     // Position i højre midlertidige array L2.
   int k;     // Position i det originale array L. (hvor vi skriver næste element)

  int n1 = mid - start + 1; // Antallet af elementer i venstre del.
  int n2 = end - mid;       // Antallet af elementer i højre del.

  int L1[n1], L2[n2]; // Midlertidige arrays, med elementerne fra hver halvdel

// Kopier data til de midlertidige arrays - 
//F.eks. først L1 = [5] L2 = [3]
  for (i = 0; i < n1; i++)
        L1[i] = L[start + i];

  for (j = 0; j < n2; j++)
        L2[j] = L[mid + 1 + j];

//Resetter dem:
  i = 0; j = 0; k = start;

// Her sammenlignes L1 og L2 for at se hvilken af dem er mindst, og skal skrives ind i L[k].
// Derefter tæller vi enten i eller j op, altefter hvilken side var mindst, og går videre til næste index i listen L, ved at tælle k op.
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
  // Når sammenligningen mellem L1 og L2 er færdige, kan der opstå et tomt array og et stadig med 1 værdi resterende.
  // De resterende elementer kan kopieres direkte, fordi de to del-arrays allerede er sorterede.
  while (i < n1) {
    L[k] = L1[i];
      i++;
      k++;
  } 

  while (j < n2) {
      L[k] = L2[j];
        j++;
        k++;
  }
}


//############# Mergesort #############//
 // Mergesort er en rekursiv algoritme: den kalder først en base case og derefter kalder den sig selv på mindre dele af arrayet. 
   //(BASE CASE: Hvis sub-arrayet kun har 0 eller 1 element, gør den ingenting).
 // Hvis der er flere elementer, deler MergeSort arrayet i to halvdele ved at beregne midtpunktet.

 // Derefter kaldes MergeSort(L, start, mid);  rekursivt på venstre halvdel. 
 // Denne deling fortsætter, indtil venstre side er splittet helt ned til 2 sub-arrays på størrelse 1.
 // Da base case er nået, og if(start < end) er falsk, returnerer den uden at gøre noget, og går videre til MergeSort(L, mid + 1, end);
 // Denne deling fortsætter, indtil denne del også er splittet helt ned til 2 sub-arrays på størrelse 1.

 // Når 2 subarrays af størrelse 1 er "sorteret",  kører Merge funktionen på de 2 subarrays i venstre side: 
 // L = [5, 3, 8, 1, 6],            [10, 7, 2, 4, 9] -> 
 // L = [5, 3, 8], [1, 6],          [10, 7, 2, 4, 9] ->
 // L = [5, 3], [8], [1, 6],        [10, 7, 2, 4, 9] ->
 // L = [5], [3], [8], [1, 6],      [10, 7, 2, 4, 9] ->
 // L = [3, 5], [8], [1, 6],        [10, 7, 2, 4, 9] ->
 // L = [3, 5, 8], [1, 6],          [10, 7, 2, 4, 9] ->
 // L = [3, 5, 8], [1], [6],        [10, 7, 2, 4, 9] ->
 // L = [3, 5, 8], [1, 6],          [10, 7, 2, 4, 9] ->
 // L = [1, 3, 5, 6, 8],            [10, 7, 2, 4, 9] ->

 // Når venstre side er sorteret, kaldes mergesort og merge nu igennem den anden halvdel, på præcis samme måde.
 // ...
 // L = [1, 3, 5, 6, 8,],        [2, 4, 7, 9, 10]
 // Listen L = [1, 3, 5, 6, 8, 2, 4, 7, 9, 10] køres nu igennem merge funktionen en sidste gang, så vi ender med en sorterede liste 
 
//                 L          l         r
void MergeSort(int L[], int start, int end){
  if(start < end){                    // Stopper hvis listen eller sublisten har 0 eller 1 elementer. 
     int mid = (end+start)/2;        // Udregner midtpunktet.
     MergeSort(L, start, mid);      // Sortérer venstre halvdel.
     MergeSort(L, mid + 1, end);   // Sortérer højre halvdel.
     Merge(L, start, mid, end);   // Merger to allerede sorterede del-lister til én samlet sorteret sektion af arrayet.
  }
}


//############# Printlist #############//
void printList(int L[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", L[i]);
  printf("\n");
}


/* Visual representation of the code:
1. MergeSort(0,9)           // mid=4

  2. MergeSort(0,4)         // mid=2   (LEFT SUBTREE of top)
    3. MergeSort(0,2)       // mid=1
      4. MergeSort(0,1)     // mid=0
        5. MergeSort(0,0)   // base -> returns
        6. MergeSort(1,1)   // base -> returns
        7. → Merge(0,0,1)   // merges [5] & [3] -> [3,5]
      8. MergeSort(2,2)     // base -> returns
      9. → Merge(0,1,2)     // merges [3,5] & [8] -> [3,5,8]
    10. MergeSort(3,4)      // mid=3
      11. MergeSort(3,3)    // base -> returns
      12. MergeSort(4,4)    // base -> returns
      13. → Merge(3,3,4)    // merges [1] & [6] -> [1,6]
    14. → Merge(0,2,4)      // merges [3,5,8] & [1,6] -> [1,3,5,6,8]

  15. MergeSort(5,9)        // mid=7  (RIGHT SUBTREE of top) — starts only now
    16. MergeSort(5,7)      // mid=6
      17. MergeSort(5,6)    // mid=5
        18. MergeSort(5,5)
        19. MergeSort(6,6)
        20. → Merge(5,5,6)  // merges [10] & [7] -> [7,10]
      21. MergeSort(7,7)
      22. → Merge(5,6,7)    // merges [7,10] & [2] -> [2,7,10]
    23. MergeSort(8,9)      // mid=8
      24. MergeSort(8,8)
      25. MergeSort(9,9)
      26. → Merge(8,8,9)    // merges [4] & [9] -> [4,9]
    27. → Merge(5,7,9)      // merges [2,7,10] & [4,9] -> [2,4,7,9,10]
  28. → Merge(0,4,9)        // final merge: [1,3,5,6,8] & [2,4,7,9,10] -> sorted array
*/