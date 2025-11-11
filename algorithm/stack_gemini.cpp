#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n,t,p,d;
long long new_cap;
long long memo[1005][1005];

long long slove(int i,int j){
    if(i==n+1){
        return 1;
    }

    if(memo[i][j]!=-1)  return memo[i][j];

    int cur_cap=0;
    if(i<=t){
        cur_cap=p;
    }else{
        cur_cap=new_cap;
    }

    long long way=0;
    
    if(j<cur_cap){
        way=(way+slove(i+1,j+1))%MOD;
    }
    if(j>0){
        way=(way+slove(i,j-1))%MOD;

    }

    return memo[i][j]=way;
    
}

int main(){
    cin>>n>>t>>p>>d;
    new_cap=p+d;
    memset(memo,-1,sizeof(memo));
    cout<<slove(1,0)<<endl;
    
    return 0;

}