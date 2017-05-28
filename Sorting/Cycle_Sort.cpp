/*
    Algorithm = Cycle Sort
    Complexity = O(n*n)
    Author = Satyam
*/
//Including header files
#include<iostream>

//Settig std namespace
using namespace std;

/*  cycle sort function definition
    This sorting algo is used only where
    the number of memory wites are very costly.
*/
void cycleSort(int arr[],int n){
     // count number of memory writes
    int writes = 0;

    // traverse array elements and put it to on the right place
    for (int cycle_start=0; cycle_start<=n-2; cycle_start++)
    {
        // initialize item as starting point
        int item = arr[cycle_start];

        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cycle_start;
        for (int i = cycle_start+1; i<n; i++)
            if (arr[i] < item)
                pos++;

        // If item is already in correct position
        if (pos == cycle_start)
            continue;

        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;

        // put the item to it's right position
        if (pos != cycle_start)
        {
            swap(item, arr[pos]);
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start+1; i<n; i++)
                if (arr[i] < item)
                    pos += 1;

            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;

            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
    cout << "Number of memory writes or swaps = "<<writes<<endl;

}
//Main function started
int main(){
    //Declarationa and Initialization
    int n,arr[20];

    //Taking input from user
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "\nEnter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }

    //Calling cycle sort function
    cycleSort(arr,n);

    //Showing output
    cout << "\nSorted elements are:\n";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
