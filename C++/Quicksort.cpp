#include <iostream>
#include <vector>

// Function to partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the rightmost element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            std::swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at index i+1 (putting it in the correct position)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);  // Return the pivot index
}

// Quicksort function
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        arr.push_back(element);
    }

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    int arraySize = arr.size();
    quicksort(arr, 0, arraySize - 1);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
