#include<bits/stdc++.h>
using namespace std;

bool isSame(int x,int d){
    while(x!=0){
        int tmp=d;  //用一个临时变量存住d
        int tmp1=x%10;  //取x的最后一位，然后依次取下一位
        while(tmp!=0){
            if(tmp%10==tmp1){   //看看d的最后一位是否和x的最后一位相等，如果没有取第二位
                return true;
            }
            tmp=tmp/10;     //除10准备取下一位
        }
        tmp1=tmp1/10;   //除10准备取下一位
    }
    return false;
}


int main(){
    int x;
    int ans=0;
    cin>>x;
    for(int i=1;i*i<=x;i++){
        int fab1=i;
        int fab2=x/i;
        if(isSame(x,fab1)){
            ans++;
        }

    }
    cout<<ans<<endl;
    return 0;
}