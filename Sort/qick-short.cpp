#include<iostream>
using namespace std;
int count=0;

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;
    count++;
    
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            count++;
            
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    count++;
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return(i+1);
}

void quicksort(int arr[], int low, int high){
    count++;
    
    if(low<high){
        
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
        count++;
    }
    count++;
    count++;
}


int main(){
    
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
    cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    
    for (int i = 0; i < n; i++){
    cout << arr[i] ;
    }
    cout << endl;
    cout<<count;

    return 0;
}