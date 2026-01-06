#include<bits/stdc++.h>
using namespace std;

int matrix[1001][1001];
int row[1001],col[1001];
int n,m,q;
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=1;i<=1000;i++){
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
            printf("%d\n",matrix[row[x]][col[y]]);
        }
    }
    return 0;
}