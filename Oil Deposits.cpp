# include <iostream>
# include <vector>
# include <queue>
using namespace std;
// 上下左右 斜對角

void bfs(int i, int j, vector<vector<char>>& graph, int& m, int& n){
    deque< pair<int, int> > dq;
    dq.push_back({i, j});

    while(dq.size()){
        int pointx = dq.front().second;
        int pointy = dq.front().first;
        if( !(pointx >= 0 && pointx < n && pointy >= 0 && pointy < m) ){
            dq.pop_front();
            continue;
        }
        graph[pointy][pointx] = '*';

        // 左
        if(pointx-1 >= 0 && graph[pointy][pointx-1] == '@'){
            dq.push_back({pointy, pointx-1}); 
        }  
        // 右
        if(pointx+1 < n && graph[pointy][pointx+1] == '@') dq.push_back({pointy, pointx+1}); 
        // 上
        if(pointy-1 >= 0 && graph[pointy-1][pointx] == '@') dq.push_back({pointy-1, pointx});
        // 下
        if(pointy+1 < m && graph[pointy+1][pointx] == '@') dq.push_back({pointy+1, pointx});
        // 左上
        if(pointx-1 >= 0 && pointy-1 >= 0 && graph[pointy-1][pointx-1] == '@') dq.push_back({pointy-1, pointx-1});
        // 右上
        if(pointx+1 < n && pointy-1 >= 0 && graph[pointy-1][pointx+1] == '@') dq.push_back({pointy-1, pointx+1});
        // 左下
        if(pointx-1 >= 0 && pointy+1 < m && graph[pointy+1][pointx-1] == '@') dq.push_back({pointy+1, pointx-1});
        // 右下
        if(pointx+1 < n && pointy+1 < m && graph[pointy+1][pointx+1] == '@') dq.push_back({pointy+1, pointx+1});
        dq.pop_front();
    }
}
int main(){
    int m = 0;
    int n = 0;
    while(cin >> m >> n){
        if( m == 0 && n == 0) break;
        vector< vector<char> > graph(m, vector<char>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> graph[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j] == '*') continue;
                bfs(i, j, graph, m, n);
                ans++;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}