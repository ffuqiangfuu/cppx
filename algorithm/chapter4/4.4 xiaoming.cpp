#include<bits/stdc++.h>
using namespace std;
#define Max 1e6+2


vector<long long>price(Max);    //价格数组
long long res=0;
long long available=0;  //手中持有的股票数量

int main(){
    int n;  //一共有n天
    int a,b,c;  //今天有a只股票，今天可以卖b的价钱，今天最多卖c只
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        available+=a;   //一共有多少只可以卖的股票
        if(available>=c){   //如果可以卖的股票比今天能卖的c多，就全部卖出去。
            price[b]+=c;    //价格为b的股票卖了c张
            res+=c*b;   //更新总收益
            available-=c;   //持有股票减去今天卖的c
        }else{
            long long regret=c-available;   //如果今天可以卖的股票比持有股票多，那么就需要从之前便宜卖的股票中买回一些重新卖。今天能卖的减去今天持有的等于需要回购的
            for(int j=1;j<b;j++){   //遍历比今天价格低卖出去的股票
                if(regret==0){  //如果需要回购的股票等于0，说明全卖了，直接跳出
                    break;
                }
                long long amount_num=0; //统计某个价钱的股票能回购多少
                if(price[j]>0){ //如果这个价格卖出过股票，则回购。
                    amount_num=min(price[j],regret);    //比较需要的数量跟这个价格卖出去的数量，如果需要的少就把需要的数量回购，如果这个价格卖出去的少，就全买回来再看下一个价格/
                    price[j]-=amount_num;   //更新价格j卖出去的数量
                    res-=amount_num*j;      //更新总收益
                    res+=amount_num*b;      //更新收益
                    price[b]+=amount_num;   //更新卖出去的数量
                    regret-=amount_num;     //更新还需要回购多少股票
                }
            }
            price[b]+=available;    //把今天剩余的股票卖出去
            res+=(b*available);
            available=0;
        }
    }
    cout<<res<<endl;
    return 0;
}
