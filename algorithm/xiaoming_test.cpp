#include<bits/stdc++.h>
using namespace std;


struct Day
{
    long long b;
    long long c;
};

bool compare(const Day &Day1,const Day &Day2)
{
    return Day1.b>Day2.b;
}

int main(){
    int n;
    cin>>n;
    long long sum=0;
    vector<Day>days(n);

    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sum+=a;
        days[i]={b,c};
    }

    long long res=0;
    long long remain=sum;
    sort(days.begin(),days.end(),compare);
    for(const auto &day:days){
        if(remain<0)    break;
        long long take=min(remain,day.c);
        res+=take*day.b;
        remain-=take;

    }
    cout<<res<<endl;
    return 0;
}