# Number Guess

### Problem Description

> Welcome to the Practice Session!
**Problem**
  This problem is a well-known classic; we present it primarily as an opportunity   for you to try out the interactive judging system.
  We are thinking of an integer P within the range (A,B] —   that is, A < P ≤ B. You have N tries to guess our   number. After each guess that is not correct, we will tell you whether P is   higher or lower than your guess.
Input and output
  This problem is      interactive, which means that the concepts of input and output are different   than in standard Code Jam problems. You will interact with a separate process   that both provides you with information and evaluates your responses.   All information comes into your program via standard input; anything that you   need to communicate should be sent via standard output.   Remember that many programming languages buffer the output by default, so   make sure your output actually goes out (for instance, by flushing the   buffer) before blocking to wait for a response. See the   FAQ   for an explanation of what it means to flush the buffer.   Anything your program sends through standard error is ignored, but it might   consume some memory and be counted against your memory limit, so do not   overflow it. To help you debug, a local testing tool script (in Python) is   provided at the very end of the problem statement.
  Initially, your program should read a single line containing a single integer   T indicating the number of test cases. Then, you need to process   T test cases.
  For each test case, your program will read a single line with two integers   A and B, representing the exclusive lower bound and inclusive   upper bound, as described above. In the next line, you will read a single   integer N, representing the maximum number of guesses you can make.   Your program will process up to N exchanges with our judge.
  For each exchange, your program needs to use standard output to send a single   line with one integer Q: your guess. In response to your guess, the judge   will print a single line with one word to your input stream, which your   program must read through standard input. The word will be   CORRECT if your guess is correct, TOO_SMALL if your   guess is less than the correct answer, and TOO_BIG if your guess   is greater than the correct answer. Then, you can start another exchange.
  If your program gets something wrong (e.g., wrong output format, or   out-of-bounds values), the judge will send WRONG_ANSWER to your input   stream and it will not send any other output after that. If your program   continues to wait for the judge after receiving WRONG_ANSWER,   your program will time out, resulting in a Time Limit Exceeded error. Notice   that it is your responsibility to have your program exit in time to receive   the appropriate verdict (Wrong Answer, Runtime Error, etc.) instead of a Time   Limit Exceeded error. As usual, if the total time or memory is exceeded, or   your program gets a runtime error, you will receive the appropriate verdict.
  If your test case is solved within N tries, you will receive the   CORRECT message from the judge, as mentioned above, and then   continue to get input (a new line with two integers A and B,   etc.) for the next test case. After N tries, if the test case is not   solved, the judge will print WRONG_ANSWER and then stop sending output   to your input stream.
  You should not send additional information to the judge after solving all test   cases. In other words, if your program keeps printing to standard output after   receiving CORRECT for the last test case, you will get a Wrong Answer judgment.
**Limits**
  1 ≤ T ≤ 20.
 A = 0.   N = 30.
 **Time limit**: 10 seconds per test set.
  **Memory limit**: 1GB.
Test set 1 (Visible)
B = 30.
Test set 2 (Hidden)
B = 109.
>
>**Sample interaction**
  Here is a piece of pseudocode that demonstrates an interaction for one test set.   Suppose there are three test cases in this test set. The pseudocode first reads an   integer t, representing the number of test cases. Then the first test case begins.   Suppose the correct answer P is 9 for the first test case. The pseudocode first   reads three integers a, b, and n, representing the guessing range and maximum number of tries, respectively, and then outputs a guess 30. Since 30 is greater   than 9, the string **TOO_BIG** is received through stdin from the judge.   Then the pseudocode guesses 5 and receives **TOO_SMALL** in response.   The guess 10 is subsequently printed to stdout which is again too big. Finally   the pseudocode guesses 9, and receives **CORRECT** because 9 is the   correct answer.
