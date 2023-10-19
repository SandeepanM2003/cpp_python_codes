#include <iostream>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a valid number of elements." << std::endl;
        return 1;
    }

    int arr[n];

    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    selectionSort(arr, n);

    std::cout << "Sorted array in ascending order:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
