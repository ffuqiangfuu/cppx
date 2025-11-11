#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (s[i - 1] == '(' || s[i - 1] == '*') {
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            if (s[i - 1] == ')' || s[i - 1] == '*') {
                if (j + 1 <= n) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    cout << dp[n][0] % MOD << '\n';

    if (dp[n][0] == 0) return 0;

    // ------------------------
    // 构造字典序最小的合法方案
    // ------------------------
    auto build = [&](bool lexMax) {
        string res = s;
        int depth = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                // 试 '(' first for lexMin, ')' first for lexMax
                vector<char> choice = lexMax ? vector<char>{')', '('} : vector<char>{'(', ')'};
                for (char c : choice) {
                    res[i] = c;
                    int tmp = depth + (c == '(' ? 1 : -1);
                    if (tmp < 0) continue; // illegal
                    // check remaining balance possible
                    int remain = n - i - 1;
                    if (tmp > remain) continue;
                    // temporarily accept this choice
                    depth = tmp;
                    break;
                }
            } else {
                depth += (s[i] == '(' ? 1 : -1);
            }
        }
        return res;
    };

    string lexMin = build(false);
    string lexMax = build(true);

    cout << lexMin << '\n';
    cout << lexMax << '\n';
    return 0;
}
