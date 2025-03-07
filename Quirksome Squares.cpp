# include <iostream>
# include <cmath>
using namespace std;

// 加快版
/*
static_cast 是 C++ 中的一種顯式類型轉換運算符，用於在編譯階段執行類型轉換。
它比 C-style 的強制類型轉換（如 (type)value）更加安全、明確，並且適合於多種常見的類型轉換。
*/
int count_digits(int num) {
    if (num == 0) return 1; // 特殊情況：0 有 1 位
    return static_cast<int>(log10(num)) + 1;
}

int main(){
    int digits = 0;
    
    while(cin >> digits){
        int mul = 0;
        mul = pow(10, digits/2);
    
        for(int i = 0; i < mul; i++){ // 前半段的數字

            for(int j = 0; j < mul; j++){ // 後半段的數字
                if ( (i+j)*(i+j) == (i*mul+j)){
                    int ans = i*mul+j;
                    for(int i = 0; i < digits-count_digits(ans); i++){
                        cout << 0;
                    }
                    cout << ans << "\n";
                }
            }


        }
    
    }


}
