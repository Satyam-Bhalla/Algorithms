/*
    Algorithm = Pigeonhole Sort
    Complexity = O(n+range)
    Author = Satyam
*/
//Including header files
#include<iostream>
#include<vector>

//Setting standard namespace
using namespace std;

//Pigeonhole function definition
void pigeonholeSort(int arr[],int n){
    //Declaration and Initialization
    int min=arr[0],max=arr[0],range=0,index = 0;
    //Finding the minimum and maximumvalue for finding the range
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
        if(min > arr[i]){
            min = arr[i];
        }
    }
    //Finding range for the holes vector
    range = max-min+1;

    // Creating an array of vectors.Each vector represents a hole that
    // is going to contain matching elements.
    vector<int> holes[range];

    /*Traverse through input array and put every
     element in its respective hole
    */
    for (int i = 0; i < n; i++){
        holes[arr[i]-min].push_back(arr[i]);
    }

    /*  Traverse through all holes one by one.
        For every hole, take its elements and put in array.
    */
    for (int i = 0; i < range; i++)
    {
        //Using iterator for accessing the values from holes and putting them in arr[]
       vector<int>::iterator it;
       for (it = holes[i].begin(); it != holes[i].end(); ++it){
            arr[index++]  = *it;
       }

    }

}

//Main function started
int main(){
    //Declaration and Initialization
    int n,arr[20];

    //Taking input from user
    cout << "How many emts  you wat to enter = ";
    cin >> n;
    cout << "\nEnter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }

    //Calling the pigeonhole sort function for sorting
    pigeonholeSort(arr,n);

    //Showing output
    cout << "Sorted elements are:"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
