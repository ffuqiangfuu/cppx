#include<bits/stdc++.h>
using namespace std;
const long long Mod=2013;

struct Matrix{
    long long m[2][2];
};
int q,a,b;

//矩阵的乘法
Matrix mul(Matrix&a,Matrix&b){
    Matrix res;
    res.m[0][0]=(a.m[0][0]*b.m[0][0]+a.m[0][1]*b.m[1][0])%Mod;
    res.m[0][1]=(a.m[0][0]*b.m[0][1]+a.m[0][1]*b.m[1][1])%Mod;
    res.m[1][0]=(a.m[1][0]*b.m[0][0]+a.m[1][1]*b.m[1][0])%Mod;
    res.m[1][1]=(a.m[1][0]*b.m[0][1]+a.m[1][1]*b.m[1][1])%Mod;
    return res;
}
//矩阵快速幂
Matrix power(Matrix base,long long e){
    Matrix res;
    res.m[0][0]=res.m[1][1]=1;    //定义一个初始矩阵
    res.m[0][1]=res.m[1][0]=0;
    while(e){
        if(e&1) res=mul(res,base);  //一位一位的看e，如果e的最后一位为1，说明要成base的2的0次方，e的倒数二位为1，要成base的2的一次方  例如3  011=base^2+base^1;
        base=mul(base,base);    //每一轮循环 base都要跟自己相乘
        e>>=1;  //每次去掉e的最后一位
    }
    return res;
}

int main(){
    cin>>q>>a>>b;
    Matrix base;
    base.m[0][0]=a; //（f(n),f(n-1)）=(a,b;1,0)(f(n-1),f(n-2))
    base.m[0][1]=b;
    base.m[1][0]=1;
    base.m[1][1]=0;
    while(q--){
        long long n;
        cin>>n;
        if(n==0||n==1){
            cout<<1<<"\n";
            continue;
        }
        Matrix tmp=power(base,n-1);
        long long Fn=(tmp.m[0][0]+tmp.m[0][1])%Mod;
        cout<<Fn<<endl;
        
    }
    return 0;
}