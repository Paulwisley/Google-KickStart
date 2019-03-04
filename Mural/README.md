### Problem Description

> Welcome to the Practice Session!
**Problem**
Thanh wants to paint a wonderful mural on a wall that is N sections long. Each section of the   wall has a beauty score, which indicates how beautiful it will look if it is   painted. Unfortunately, the wall is starting to crumble due to a recent flood, so he will need to work fast!
>
>  At the beginning of each day, Thanh will paint one of the sections of the wall. On the first day,   he is free to paint any section he likes. On each subsequent day, he must paint a new section   that is next to a section he has already painted, since he does not want to split up the mural.
 >
 >At the end of each day, one section of the wall will be destroyed.   It is always a section of wall that is adjacent to only one other section and is unpainted   (Thanh is using a waterproof paint, so painted sections can't be destroyed).
  The total beauty of Thanh's mural will be equal to the sum of   the beauty scores of the sections he has painted.   Thanh would like to guarantee that, no matter how the wall is destroyed, he can still achieve a total beauty of at least B.   What's the maximum value of B for which he can make this guarantee?

>**Input**
>The first line of the input gives the number of test cases, T. T test cases follow.   Each test case starts with a line containing an integer N. Then, another line follows containing   a string of N digits from 0 to 9. The i-th digit represents the beauty score of the i-th section of the wall.

>**Output**
>For each test case, output one line containing Case #x: y, where x is the   test case number (starting from 1) and y is the maximum beauty score that Thanh can   guarantee that he can achieve, as described above.

>**Limits**
>1 ≤ **T** ≤ 100.
Time limit: 20 seconds per test set.
Memory limit: 1 GB.

>**Small dataset (Test set 1 - Visible)**
2 ≤ N ≤ 100.

>**Large dataset (Test set 2 - Hidden)**
>For exactly 1 case, N = 5 × 106; for the other T - 1 cases, 2 ≤ N ≤ 100.

>**Samples**
> **Input** 	
><br/>
>4
><br/>
>4
><br/>
>1332 
><br/>
>4
><br/>
>9583
><br/>
>3
><br/>
>616
><br/>
>10
><br/>
>1029384756
>
>**Output**
><br/>
>Case #1: 6 &nbsp;&nbsp;&nbsp;Case #2: 14
><br/>
>Case #3: 7 &nbsp;&nbsp;&nbsp;Case #4: 31


### Analysis
#### 题目重述
这道题有点花里胡哨了，又是洪水又是糊墙。简单来说，是这样的，有这样一面墙，有*N*个区域，每个区域上都有权值，小明每天糊一个区域（随机），糊完的墙面在一天结束之后不会被摧毁，一般洪水都是从两端开始摧毁。问小明如何糊墙，不管洪水从哪边来袭，得到的最大权值为多少。

#### 分析
这题除了有点花里胡哨之外，其实也没有什么太大的难点。初始反应是拿贪心去求解，再往下思考，发现是个很经典的滑动窗口问题，稍微分析下就可以知道，在这个问题里，滑动窗口的大小为N/2，取N/2大小墙面，依次遍历，便可以得到最大的值.

#### 核心代码
```C++
vector<int> nums(N, 0);
nums = strToInt(mdigit);
int max = -1;
int left = 0, right = int(N/2.0 + 0.5) - 1;
//计算左右边界,都是标签位，index
for(; left < N - right; left++){
    cout<<left<<" ";
    int tmp = accumulate(nums.begin()+left, nums.begin() + right + left + 1, 0);
    int a = *(nums.end()-right-1+left);
    if(tmp > max)
        max = tmp;
}
```
>注：
>这里我习惯用stl解决这种问题了，但一开始的时候写太快，由于容器特有的左闭右开性质，我的索引计算出了点问题，后来认真算过之后，总算对了。（哎，我还真是浮躁啊，心粗的有点可怕了，#吐槽）

>这里还提供一种比较朴素的求解方法，即逐位相移的办法。
###### 看代码
```C++
int low=0, high = int(N/2.0 + 0.5)-1, max = 0;
int sum = 0;
while(high < N){
    if(sum > max)
        max = sum;
    sum = sum - num[low];
    ++low;
    ++high;
    sum = sum + num[high];
}
```
