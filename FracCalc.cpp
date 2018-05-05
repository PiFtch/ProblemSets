/*
分数运算
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
计算机中采用浮点数表示所有实数，但这意味着精度丢失。例如无法精确表示“1/3”。

NowCoder最近要处理很多金融问题，这些账目不允许出现精度丢失，因为差之毫厘谬之千里。你能帮他实现一套分数的计算器吗？

输入描述:
输入包含多组数据。

每组数据一行，包含两个分数和一个运算符，中间用空格隔开。

其中分子与分母均为不大于30的正整数。


输出描述:
对应每一组数据，输出两个分数的计算结果。

要求输出最简分数，即分子与分母互质。

输入例子:
1/3 2/3 +
1/5 1/4 -
1/2 1/3 *
2/3 4/3 /

输出例子:
1/1
-1/20
1/6
1/2
*/
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void simplize(int *numerator, int *denominator) {
    int sign = 1;
    if (*numerator < 0 && *denominator > 0 || *numerator > 0 && *denominator < 0)
        sign = -1;
    *numerator = abs(*numerator);
    *denominator = abs(*denominator);
    
    int div;
    if (*numerator > *denominator)
        div = gcd(*numerator, *denominator);
    else
        div = gcd(*denominator, *numerator);

    *numerator = *numerator / div * sign;
    *denominator = *denominator / div;
}
int main() {
    char op;
    int numeratorA, denominatorA,
        numeratorB, denominatorB;
    int resNumerator, resDenominator;
    while (cin >> numeratorA >> op >> denominatorA
               >> numeratorB >> op >> denominatorB >> op) {
        switch (op) {
            case '*':
                resNumerator = numeratorA * numeratorB;
                resDenominator = denominatorA * denominatorB;
                break;
            case '/':
                resNumerator = numeratorA * denominatorB;
                resDenominator = denominatorA * numeratorB;
                break;
            case '+':
                resDenominator = denominatorA * denominatorB;
                resNumerator = numeratorA * denominatorB + numeratorB * denominatorA;
                break;
            case '-':
                resDenominator = denominatorA * denominatorB;
                resNumerator = numeratorA * denominatorB - numeratorB * denominatorA;
                break;
            default:
                break;
        }
        simplize(&resNumerator, &resDenominator);
        cout << resNumerator << '/' << resDenominator << endl;


    }
    return 0;
}