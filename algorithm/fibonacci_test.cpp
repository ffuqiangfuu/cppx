#include<bits/stdc++.h>
using namespace std;
const int MOD = 2013;

struct Matrix{
    long long m[2][2];
    Matrix(){   memset(m,0,sizeof(m));}
};

Matrix mul(const Matrix &A,const Matrix &B){
    Matrix C;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
            {
                C.m[i][j]=C.m[i][j]+(A.m[i][k]*B.m[k][j])%MOD;
           }
    return C;
}

Matrix qpow(Matrix base, long long exp){
    Matrix res;
    res.m[0][0]=res.m[1][1]=1;
    while (exp)
    {
        if(exp&1)   res=mul(res,base);
        base=mul(base,base);
        exp>>=1;
    }
    return res;
    
}

long long fib(long long n,long long a,long long b){
    if(n==0||n==1)  return 1;
    Matrix trans;
    trans.m[0][0]=a%MOD;
    trans.m[0][1]=b%MOD;
    trans.m[1][0]=1;
    trans.m[1][1]=0;
    Matrix res=qpow(trans,n-1);
    long long Fn=(res.m[0][0]+res.m[0][1])%MOD;
    return Fn;
}