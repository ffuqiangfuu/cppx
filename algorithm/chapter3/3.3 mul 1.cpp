#include<bits/stdc++.h>
using namespace std;

//思路，尽量把每个数变成-1或者1，然后主要看-1的个数有多少个
int main(){
    int n=0;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int zeroSum=0;  //统计0的数量
    int smallzeroSum=0; //统计有几个负数
    long long smallzeroCost=0;  //统计把全部负数变成-1需要消耗多少次操作
    int bigzeroSum=0;   //统计大于0的数有几个
    long long bigzeroCost=0;    //统计把大于0的数变成1需要消耗多少
    for(int i=0;i<n;i++){   //遍历每一个数字
        if(a[i]>0){     //如果大于0
            bigzeroSum+=1;  
            bigzeroCost+=a[i]-1;    //看一下这个数变成1需要消耗的操作次数
        }else if(a[i]<0){
            smallzeroSum+=1;
            smallzeroCost+=-a[i]-1; //变成-1需要的操作次数
        }else{
            zeroSum++;  //统计0的数量
        }
    }
    long long ans=0;
    //看-1的数量
    if(smallzeroSum%2==1){  //如果小于0的数量是奇数的话
        ans+=smallzeroCost;     //先全部变成-1
        if(zeroSum==0){     //因为相乘等于1的话，我们需要把-1的个数变成偶数，看0的个数是否等于0，如果等于0
            ans+=2;     //那就把一个-1变成1需要两次操作。
        }else{
            ans+=zeroSum;   //0的个数不为0，那就选一个变成-1，其他变成1，每个数字都是操作一次，所以直接加zeroSum
        }
    }else{
        ans+=smallzeroCost; //如果是偶数个-1的话直接加就行了
        ans+=zeroSum;   //0全变成1，需要zeroSum次操作
    }
    ans+=bigzeroCost;   //把正数变成1
    cout<<ans<<endl;
    
}