#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    int num;
    while(cin >> num){
        nums.push_back(num);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        if(size % 2)
            cout << nums[size/2] << "\n";  // 奇數情況
        else{
            long long int x = nums[size/2];
            long long int y = nums[size/2 - 1];
            // 如果想用浮點數計算平均值再取 floor，可以這樣：
            // cout << floor((x + y) / 2.0) << "\n";
            // 但由於 x,y 非負，直接整數除法也符合題目要求：
            cout << (x + y) / 2 << "\n";
        }
    }
    return 0;
}