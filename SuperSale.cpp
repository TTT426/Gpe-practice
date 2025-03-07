# include <iostream>
# include <vector>
# include <climits>
using namespace std;

int main() {
	
	int test_case = 0;
	cin >> test_case;

	while (test_case) {
		int list_number = 0;
		cin >> list_number;
		vector<int> weight(list_number, 0);
		vector<int> price(list_number, 0);

		for (int i = 0; i < weight.size(); i++) {
			cin >> price[i] >> weight[i];
		}

		int person_num = 0;
		cin >> person_num;
		
		vector<int> query(person_num, 0);
		int max_backpack_space = 0;
		for (int i = 0; i < person_num; i++) {
			cin >> query[i];
			max_backpack_space = max(max_backpack_space, query[i]);
		}
		
		vector< vector<int> > dp(list_number, vector<int>(max_backpack_space+1, 0));

		// 初始化
		for (int i = 0; i < list_number; i++) {
			for (int j = 0; j <= max_backpack_space; j++) {
				dp[i][j] = 0;
			}
		}

		// 先放物品0 (不然遍歷時的通式 max(dp[i - 1][j], dp[i - 1][j - weight[i]] + price[i]) 會 超出邊界
		for (int j = weight[0]; j <= max_backpack_space; j++) {
			dp[0][j] = price[0];
		}

		// 遍歷
		for (int i = 1; i < list_number; i++) { // 物品
			for (int j = 0; j <= max_backpack_space; j++) { // 遍歷背包
				if (j < weight[i]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + price[i]);
			}
		}
			
		// 計算答案
		int ans = 0;
		for (int i = 0; i < query.size(); i++) {
			
			int best_result = 0;
			int container = query[i];
			for (int idx = 0; idx < list_number; idx++) best_result = max(best_result, dp[idx][container]);
			ans += best_result;
		}

		cout << ans << "\n";
		test_case--;
	}

	return 0;
}