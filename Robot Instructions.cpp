# include <iostream>
# include <vector>
using namespace std;

int main(){
    int testcase = 0;

    while(cin >> testcase){

        while(testcase--){
            int n = 0;
            cin >> n;

            string str = "";
            vector<string> record(n);
            int result = 0;

            for(int i = 0; i < n; i++){
                cin >> str;
                
                if(str != "LEFT" && str != "RIGHT"){
                    int idx = 0;
                    string ignore;
                    cin >> ignore;
                    cin >> idx;
                    
                    record[i] = record[idx-1];
                }

                else{
                    record[i] = str;
                }
            }


            for(string s : record){
                if(s == "LEFT") result--;
                else result++;
            }
            cout << result << "\n";
        }
        
    }

    return 0;
}