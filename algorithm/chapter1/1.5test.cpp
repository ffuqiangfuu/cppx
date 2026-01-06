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
        x=x/10;   //除10准备取下一位
    }
    return false;
}


int main(){
    int x;
    int ans=0;
    cin>>x;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            int fab1=i;
            int fab2=x/i;
            if(isSame(x,fab1)){
                ans++;
            }
            if(fab1!=fab2&&isSame(x,fab2))    ans++;    //如果两个因子是同一个数就不需要重复加，如果两个数不相同我们才考虑另一个因素，如果两个因素相同则不用考虑。
        }
    }
    cout<<ans<<endl;
    return 0;
}