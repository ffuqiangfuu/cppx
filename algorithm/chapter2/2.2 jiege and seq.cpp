#include<bits/stdc++.h>
using namespace std;

//交换相邻元素让数组有序，最少的交换次数就是逆序数的对数

const int Max=1e5+1;
int N,A,B;
long long invCount=0;   //逆序数的个数
int a[Max];     //题目输入的a数组
int tmp[Max];    //用于归并排序的临时数组

void mergeRange(int left,int right){
    int mid=left+(right-left)/2;
    int l=left;
    int r=mid+1;
    int k=0;    //合并进去临时数组的下标
    while(l<=mid&&r<=right){
        if(a[l]<=a[r]){
            tmp[k]=a[l];    //两个区间都是有序的，依次对比小的先放进去tmp数组。
            k++;
            l++;
        }else{  //左边最小的比右边最小的大
            tmp[k]=a[r];
            k++;
            r++;
            invCount+=(mid-l+1);    //因为这时候左边最小的都比右边最小的大，那么左边剩下数跟右边最小的数肯定是逆序数。
        }
      
    }
    while(l<=mid){      //左半段剩下的全部放进去
        tmp[k]=a[l];
        k++;
        l++;
    }
    while(r<=right){
        tmp[k]=a[r];
        k++;
        r++;
    }
    for(int i=0;i<k;i++){   //这时候只排序了left到right这一段，所以i<k;
        a[left+i]=tmp[i];           //因为排序的起始坐标是left，所以a[left+1[]=tmp[i]
    }
}

void merge(int left,int right){     //分段归并  
    if(left>=right)  return;    //这里要等号,只有单个元素区间才会停止。
    int mid=left+(right-left)/2;
    merge(left,mid);     //先归并左边   要先分区间，再排序，先分左区间，
    merge(mid+1,right);    //再归并右边     再分右区间
    mergeRange(left,right);     //再排序排序    
    
}

int main(){
    cin>>N>>A>>B;
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    merge(0,N-1);
    cout<<invCount*min(A,B)<<endl;  //只要求出逆序数，然后用逆序数乘开销小的那个数字。
    return 0;
}
