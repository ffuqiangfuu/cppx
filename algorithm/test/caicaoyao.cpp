#include<bits/stdc++.h>
using namespace std;

int T,M;    //代表能用于采药的时间，M代表草药的数量。
int value[105];     //草药的价值数组
int time_cost[105];      //采第i棵草药所需要的时间。
int dp[105][1005];  //dp数组，dp[i][j]表示只考虑前i棵草药，可用时间总量为j时所能达到的最大价值。

int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++){  //依次输入采集每个草药所需要的时间，和每个草药价值。1-base
        cin>>time_cost[i];
        cin>>value[i];
    }
    for(int i=1;i<=M;i++){     //遍历每个草药
        for(int j=1;j<=T;j++){      //遍历每个时间容量
            if(j<time_cost[i]){      //如果当前的时间容量不能收下第i棵草药
                dp[i][j]=dp[i-1][j];         //那么因为没采草药，考虑前i棵草药的最大值就等于考虑前i-1棵
            }else{  //时间足够的情况下有两种选择，采这个草药和不采这个草药
                int dp1=dp[i-1][j-time_cost[i]]+value[i];   //采集草药，由上一个状态，考虑i-1棵草药，并且时间由j-time_cost[i]转移过来的，价值要加上第i棵草药的价值
                int dp2=dp[i-1][j];         //不采集这颗草药
                dp[i][j]=max(dp1,dp2);      //选两种情况的最大值
            }
        }
    }

    cout<<dp[M][T]<<endl;       //考虑了M个物品，并且拥有的总时间为T；
    return 0;
}