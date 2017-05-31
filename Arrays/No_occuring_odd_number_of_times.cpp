/*
    Program = To Check which number is occuring odd number of times in an array containing 1 odd
              times occuring element.
    Author = Satyam
*/
//Including header files
#include<iostream>

//Setting std namespace
using namespace std;

//Function to check the number occuring odd number of imes
int checkOddOccurences(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        // By using XOR operation we can find the element
        res = res ^ arr[i];
    }

    return res;
}

  /*
        Example suppose we have an array with elements arr[2,3,4,5,3,2,4]
           i.)  when we do XOR operation with its 1st element then res becomes 2
           ii.) when 2 is XORed with 3 answer becomes 1
           iii.)when 1 is XORed with 4 answer becomes 5
           iv.) when 5 is XORed with 5 answer becomes 0
           v.)  when 0 is XORed with 3 answer becomes 3
           vi.) when 3 is XORed with 2 answer becomes 1
           vii.)when 1 is XORed with 4 answer becomes 5
           which is the odd time occuring element in an array
    */

//Main function started
int main(){
    //Initialization and Declaration
    int n,arr[20];
    //Taking Input from user
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
    }
    //Calling the checkOddOccurences function and storing result  in result variable
    int result = checkOddOccurences(arr,n);

    //Showing output
    cout << "\nOdd times occuring element is = "<< result;
    return 0;
}
