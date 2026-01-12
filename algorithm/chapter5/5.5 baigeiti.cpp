#include<bits/stdc++.h>
using namespace std;


int n;
vector<bool>used;
vector<int>nums;
vector<int>res;
bool found= false;

bool isPrime(int num){
    if(num<2)  return false;
    for(int i=2;i<num;i++){
        if(num%i==0)   return false;
    }
    return true;
}
//cur当前的填充第几个数字，last上一个填充数组的坐标。从0这个位置开始填充
void dfs(int cur,int last){
    if(found)   return;
    if(cur==n){ //如果填充的数量已经达到n个的话
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        found=true;
        return;
    }
    //依次吧nums里面的数组填充到cur当前的位置，看看是否满足条件
    for(int i=0;i<n;i++){
        if(used[i]==true)   continue;
        int sum=nums[i]+nums[last];
        if(isPrime(sum)){
            used[i]=true;
            res[cur]=nums[i];
            dfs(cur+1,i);
            used[i]=false;
        }
    }
}

int main(){
    cin>>n;
    nums.assign(n,0);
    res.assign(n,0);
    used.assign(n,false);
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        nums[i]=i+1;
    }
    res[0]=nums[0];
    used[0]=true;
    dfs(1,0);
    if(!found)  cout<<"-1"<<endl;
    return 0;
}