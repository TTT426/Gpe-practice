# include <bits/stdc++.h>
using namespace std;

int main(){
    
    int m = 0;
    while( cin >> m ){
        string str = "";
        cin.get();
        for(int i = 0; i < m; i++){
            getline(cin, str);
           
            vector<int> item;
            string temp = "";
            for(int i = 0; i < str.size(); i++){
                if(str[i] == ' '){
                    int num = stoi(temp);
                    item.push_back(num);
                    temp = "";
                    continue;
                }
                temp += str[i];
            }
            if(temp.size()) item.push_back(stoi(temp));
            
            // 背包
            long long int sum = 0;
            for(int i = 0; i < item.size(); i++) sum += item[i];
            if(sum%2){
                cout << "NO\n";
                continue;
            }
            
            int target = sum / 2;
            vector<int> dp(target+1, 0);

            for(int i = 0; i < item.size(); i++){
                for(int j = target; j >= item[i]; j--){
                    dp[j] = max(dp[j], dp[j-item[i]]+item[i]);
                }
                
            }
            
            if(dp[target] == target) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}