#include <iostream>
#include <vector>

using namespace std;

int N; 

// path: 存放当前正在构建的排列
// 比如 N=3 时，它会是 [1], [1, 2], [1, 2, 3] (打印), [1, 3], [1, 3, 2] (打印)...
vector<int> path;

// used: 标记数字 1 到 N 是否已被使用
// used[1] = true 表示 1 号球已经被放进 path 里了
vector<bool> used;

/**
 * @brief 深度优先搜索函数，用于生成全排列
 * @param index 当前正在填充 path 数组的第几个位置 (从 0 到 N-1)
 */
void dfs_generate_permutations(int index) {
    
    // 1. 基准情况 (Base Case):
    // 如果 N 个位置都已填满 (index 从 0 走到了 N)
    if (index == N) {
        // 我们找到了一个完整的排列，打印它
        for (int i = 0; i < N; ++i) {
            cout << path[i] << (i == N - 1 ? "" : " ");
        }
        cout << endl;
        return; // 结束这个分支
    }

    // 2. 递归步骤 (Recursive Step):
    // 尝试把 1 到 N 中的每一个数字，放入 path[index] 这个位置
    for (int num = 1; num <= N; ++num) {
        
        // 检查这个数字是否还没被用过
        if (!used[num]) {
            
            // --- 1. 做出选择 (Choose) ---
            // 把 num 放入当前位置
            path[index] = num;
            // 标记 num 为“已使用”
            used[num] = true;

            // --- 2. 深入探索 (Explore) ---
            // 递归地去填充下一个位置 (index + 1)
            dfs_generate_permutations(index + 1);

            // --- 3. 撤销选择 (Unchoose / Backtrack) ---
            // 当 dfs_generate_permutations(index + 1) 返回时，
            // 意味着所有以 path[0...index] 为前缀的排列都已找完。
            // 
            // 我们必须把 num "拿出来"，以便它可以在其他分支中被使用。
            // (比如：[1, 2, 3] 找完后，撤销 3，撤销 2，
            //        然后 [1, 3, ...]，此时 2 就可以被用了)
            used[num] = false; 
            
            // path[index] 的值会在下一次 for 循环时被覆盖，
            // 所以不需要显式地去 "清空" path[index]。
        }
    }
}

int main() {
    cout << "请输入 N: ";
    cin >> N;

    // 初始化辅助数组
    path.resize(N);               // 准备 N 个插槽
    used.resize(N + 1, false);  // N+1 是因为我们要用 1 到 N 的索引

    cout << "N=" << N << " 的所有全排列如下：" << endl;
    
    // 从第 0 个位置开始填充
    dfs_generate_permutations(0);

    return 0;
}