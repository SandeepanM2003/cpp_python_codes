
// Method 1
// #include<iostream>
// using namespace std;

// int main()
// {   int arr[] ={1,3,5,7,9};
//     for(int i=4; i>=0; i--)
//     {
//         cout<<arr[i];
//     }
//     return 0;
// }

//Method 2
#include<iostream>
using namespace std;

int main()
{   int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}


// Adding Method 3 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        // Swap the elements at left and right indices
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        // Move the indices towards each other
        left++;
        right--;
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
