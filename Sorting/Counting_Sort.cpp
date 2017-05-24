/*
    Algorithm = Counting Sort
    Complexity = O(n)
    Author = Satyam
*/
//Including header files
#include<iostream>
//Setting std namespace
using namespace std;

//Defining countingSort function
void countingSort(int *arr, int length) {
    int i, j, k; //Declaration of variables

    //If value of array is greater then 100 then return
    for (i = 0; i < length; i++) {
      if (arr[i] >= 100) {
        return;
      }
    }
    //Dynamically initialize arrays for less consumption of memory
    int *count_arr = new int[100]();
    int *sorted_arr = new int[length]();

    //Increment the index present at position arr[i]
    //This means if arr[i] == 2 then increment count_arr[2]
    //To check multiple instances of a value
    for (i = 0; i < length; i++) {
      count_arr[arr[i]]++;
    }

    /*  Example of counting sort
        arr = 5, 4, 1, 12, 1, 4, 1
        count_arr indexes-> 00 01 02 03 04 05 06 07 08 09 10 11 12 13
        count_arr values->   0  3  0  0  2  1  0  0  0  0  0  0  1
    */

    //  0  3  3  3  5  6  6  6  6  6  6  6  7
    //To check multiple instances
    for (k = 1; k < 100; k++) {
      count_arr[k] += count_arr[k-1];
    }

    //Setting the sorted array
    for (j = length; j > 0; j--) {
        //Solving the innermost array first
        //If at the jth location we have an element 18 then
        //we will store this value at 17th location because starting index is 0
        sorted_arr[count_arr[arr[j-1]]-1] = arr[j-1];
      // this is important
      count_arr[arr[j-1]]--;
    }
    //Storing result back in arr
    for (j = 0; j < length; j++) {
      arr[j] = sorted_arr[j];
    }

    //Clearing the memory
    delete[] count_arr;
    delete[] sorted_arr;
}
//Starting main function
int main(){
    int n,arr[20];
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "\nEnter Elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }
    //Calling countingSort function
    countingSort(arr,n);

    //Showing output
    cout << "Sorted array is: "<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
    return 0;
}
