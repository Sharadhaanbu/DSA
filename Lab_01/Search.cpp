#include <cstdio>
#include "sort.h"

// Function Prototypes
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int n, int target);
void displayArray(int arr[], int n);

// Main Function
int main() {
    int n, option, target;
    
    // Input number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nMenu:\n 1. Linear Search\n 2. Binary Search\n 3. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the element to search for: ");
                scanf("%d", &target);
                {
                    int index = linearSearch(arr, n, target);
                    if (index != -1) {
                        printf("Element found at index %d\n", index);
                    } else {
                        printf("Element not found!\n");
                    }
                }
                break;
            case 2:
                printf("Enter the element to search for: ");
                scanf("%d", &target);
                
                bubbleSort(arr[], n); //calling function from header file 
                printf("Array sorted: ");
                displayArray(arr, n);
                
                {
                    int index = binarySearch(arr, n, target);
                    if (index != -1) {
                        printf("Element found at index %d\n", index);
                    } else {
                        printf("Element not found!\n");
                    }
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (option != 3);
    
    return 0;
}

// Linear Search Function
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;
}

// Binary Search Function (Assumes the array is sorted)
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Return index if found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Display Array Function
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}