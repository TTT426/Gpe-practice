# include <bits/stdc++.h>
using namespace std;

void deal_plus(vector<vector<long long>>& record, long long m, int digit){
    vector<long long> vec(digit, 0);
    vec[0] = m;
    
    vector<long long> s;
    s = record.back();
    
    for(int i = 1; i < digit; i++){
        vec[i] = vec[i-1] + s[i-1]; 
    }
    
    // for(int i : vec) cout << i << "\n";
    record.push_back(vec);   
}


void deal_mul(vector<vector<long long>>& record, long long m, int digit){
    vector<long long> vec(digit, 0);
    vector<long long> s;
    s = record.back();
    
    vec[0] = m*s[0];
    
    
    
    for(int i = 1; i < digit; i++){
        vec[i] = vec[i-1] * s[i]; 
    }
    record.push_back(vec);   
}


long long get_first_num(stack<char>& s){
    string temp = "";
                
    while(s.top() != '['){
        temp += s.top();
        s.pop();
    }
    s.pop(); // 把 [ 弄掉
    
    reverse(temp.begin(), temp.end());
    long long int m = stoll(temp);
    return m;
}

int main(){
    string str = "";
    int digit = 0;
    
    while( cin >> str && cin >> digit){
        stack<char> s;
        vector<vector<long long>> record;
        bool first = true;
        
        for(int i = 0; i < str.size(); i++){
            s.push(str[i]);
            
            if(first && s.top() == ']'){ // 單純想 [ ] 
                s.pop();
                
                long long int n = get_first_num(s);
                vector<long long> vec;
                for(int k = 0; k < digit; k++) vec.push_back(n);
                record.push_back(vec);
                first = false;
    
            }
            
            else if(!first && s.top() == ']'){
                
                s.pop(); // 去除 ]
                if(s.top() == '+'){
                    s.pop();
                    
                    deal_plus(record, get_first_num(s), digit);
                }
                
                else if(s.top() == '*'){
                    s.pop();
                    
                    deal_mul(record, get_first_num(s), digit);
                }
            }
        }
            
        for(int j = 0; j < digit; j++){
            if(j == digit-1) cout << record.back()[j];
            else cout << record.back()[j] << " ";
            
        }
        cout << "\n";
    }
    return 0;
}