/*
    Menu driven program for searching,insertion and deletion of elements in an unsorted array.
    Author = Satyam
*/
//Including header files
#include<iostream>
#include<cstdlib>
//Setting standard namespace
using namespace std;

//Main function started
int main(){
    //Declaration and Initilaization
    int n,arr[20],choice,element,pos=0;

    //Taking input from user
    cout << "How many elements do you want to enter?"<<endl;
    cin >> n;
    cout << "Enter the elements in array:"<<endl;
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
            for(int i=1;i<=n;i++){
                if(arr[i] == element){
                    pos = i;
                    cout << "Element found at location = " <<i;
                }
            }
             if(pos==0){
                    cout << "Element not found";
            }
            break;
        case 2:
            cout << "Enter the element you want to insert = ";
            cin >> element;
            n= n+1;//Increasing the length of the array by 1 to insert the element at that place
            arr[n] = element;
            cout << "Element inserted at location ="<<n;
            break;
        case 3:
            cout << "Enter the element you want to delete = ";
            cin >> element;
            for(int i=1;i<=n;i++){
                if(arr[i]==element){
                    pos=i;//If the position to delete element is found
                    if(pos!=0){
                            //Override all the elements from that position to n for deletion
                          for(int i=pos;i<n;i++){
                            arr[i] = arr[i+1];
                        }
                        cout << "Element deleted successfully";
                        n=n-1;//Decrement n by 1
                    }
                }
            }

            if(pos==0){
                cout << "\nElement not found!"<<endl;
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
