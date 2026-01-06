#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,p;
    int num[300005];
    long long ans,num1,num2;

    scanf("%d",&n);
    //初始化数组，初始的每个数字的卡片都是0；
    for(int i=0;i<=300000;i++){
        num[i]=0;
    }
    int x_num;
    for(int i=1;i<=n;i++){
        scanf("%d",&x_num);
        num[x_num]++;   //数字为x的卡票有多少张
    }
    
    //这时候变成num[x]等于卡片数字小于等于x的数量有几张
    for(int i=1;i<=300000;i++){
        num[i]+=num[i-1];
    }
    scanf("%d",&m); //m次查询
    for(int i=1;i<=m;i++){
        scanf("%d",&p);
        int x=ceil(sqrt(p));   //记录根号p，根号p向上取整；ceil向上取整
        long long num1=num[300000]-num[x-1];  //求出大于根号p的数字有多少
        long long ans= num1*(num1-1);   //在大于根号p的数字中选2个，这样的数字都能够满足的，n个中选2 n(n-1)
        //接下来枚举一张大于根号p一张小于根号p的情况，两张都小于根号p的情况不用考虑。
        for(int j=1;j<x;j++){
            int need = (p+j-1)/j;     //看看至少还需要多少数相乘才会达到p,向上取整就是(p+j-1)/j
            long long num2=num[300000]-num[need-1];   //大于等于need的数字有多少
            long long num3=num[j]-num[j-1];   //大小恰好等于j的数字有几张
            long long ans1=2*num2*num3;   //小于根号p和大于根号p中各取一张，因为两个人可以换着拿，所以×2；
            ans+=ans1;


        }
        cout<<ans<<endl;

    }
    return 0;
}