# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

void bfs(vector<vector<char>>& graph, char target, int x, int y) {
	deque< pair<int, int> > dq;
	dq.push_back({ x, y });
	int m = graph.size();
	int n = graph[0].size();

	while (dq.size()) {
		int i = dq.front().first;
		int j = dq.front().second;
		graph[i][j] = '0';
		dq.pop_front();

		if (i - 1 >= 0 && graph[i - 1][j] == target) {
			dq.push_back({ i - 1, j });
		}

		if (i + 1 < m && graph[i + 1][j] == target) {
			dq.push_back({ i + 1, j });
		}

		if (j - 1 >= 0 && graph[i][j - 1] == target) {
			dq.push_back({ i, j - 1 });
		}

		if (j + 1 < n && graph[i][j + 1] == target) {
			dq.push_back({ i, j + 1 });
		}
	}

	return;
}

bool cmp(const pair<int, char>& a, const pair<int, char>& b) {
	if (a.first != b.first) {
		return a.first > b.first;
	}

	else {
		return a.second < b.second;
	}
}
int main() {
	int world_num = 0;

	while (cin >> world_num) {

		for (int i = 1; i <= world_num; i++) {
			int m = 0;
			int n = 0;
			cin >> m >> n;
			vector<vector<char>> graph(m, vector<char>(n, '0'));
			vector<pair<int, char>> record(26);
            
			for (int k = 0; k < m; k++) {
				for (int j = 0; j < n; j++) {
					cin >> graph[k][j];
				}
			}
            
			// bfs
			for (int k = 0; k < m; k++) {
				for (int j = 0; j < n; j++) {
					if (graph[k][j] != '0') {
						char target = graph[k][j];
						record[target - 'a'].first++;
						record[target - 'a'].second = target;
						bfs(graph, target, k, j);
					}
				}
			}

			sort(record.begin(), record.end(), cmp);
			cout << "World #" << i << "\n";
			
			for (int i = 0; i < 26; i++) {
				if (record[i].first == 0) continue;
				cout << record[i].second << ": " << record[i].first << "\n";
			}
		}
	}
}