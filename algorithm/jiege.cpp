#include <bits/stdc++.h>
using namespace std;
#define max 100000

long long inv_num=0;
vector<int>D(max);
vector<int>tmp(max);

void merge(vector<int>arr,vector<int>tmp,int left,int mid,int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid&&j<=right)
    {
        if(arr[i]<=arr[j]){
            tmp[k++]=arr[i++];
        }else{
            tmp[k++]=arr[j++];
            inv_num+=(mid-i+1);
        }
    }
    while (i<=mid)
    {
        tmp[k++]=arr[i++];

    }
    while(j<=right){
        tmp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i]=tmp[i];
    }
}

    void mergeSort(vector<int>arr,vector<int>tmp,int left,int right){
        if(left<right){
            int mid=(left+right)/2;
            mergeSort(arr,tmp,left,mid);
            mergeSort(arr,tmp,mid+1,right);
            merge(arr,tmp,left,mid,right);
        }
    }

    int main(){
        int N,A,B;
        cin>>N>>A>>B;
        for(int i=0;i<N;i++){
            cin>>D[i];
        }
        mergeSort(D,tmp,0,N-1);
        long long min;

        if(A<B){
            min=inv_num*A;
        }else{
            min=inv_num*B;
        }
        cout<<min<<endl;
        return 0;
    }
    
