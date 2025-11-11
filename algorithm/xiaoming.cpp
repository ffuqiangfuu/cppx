#include<bits/stdc++.h>
using namespace std;

struct Days
{
    long long b;   //单价
    long long c;   //可交易数量
};

bool compare(const Days &day1,const Days& day2){
    return day1.b>day2.b;
}

int main(){
    int n;
    cin>>n;
    vector<Days>days(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sum+=a;
        days[i].b=b;
        days[i].c=c;
    }

    sort(days.begin(),days.end(),compare);

    long long res=0;
    long long remain=sum;

    for(const auto &day:days){
        if(remain<=0)   break;
        long long take=min(remain,day.c);   //当天卖了多少
        res+=take*day.b;
        remain-=take;
    }

    cout<<res<<endl;

    return 0;
}