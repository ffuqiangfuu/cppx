#include<bits/stdc++.h>
using namespace std;

vector<int>a(29);
vector<int>b(29);
vector<int>c(29);
vector<int>d(29);
int n,m,t;
long long max_sum=-20000000000;

void init_vector(vector<int>&nums){
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}

void getSum(vector<int>&nums){
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i]*c[i];
    }
    if(sum>max_sum){
        max_sum=sum;
    }
}

void dfs(vector<int>&a,int op,int deep){
    if(deep>=m){
        return;
    }
    if(op==2){
        vector<int>new_a(29);
        for(int i=0;i<n;i++){
            new_a[i]=a[i]^b[i];
        }
        if((m-deep-1)%2==0){
            getSum(new_a);
        }
        dfs(new_a,1,deep+1);
    }

    vector<int>new_a2(29);
    for(int i=0;i<n;i++){
        new_a2[i]=a[d[i]-1]+t;
    }
    if((m-deep-1)%2==0){
        getSum(new_a2);
    }
    dfs(new_a2,2,deep+1);

}
int main(){
    cin>>n>>m>>t;
    init_vector(a);
    init_vector(b);
    init_vector(c);
    init_vector(d);
    dfs(a,2,0);
    cout<<max_sum<<endl;
    return 0;
}