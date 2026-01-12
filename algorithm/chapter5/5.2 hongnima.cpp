#include<bits/stdc++.h>
using namespace std;

vector<int>borad;   //存放木板
int targe=0;
int n;
bool dfs(int idx,int s1,int s2,int s3){
    if(idx==n){
        return (s1==targe&&s2==targe&&s3==targe);
    }
    if(s1+borad[idx]<=targe){
        if(dfs(idx+1,s1+borad[idx],s2,s3))  return true;
    }
    if(s2+borad[idx]<=targe){
        if(dfs(idx+1,s1,s2+borad[idx],s3))  return true;
    }
    if(s3+borad[idx]<=targe){
        if(dfs(idx+1,s1,s2,s3+borad[idx]))  return true;
    }

    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        borad.resize(n,0);
        int sum=0;
        for(int i=0;i<borad.size();i++){
            cin>>borad[i];
            sum+=borad[i];
        }
        if(sum%3!=0){
            cout<<"No"<<endl;
            continue;
        }
        targe=sum/3;
        bool ok=true;
        for(int i=0;i<n;i++){
            if(borad[i]>targe){
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<"No"<<endl;
            continue;
        }
        
        if(dfs(0,0,0,0)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }


    }
    return 0;
}