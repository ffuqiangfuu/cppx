#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 定义常量
// N: 商品数量上限（题目中N比较小，约300）
// M: 询问数量上限，同时也作为DP数组 f 的大小（假设最大原价总和不超过10万）
const int N = 310, M = 100010;

// 定义商品结构体
struct item {
    int c; // Cost: 折后价（我们付出的钱） -> 对应背包问题中的“体积/花费”
    int v; // Value: 原价（我们获得的价值） -> 对应背包问题中的“价值”
    int t; // Time:  上架时间 -> 限制条件
} items[N];

// 定义询问结构体
struct query {
    int t;  // Time:  询问发生的时间
    int m;  // Money: 你的预算
    int id; // ID:    这个询问原本是第几个输入的（用于最后按顺序输出答案）
} queries[M];

int n, m;           // n: 商品数, m: 询问数
int res[M];         // res: 存储每个询问的最终答案（最大原价）
int f[M];           // f[k]: 获得原价至少为 k，所需要的“最小花费”

// 比较函数1：让商品按“上架时间”从小到大排序
bool cmp1(item a, item b) { 
    return a.t < b.t; 
} 

// 比较函数2：让询问按“查询时间”从小到大排序
// 只有时间有序，我们才能用“离线处理”的方法，一遍扫过去
bool cmp2(query a, query b) { 
    return a.t < b.t; 
} 

int main() {
    // 1. 输入数据
    scanf("%d %d", &n, &m);
    
    int total_v = 0; // 记录所有商品的原价总和，确定DP数组的上限
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d %d %d", &items[i].c, &items[i].v, &items[i].t);
        total_v += items[i].v; // 累加最大可能的价值
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &queries[i].t, &queries[i].m);
        queries[i].id = i; // 必须记下它原来的位置，否则排序后就乱了，无法按原顺序输出
    }
    
    // 2. 核心预处理：排序
    sort(items + 1, items + n + 1, cmp1);   // 商品按时间排
    sort(queries + 1, queries + m + 1, cmp2); // 询问按时间排
    
    // 3. DP 初始化
    // 因为我们要在这个数组里求“最小花费”，所以初始值设为无穷大 (0x3f3f3f3f)
    // 这样在取 min() 的时候，才能把有效值更新进去
    memset(f, 0x3f, sizeof(f));
    
    // 获得 0 原价，显然只需要 0 花费。这是DP的起点。
    f[0] = 0;
    
    int j = 1; // j 是一个指针，指向当前还没上架的第一个商品
    
    // 4. 遍历每一个询问（时间轴推进）
    for (int i = 1; i <= m; i ++ ) { 
        
        // 【步骤 A：商品上架】
        // 只要当前商品的时间 items[j].t 早于或等于 询问时间 queries[i].t
        // 就说明这个商品在当前时间点是“可购买”的，把它加入背包
        while (j <= n && items[j].t <= queries[i].t) { 
            
            int c = items[j].c; // 当前商品的花费
            int v = items[j].v; // 当前商品的原价
            
            // 【步骤 B：0/1背包 DP 转移】
            // 我们倒序遍历价值 k (从最大可能价值 total_v 到当前商品价值 v)
            // f[k] = min(不买这个商品的花费, 买这个商品的花费)
            // 买这个商品的花费 = f[k - v] (凑出剩余价值的最小花费) + c (当前商品花费)
            for (int k = total_v; k >= v; k -- ) {
                f[k] = min(f[k], f[k - v] + c);
            }
            
            // 【步骤 C：维护单调性（关键优化）】
            // 这一步是为了修正 f 数组的含义，并让它支持二分查找。
            // 逻辑：如果凑出价值 k+1 只需要花费 100元，那凑出价值 k (比 k+1 少) 的花费肯定也不会超过 100元。
            // 比如：花100元买了价值500的东西，那我一定可以说“我花100元买了价值至少499的东西”。
            // 所以，我们用 f[k+1] 去更新 f[k]，保证 f[k] <= f[k+1]。
            // 经过这步，f[k] 的含义变成了：获得“至少” k 原价的最小花费。
            for (int k = total_v; k >= 0; k -- ) {
                f[k] = min(f[k], f[k + 1]);
            }
            
            j ++ ; // 当前商品处理完了，指针后移，准备看下一个商品
        }
        
        // 【步骤 D：回答询问】
        // 现在 f 数组已经是单调递增的了（价值越高，花费越高）。
        // 我们要找：在花费不超过 queries[i].m 的情况下，能买到的最大价值是多少？
        // 也就是找一个最大的 k，使得 f[k] <= queries[i].m。
        
        // upper_bound 查找 f 数组中 第一个 > queries[i].m 的位置。
        // 减去 f 再减 1，就是最后一个 <= queries[i].m 的位置（即我们能买得起的最大价值）。
        int max_val = upper_bound(f + 1, f + total_v + 1, queries[i].m) - f - 1;
        
        // 把答案存回原来的 ID 位置
        res[queries[i].id] = max_val;
    }
    
    // 5. 输出结果
    for (int i = 1; i <= m; i ++ ) {
        printf("%d\n", res[i]);
    }
        
    return 0;
}