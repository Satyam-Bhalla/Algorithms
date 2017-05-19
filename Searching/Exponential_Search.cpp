/*
    Algorithm = Exponential Search
    Complexity = O(logn)
    Author = Satyam
*/
//Including header files
#include<iostream>

//Setting std namespace
using namespace std;

//Declaring binary serach function for later use
int binarySearch(int arr[], int, int, int);

//Exponential Search
int exponentialSearch(int arr[], int n, int element)
{
    // If element is present at firt location itself
    if (arr[0] == element)
        return 0;

    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= element)
        i = i*2;

    //  Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n), element);
    //returning the location from binary search
}


int binarySearch(int arr[], int l, int r, int element)
{
    //Right must be always greater then left
    if (r >= l)
    {
        //Calculating the mid term
        int mid = l + (r - l)/2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == element)
            return mid;

        // If element is smaller than mid, then it
        // can only be present n left subarray
        if (arr[mid] > element)//Recursive call to binary search to find the mid value
            return binarySearch(arr, l, mid-1, element);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, element);
    }

    // We reach here when element is not present in array
    return -1;
}


//Main function starts
int main(){
    //Declaration and Initialization of variables
    int n,arr[20],element;

    //Taking input from user
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "\nEnter the elements in sorted order:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
    }
    cout << "Enter the element to search = ";
    cin >>  element;

    //Calling the exponentialSearch function for checking the location
    int result = exponentialSearch(arr, n, element);
    if(result == -1){
        cout << "\nElement not found"<<endl;

    }else{
        cout << "\nElement found at location "<<result+1<<endl;
    }

     return 0;
}
