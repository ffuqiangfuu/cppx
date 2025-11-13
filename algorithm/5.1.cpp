#include <iostream>
#include <vector>
#include <numeric> // 用不上，但通常和 vector 一起

// 使用 long long 来防止中间和溢出
using namespace std;

int N;
long long TargetSum;

// coeffs: 存储二项式系数 C(N-1, 0), C(N-1, 1), ...
vector<long long> coeffs;

// path: 存储我们当前正在构建的排列
vector<int> path;

// used: 标记数字 1 到 N 是否已被使用
vector<bool> used;

// 标记是否已找到解
bool solutionFound = false;

/**
 * @brief 深度优先搜索函数
 * @param index         当前正在填充 path 数组的第几个位置 (从 0 到 N-1)
 * @param remainingSum  还需要凑够多少和
 */
void dfs(int index, long long remainingSum) {
    // 关键优化：如果已经找到了一个解，立即停止所有其他搜索分支。
    // 因为我们是按字典序尝试的，第一个找到的解一定是最小的。
    if (solutionFound) {
        return;
    }

    // 基本情况：所有 N 个位置都已填满
    if (index == N) {
        // 检查和是否刚好等于目标和 (即剩余和为 0)
        if (remainingSum == 0) {
            solutionFound = true;
            // 打印结果
            for (int i = 0; i < N; ++i) {
                cout << path[i] << (i == N - 1 ? "" : " ");
            }
            cout << endl;
        }
        return; // 结束这个分支
    }

    // 递归步骤：尝试在 index 位置放入一个可用的数字
    // 为了保证字典序最小，我们从 1 到 N 依次尝试
    for (int num = 1; num <= N; ++num) {
        // 如果这个数字还没被用过
        if (!used[num]) {
            // 计算这个数字在当前位置的贡献
            long long contribution = num * coeffs[index];

            // 剪枝：如果当前数字的贡献已经超过了剩余所需的和，
            // 那么放这个数字肯定不行。
            // （也不用看更大的数字了，但我们用 continue 只是跳过这一个）
            if (contribution <= remainingSum) {
                
                // 1. 做出选择
                path[index] = num;
                used[num] = true;

                // 2. 进入下一层搜索
                //    目标是凑够 remainingSum - contribution
                dfs(index + 1, remainingSum - contribution);

                // 3. 撤销选择（回溯）
                //    注意：如果 solutionFound 已经是 true，
                //    我们其实可以不用回溯，直接层层返回。
                //    所以在函数开头加一个检查。
                used[num] = false; 
            }
        }
    }
}

int main() {
    // 提高cin/cout效率
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> TargetSum;

    // 初始化辅助数组
    coeffs.resize(N);
    path.resize(N);
    used.resize(N + 1, false); // N+1 是因为我们要用 1 到 N 的索引

    // 预计算二项式系数 C(N-1, k)
    // C(n, k) = C(n, k-1) * (n - k + 1) / k
    coeffs[0] = 1; // C(N-1, 0)
    for (int i = 1; i < N; ++i) {
        // coeffs[i] 存 C(N-1, i)
        // C(N-1, i) = C(N-1, i-1) * (N-1 - i + 1) / i
        coeffs[i] = coeffs[i - 1] * (N - i) / i;
    }

    // 开始从第 0 个位置搜索，目标和为 TargetSum
    dfs(0, TargetSum);

    // 如果搜索完毕仍未找到解
    if (!solutionFound) {
        cout << "GG" << endl;
    }

    return 0;
}