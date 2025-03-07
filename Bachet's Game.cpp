# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int main() {

    int stone = 0;
    int item_number = 0;

    while (cin >> stone >> item_number) {

        vector<int> item(item_number, 0);

        for (int i = 0; i < item_number; i++) {
            cin >> item[i];
        }

        sort(item.begin(), item.end());

        // 一維 dp + 初始化 
        // dp[j] 定義 : 如果某玩家面前有j個石頭，有必勝策略的話則 為 true, 反之為 false
        vector<bool> dp(stone + 1, 0);
        dp[0] = false;

        // 應該是先遍歷 j 再遍歷 物品(可以走的步數)
        for(int j = 1; j <= stone; j++){
            for(int i = 0; i < item_number; i++){
                if(j >= item[i] && dp[j-item[i]] == false){
                    dp[j] = true;
                    break;
                }
            }
        }
        
        // for(int j = 0; j <= stone; j++){
        //     cout << dp[j] << " ";
        // }
        // cout << "\n";

        if (dp[stone]) {
            cout << "Stan wins\n";
        }

        else {
            cout << "Ollie wins\n";
        }
    }
    return 0;
}