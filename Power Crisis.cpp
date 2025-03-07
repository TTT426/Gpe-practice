#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 1;
    
    while(cin >> n){
        if(n == 0) break;
        
        if(n == 13) {
            cout << 1 << "\n";
            continue;
        }
        
        int m = 2;
        queue<int> q;
        n = n - 1;
        bool end = false;
        for(int i = 1; i <= n; i++) q.push(i);
        
        while(!end){
            
            while( q.size() != 1){
                for(int i = 0; i < m-1; i++){
                    q.push(q.front());
                    q.pop();
                }    
                q.pop();
            }
            
            if(q.front() == 12){
                cout << m << "\n";
                end = true;
            } 
            else{
                m++;
                q.pop();
                for(int i = 1; i <= n; i++) q.push(i);
            }
        }
    }

    return 0;
}