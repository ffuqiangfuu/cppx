#include<bits/stdc++.h>
using namespace std;

vector<int>a;

void Binary(int left,int right){
    if(left>right)  return;          //别忘记写终止条件
    int mid=left+(right-left)/2;    //二分查找防止溢出
    cout<<a[mid]<<" ";
    Binary(left,mid-1); 
    Binary(mid+1,right);
}

int main(){
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());    //因为每次都是取中位数，所以我们直接排序，然后二分查找，每次输出的就是每个区间的中位数。
    Binary(0,n-1);
    cout<<endl;
    return 0;
}