/*
    Algorithm = Merge Sort
    Complexity = O(nlogn)
    Author = Satyam
*/
//Adding Heafer files
#include<iostream>
//Setting std namespace
using namespace std;

/*  Merge function is used for merging the 2 final arrays
    First subarray is arr[l..m]
    Second subarray is arr[m+1..r]
*/
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;//getting the length of left and right sub arrays
    int n2 =  right - mid;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        /*  If value at index i of left sub array is less than or equal to the right
            arrays jth index then put the smaller value in arr[k] and increment i for next value
        */
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++; //Putting next value
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[] ,int left,int right){
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = left+(right-left)/2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        //Merging the two arrays
        merge(arr, l, m, r);
    }
}
//Main function starting
int main(){
    //Declaration and Initialization
    int n,arr[20];

    //Taking input from user
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "\nEnter the elements"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }
    //Calling the merge sort function defined above
    mergeSort(arr, 0, n - 1);

    //outputing the sorted data
    cout << "After Sorting" <<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}
