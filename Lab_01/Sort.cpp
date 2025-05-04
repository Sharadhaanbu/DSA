#include <cstdio>

// Function prototypes
int bubbleSort(int arr[], int n);
int selectionSort(int arr[], int n);
int insertionSort(int arr[], int n);
int displayArray(const int arr[], int n);

// Main function
int main() {
    int n, option;
    
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
    
    printf("\nMenu:\n 1. Bubble Sort\n 2. Selection Sort\n 3. Insertion Sort\n 4. Exit\n");
    
    do {
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                bubbleSort(arr, n);
                printf("Sorted array using Bubble Sort: ");
                displayArray(arr, n);
                break;
            case 2:
                selectionSort(arr, n);
                printf("Sorted array using Selection Sort: ");
                displayArray(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                printf("Sorted array using Insertion Sort: ");
                displayArray(arr, n);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (option != 4);
    
    return 0;
}

// Bubble Sort Function
int bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

// Selection Sort Function
int selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    return 0;
}

// Insertion Sort Function
int insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0;
}

// Function to display the array
int displayArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}