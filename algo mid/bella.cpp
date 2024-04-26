#include<iostream>
#include<ctime>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
    int n1= m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
  for(int i=0; i<n1;i++)
  {
    L[i]=arr[l+i];
  }
 for(int j=0; j<n2;j++)
  {
    R[j]=arr[m+1+j];
  }
  
      int i=0;
      int j=0;
      int k=l;
      while (i<n1 && j< n2)
      {
        if (L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
      }
      while (i<n1)
      {
        arr[k]=L[i];
        i++;
        k++;

      }
      while (j<n2)
      {
        arr[k]=R[j];
        j++;
        k++;
      }
      
      
}
 void margeSort(int arr[],int l,int r)
 {
    if (l>=r)
    {
        return;
    }
    int m=l+(r-l)/2;
    margeSort(arr,l,m);
    margeSort(arr,m+1,r);
    merge(arr,l,m,r);
 }
 int main() {
    cout<<"Name: MD.Kamruzzaman\n";
    cout<<"ID:22234103167\n";
    cout<<"Section:06\n";
    cout<<"Intake: 50\n";
    int arr[10];
    cout<<"enter 10 unsorted Number:\n";
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }

    clock_t startTime =clock();
    
    margeSort(arr,0,9);
    clock_t endTime = clock();
    double timeTaken =double(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Sorted array\n";
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Time complexity of merge sort : O(n log n)\n";
    cout<<"Time taken for sorting: "<<timeTaken<<"sec\n";
    return 0;
    
    
 }