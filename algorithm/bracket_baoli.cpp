#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;


bool isValid(const string &s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false; 
    }
    return balance == 0;
}

int main() {
   

    string S;
    cin >> S;
    int n = S.size();

    // 记录 * 的位置
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (S[i] == '*') pos.push_back(i);
    }
    int k = pos.size();

    long long countValid = 0;
    string lexMin = "", lexMax = "";

    // 2^k 枚举所有替换情况
    for (int mask = 0; mask < (1 << k); ++mask) {
        string cur = S;
        for (int j = 0; j < k; ++j) {
            cur[pos[j]] = (mask & (1 << j)) ? ')' : '(';
        }
        if (isValid(cur)) {
            countValid = (countValid + 1) % MOD;
            if (lexMin.empty() || cur < lexMin) lexMin = cur;
            if (lexMax.empty() || cur > lexMax) lexMax = cur;
        }
    }

    cout << countValid % MOD << "\n";
    if (countValid > 0) {
        cout << lexMin << "\n" << lexMax << "\n";
    }
    return 0;
}
