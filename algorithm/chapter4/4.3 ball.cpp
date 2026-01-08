#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<long long>a(n);  
    for(int i=0;i<n;i++)    cin>>a[i];
    unordered_map<long long,long long>count;    //定义一个unordered_map键值对，颜色-数量，统计一下每个颜色出现了几次
    for(int i=0;i<n;i++){   
        count[a[i]]++;  //a[i]这个颜色出现了几次
    }
    vector<long long>freq;  //统计频率
    for(auto it:count){     //auto it:count 遍历unordered_map，用迭代器指针it遍历。
        freq.push_back(it.second);  //把各种颜色出现的次数加入freq数组
    }
    sort(freq.begin(),freq.end());  //把频率数组排序，我们每次取数量最少的颜色，这样剩下的颜色种类就是最多的。
    int kinds=freq.size();      //颜色种类
    for(int i=0;i<freq.size();i++){
        if(k>=freq[i]){        //如果能把整个种类都取走，就用k减去这个颜色的数量。
            k-=freq[i];
            kinds--;        //取掉一个颜色就减一
        }else{
            break;
        }
    }
    cout<<kinds<<endl;
    return 0;
}