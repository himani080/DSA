#include<iostream>
#include<vector>
using namespace std;
int partition(int start,int end,int arr[]){
    int pivot=arr[start];
    int count=0;
    for(int i=0;i<end;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int pivotindex=start+count;
    swap(arr[start],arr[pivotindex]);
    int i=start;
    int j=end;
    while(i<pivotindex&&j>pivotindex)
    {
        while(arr[i]<=pivotindex){
            i++;
        }
        while(arr[j]>pivotindex){
            j--;
        }
        if(i<pivotindex&&j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void quicksort(int start,int end,int arr[]){
    if(start>=end){
        return;
    }
    int pivot=partition(start,end,arr);
    quicksort(start,pivot-1,arr);
    quicksort(pivot+1,end,arr);


}