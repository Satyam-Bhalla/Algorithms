/*
    Algorithm = Interpolation Search
    Complexity =  O (log log n))
    Author = Satyam
*/
//Including header files
#include<iostream>

//Setting std namespace
using namespace std;

//Main program started
int main(){
    //Declaration and Initialization
    int n,arr[20],element;
    bool a= false;

    //Taking input from user
    cout << "Enter the number of elements you want to enter = ";
    cin >> n;

    //Entering elements in array
    cout << "\nEnter the numbers in sorted order:"<<endl;
    for (int i=0;i<n;i++){
        cout << i+1 << ".)\t";
        cin >> arr[i];
        cout << endl;
    }
    //Element to search
    cout << "Enter the element you want to search =";
    cin >> element;

    //Setting the starting and end point
    int start = 0, end = (n - 1);
    //Starting Interpolation its just like binary search but more precise
    while (start <= end && element >= arr[start] && element <= arr[end])
    {
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = start + (((double)(end-start) /
              (arr[end]-arr[start]))*(element - arr[start])); //Formula for interpolation search

        // If the element found at location
        if (arr[pos] == element){
            cout << "Element found at location "<<pos+1;
            a=true;
        }
        // If element is larger, element is in upper part
        if (arr[pos] < element)
            start = pos + 1;

        // If element is smaller, element is in lower part
        else
            end = pos - 1;
    }
    if(a==false){
        cout << "Element not found!!";
    }

    return 0;
}
