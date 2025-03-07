# include <iostream>
# include <unordered_map>
using namespace std;

// 句號是有意義的！
int check(string& word, unordered_map<string, int>& um){

    for(auto& it : um){
        if(it.first == word){
            return it.second;
        } 
    }

    return 0;
}

int main(){
    int m = 0;
    int n = 0;

    cin >> m >> n;
    unordered_map<string, int> um;
    for(int i = 0; i < m; i++){
        string s = "";
        cin >> s;
        int num = 0;
        cin >> num;

        um[s] = num;
    }
    
    string word = "";

    for(int i = 0; i < n; i++){
        int money = 0;    
        string str = "";

        while(cin >> str && str != "."){
            money += check(str, um);
        }
        
        cout << money << "\n";
    }
    return 0;
}