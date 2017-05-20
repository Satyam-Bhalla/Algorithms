/*
    Algorithm = Selection Sort
    Complexity = O(n^2(n square))
    Author = Satyam
*/
//Including Header files
#include<iostream>

//Setting std namespace
using namespace std;

//Main function starting
int main(){
    //Declaration and Initialization
    int n,arr[20],min=0,temp=0,loc=0;

    //taking input from user
    cout<<"Enter No. of Elements : ";
    cin>>n;
    cout<<"\nEnter Elements : \n";
    for(int i=0;i<n;i++)
    {
        cout << i+1 << ".) ";
        cin>>arr[i];
    }

    //Selection Sort
    //Upper for loop runs n-1 times because last element is sorted automatically
    for(int i=0;i<n-1;i++){
        //Assuming the ith element as the smallest element and compare with each element
        min = arr[i];
        loc = i;
        for(int j=i+1;j<n;j++){
            //If another minimum element is found then replace the value of min
            if(min>arr[j]){
                min = arr[j];
                loc = j;
            }
        }
        //Assigning the min value to 1st location
        temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;

    }
    //Output of sorted array
    cout << "\nSorted array is "<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << "\t";
    }
    //For clean output
    cout << endl;




    return 0;
}
