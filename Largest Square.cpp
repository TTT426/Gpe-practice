# include <bits/stdc++.h>
using namespace std;

int move_x[] = {0, +1, -1};
int move_y[] = {0, +1, -1};

int bfs(vector<vector<char>>& graph, int x, int y){
    int size = 1;
    deque< pair<int, int> > dq;
    dq.push_back({x, y});
    int m = graph.size();
    int n = graph[0].size();
    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    char target = graph[x][y];
    isVisited[x][y] = true;
    bool loop = true;
    
    int dq_size = dq.size();
    int state = 1;
    while(1){
        for(int k = 0; k < dq_size; k++){
            int start_x = dq.front().first;
            int start_y = dq.front().second;
            isVisited[start_x][start_y] = true;
            
            // cout << start_x << " " << start_y << ":\n";
            bool loop = true;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if( i == 0 && j == 0) continue;
        
                    int offset_x = move_x[i]+start_x; int offset_y = move_y[j]+start_y;
                    if(offset_x >= 0 && offset_x < m && offset_y >= 0 && offset_y < n && graph[offset_x][offset_y] == target){
                        if(isVisited[offset_x][offset_y]) continue;
                        else{
                            // cout << offset_x << " " << offset_y << "\n";
                            isVisited[offset_x][offset_y] = true;
                            dq.push_back({offset_x, offset_y});
                        }
                    }
                    
                    else{
                        loop = false;
                        break;
                    }
                }
                
                if(!loop) break;
            }
            
            dq.pop_front();
        }
        
        // cout << dq.size() << "\n";
        if(dq.size() == 8*state){
            state++;
            dq_size = dq.size();
            size += 2;
        }
        
        else{
            break;
        }
    }
    
    return size;
}

int main(){
    int testcase = 0;
    
    cin >> testcase;
    int m = 0;
    int n = 0;
    int query = 0;
    while( testcase-- ){
        cin >> m >> n >> query;
        vector<vector<char>> graph(m, vector<char>(n, '0'));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> graph[i][j];
            }
        }
        
        int x = 0;
        int y = 0;
        cout << m << " " << n << " " << query << "\n";
        for(int i = 0; i < query; i++){
            cin >> x >> y;
            cout << bfs(graph, x, y) << "\n";
        }
    }
    return 0;
}