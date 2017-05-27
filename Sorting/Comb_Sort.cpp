/*
    Algorithm = Comb Sort
    Complexity = O(n*n) in worst case and O(n) in average case
    Author = Satyam
*/
//Including header files
#include<iostream>
//Setting std namespace
using namespace std;

//getNextGap function to calculate the next gap for the next loop iteration in comb sort function
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;

    if (gap < 1)
        return 1;
    return gap;
}

//Comb sort function for sorting elements
void combSort(int arr[],int n){
    //Initialize gap
    int gap;
    gap = n;
    //Check if the numbers are already swapped or not
    bool swapped = true;

    //Loop for sorting
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;

        // Compare all elements with current gap
        for (int i=0; i<n-gap; i++)
        {
            if (arr[i] > arr[i+gap])
            {
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}
//Main function started
int main(){
    //Declaration and Initialization
    int n,arr[20];

    //Taking Input from user
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }

    //comb sort function called
    combSort(arr,n);

    //Output of sorted array
    cout << "Sorted elements are:"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}
