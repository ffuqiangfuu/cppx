#include<bits/stdc++.h>
using namespace std;


int N;
int Sum;
vector<long long>coeffs;
vector<int>path;
vector<bool>used;

bool slove = false;

void dfs(int index,long long remainSum){
    if(slove==1){
        return;
    }
    if(index==N){
        if(remainSum==0){
            slove=true;
            for(int i=0;i<path.size();i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int num=1;num<=N;num++){
        if(used[num]==false){
            long long contribution=num*coeffs[index];
            if(contribution<=remainSum){
                used[num]=true;
                
                path[index]=num;
                dfs(index+1,remainSum-contribution);
                used[num]=false;

            }
        }
    }   

}


int main(){
    cin>>N>>Sum;
    coeffs.resize(N);
    path.resize(N);
    used.resize(N+1);   //因为是从1开始到N+1，一共N个；
    coeffs[0]=1;
    for(int i=1;i<N;i++){
        coeffs[i]=coeffs[i-1]*(N-i)/i;
    }
    dfs(0,Sum);
    if(slove==0){
        cout<<"GG"<<endl;
    }

    return 0;
}