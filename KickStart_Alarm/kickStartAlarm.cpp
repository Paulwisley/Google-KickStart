#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>

#define M 1000000007
using namespace std;

long long mPow(long long a, long long b);
vector<long long> createArray(long long N, long long x, long long y, long long C, long long D, long long E1, long long E2, long long F);
long long calculate(vector<long long> A, long long N, long long K);


long long mPow(long long a, long long b){
    long long ans = 1, base = a;
    while(b != 0){
        long long x = b&1;
        if(b&1){
            ans *= base;
        }
        base *= base;
        b >>= 1;
    }
    return ans;
}



vector<vector<long long> >calHelper(vector<long long>A){
    vector<vector<long long> > ans;
    int len = A.size();
    for(int i = 0; i < len; i++){
        int count = len - i;
        int num = 1;
        while(count--){
            vector<long long> tmp;
            int j = 0;
            while (j < num && (i + j) < len){
                tmp.push_back(A[i + j]);
                j++;
            }
            ans.push_back(tmp);
            num++;
        }
    }
    return ans;
}

long long calculate(vector<long long> A, long long N, long long K){
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        for(int j = i; j < N; j++){
            double q = i + 1;
            long long sn;
            if(q == 1){
                sn = K;
            }else{
                sn = (long long)(q * (1 - mPow(q, K)) / (1 - q));
            }
            long long tmp = A[j] * sn;
            tmp = tmp % M;
            //            cout << "sum =" <<tmp <<endl;
            long long all = tmp * (N - j);
            all = all % M;
            //            cout << "sn = "<< all<<endl;
            sum += all;
            sum = sum % M;        }
    }
    return sum;
}


int main(){
    int T;
    cout<<"?2"<<endl;
    cin>>T;
    cin.ignore();
    cin.clear();//重置错误输入
    cin.sync();//清空缓冲区

    long long N,K,x,y,C,D,E1,E2,F;
    while (T--) {
        int n = 1;
        cin>> N >> K >> x >> y >> C >> D >> E1 >> E2 >> F;
        vector<long long> tmp;
        tmp = createArray(N, x, y, C, D, E1, E2, F);
        //        vector<vector<long long> > mArray;
        //        mArray = calHelper(tmp);
        long long sum = calculate(tmp, N, K);
        cout<<"Case #"<<n<<": "<<sum<<endl;
        ++n;
    }
    return 0;
}

vector<long long> createArray(long long N, long long x, long long y, long long C, long long D, long long E1, long long E2, long long F){
    vector<long long> A;
    if(F == 0) return A;
    long long first = (x + y) % F;
    A.push_back(first);
    while (--N) {
        long long tmpX = (C * x + D * y + E1) % F;
        long long tmpY = (D * x + C * y + E2) % F;
        long long temp = (tmpX + tmpY) % F;
        A.push_back(temp);
        x = tmpX;
        y = tmpY;
    }
    return A;
}
