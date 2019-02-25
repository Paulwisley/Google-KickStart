# KickStart Alarm
### Problem Description

> Welcome to the Practice Session!
>**Problem**
>Shil has a very hard time waking up in the morning each day, so he decides to buy a powerful alarm   clock to Kickstart his day. This Alarm is called a Kickstart Alarm. It comes pre-configured with   K powerful wakeup calls. Before going to bed, the user programs the clock with a Parameter   Array consisting of the values A1, A2, ..., AN.   In the morning, the clock will ring K times, with the i-th wakeup call having power POWERi.
  To calculate POWERi, the alarm generates all the contiguous subarrays of the Parameter   Array and calculates the summation of the i-th exponential-power of all contiguous subarrays.   The i-th exponential-power of subarray Aj, Aj+1, ..., Ak   is defined as Aj  × 1i + Aj+1 ×   2i + Aj+2 × 3i + ... + Ak × (k-j+1)i.   So POWERi is just the summation of the i-th exponential-power of all the contiguous subarrays of the Parameter Array.
  >
  >For example, if i = 2, and A = [1, 4, 2], then the i-th exponential-power of A would be calculated as follows:
>
>* 2-nd exponential-power of [1] = 1 × 1^2 = 1
>* 2-nd exponential-power of [4] = 4 × 1^2 = 4
>* 2-nd exponential-power of [2] = 2 × 1^2 = 2
>* 2-nd exponential-power of [1, 4] = 1 × 1^2 + 4 × 2^2 = 17
>* 2-nd exponential-power of [4, 2] = 4 × 1^2 + 2 × 2^2 = 12
>* 2-nd exponential-power of [1, 4, 2] = 1 × 1^2 + 4 × 2^2 + 2 × 3^2 = 35
  so the total is 71.
  Tonight, Shil is using his Kickstart Alarm for the first time. Therefore, he is quite worried about   the sound the alarm might make in the morning. It may wake up the neighbors, or, worse yet, it may wake up the whole planet!   However, calculating the power of each wakeup call is quite difficult for him.   Given K and the Parameter Array A1, A2, ..., AN,   can you help him by calculating the summation of power of each wakeup call:   POWER1 + POWER2 + ... + POWERK?
Input
  The first line of the input gives the number of test cases, T. T   test cases follow. Each test case consists of one line with nine integers   N, K, x1, y1, C, D, E1, E2 and F.   N is the length of array A, K is the number of wakeup calls.   Rest of the values are parameters that you should use to generate the elements of the array A, as follows.
   Use the recurrences below to generate xi and yi for i = 2 to N:    
>* xi = ( C × xi-1 + D × yi-1 + E1 ) modulo F.
>* yi = ( D × xi-1 + C × yi-1 + E2 ) modulo F.
We define Ai = ( xi + yi ) modulo F, for all i = 1 to N.
Output
  For each test case, output one line containing Case #x: POWER, where   x is the test case number (starting from 1) and POWER is the summation of POWERi, for i = 1 to K.   Since POWER could be huge, print it modulo 1000000007 (10^9 + 7).

>
>**Limits**
  1 ≤ **T** ≤ 100.
  **Time limit**: 90 seconds per test set.
 **Memory limit**: 1 GB.
  1 ≤ x1 ≤ 105.
  1 ≤ y1 ≤ 105
  1 ≤ C ≤ 105.
  1 ≤ D ≤ 105.
  1 ≤ E1 ≤ 105.
  1 ≤ E2 ≤ 105.
  1 ≤ F ≤ 105.
  >

>**Small dataset (Test set 1 - Visible)**
  1 ≤ **N** ≤ 100.
  1 ≤ **K** ≤ 20.


>**Large dataset (Test set 2 - Hidden)**
  1 ≤ **N** ≤ 106.
  1 ≤ **K** ≤ 104.
  
##### Samples
 >**Input** 
>
>2
2 3 1 2 1 2 1 1 9
> </br>
>10 10 10001 10002 10003 10004 10005 10006 89273

>**Output**
>
>Case #1: 52
> </br>
>Case #2: 739786670

```
In Sample Case #1, the Parameter Array is [3, 2].   
All the contiguous subarrays are [3], [2], [3, 2].
  For i = 1:   
* 1-st Exponential-power of [3] = 3 × 1^1 = 3
* 1-st Exponential-power of [2] = 2 × 1^1 = 2
* 1-st Exponential-power of [3, 2] = 3 + 2 × 2^1 = 7
  So POWER1 is 12.
  For i = 2:   
* 2-nd Exponential-power of [3] = 3 × 1^2 = 3
* 2-nd Exponential-power of [2] = 2 × 1^2 = 2
* 2-nd Exponential-power of [3, 2] = 3 + 2 × 2^2 = 11
  So POWER2 is 16.
  For i = 3:   
* 3-rd Exponential-power of [3] = 3 × 1^3 = 3
* 3-rd Exponential-power of [2] = 2 × 1^3 = 2
* 3-rd Exponential-power of [3, 2] = 3 + 2 × 2^3 = 19
  So POWER3 is 24.
```


### Analysis
这道题暂时没有想到什么好的方法，直接根据题目中讲的公式进行计算。开始时，自己犯了一个很蠢的错误，即没有进行绕弯的做法，纯粹暴力，将所有的可能的组合都跑出来，放在一个二维数组中，然后按照i = 1，2 ，3按阶计算。
```C++
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
```
*不得不说，太愚蠢了，哎。*

然后跟周巨讨论，发现，这他妈不是个等比数列嘛。
将所有的系数提取出来，剩下来的数就是个等比数列，然后根据该系数在数组所在的位置计算出其出现的次数，直接相乘即是我们欲求的结果。
```C++
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
```

最后，在记录下郑巨所说的快速幂问题，其实之前刷题也有遇到过，但就是真的忘记了，啥都不剩的那种，由此机会，赶紧再次学习下。

##### 快速幂
`暂时笔记本没有装写公式的软件，这里就先文字表述，回头配置好环境再补上`
简单来说，就是利用二分的思想，比如原来需要乘8次的幂运算换成两个四次的，原本要成6次的可以换成3个两次的。。。以此类推，这样子可以将原本n次的运算降低为logn / log2次

利用位运算的一些特性，可以得出很优美的代码
```C++
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
```

**注：**
****
* 按位与
    1. 只有当两个数都是1时相与才是1，即遇一个0就是0
    2. 利用该特性可以用来取最后一位或清零 X&1 
    3. 同样可以利用该特性进行奇偶判断
       * x&1为0 表示为偶数
       * x&1为1 表示为奇数
 * 按位或
    1. 进行按位或的两个数只要有一个为1，结果便为1
    2. 常用此方法将某个特定位置设为1
 * 按位异或
    1. 两个数异或，相同为0，否则为1
    2. 异或常用的骚操作：
        * 跟0异或，保留原值
        * 不借助临时变量进行交换
        ```
        a = a^b;b = a^b;a = a^b;
        ```
* 左移，右移操作
    * 左移 一般相当于乘2
    * 右移 一般相当于除以2
    * *注：当然在高系中学的左移，右移还有算术左/右移和逻辑左/右移等等的问题，目前还没在程序中遇到更复杂的用法（更骚的操作），遇到再进行总结，目前先记住这些吧*
