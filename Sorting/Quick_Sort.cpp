/*
    Algorithm = Quick Sort
    Complexity = O(nLogn) or O(n*n) in worst case
    Author = Satyam
*/
//Including header files
#include<iostream>

//Setting standard namespace
using namespace std;

//Function declaration
void swap(int* ,int*);
int partition(int[] ,int ,int );
void quickSort(int[], int , int );

//Main function started
int main(){
    //Initialization and Declaration of variables
    int n,arr[20];

    //Taking Input from user
    cout << "Enter the no. of elements = ";
    cin >> n;
    cout<<"\nEnter Elements : \n";
    for(int i=0;i<n;i++)
    {
        cout << i+1 << ".) ";
        cin>>arr[i];
        cout << endl;
    }

    //Calling the quickSort function
    quickSort(arr, 0, n-1);
    cout << "Sorted Elements are :\n";
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    return 0;
}

//Function Definitions Section

//Swap function
void swap(int *a,int *b){
     int t = *a; // swapping with a temp variable
    *a = *b;
    *b = t;
}

/*
    partition function started
    Steps of partitioning function
        i.) Select the pivot
        ii.)Place all the greater elements to right and smaller elements to left of pivot
        iii.) Repeat the quicksort function with left and right sub arrays
*/
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element(Initially set to 0)

    for (int j = low; j <= high- 1; j++) //For loop excluding the last element
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            // increment index of smaller element
            i++;
            /*
                Swap function called to swap the lower element
                and put that at the next location where the loop
                starts next time
            */
            swap(&arr[i], &arr[j]);

        }
    }
    /*  swap the last element with location i+1
        So that all the smaller elements are on the left side
        and all the greater elements are on the right side
    */
    swap(&arr[i + 1], &arr[high]);
    //return the pivot
    return (i + 1);
    //Hence the pivot is set
}

//Quick sort function started
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //pi variable contains the retuned pivot which is now at its exact place
        int pi = partition(arr, low, high);

        /*
            Now recursively call the quickSort function
            for the left and right sub arrays and place 2 more
            elements at the right position again partitioning the sub arrays
            and place all the elements at their exact position
        */
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
