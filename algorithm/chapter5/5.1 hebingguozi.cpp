#include<bits/stdc++.h>
using namespace std;

bool found=false;
int res[15];    //记录生成的逆序数
bool used[15];   //用于生成逆序数的时候判断这个数字是否用过了
int coffee[15];  //杨辉三角数组
int Sum=0;
int N;


/**
 * @brief 生成杨辉三角系数
 * @param 杨辉三角数组
 */
void init_coffee(int coffee[]){
    for(int i=1;i<N;i++){
        coffee[i]=coffee[i-1]*(N-i)/i; 
    }
}
/**
 * @brief dfs遍历每个数字，让他们分别乘上杨辉三角系数
 * @param cur 当前正在填充的数字是什么
 * @param cur_sum 当前的总和是多少
 */
void dfs(int cur,int cur_sum){
    if(cur_sum>Sum){
        return;         //如果当前的和大于总的和，剪枝
    }
    if(found)   return;     //如果found找到了直接剪枝
    if(cur==N){
        if(cur_sum==Sum){
            for(int i=0;i<N;i++){
                cout<<res[i]<<" ";
                found=true;
            }    
            cout<<endl;
        }
        return;
    }

    for(int i=1;i<=N;i++)
    {
        if(used[i]==false){
            used[i]=true;
            res[cur]=i;
            dfs(cur+1,cur_sum+i*coffee[cur]);   //因为coffee[]杨辉三角系数只跟当前的位置有关，也就是cur的值，你当前正在填的这个值有关，所以要用当前填的数字i乘上当前的系数，coffee[cur];
            used[i]=false;
        }
    }
    
}



int main(){
    cin>>N;
    coffee[0]=1;    //杨辉三角第一个数永远是1
    init_coffee(coffee);
    cin>>Sum;
    dfs(0,0);
    return 0 ;
}