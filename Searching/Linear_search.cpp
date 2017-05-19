/*Linear search algo to search all the elements linearly
    Author =  Satyam
    Complexity = O(n)
*/
//Adding Header files
#include<iostream>

//Setting std namespace
using namespace std;

//Main function started
int main(){
    //Declaring variables
    int n,arr[50],element;
    bool a=false;

    cout << "How many numbers do you want to enter = ";
    cin >> n;

    //Entering the elements in array
    cout << "\nEnter the numbers:"<<endl;
    for (int i=0;i<n;i++){
        cout << i+1 << ".)\t";
        cin >> arr[i];
        cout << endl;
    }

    //Searching the elemets linearly
    cout << "Enter the element to search = ";
    cin >> element;
    for(int i=0;i<n;i++){
        if(element == arr[i]){
            cout << "\nElement found at location " << i+1 << endl ;
            a = true;
        }
    }

    //If element not found
    if(a == false){
        cout << "\nElement not found";
    }
    return 0;
}
