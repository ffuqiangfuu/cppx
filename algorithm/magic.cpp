#include<bits/stdc++.h>
using namespace std;

string s;
int pos1 = 0;
int pos2 = 0;


bool isMagic(string str) {
    int left = 0;
    int right = str.length() - 1;
    while (left <= right)
    {
        if (str[left] == str[right]) {
            left++;
            right--;
        }
        else {
            // 记录出错的位置
            pos1 = left;
            pos2 = right;
            return false;
        }
    }
    return true;

}

int main() {
    cin >> s;

    // 第一次检查
    if (isMagic(s)) {
        cout << "true" << endl;
    }
    else {
        int p1=pos1;
        int p2=pos2;
        string tmp1=s;
        string tmp2=s;
        tmp1.erase(p1,1);
        tmp2.erase(p2,1);
        if(isMagic(tmp1)||isMagic(tmp2)){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
        
    }

    return 0;
}