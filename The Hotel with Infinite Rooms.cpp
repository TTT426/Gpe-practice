# include <bits/stdc++.h>
using namespace std;

int main(){
    
    uint64_t init_size = 0;
    uint64_t day = 0;
    while( cin >> init_size >> day){
        uint64_t ans = init_size;
        
        while(day > ans){
            day -= ans;
            ans++;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}