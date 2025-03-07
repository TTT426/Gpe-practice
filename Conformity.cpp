# include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    while(cin >> n){
        if(n == 0) break;
        unordered_map< string, int > um;
        
        for(int i = 0; i < n; i++){
            string temp = "";

            vector<int> vec(5, 0);
            for(int k = 0; k < 5; k++){
                cin >> vec[k];
            }
            sort(vec.begin(), vec.end());
            
            for(int j = 0; j < 5; j++){
                temp += to_string(vec[j]); 
            }
            
            um[temp]++;
        }
        
        int Max = -1;
        for(auto& it : um){
            Max = max(Max, it.second);
        }
        
        int ans = 0;
        for(auto& it : um){
            if(it.second == Max) ans += Max;
        }
        
        cout << ans << "\n";
    }
    
    
    return 0;
}