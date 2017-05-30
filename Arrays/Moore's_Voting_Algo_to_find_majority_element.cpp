/*
    Program = Find the majority element from an array
    Author = Satyam
    Description = I have used Moore's voting algo here to find the majority element.
                  Majority element is basically the element that occurs more than n/2 times
                  if the array is of size n.Moore's voting algo has 2 steps:
                    i.) Find the majority element
                    ii.) Check whether the selected element is the majority element or not
*/
//Including header file
#include<iostream>

//Setting std namespace
using namespace std;

//find candidate function is used for the 1st step of Moore's voting algo
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    int i;
    for (i = 1; i < size; i++)
    {
        //Checking the 2 elements to see if the next element is same as the previous one then increment the count
        if (a[maj_index] == a[i])
            count++;
        else//Decrement the count
            count--;
        if (count == 0)
        {//If count is 0 then select the current value of array[i] and set maj_index to i
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index]; //Return the major index value
}
/* Function to check if the candidate occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int i, count = 0;
    for (i = 0; i < size; i++){
      if (a[i] == cand){
        count++;
      }
    }
    if (count > size/2)
       return 1;
    else
       return 0;
}

//Main function started
int main(){
    int n,arr[20];
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> arr[i];
        cout << endl;
    }
    int result = findCandidate(arr,n);
    //Pass the result to the isMajority function to check whether the selected element have the major occurences
    if (isMajority(arr, n, result)){
        cout << "The majority element is = " << result << endl;
    }
    else{
        cout << "\nNo majority element!"<<endl;
    }

    return 0;
}
