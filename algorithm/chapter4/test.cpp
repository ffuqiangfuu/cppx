#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Max 1000005
LL ans=0;
LL price[Max];

int main()
{
    int n;
    cin>>n;
    LL a,b,c;
    LL available;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        available+=a;
        if(available>=c){
            price[b]+=c;
            ans+=b*c;
            available-=c;
        }else{
            LL regret=c-available;
            
            for(int j=0;j<b;j++){
                
                if(regret==0){
                    break;
                }
                if(price[j]>0){
                LL amount_num=min(regret,price[j]);
                ans-=amount_num*j;
                ans+=amount_num*b;
                price[j]-=amount_num;
                price[b]+=amount_num;
                regret-=amount_num;
                }
            }
            ans+=available*b;
            price[b]+=available;
            available=0;    //因为全卖出去了，available的数量要发生变化。
        }

    }
    cout<<ans<<endl;
}