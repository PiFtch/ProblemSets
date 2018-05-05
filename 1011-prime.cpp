/*
NowCoder小定律
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<50),判定该表达式的值是否为素数

输入描述:
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。


输出描述:
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。

输入例子:
0 1
0 0

输出例子:
OK
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int x, y;
    int res, num;
    while (cin >> x >> y) {
        if (x == 0 && y == 0)
            return 0;
        bool flag = true;
        for (num = x; num <= y; num++) {
            res = num * num + num + 41;
            if (res > 2 && res % 2 == 0) {
                flag = false;
                break;
            } else {
                int bound = pow(res, 0.5);
                for (int i = 2; i <= bound; i++) {
                    if (res % i == 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                break;
        }
        cout << (flag ? "OK" : "Sorry") << endl;
    }
    return 0;
}