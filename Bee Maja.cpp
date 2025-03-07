# include <iostream>
# include <vector>
using namespace std;
/*
record[0] = 下 y+1
record[1] ＝ 左下 x-1 y+1
record[2] ＝ 左 x-1
record[3] ＝ 上 y-1
record[4] = 右上 x+1 y-1
record[5] ＝ 右 x+1


*/

inline void compute(vector<int>& record, vector<int>& step){
    for(int i = 0; i < 6; i++){
        record[i] += step[i];
        step[i] = 0;
    }
}

int main(){
    int num = 0;
    while(cin >> num){
        int state = 1;
        int idx = 0;

        vector<int> record = {0, 0, 0, 0, 0, 0};
        vector<int> step = {0, 0, 0, 0, 0, 0};
        
        for(int count = 1; count < num; count++){
            if(idx == 1 && step[idx] == state-1) idx++;
            step[idx]++;
            
            if(step[idx] == state){
                idx = (idx+1)%6;
                if(idx == 0){
                    compute(record, step);
                    state++;
                } 
            }
        }

        compute(record, step);
        
        int x = 0;
        int y = 0;

        x = (-1)*record[1]+(-1)*record[2]+record[4]+record[5];
        y = (-1)*record[3]+(-1)*record[4]+record[0]+record[1];
        cout << x << " " << y << "\n";
    }

    return 0;
}