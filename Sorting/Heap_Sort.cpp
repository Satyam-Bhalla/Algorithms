/*
    Algorithm = Heap Sort
    Complexity = O(nLogn)
    Author = Satyam
*/
//Including header files
#include <iostream>

//Setting std namespace
using namespace std;

/* To heapify a subtree rooted with node i
    Let us take an example suppose we have 10 elements
    then i = 10/2 - 1 --> i=4;
    then the left of 4 is 4*2+1 i.e 9 and right is 4*2+2 i.e 10
    We will solve these values first then for i=3; left=7,right=8 and so on.
*/
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest); //for inner elements of heap to make the max heap
    }
}

//Heap sort function
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Main program starting
int main()
{
    //Declaration and Initialization of variables
    int arr[20],n;

    //Taking Input from user
    cout<<"Enter No. of Elements : ";
    cin>>n;
    cout<<"\nEnter Elements : \n";
    for(int i=0;i<n;i++)
    {
        cout << i+1 << ".) ";
        cin>>arr[i];
    }

    //Calling heapSort function defined above
    heapSort(arr, n);

    //Showing output
    cout << "\nSorted array is \n";
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
