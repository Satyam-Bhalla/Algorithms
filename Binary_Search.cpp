/*Binary search algo to search all the elements linearly
    Author =  Satyam
    Complexity = O(Log(n))
*/
//Adding Header files
#include<iostream>

//Setting std namespace
using namespace std;

//Starting main function
int main(){
    //Declaring variables
    int n,arr[20],item,beg,mid,end;

    //Entering numbers in array in sorted order
    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "\nEnter the numbers in sorted order:"<<endl;
    for (int i=0;i<n;i++){
        cout << i+1 << ".)\t";
        cin >> arr[i];
        cout << endl;
    }

    //Binary search
    cout<<"\nEnter Item you want to Search= ";
    cin>>item;
    beg=1;
    end=n;
    mid=(beg+end)/2;
    // Find Mid Location of Array
    while(beg<=end && arr[mid]!=item)// Compare Item and Value of Mid
        {
        if(arr[mid]<item)
            beg=mid+1; //If the element is greater then the mid value of array
                       // then set beg to mid + 1 so that half elements are ignored
        else
            end=mid-1;

        mid=(beg+end)/2;
        }

        //Check for availability of data
        if(arr[mid]==item)
            {
            cout<<"\nData is Found at Location : "<<mid+1<<endl;
            }
        else
            {
            cout<<"Data is Not Found";
            }

 return 0;
}

