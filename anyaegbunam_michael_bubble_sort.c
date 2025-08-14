// Program Name: Bubble Sort
// Author: Michael Anyaegbunam
// Description: The bubble sort algorithm is a common approach in sorting an array of numbers based on their quantity. In this case, the use of pointers, loops and functions will be utilized.
// There may be notes to myself scattered along this code. 




#include <stdio.h>

//Function Declaration =
void bubble_sort(int array[10], int n, int *min, int *max) // array of 10 bytes, "n" as an integer, a pointer to min and a pointer to max.

int main() {
   int array[10], min, max;
   int i;

   printf("Please Enter Number: ");

   for (i = 0; i < 10; i++) {
    printf("Number %d: ", i + 1);
    scanf("%d", &array[i]);
}

    bubble_sort(array, 10, &min, &max);
   
    printf("Bubble Sort: ");
    for (int i = 0; i < 10; i++) {
        printf("%d",  array[i]);
    } 


   
    printf("\nSmallest: %d, Largest: %d\n", min, max);

    return 0;
}

// reminder: DO NOT return any values.
void bubble_sort(int array[10], int n, int *min, int *max) {
    int temp;  //Performing a bubble sort without a temporary variable is tedious, especially in python. let us avoid this here.


    for (; n > 1; n--) {
        for (int i = 0; i < n - 1; i++) {
            if (array[i] > array[i + 1]) {

                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }

        }
    }

        
    *min =  array[0]; //pointers are defined here
    *max = array[9];
     
   // For now, ignore int min and max 

}

