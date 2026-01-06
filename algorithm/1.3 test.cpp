#include<bits/stdc++.h>
using namespace std;

const long long Mod=2013;

struct Matrix{
    long long m[2][2];
};

Matrix mul(Matrix &a,Matrix &b){
    Matrix res;
    res.m[0][0]=(a.m[0][0]*b.m[0][0]+a.m[0][1]*b.m[1][0])%Mod;
    res.m[0][1]=(a.m[0][0]*b.m[0][1]+a.m[0][1]*b.m[1][1])%Mod;
    res.m[1][0]=(a.m[1][0]*b.m[0][0]+a.m[1][1]*b.m[1][0])%Mod;
    res.m[1][1]=(a.m[1][0]*b.m[0][1]+a.m[1][1]*b.m[1][1])%Mod;
    return res;
}

Matrix power(Matrix base,long long e){
    Matrix res;
    res.m[0][0]=res.m[1][1]=1;
    res.m[0][1]=res.m[1][0]=0;
    while(e){
        if(e&1) res=mul(res,base);
        base=mul(base,base);
        e>>=1;
    }
    return res;
}


int main(){
    int q,a,b;
    cin>>q>>a>>b;
    Matrix base;
    base.m[0][0]=a%Mod;
    base.m[0][1]=b%Mod;
    base.m[1][0]=1;
    base.m[1][1]=0;
    while (q--)
    {
        long long n;
        cin>>n;
        if(n==1||n==0){
            cout<<1<<endl;
            continue;
        }
        Matrix res=power(base,n-1);
        long long fn=(res.m[0][0]+res.m[0][1])%Mod;
        cout<<fn<<endl;
            
    }
    return 0;
}