/*
    Algorithm = Radix Sort
    Complexity = O(n+k) in worst case
    Author = Satyam
*/
//Including Header files
#include<iostream>

//Setting std namespace
using namespace std;

//Max function to get the maximum value of array
int Max(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

//Count sort function to Place the values in correct order

void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = Max(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main(){
    int n,arr[20];
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "\nEnter the elements:\n";
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }
    radixSort(arr,n);
    cout << "Sorted array is:"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}
