#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,p;
    int num[300005];
    scanf("%d",&n);
    for(int i=1;i<=300000;i++){
        num[i]=0;
    }
    int numx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&numx);
        num[numx]++;
    }
    for(int i=1;i<=300000;i++){
        num[i]+=num[i-1];
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&p);
        long long ans=0;
        int x=ceil(sqrt(p));
        long long num1=num[300000]-num[x-1];
        long long ans1=num1*(num1-1);
        ans+=ans1;
        for(int j=1;j<x;j++){
            int need = (p+j-1)/j;
            long long num2 = num[300000]-num[need-1];
            long long num3 = num[j]-num[j-1];
            long long ans2 = 2*num2*num3;
            ans+=ans2;
        }
        cout<<ans<<endl;
    }

}