# include <bits/stdc++.h>
using namespace std;

int main(){
    
    int num = 0;
    while( cin >> num ){
        if(num == 0) break;
        string c = "";
        unordered_map<string, int> dice;
        
        dice["top"] = 1;
        dice["north"] = 2;
        dice["west"] = 3;
        dice["east"] = 4;
        dice["south"] = 5;
        dice["back"] = 6;
        
        for(int i = 0; i < num; i++){
            cin >> c;
            
            if(c == "north"){
                int original_south = dice["south"];
                int original_top = dice["top"];
                
                dice["top"] = original_south;
                dice["north"] = original_top;
            }
            
            else if(c == "east"){
                int original_west = dice["west"];
                int original_back = dice["back"];
                
                dice["top"] = original_west;
                dice["west"] = original_back;
            }
            
            else if(c == "south"){
                int original_north = dice["north"];
                int original_back = dice["back"];
                
                dice["top"] = original_north;
                dice["north"] = original_back;
            }
            
            else{ // c == "west"
                int original_east = dice["east"];
                int original_top = dice["top"];
                
                dice["top"] = original_east;
                dice["west"] = original_top;
            }
            
            dice["south"] = 7-dice["north"];
            dice["back"] = 7-dice["top"];
            dice["east"] = 7-dice["west"];
        }
        
        cout << dice["top"] << "\n";
    }
    
    return 0;
}