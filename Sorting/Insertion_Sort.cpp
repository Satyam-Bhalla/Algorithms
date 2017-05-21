/*
    Algorithm = Insertion Sort
    Complexity = O(n*n)
    Author = Satyam
*/
//Adding header files
#include<iostream>
//Setting std namespace
using namespace std;
//Defining insertion sort function for sorting
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++) //This loop runs in the forward direction by taking a single elements
   {
       key = arr[i];
       j = i-1;

       /* This while loops runs from back to front by checking
        and comparing the jth element with elements j-1,j-2....1*/
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j]; //Placing the higher value at j+1 position
           j = j-1;//Comparing with each left value
       }

       arr[j+1] = key; //Updating the next value
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
    //Calling the insertionSort function defined above
    insertionSort(arr,n);
    //Showing Output
    cout << "\nSorted values are\n";
    for(int i=0;i<n;i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}
