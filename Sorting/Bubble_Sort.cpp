/*
    Algorithm = Bubble Sort
    Complexity = O(n^2(n square))
    Author = Satyam
*/
//Including Header files
#include<iostream>

//Setting Std namespace
using namespace std;

//Main function started
int main()
{
    //Declaration and Initialization of variables
    int arr[20],n,temp;

    //Taking Input from user
    cout<<"Enter No. of Elements : ";
    cin>>n;
    cout<<"\nEnter Elements : \n";
    for(int i=1;i<=n;i++)
    {
        cout << i << ".) ";
        cin>>arr[i];
    }

    //Bubble Sort
    //Comparing each element with all other elements
    for(int p=1;p<=n-1;p++)
    {
        for(int j=1;j<=n-1;j++) //Loop runs till n-1 because last element is automatically sorted
        {
            if(arr[j]>arr[j+1])
                {
                    temp=arr[j]; //Interchanging values with a temporary variable
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
        }
    }
    //Displaying final results
    cout<<"\nAfter Sorting : \n";

    for(int i=1;i<=n;i++)
    {
    cout << arr[i] << "\t";
    }
    //For clean output
    cout << endl;

    return 0;
}
