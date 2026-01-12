#include<bits/stdc++.h>
using namespace std;

int N,M,T;
vector<vector<char>>grid;   //记录地图
vector<vector<bool>>visited;    //记录是否访问过
string ans="";


/**
 * @brief   判断两个字符串谁比较大，用于确定最后的答案。
 * @param   a   字符串a
 * @param   b   字符串b
 */
bool isGreater(string &a,string &b){
    if(a.length()!=b.length()){
        return a.length()>b.length();
    }else{
        return a>b;
    }
}

/**
 * @brief   深度优先搜索最佳答案
 * @param   x,y     起始坐标
 * @param   cur     当前的分数
 */

void dfs(int x,int y,string cur){
    if(isGreater(cur,ans)){
        ans=cur;        //只是更新答案，不用return
    }
    //定义上下左右移动
    vector<int>dx={-1,1,0,0};       //上下移动y不变x边，左右移动x不变y变。
    vector<int>dy={0,0,-1,1};       
    //尝试一下上下左右四个方向。
    for(int i=0;i<4;i++){
        int new_x=x+dx[i];  //记录一下新坐标
        int new_y=y+dy[i];
        if(new_x<0||new_x>=N||new_y<0||new_y>=M){   //如果新坐标不合理就退出尝试一下个
            continue;
        }
        if(grid[new_x][new_y]=='#'||visited[new_x][new_y]==true){   //如果新坐标的位置已经访问过了，或者是障碍物不能访问，尝试下一个
            continue;
        }
        visited[new_x][new_y]=true;
        dfs(new_x,new_y,cur+grid[new_x][new_y]);    //深度搜索新坐标
        visited[new_x][new_y]=false;    //回溯
    }
}




int main(){
    cin>>T;     //输入T组数据
    while (T--)
    {
        cin>>N>>M;
        ans=""; //每轮的ans都要初始化一下
        //初始化数组
        grid.assign(N,vector<char>(M,0));   
        visited.assign(N,vector<bool>(M,false));    
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>grid[i][j];
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]!='#'){
                    visited[i][j]=true;     //从节点i，j开始
                    string start;       //记录一下开始的成绩
                    start.push_back(grid[i][j]);   
                    dfs(i,j,start);
                    visited[i][j]=false;    //尝试下一个坐标，当然要把这次的坐标给false标记回去
                    
                }
            }
        }
        cout<<ans<<endl;
    }
    
}