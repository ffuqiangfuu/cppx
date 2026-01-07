#include<bits/stdc++.h>
using namespace std;

vector<vector<char>>a;
int n,x,y;

//画三角形的n，然后(x,y)是三角形区域左上角的坐标。
void draw(int n,int x,int y){
    if(n==1){
        //画最小的那个三角形
        a[x][y+1]='/';
        a[x][y+2]='\\';     //反斜杠要加转义符
        a[x+1][y]='/';
        a[x+1][y+1]='_';
        a[x+1][y+2]='_';
        a[x+1][y+3]='\\';

        return;
    }
    //开始准备画三个n-1的三角形；
    int h=pow(2,n-1);   //n-1个三角形的高
    int w=pow(2,n);     //n-1个三角形的宽
    draw(n-1,x,y+w/2);  //最上面那个三角形
    draw(n-1,x+h,y);    //左下角那个三角形
    draw(n-1,x+h,y+w);
}

int main(){
    cin>>n;
    a.resize(5000,vector<char>(5000,' '));  //初始化数组，n行，每行是大小为n，值为0的数组。
    draw(n,0,0);    //画三角形
    int h=pow(2,n);     //计算高度
    int w=pow(2,n+1);   //计算宽度
    //去掉多余空格并且输出；
    for(int i=0;i<h;i++){
        int last = w-1; //每行最多的长度到W-1，0-base
        while(last>=0&&a[i][last]==' ') last--;     //直到每行的最后一个有效字符。
        for(int j=0;j<=last;j++){
            cout<<a[i][j];
        }
        if(i!=h-1)  cout<<"\n";     //除了最后一行，每一行输出后都要回车进入下一行
    }
    
}