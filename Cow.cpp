/*
题目描述
有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？

输入描述:
输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。


输出描述:
对于每个测试实例，输出在第n年的时候母牛的数量。

每个输出占一行。

输入例子:
2
4
5

输出例子:
2
4
6
*/
#include <iostream>
using namespace std;

int main() {
    unsigned arr[55];
    arr[0] = arr[1] = 1;
    int a = 1, b = 0, c = 0;
    int ta, tb, tc;
    for (int i = 1; i < 55; i++) {
        arr[i] = a + b + c;
        ta = a; tb =b; tc = c;
        a = ta + tb;
        b = tc;
        c = ta;
    }
    int n;
    while (cin >> n) {
        cout << arr[n] << endl;
    }
    return 0;
}