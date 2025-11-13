#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<string>grid;   //地图
vector<vector<bool>>visited; //是否访问过
string ans;


// 判断哪个答案更大
bool isGreater(const string& a,const string & b){
    if(a.length()!=b.length()){
        return a.length()>b.length();
    }
    return a>b;
}

void dfs(int x,int y,string curr){
    if(isGreater(curr,ans)){
        ans=curr;
    }
    //这两个数组定义移动的方向，例如dx[0],dy[0]表示向上移动一格，x坐标减1，y坐标不变。
    vector<int>dx={-1,1,0,0};      
    vector<int>dy={0,0,-1,1};

    for(int i=0;i<4;i++){
        int new_x=x+dx[i];
        int new_y=y+dy[i];

        if(new_x<0||new_x>=N||new_y<0||new_y>=M){
            continue;
        }

        if(grid[new_x][new_y]=='#'||visited[new_x][new_y]==true){
            continue;
        }
        // 如果当前路径和最佳路径相同，且所有格子都是9也没法超过，则剪枝。
        if(curr.length()==ans.length()&&curr<ans){
            continue;
        }

        visited[new_x][new_y]=true;

        dfs(new_x,new_y,curr+grid[new_x][new_y]);

        visited[new_x][new_y]=false;

    }
}

int main(){
    int T;
    cin >> T; 
    
    while(T--){ 
        cin>>N>>M;
        grid.resize(N);
        visited.assign(N,vector<bool>(M,false));
        ans="";
        
        for(int i=0;i<N;i++){
            cin>>grid[i];
        }

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
        cout<<ans<<endl;
    }
    return 0;
}