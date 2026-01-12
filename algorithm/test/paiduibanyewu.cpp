#include<bits/stdc++.h>
using namespace std;


struct people{
    int T;
    int idx;
};

int n;

bool cmp(people a,people b){    //注意，当时间不同的时候看时间，当时间相同的时候看idx。
    if(a.T!=b.T)    return a.T<b.T;
    return a.idx<b.idx;
}

int main(){
    cin>>n;
    vector<people>peoples(n);
    for(int i=0;i<n;i++){
        cin>>peoples[i].T;
        peoples[i].idx=i;
    }
    sort(peoples.begin(),peoples.end(),cmp);
    vector<int>time(n);
    time[0]=0;
    for(int i=1;i<n;i++){
        time[i]=peoples[i-1].T+time[i-1];
    }
    int sum_time=0;
    for(int i=0;i<n;i++){
        sum_time+=time[i];
    }
    for(int i=0;i<n;i++){
        cout<<peoples[i].idx+1<<" ";
    }
    cout<<endl;
    double ans=double(sum_time)/n;
    printf("%.2f",ans);
    
}