/*
    Algorithm = Jump Search
    Complexity = O(√n)
    Author = Satyam

*/
//Including Header files
#include<iostream>
#include<cmath>

//Setting std namespace
using namespace std;

//Starting main function
int main(){
    //Declaration and Initialization
    int n,arr[20],jump=0,start=0,j=0,element;
    bool a=false;

    //Taking Input from user
    cout << "How many numbers do you want to enter = ";
    cin >> n;
    cout << "\nEnter the elements in sorted order:"<<endl;

    //Entering elements in array
    for(int i=0;i<n;i++){
        cout << endl << i+1 << ".) ";
        cin >>arr[i];
    }

    //Setting the jump variable
    jump = sqrt(n); //Jump variable is equal to the squareroot of the total number of items

    //Element to search
    cout<< "Enter the element to search = ";
    cin >> element;

    //Initializing J for the loop jumps
    j = jump;


    for(int i=0;i<j;i++){
        /*
            If the element is greater than the 1st jump value
            Suppose the jump is 2
            then the element will be checked against the value arr[2]
        */
        if(element > arr[j]){
            i=j;
            j=i+jump;
        }

        /*
            If the element is found at the jump place
            i.e element is found at location 2
        */
        if(element == arr[j] || a == true){
            cout << "\nElement found at location "<<j;
            break;
        }

        /*
            If the element is less then the the jump value
            then perform the linear search and break
        */
        if(element < arr[j]){
            for(int k=i;k<j;k++){
                if(element == arr[k]){
                    a=true;
                    break;
                }
            } //loop ended
        }


    }//Main loop ended



    return 0;
}
