#include<bits/stdc++.h>
using namespace std;


int m;  //走的步数
vector<int>d;   //存放距离数组
int path[30];   //path[i],表示第i步所在的坐标
int min_n=1000000;  //记录最小的步数

/**
 * @brief   dfs深度搜索可能存在的站点
 * @param   step    当前是第几步
 * @param   cur_pos 当前所在的位置
 * @param   count   已经访问过的不同站点的数量。
 */
void dfs(int step,int cur_pos,int count){
    //如果当前不同站点的数量已经大于最小站点数量的话直接剪枝，不用继续搜索了
    if(count>=min_n){
        return;
    }
    //已经走了m步还没提前剪枝说明，当前就是最小的站点数量。
    if(step==m){
        min_n=count;
        return; 
    }
    //记录下一个站点的位置，正向走
    int new_pos=cur_pos+d[step];
    bool is_new=true;   //记录一下这个站点是否是新的；
    for(int i=0;i<=step;i++){
        if(path[i]==new_pos){   //判断当前站点是不是新站点
            is_new=false;
            break;
        }
    }
    path[step+1]=new_pos;   //记录下一步站点的位置。
    if(is_new){
        dfs(step+1,new_pos,count+1);    //如果是新站点的话，count要加1
    }else{
        dfs(step+1,new_pos,count);  //如果不是新站点，count不变。
    }

    if(step==0) return;     //第一步你走正向，跟只走负向，得到的结果是一样的，只是坐标取负数了，所以我们就默认第一步只走正向，这样可以减少一半的搜索。

    //负向走
    new_pos=cur_pos-d[step];
    is_new=true;
    for(int i=0;i<=step;i++){   //我在第step步，检查的应该是0-step，所以cur_pos也是应该要检查的，所以要是<=
        if(path[i]==new_pos){
            is_new=false;
            break;
        }
    }
    path[step+1]=new_pos;
    if(is_new){
        dfs(step+1,new_pos,count+1);
    }else{
        dfs(step+1,new_pos,count);
    }

}



int main(){
    cin>>m;
    d.resize(m,0);
    for(int i=0;i<m;i++){   //输入
        cin>>d[i];
    }

    path[0]=0;      //起始点的坐标为0
    min_n=m+1;      //最坏的情况下，m步有m+1个站点
    dfs(0,0,1);
    cout<<min_n<<endl;
    return 0;
}