//String Reversal
// Author: Michael Anyaegbunam
// The user will be prompted to input a string and the program will reverse it's contents.


#include <string.h>
#include <stdio.h>


void reverseString(char *str);

int main(void) {

    
    char string[1000];
     //Im Sure these are generous bit limits....
    
    printf("Enter a string: ");
    scanf("%s", string);

    // call reverseString here.. 
    reverseString(string);


    //print string...

    printf("Reversed string: %s\n", string);
  


    return 0;
}

void reverseString(char *str) {
    if (*str == '\0') {
        return;        //checks if string is empty, program will return null.
    }
    
    int length = strlen(str); //length is determined with helper function from imported directive
    char *begin = str;  //the beginning is the string
    char *end = str + length - 1;  //the end is it's length minus 1 to compensate for a null character

    while (begin < end) {
        char temp = *begin; //The temporary variable is the beginning
        *begin = *end; //the beginning reaches the end
        *end = temp; //the end meets the temp

        begin++;
        end--;   //Here, both pointers are moved to the middle of the array 
    }
    //This is very similar to the Rabbit and Tortise algorithm in linked lists
}



void swap(char *left, char *right) { //Similar implementation here.
    char temp = *left;
    *left = *right;
    *right = temp;

}






