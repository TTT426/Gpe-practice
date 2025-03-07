# include <iostream>
# include <map>
using namespace std;

struct TrieNode {
	map<string, pair<TrieNode*, int>> children;
};

TrieNode* root = NULL;

void dfs(TrieNode* node) {

	for (auto& it : node->children) {
		string str = it.first;

		int cur_depth = it.second.second;
		for (int i = 0; i < cur_depth; i++) cout << " ";
		cout << str << "\n";

		dfs(it.second.first);
	}

	return;
}

int main() {
	int num = 0;

	while (cin >> num) {
		string str = "";
		map<string, int> m;
        root = new TrieNode;
        
		for (int i = 0; i < num; i++) {
			cin >> str;

			string substr = "";
			TrieNode* cur = root;
			int cur_depth = 0;

			for (char c : str) {

				if (c == '\\') {
					if (cur->children.find(substr) == cur->children.end()) {
						TrieNode* temp = new TrieNode;
						cur->children[substr] = { temp, cur_depth };
					}

					cur_depth++;
					cur = cur->children[substr].first;
					substr = "";
				}

				else {
					substr += c;
				}

			}

			// 尾巴處理
			if (cur->children.find(substr) == cur->children.end()) {
				TrieNode* temp = new TrieNode;
				cur->children[substr] = { temp, cur_depth };
			}

		}

		dfs(root);
		cout << "\n";
	}

	return 0;
}