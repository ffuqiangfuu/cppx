#include<bits/stdc++.h>
using namespace std;

vector<int>a(28);    //初始化数组
vector<int>b(28);
vector<int>c(28);
vector<int>d(28);
long long max_sum=-200000000;   //定义一个最小的初始值
int n,m,t;              //定义题目要求输入的变量

//求最大值的函数
void getSum(vector<int>&a)
{
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i]*c[i];
    }
    if(sum>max_sum){
        max_sum=sum;
    }
}
//初始化数组
void init_vector(vector<int>&nums,int n){
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}
//dfs搜索答案
void dfs(vector<int>&a,int op,int deep);
int main(){
    
    cin>>n>>m>>t;   //n数组长度，m操作次数，t操作2的参数
    init_vector(a,n);
    init_vector(b,n);
    init_vector(c,n);
    init_vector(d,n);

    dfs(a,2,0);     //初始值的dfs是操作2，默认它可以进行操作1，因为操作1进行两次以后的话就会变成原来的值A op1 B op1 B = A
    cout<<max_sum<<endl;
    return 0;

}

//dfs搜索答案
void dfs(vector<int>&a,int op,int deep){
    if(deep>=m){    //如果大于次数的话，就停止搜索
        return;
    }
    if(op==2){  //只有上次操作是操作2才能继续进行操作1，不然的话做两次操作1就是没意义的
        vector<int>new_a(28);
        for(int i=0;i<n;i++){
            new_a[i]=a[i] xor b[i];
        }
        if((m-deep-1)%2==0){    //剪枝，如果剩下的操作次数是偶数，正好此时的答案特别好，那我们可以剩下都做操作1保留这次的答案，如果是奇数的话肯定有一次操作会让他变成别的值
            getSum(new_a);
        }
        dfs(new_a,1,deep+1);    //代表这次做的是操作1，下次不能做了，不然没意义
        
    }
    vector<int>new_a2(28);
    for(int i=0;i<n;i++){
        new_a2[i]=a[d[i]-1]+t;  //这里一定要记得d[i]-1因为题目给的d数组是1-base的
    }
    if((m-deep-1)%2==0){
        getSum(new_a2);
    }
    dfs(new_a2,2,deep+1);
}