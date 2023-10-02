// Question Link -  https://www.codingninjas.com/studio/problems/bubble-sort_624380

void bubbleSort(int arr[], int n)
{
    // write your code here
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}