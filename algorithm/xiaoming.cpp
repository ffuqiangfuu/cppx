#include <bits/stdc++.h>
using namespace std;
#define max 1000001 // 定义了价格的最大范围


// priceCount[j]表示以价钱j卖掉了多少
vector<long long> priceCount(max, 0); 
long long res = 0;       // 最终总收益
long long available = 0; // 当前可卖股票数

int main() {
    int n;
    int a, b, c;
    cin >> n; // 读入天数

    for (int i = 0; i < n; i++) { // 循环每一天
        cin >> a >> b >> c; // 读入a, b, c
        available += a;   // 1. 获得当天的股票

        // 2. 判断是情况一还是情况二
        if (available >= c) {
            // 情况一：股票充足
            priceCount[b] += c; // 更新账本：在b价卖了c个
            available -= c;     // 股票减少
            res += (b * c);     // 增加收益
        } else if (available < c) {
            // 情况二：股票不足
            // (A) 计算缺口
            long long regret = c - available; // 还需要补充多少股票
            // (B) 执行反悔操作
            for (int j = 1; j < b; j++) { // 遍历所有比今天便宜的价钱
                if (regret == 0) { // 缺口补足了，退出
                    break;
                }
                if (priceCount[j] > 0) { // 找到了以前在j价卖过的
                    
                    // 确定能反悔多少个
                    long long regret_amount = min(priceCount[j], regret);

                    // (C) 更新账本和收益
                    priceCount[j] -= regret_amount; // j价卖出的减少
                    priceCount[b] += regret_amount; // b价卖出的增多
    
                    res -= (j * regret_amount); // 减去j价的收益
                    res += (b * regret_amount); // 加上b价的收益

                    regret -= regret_amount; // 缺口减少
                }
            }
            // (D) 卖掉手上原有的股票
            // 别忘了，我们手上原有的available支股票也要卖掉
            priceCount[b] += available;
            res += (b * available);
            available = 0; // 手上股票卖完了
        }
    }
    cout << res << endl; // 输出总收益
    return 0;
}