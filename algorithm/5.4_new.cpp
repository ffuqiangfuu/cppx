#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<string>grid;
vector<vector<bool>>visited;
string maxRes;

bool compare(const string&a,const string&b)
{
    if(a.length()!=b.length()){
        return a.length()>b.length();
    }
    return a>b;
}

void dfs(int x,int y,string curr){
    if(compare(curr,maxRes)){
        maxRes=curr;
    }
    vector<int >dx={-1,1,0,0};
    vector<int >dy={0,0,-1,1};
    for(int i=0;i<4;i++){
        int nextx=x+dx[i];
        int nexty=y+dy[i];
        if(nextx<0||nextx>=N||nexty<0||nexty>=M){
            continue;
        }
        if(grid[nextx][nexty]=='#'||visited[nextx][nexty]==true){
            continue;
        }
        if(curr.length()==maxRes.length()&&curr<maxRes){
            continue;
        }
        visited[nextx][nexty]=true;
        dfs(nextx,nexty,curr+grid[nextx][nexty]);
        visited[nextx][nexty]=false;

        
    }
    
}
int main(){
    int T;
    cin>>T;
    while (T--)
    {
        cin>>N>>M;
        grid.clear();
        grid.resize(N);
        for(int i=0;i<N;i++){
            cin>>grid[i];
        }

        maxRes="";
        visited.assign(N,vector<bool>(M,false));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]!='#'){
                    
                    visited[i][j]=true;
                    string start(1,grid[i][j]);
                    dfs(i,j,start);
                    visited[i][j]=false;
                }
            }
        }
        cout<<maxRes<<endl;

    }
    
}