>  ```C++
>  t = readline_int()         // reads 3 into t
>  a, b = readline_two_int()  // reads 0 into a and 30 into b; note that 0 30 is one line
 > n = readline_int()         // reads 30 into n
 > printline 30 to stdout     // guesses 30
 > flush stdout
  >string s = readline()      // because 30 > 9, reads TOO_BIG into s
>  printline 5 to stdout      // guesses 5
 > flush stdout
 > s = readline()             // reads TOO_SMALL  into s since 5 < 9
 > printline 10 to stdout     // guesses 10
  >flush stdout
 > s = readline()             // reads TOO_BIG into s since 10 > 9
 > printline 9 to stdout      // guesses 9
 > flush stdout
 > s = readline()             // reads CORRECT into s
 > ```
 > The second test case shows what happens if the code continues to read from stdin   after the judge stops sending info. In this example, the contestant guesses 31,   which is outside the range (0, 30]. As a result, the judging system sends WRONG_ANSWER   to the input stream of the pseudocode and stops sending anything after that.   However, after reading WRONG_ANSWER into string s, the code continues to read for   the next test case. Since there is nothing in the input stream (judge has stopped   sending info), the code hangs and will eventually receive a Time Limit Exceeded Error.
> ``` c++
> a, b = readline_two_int()  // reads 0 into a and 30 into b; note that 0 30 is one line
> n = readline_int()         // reads 30 into n
> printline 31 to stdout     // guesses 31
> flush stdout
> string s = readline()      // reads        WRONG_ANSWER
> a, b = readline_two_int()  // tries to read for the third test case but hangs since
>                             // judge has stopped sending info to stdin
>  ```
>  *If the code in the example above exits immediately after reading WRONG_ANSWER,   it will receive a Wrong Answer judgment instead.*
> ``` C++
> a, b = readline_two_int()  // reads 0 into a and 30 into b; note that 0 30 is one line
  >n = readline_int()         // reads 30 into n
  >printline 31 to stdout     // guesses 31
  >flush stdout
  >string s = readline()      // reads WRONG_ANSWER
  >exit                       // receives a Wrong Answer judgment    


### Analysis

这道题还是蛮有意思的，第一次做交互式的题目。
简单翻译下题目内容「 详细内容见[Problem Description](#10) 」
</br>
模拟猜数游戏
输入三个参数 **T**, **A**, **B**, **N**
-   T: 猜数游戏的轮数
-   A: 猜数的上限， B: 猜数的下限. 上开下闭
-   N: 单轮游戏的猜数次数

每次系统通过标准输入输出进行交互：从输出读取你猜的数，然后你通过标准输入获取系统给你的反馈。
- **TOO_BIG** 表示猜的太大，游戏继续
- **TOO_SMALL** 表示猜的太小，游戏继续
- **Correct** 表示猜的正确，此轮退出
- **WRONG_ANSWER** 猜的数越界或者单轮猜的次数用尽仍未得到答案

这道题相对来说还是比较简单的，第一反应使用二分查找来做，比较基础。但是自己在做的时候，出了很多岔子，比如漏状态，又比如把二分查找写的诡异无比，仿佛一年级新生一样，太丢脸了。看了某郑姓大佬的代码后，瞬间记忆恢复，这里再次做下记录，以防遗忘。

#### 二分查找
大佬的代码是每次对 [A, B] 取中，然后经过一次比较之后若得到的回馈是大了，则将mid减1，再另其为新的右边界，若是小了，则直接将mid当做是左边界，进行下一轮二分查找。不过这样做有个问题，到最后一轮的时候，如果要取得数刚好在右边界上的话，会一直取左边界作为新的中点，这个时候需要做一步处理，即，遇到这种情况时直接令mid=右边界。
```C++
//Code
while(n--){
    int mid = (b - a) / 2 + a;
    if(mid == a)
        mid = b;
    if(bigger) 
        b = mid - 1;
    else if(smaller) 
        a = mid;
    else 
        break;
}
```


我比较习惯另外一种方式，如果大了仍然将右边界减1，而如果小了则将左边界+1，这样不会出现上述的问题，更将方便快捷。
对了，为了防止在有大数的情况下越界，我也比较习惯用减法的方式取中 `int mid = (b - a) / 2 + a` 简略代码如下：
```C++
//Code
while(n--){
    int mid = (b - a) / 2 + a;
    if(bigger) 
        b = mid - 1;
    else if(smaller) 
        a = mid + 1;
    else 
        break;
}
```

