#include <bits/stdc++.h>
using namespace std;


long long getMax(long long arr[], int n) {//find the max of the array
    long long max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


void countSort(long long arr[], int n, long long exp) {//counting sort being done based on the exp of the element of the array
    const long long RADIX = 10;
    long long output[n];
    long long count[RADIX] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % RADIX]++;
    }

    for (int i = 1; i < RADIX; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}


void radixSort(long long arr[], int n) {//the actual radix sort function
    long long max = getMax(arr, n);

    for (long long exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    int n;
    cin >> n;
    long long arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
