
#include <bits/stdc++.h>
using namespace std;


bool check(vector<long long>& a, int N, int M, long long mid) {
    int cnt = 1; // 已选择第一个数
    long long last = a[0];
    for (int i = 1; i < N; i++) {
        if (a[i] - last >= mid) {
            cnt++;
            last = a[i];
        }
        if (cnt >= M) return true; // 已成功选出 M 个数
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());

    long long left = 0, right = a[N - 1] - a[0];
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (check(a, N, M, mid)) {
            ans = mid;
            left = mid + 1; // 尝试更大的间距
        } else {
            right = mid - 1; // 缩小间距
        }
    }

    cout << ans << "\n";
    return 0;
}
