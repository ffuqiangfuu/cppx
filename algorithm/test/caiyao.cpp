#include<bits/stdc++.h>
using namespace std;

const int TMAX=1005;
const int MMAX=105;
int T,M;
int dp[MMAX][TMAX];     //考虑前i课草药，可用时间为j时能达到的最大值
int value[MMAX];
int cost_time[MMAX];


int main(){
    cin>>T;
    cin>>M;
    for(int i=1;i<=M;i++){
        cin>>cost_time[i];
        cin>>value[i];
    }

    for(int i=1;i<=M;i++){  //遍历每棵草药
        for(int j=0;j<=T;j++){
            if(j<cost_time[i]){
                dp[i][j]=dp[i-1][j];    //这棵草药不能采，所以就等于考虑i-1棵
            }else{
                int dp1=dp[i-1][j];     //这棵草药不能采。
                int dp2=dp[i-1][j-cost_time[i]]+value[i];
                dp[i][j]=max(dp1,dp2);
            }
        }
    }
    cout<<dp[M][T]<<endl;
    return 0;
}

