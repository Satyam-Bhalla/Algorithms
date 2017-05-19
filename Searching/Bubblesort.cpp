//Bubble sort
#include<iostream>
using namespace std;
int main()
{
int a[100],i,n,p,j,temp,beg,mid,end,item;
cout<<"\n------------ BUBBLE SORT ------------ \n\n";
cout<<"Enter No. of Elements : ";
cin>>n;
cout<<"\nEnter Elements : \n";
for(i=1;i<=n;i++)
{
cin>>a[i];
}

for(p=1;p<=n-1;p++)             // Loop for Pass
{
for(j=1;j<=n-1;j++)
    {
        if(a[j]>a[j+1])
            {
            temp=a[j];                      // Interchange Values
            a[j]=a[j+1];
            a[j+1]=temp;
            }
    }
}

cout<<"\nAfter Sorting : \n";

for(i=1;i<=n;i++)
{
cout<<a[i]<<endl;
}


cout<<"\nEnter Item you want to Search= ";
cin>>item;
beg=1;
end=n;
mid=(beg+end)/2;                       // Find Mid Location of Array
while(beg<=end && a[mid]!=item)      // Compare Item and Value of Mid
    {
    if(a[mid]<item)
        beg=mid+1;
    else
        end=mid-1;

    mid=(beg+end)/2;
    }

    if(a[mid]==item)
        {
        cout<<"\nData is Found at Location : "<<mid;
        }
    else
        {
        cout<<"Data is Not Found";
        }
return 0;
}
