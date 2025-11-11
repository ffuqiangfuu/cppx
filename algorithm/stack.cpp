#include<bits/stdc++.h>
#define MOD 998244353

using namespace std;

int n,t,p,d;
long long memo[1005][1005];
int new_capacity;

//处理到第i人，当前有j个人在栈中
long long solve(int i,int j){
    if(i==n+1){
        return 1;
    }
    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    long long ways=0;

    int current_capactity=0;
    if(i<=t){
        current_capactity=p;
    }else{
        current_capactity=new_capacity;
    }
    
    if(j<current_capactity){
        ways=(ways+solve(i+1,j+1))%MOD;
    }

    if(j>0){
        ways=(ways+solve(i,j-1))%MOD;
    }

    return memo[i][j]=ways;
}


int main(){
    cin>>n>>t>>p>>d;

    new_capacity=p+d;
    memset(memo,-1,sizeof(memo));
    cout<<solve(1,0)<<endl;

    return 0;


}