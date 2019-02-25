#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;


vector<int> strToInt(string mdigit){
   vector<int> ans;
   int len = mdigit.size();
   for(int i = 0; i < len; i++){
       int tmp = mdigit[i] - '0';
       ans.push_back(tmp);
   }
   return ans;
}

int main(){
   int T;
   cin >> T;
   int m = T;
   while(T--){
       /* code */
       long long N;
       cin >> N;
       string mdigit;
       cin >> mdigit;
       vector<int> nums(N, 0);
       nums = strToInt(mdigit);
       int max = -1;
       int left = 0, right = int(N/2.0 + 0.5) - 1;
       //计算左右边界,都是标签位，index
        for(; left < N - right; left++){
            int tmp = accumulate(nums.begin()+left, nums.begin() + right + left + 1, 0);
            if(tmp > max)
                max = tmp;
        }
        cout << "Case #" << m - T << ": "<<max<<endl;
   }
   return 0;
}
