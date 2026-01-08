#include<bits/stdc++.h>
using namespace std;

int pos1=0;     //全局变量记录一下不同字符的位置，方便后续删除字符。
int pos2=0;

//判断是否是魔法串，并且记录出现问题的位置。
bool check(string s)
{
    int begin=0;    //一个指针从字符的头开始
    int end=s.length()-1;   //一个指针从字符的尾巴开始
    while(begin<=end){
        if(s[begin]==s[end]){
            begin++;
            end--;
        }else{
            pos1=begin;
            pos2=end;
            return false;
        }
    }
    return true;
}


int main(){
    string s;
    cin>>s;
    if(check(s)){
        cout<<"true"<<endl;
    }else{
        int p1=pos1;    //这里要复制一下出现不同的位置，因为如果不复制的话，那么下面check(str1)的时候会把全局变量更改，那么check(str2)的时候就会有问题。
        int p2=pos2;
        string str1=s.erase(p1,1);  //earse(pos,len)    表示从pos的位置开始删除len个字符。
        string str2=s.erase(p2,1);
        if(check(str1)||check(str2)){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}