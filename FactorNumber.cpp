/*
因子个数
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。

输入描述:
输入包括多组数据。
每组数据仅有一个整数n (2≤n≤100000)。


输出描述:
对应每个整数，输出其因子个数，每个结果占一行。

输入例子:
30
26
20

输出例子:
3
2
2
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    int numOfFactors;
    while (cin >> n) {
        numOfFactors = 0;
        // int bound = sqrt(n);
        int lastFactor = 0;
        int i;
        if (n == 2)
            numOfFactors = 1;
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (i != lastFactor) {
                    lastFactor = i;
                    numOfFactors++;
                }
                n = n / i;
                i--;
            }
        }
        if (n != i)
            numOfFactors++;
        cout << numOfFactors << endl;
    }
}