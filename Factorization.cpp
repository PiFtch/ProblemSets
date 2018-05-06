/*
分解因数
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an,并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。

先给出一个整数a，请输出分解后的因子。

输入描述:
输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。


输出描述:
对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。

输入例子:
10
18

输出例子:
10 = 2 * 5
18 = 2 * 3 * 3
*/
/*
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n > 2 && n % 2 == 0)
        return false;
    int bound = pow(n, 0.5);
    for (int i = 2; i <= bound; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void factorize(int num) {
    if (isPrime(num))
        cout << num;
    else {
        int bound = pow(num, 0.5);
        for (int i = 2; i <= bound; i++) {

        }
    }
}
int main() {
    int a;
    while (cin >> a) {
        if (isPrime(a))
            continue;
        // int bound = pow(a, 0.5);
        // for (int i = 2; i <= bound; i++) {
        //     if (a % i == 0) {
        //         if (isPrime(i))
        //     }
        // }
    }
}
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a, bound;
    int j;
    while (cin >> a) {
        j = 2;
        bound = sqrt(a);
        cout << a << " = ";
        for (int i = 2; i <= bound; i = j) {
            if (a % i == 0) {
                cout << i << " * ";
                a = a / i;
                bound = sqrt(a);
                j = i;
            } else
                j++;
        }
        cout << a << endl;
    }
}