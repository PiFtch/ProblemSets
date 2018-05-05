/*
童年生活二三事
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
NowCoder小时候走路喜欢蹦蹦跳跳，他最喜欢在楼梯上跳来跳去。
但年幼的他一次只能走上一阶或者一下子蹦上两阶。
现在一共有N阶台阶，请你计算一下NowCoder从第0阶到第N阶共有几种走法。

输入描述:
输入包括多组数据。每组数据包括一个整数n, (1≤n≤90)。


输出描述:
对应每个输入包括一个输出。
为redraiment到达第n阶不同走法的数量。

输入例子:
1
2

输出例子:
1
2
*/
#include <iostream>
using namespace std;

int main() {
    unsigned long long arr[91] = {1,1,2,3,5,8};
    for (int i = 6; i <= 90; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    int n;
    while (cin >> n) {
        cout << arr[n] << endl;
    }
}   