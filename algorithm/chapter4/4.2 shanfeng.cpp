#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[1005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxlength=1;    //第一个数字作为山峰序列
    int prediff=0;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n;i++)    //第一个数字a[0]已经是山峰序列，所以从a[1]开始判断
    {
        int diff=a[i]-a[i-1];
        if(diff>0&&prediff<=0){ //diff不用等于0，如果两个数相等，不构成山峰序列。
            maxlength++;
            prediff=diff;
        }else if(diff<0&&prediff>=0){
            maxlength++;
            prediff=diff;
        }
    }
    cout<<maxlength<<endl;
    return 0;
}