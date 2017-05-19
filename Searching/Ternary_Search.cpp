/*
    Algorithm = Ternary Search
    Complexity = O(logn)
    Author = Satyam
*/
//including Header files
#include<iostream>

//Setting std namespace
using namespace std;
// A recursive ternary search function. It returns location of item in given array arr[l..r] is present, otherwise -1
int ternarySearch(int arr[], int l, int r, int x)
{
    //Right must be greater then left
if (r >= l)
{
    //Find 2 mid values for fast results
		int mid1 = l + (r - l)/3;
		int mid2 = mid1 + (r - l)/3;

		// If x is present at the mid1
		if (arr[mid1] == x) return mid1;

		// If x is present at the mid2
		if (arr[mid2] == x) return mid2;

		// If x is present in left one-third
		if (arr[mid1] > x) return ternarySearch(arr, l, mid1-1, x);

		// If x is present in right one-third
		if (arr[mid2] < x) return ternarySearch(arr, mid2+1, r, x);

		// If x is present in middle one-third
		return ternarySearch(arr, mid1+1, mid2-1, x);
}
// We reach here when element is not present in array
return -1;
}
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
    cout<<"\nEnter Item you want to Search= ";
    cin>>item;

    //Setting the begining and ending value
    beg=1;
    end=n;
    //Calling ternary search function to search location in array
    int result = ternarySearch(arr,beg,end,item);

    //Checking the result
    if(result == -1){
        cout << "\nElement not found!!"<<endl;
    }else{
        cout << "Element found at location "<<result+1;
    }
    return 0;
}
