#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    //dp[j][k]表示以a[j]和a[k]为最后两项的斐波那契子数列的长度为多少/
    vector<vector<int>>dp(n,vector<int>(n,2));  //初始化dp数组，每个初始值为2，因为每两个数字都可以组成一个长度为2的斐波那契数列子数组。
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<long long,long long>pos;  //键值对，键是a[i]的值，值是这个值在a[i]所对应的位置。
    for(int i=0;i<n;i++){
        pos[a[i]]=i;    //把每个数字对应的位置存进去。
    }
    int ans=0;


    for(int k=0;k<n;k++){   //先遍历后面大的，再遍历小的
    
        for(int j=0;j<k;j++){
            long long need=a[k]-a[j];   //need,a[k],a[j]看看能否构成斐波那契数列的子数列
            if(need>=a[j])  continue;  //因为序列是严格递增的，如果need都大于了a[j]的话，那么a[j]前面一定不可能有个值是need
            auto it=pos.find(need); // 用一个迭代器遍历，去查找need在数组中的位置，find()函数返回一个迭代器。
            if(it==pos.end())    continue;   //end()函数返回unordered_map中最后一个值所在的迭代器的位置，说明找遍了map都没找到need对应的位置，说明这个值在a中不存在
            int i=it->second;   //如果存在的话返回这个数在a[i]中的位置。
            if(i<j){
                dp[j][k]=dp[i][j]+1;    //你已经找到了（i,j）结尾的长度为dp[i][j]所以把a[k]加上去的话就是dp[j][k]=dp[i][j]+1
                ans=max(ans,dp[j][k]);  //更新最大长度的
            }

        }
    }

    if(ans>2){
        cout<<ans<<endl;
    }else{
        cout<<"-1"<<endl;
    }

}