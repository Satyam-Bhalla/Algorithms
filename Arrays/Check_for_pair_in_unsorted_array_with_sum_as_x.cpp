/*
    Program = To find a pair in a array whose sum is equal to the sum user wants to find.
    Author  = Satyam
*/
//Including header files
#include<iostream>
#include<vector>
#include<algorithm>

//Setting std namesopace
using namespace std;

//Main function started
int main(){
    //Initialization and Declaration
    int n,sum=0,num,left,right;
    bool found=false;
    vector<int> arr;

    //Taking input from user
    cout << "How many elements do you wish to enter = ";
    cin >> n;
    cout << "\nEnter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cout << i+1 << ".) ";
        cin >> num;
        arr.push_back(num);
    }

    //Sorting the vector array with built in function sort of Algorithm library
    sort(arr.begin(),arr.end());

    //Taking input for the sum
    cout << "Enter the sum to found = ";
    cin >> sum;

    //Setting left and right position
    left=0;
    right = arr.size()-1;

    //Finding the pair
    while(left<right){
        if(arr[left]+arr[right]==sum){
            cout << "\nThe two elements are :" << arr[left] <<" , "<<arr[right]<<endl;
            found = true;
            break;
        }else if(arr[left]+arr[right]<sum){
            left++;
        }
        else if(arr[left]+arr[right]>sum){
            right--;
        }
    }
    //If pair not found
    if(!found){
        cout << "\nPair not found!"<<endl;
    }

    return 0;
}
