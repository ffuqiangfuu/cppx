#include <bits/stdc++.h>
using namespace std;
#define max 1000001


vector<long long>priceCount(max,0);  //priceCount[j]表示以价钱j卖掉了多少
long long res=0;
long long available=0;    //可卖股票数


int main(){
    int n;
    int a,b,c;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        available+=a;
        if(available>=c)
        {
            priceCount[b]+=c;
            available-=c;
            res+=(b*c);
        }else if(available<c){
            long long regret=c-available;    //还需要补充多少股票
            for(int j=1;j<b;j++){    //遍历所有比今天便宜的价钱
                if(regret==0){
                    break;
                }
                if(priceCount[j]>0){
                    long long regret_amount=min(priceCount[j],regret);
                    priceCount[j]-=regret_amount;
                    priceCount[b]+=regret_amount;

                    res-=(j*regret_amount);
                    res+=(b*regret_amount);

                    regret-=regret_amount;
                }
            }
            priceCount[b]+=available;
            res+=(b*available);
            available=0;
        }

    }
    cout<<res<<endl;
    return 0;
}
