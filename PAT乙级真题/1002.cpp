/*
数字分类 (20)
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：



A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

输入描述:
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。


输出描述:
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入例子:
13 1 2 3 4 5 6 7 8 9 10 20 16 18

输出例子:
30 11 2 9.7 9
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    int arr[1000];
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        // A1
        int A1 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 5 == 0 && arr[i] % 2 == 0)
                A1 += arr[i];
        }

        // A2
        int A2 = 0;
        int exp = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] % 5 == 1)
                A2 += pow(-1, exp++) * arr[i];
        }

        // A3
        int A3 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 5 == 2)
                A3++;
        }

        // A4
        float A4;
        int sum = 0, div = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 5 == 3) {
                sum += arr[i];
                div++;
            }
        }
        if (div > 0)
            A4 = (float)sum / (float)div;

        // A5
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 5 == 4)
                if (arr[i] > max)
                    max = arr[i];
        }
        int A5 = max;

        //cout << A1 << " " << A2 << " " << A3 << " ";
        if (A1 == 0)
            cout << "N";
        else
            cout << A1;
        cout << " ";

        if (exp == 0)
            cout << "N";
        else
            cout << A2;
        cout << " ";

        if (A3 == 0)
            cout << "N";
        else
            cout << A3;
        cout << " ";

        if (div > 0)
            cout << fixed << setprecision(1) << A4;
        else
            cout << "N";
        cout << " ";

        if (A5 == 0)
            cout << "N";
        else
            cout << A5;
    }
    
}