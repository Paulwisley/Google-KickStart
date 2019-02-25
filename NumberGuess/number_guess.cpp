#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;


int main(){
    int T;
    cin >> T;
    while(T--){
        long long a, b;
        int n;
        cin >> a >> b;
        cin >> n;
        // cout.flush();
        while(n--){
            long long mid = (b - a) / 2 + a;
            cout << mid << endl;
            cout.flush();
            string tmp;
            cin>>tmp;
            if(tmp == "TOO_BIG"){
                b = mid - 1;
            }else if(tmp == "TOO_SMALL"){
                a = mid + 1;
            }else {
                break;
            }
        }
    }
    return 0;
}
