/*
    Program = To find the maximum continuous sum in an array
    Algorithm Used = Kadane's Algorithm
    Author = Satyam
*/
//Including Header files
#include<iostream>

//Setting Standard namespace
using namespace std;

//Find the max sum and elements function definition
int findMaxSum(int arr[],int n){
    //Initialization and declaration
    int max_so_far = 0, max_ending_here = 0,start =0, end = 0, s=0;

    for (int i=0; i< n; i++ )
    {
        //max_ending_here gives the upper bound where the last maximum sum element is present
        max_ending_here += arr[i];

        if (max_so_far < max_ending_here)
        {
            //Finding the max_so_far element which gives the starting point or lower bound
            //Of the array where the 1st largest +ve number is stored
            max_so_far = max_ending_here;
            //Setting start and end
            start = s;
            end = i;
        }
        //if the max_ending element or the upper bound is smaller then 0 then make the max_ending
        //variable to zero
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i+1;//Incrementing S
        }
    }
    //Showing the output
    cout << "Maximum contiguous sum is "
        << max_so_far << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}
//Main function definition
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
    findMaxSum(arr,n);

    return 0;
}
