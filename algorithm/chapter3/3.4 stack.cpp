#include<bits/stdc++.h>
using namespace std;

int n,t,p,d;
const long long Mod=998244353;
long long new_cap;
long long memo[1005][1005];

//slove(i,j)处理到第i个人是，此时栈内有j个人的合法方案数；
long long slove(int i,int j){
    if(i==n+1)   //一共有n个人，处理到n+1说明全部人都处理完了，这时候只有1中方案，就是全部出栈；
    {
        return 1;
    }
    if(memo[i][j]!=-1)  return memo[i][j];  //如果这个状态之前出现过了，直接返回。
    int cur_cap=0;  //定义当前状态。
    if(i<=t){    //判断当前栈的容量是多少，注意是小于等于，因为i=t的时候正要处理老板，老板还没入栈
        cur_cap=p;
    }else{
        cur_cap=p+d;
    }
    long long way=0;
    if(j<cur_cap){
        way=(way+slove(i+1,j+1))%Mod;   //入栈操作所以slove(i+1,j+1)这个人已经入栈了，所以要处理第i+1个人，这时候栈里有j+1个人。
    }
    if(j>0) //此时栈内有人的话就有出栈这个选项//这里注意别写else了是入栈出栈都要操作，而不是每次二选一
    {
        way=(way+slove(i,j-1))%Mod;     //出栈操作，slove(i,j-1)这个人没入栈，所以是处理第i人，出了一个人，所以j-1；
    }
    return memo[i][j]=way;  //存储进记忆数组。
}

int main(){
    cin>>n>>t>>p>>d;
    memset(memo,-1,sizeof(memo));
    cout<<slove(1,0)<<endl;     //从第一个人开始，处理第一个人，此时栈内为0人
    return 0;
}