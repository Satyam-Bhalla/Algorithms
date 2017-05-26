/*
    Algorithm = Bucket Sort
    Complexity = O(n+k) in Average case and O(n*n) in worst case
    Author = Satyam
*/
//Including header files
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

//Setting standard namespace
using namespace std;

//Bucket sort function definition
void bucketSort(float arr[],int n){
    //Create n empty buckets
    vector<float> b[n];

    //Initialize elements
    float minNum=arr[0],maxNum=arr[0];
    int size = n-2,divider=0;

    //Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
        if(maxNum < arr[i]){
            maxNum = arr[i];
        }
        if(minNum>arr[i]){
            minNum = arr[i];
        }

        //finding the location of bucket where the element is to be added
        divider = ceil((maxNum+1)/size);
        int bi = floor(arr[i]/divider);

       // Index in bucket
       b[bi].push_back(arr[i]);
    }

    //Sort individual buckets with the built in sort function
    for (int i=0; i<n; i++){
       sort(b[i].begin(), b[i].end());
    }


    //Concatenate all sorted buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
          arr[index++] = b[i][j];
        }
    }
}
//Main function started
int main(){

    int n;
    float arr[20];

    cout << "How many elements do you want to enter = ";
    cin >> n;
    cout << "Enter the elements:\n";
    for(int i=0;i<n;i++){
        cout <<i+1<< ".) ";
        cin >> arr[i];
    }

    //bucket sort function called
    bucketSort(arr,n);

    //Showing the output
    cout << "Sorted elements are:"<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
