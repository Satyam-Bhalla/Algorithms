/*
    Algorithmm = Shell Sort
    Complexity = O(n*n)
    Author = Satyam
*/
//Including Header files
#include<iostream>

//Setting std namespace
using namespace std;

//Shell sort function definition
void shellSort(int arr[],int n){
      // Start with a big gap, then reduce the gap
      // Decrease the gap by half elements each time
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        /*
            Select a gap to move forward until the
            selected index is less then n.
        */
        for (int i = gap; i < n; i += 1)
        {
            //From the gap element go towards right side
            //Then sort all the elements
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            //Move from right to left to check that all the left elements are in sorted order
            // shift earlier gap-sorted elements up until the correct location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

//Main function started
int main(){
    //Declaration and Initialization
    int n,arr[20];

    //Taking input from user
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout <<i+1<< ".) ";
        cin >> arr[i];
    }
    //calling shell sort function
    shellSort(arr,n);

    //Showing Output
    cout << "Sorted elements are:"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
