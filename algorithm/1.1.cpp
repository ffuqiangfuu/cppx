#include<bits/stdc++.h>
using namespace std;

vector<int>a(28);
vector<int>b(28);
vector<int>c(28);
vector<int>d(28);
long long max_sum=-200000000;
int n,m,t;
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

void init_vector(vector<int>&nums,int n){
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}
void dfs(vector<int>&a,int op,int deep);
int main(){
    
    cin>>n>>m>>t;   //n数组长度，m操作次数，t操作2的参数
    init_vector(a,n);
    init_vector(b,n);
    init_vector(c,n);
    init_vector(d,n);

    dfs(a,2,0);
    cout<<max_sum<<endl;
    return 0;

}

void dfs(vector<int>&a,int op,int deep){
    if(deep>=m){
        return;
    }
    if(op==2){
        vector<int>new_a(28);
        for(int i=0;i<n;i++){
            new_a[i]=a[i] xor b[i];
        }
        if((m-deep-1)%2==0){
            getSum(new_a);
        }
        dfs(new_a,1,deep+1);
        
    }
    vector<int>new_a2(28);
    for(int i=0;i<n;i++){
        new_a2[i]=a[d[i]-1]+t;
    }
    if((m-deep-1)%2==0){
        getSum(new_a2);
    }
    dfs(new_a2,2,deep+1);
}