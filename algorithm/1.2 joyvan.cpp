#include<bits/stdc++.h>
using namespace std;

int joyvan[1001][1001];
int row[1001];
int col[1001];

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){              //从1开始，交换第一行和第二行，就是对应数组的第一行第二行
        for(int j=1;j<=m;j++){
            scanf("%d",&joyvan[i][j]);
        }
    }
    for(int i=1;i<=1000;i++){           //row[i]的意思就是表面上第i行，实际上存的是第几行
        row[i]=i;
        col[i]=i;
    }
    while(q--){
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(op==0){
            swap(row[x],row[y]);
        }else if(op==1){
            swap(col[x],col[y]);
        }else{
            printf("%d\n",joyvan[row[x]][col[y]]);  //注意这个\n别漏了
        }
    }

    return 0;
}