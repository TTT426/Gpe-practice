#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 自定義比較函數，從大到小排序
static bool cmp(int a, int b) {
    return a > b;
}

// 找到滿足條件的最大值d
int find(vector<int>& S, int count) {
    for (int i = 0; i < count; ++i) { // 從最大的d開始
        int d = S[i];
        for (int j = 0; j < count; ++j) {
            if (j == i) continue; // 確保d和a不同
            int a = S[j];
            for (int k = 0; k < count; ++k) {
                if (k == i || k == j) continue; // 確保d和b和a不同
                int b = S[k];
                for (int p = 0; p < count; ++p) {
                    if (p == i || p == k || p == j) continue; // 確保d和c和b和a不同
                    int c = S[p];
                    if (a + b + c == d) {
                        return d;
                    }
                }
            }
        }
    }
    return INT_MAX;
}

int main() {
    int count = 0;

    while (cin >> count) {
        if (count == 0) return 0;

        vector<int> S(count);
        for (int i = 0; i < count; i++) {
            cin >> S[i];
        }

        // 傳統array的排序，從大到小
        sort(S.begin(), S.end(), cmp);

        int result = find(S, count);
        if (result != INT_MAX)
            cout << result << "\n";
        else
            cout << "no solution\n";
    }

    return 0;
}