# include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 利用 KMP 對兩個子字串
    // 找 S1 的前綴 跟 S2 的後綴
    // 的最長共同子字串
    
    string str = "";
    while(cin >> str){
        string s2 = str;
        reverse(s2.begin(), s2.end());
        
        string temp = s2 + '#' + str; // s2的前綴 + str 的後綴
        vector<int> Lps(temp.size(), 0);
        
        int i = 1;
        int prev = 0;
        while(i < temp.size()){
            if(temp[i] == temp[prev]){
                Lps[i] = prev+1;
                i++;
                prev++;
            }    
            
            else if(prev == 0){
                i++;
            }
            
            else{
                prev = Lps[ prev-1 ];
            }
        }
        
        string common = "";
        for(int i = 0; i < Lps.back(); i++){
            common += temp[temp.size()-i-1];
        }
        reverse(common.begin(), common.end());
        str.erase(str.size()-common.size(), common.size());
        // cout << common << " " << str << "\n";
        str += s2;
        cout << str << "\n";
    }
    
    return 0;
}