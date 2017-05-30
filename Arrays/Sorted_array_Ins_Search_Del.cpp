/*
    Menu driven program for searching,insertion and deletion of elements in a sorted array.
    Author = Satyam
*/
//Including header files
#include<iostream>
#include<cstdlib>
//Setting standard namespace
using namespace std;
//Binary search function definition
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high)/2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid -1), key);
}

//Main function started
int main(){
    //Declaration and Initilaization
    int n,arr[20],choice,element,mid,beg,end;

    //Taking input from user
    cout << "How many elements do you want to enter?"<<endl;
    cin >> n;
    cout << "Enter the elements in sorted order:"<<endl;
    for(int i=1;i<=n;i++){
        cout << i << ".) ";
        cin >> arr[i];
    }

    //Infinite loop to perform search,insert and delete operations according to the user
    while(true){
        cout << "\n\n====================================="<<endl;
        cout << "Press 1 for searching"<<endl;
        cout << "Press 2 for insertion"<<endl;
        cout << "Press 3 for deletion"<<endl;
        cout << "Press 4 to view array"<<endl;
        cout << "Press 5 to exit"<<endl;
        cout << "====================================="<<endl;

        cout << "\nEnter your choice =";
        cin >> choice;

        //choice to perform the specific operation
        switch(choice)
        {
        case 1:
            cout << "Enter the element to search = ";
            cin >> element;
            beg=1;
            end=n;
            mid = binarySearch(arr,beg,end,element);

            //Check for availability of data
            if(arr[mid]==element)
            {
                cout<<"\nElement found at location : "<<mid<<endl;
            }
            else
            {
                cout<<"Element not found";
            }
            break;
        case 2://Insertion of an element
            cout << "Enter the element you want to insert = ";
            cin >> element;
            int i;//Insert element in such a way that all the right elements are greater and left elements are smaller
            for (i=n; (arr[i] > element && i >= 0); i--){
                arr[i+1] = arr[i];
            }
            arr[i+1] = element;
            cout << "Element inserted at location ="<<i+1;
            //Increment the value of n
            n=n+1;
            break;
        case 3:
            cout << "Enter the element you want to delete = ";
            cin >> element;
            beg=1;
            end=n;
            //find the mid location for deletion
            mid = binarySearch(arr,beg,end,element);
            if(mid == -1){
                cout << "\nElement not found!"<<endl;
                break;
            }else{
                    for (int i=mid; i<=n; i++){
                            arr[i] = arr[i+1];//Deleting ith element
                    }
                    cout << "Element deleted successfully!"<<endl;
                    //Decrement n
                    n=n-1;
               }
            break;
        case 4:
            for(int i=1;i<=n;i++){
                cout << arr[i] << " ";//Printing the array
            }
            break;
        case 5:
            exit(1);
        }
    }
    return 0;
}
