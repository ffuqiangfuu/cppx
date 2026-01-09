#include<bits/stdc++.h>
using namespace std;
//本题的代码都是0-base
int main(){
    int n;
    cin>>n;
    
    if(n<2){
        cout<<0<<endl;
        return 0;
    }
    int x;  //第一个位置能到达的最大距离
    cin>>x;
    if(x>n-2){  //因为是0-base,如果大于n-2，那就是最小x=n-1，n-1刚好是最后一个位置的下标。
        cout<<1<<endl;
        return 0;
    }
    int step=1; //已经输入了一个x，所以已经走了一步了
    int currEnd=x;  //当前能达到的最远距离
    int nextfast=x;    //下一步能达到的最远距离
    for(int i=1;i<n;i++){
        cin>>x;     //输入下一个a[i]
        nextfast=max(nextfast,i+x);
        if(i==currEnd){     //如果达到当前能到达的最远距离
            currEnd=nextfast;   //更新下一步能到达的最远距离
            step++;     //步数+1；
            if(currEnd>n-2) break;  //0-base，n-2是倒数第二个坐标，n-1是最后一个，如果能大于n-2的话，那说明就能到达最后一个点了
        }
    }
    cout<<step<<endl;
    return 0;

    
}