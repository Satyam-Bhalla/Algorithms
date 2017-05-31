/*
    Program = To find the missing element in a seris having sequential numbers
    Author =  Satyam
*/
//Adding header files
#include<iostream>

//Setting std namespace
using namespace std;

//Defining the findMissingNum function to get the output
void findMissingNum(int arr[],int n){
    int total;
    //Find the max possible sum that an array cann have with n values
    total = ((n+1)*(n+2))/2;
    //Decrementing the total with the arr[i] position so that the last element in the total is
    //the missing number
    for(int i=0;i<n;i++){
        total -= arr[i];
    }

    cout << "The missing element is = " << total << endl;
}

//Main function started
int main(){
     //Declaration of variables
    int n,arr[20];

    //Taking input from user
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }

    //Calling the findMaxSum function
    findMissingNum(arr,n);

    return 0;
}
