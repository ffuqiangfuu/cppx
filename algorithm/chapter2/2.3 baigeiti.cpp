#include<bits/stdc++.h>
using namespace std;

int N,M;

bool check(vector<long long>&a ,int N,int M,long long mid ){
    long long last=a[0];    //已经选了一个了，先选最小的，然后贪心
    int cnt=1;  //初始计数为1；
    for(int i=1;i<N;i++){
        if(a[i]-last>=mid){
            last=a[i];
            cnt++;
        }
        if(cnt>=M)   return true;
    }
    return false;

}


int main(){
    cin>>N>>M;
    vector<long long>a(N);  //开n个就好，不要多开，不然用sort排序的时候会把0也算进去
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());    //先排序，有利于选取二分的范围
    long long left=0;   //最小差值 0-0=0
    long long right=a[N-1]-a[0];        //最大差值 最大值-最小值
    long long ans;
    while(left<=right){
        long long mid=(left+right)/2;   //注意防止溢出，这里用longlong就不会溢出
        if(check(a,N,M,mid)){
            left=mid+1;
            ans=mid;    //这个ans的更新要可行的时候才更新ans；
        }else{
            right=mid-1;
        }
    }
    cout<<ans<<endl;
}
