#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Develop a C program to sort the given names using array of pointers.


// Function to sort names using an array of pointers
void sortNames(char *names[], int n) {
    char *temp;
    
    // Simple Bubble Sort algorithm to sort names alphabetically
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the pointers if they are in the wrong order
                temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int n;
    
    // Input number of names
    printf("Enter the number of names: ");
    scanf("%d", &n);
    
    // Allocate memory for the array of pointers
    char *names[n];
    
    // Clear the input buffer
    while (getchar() != '\n');
    
    // Input names
    printf("Enter the names:\n");
    for (int i = 0; i < n; i++) {
        char buffer[100];
        printf("Name %d: ", i + 1);
        gets(buffer);  // Use gets to read input (unsafe, but per request)
        
        // Allocate memory for each name and copy the input
        names[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (names[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        strcpy(names[i], buffer);
    }
    
    // Sort the names
    sortNames(names, n);
    
    // Display the sorted names
    printf("\nSorted Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
        free(names[i]);  // Free the allocated memory
    }
    
    return 0;
}
