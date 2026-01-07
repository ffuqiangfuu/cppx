#include<bits/stdc++.h>
using namespace std;

//我们只计算，由N产生的序列与LR区间的交集部分有多少个01.

long long l,r,L,R,N;    //L和R是题目给的范围，l和r是生成序列的范围,N是用于生成01序列的数字。
int ans=0;

//求生成序列的长度
long long getlen(long long n){
    if(n<=1)    return 1;   //如果N只有1的话，那么返回1
    long long len=0;
    len=pow(2,int(log2(n)+1))-1;       //用数学公式推理。
    return len; 
}

void countNum(long long N,long long l,long long r){
    if(L>r||R<l||l>r)   return;     //如果我们要求的区间L，大于这次递归的右区间r那么这次递归区间与我们要的LR区间没有交集，R<L同理，l>r是二分的终止条件
    long long mid=(l+r)>>1;
    if(R<mid){      //如果右区间R在mid的左边，那么此时我们只要考虑N这个序列的左半段
        countNum(N/2,l,mid-1);
    }else if(L>mid){    //如果左区间L在mid的右边，那么此时我们只要考虑N这个序列的右半段
        countNum(N/2,mid+1,r);
    }else{      //如果L和R把mid包含住，那么，mid的左右半段都要考虑
        ans+=N%2;   //同时还要考虑中间那个点。
        countNum(N/2,l,mid-1);
        countNum(N/2,mid+1,r);
    }
}

int main(){
    cin>>N>>L>>R;
    long long len=getlen(N);
    countNum(N,1,len);
    cout<<ans;
}