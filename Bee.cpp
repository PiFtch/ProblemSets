/*
蜜蜂寻路
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
nowcoder利用业余时间养了一窝蜜蜂，因为空间比较小，蜂房只有两排，如下图所示：



如你所见，蜜蜂的蜂房是正六边形，假设蜜蜂只会从左往右爬，即从1号蜂房能爬到2号和3号；从6号蜂房能爬到7号和8号……

现给出两个蜂房的编号a和b，要求计算蜂房a的蜜蜂爬到蜂房b有几条不同路线。

输入描述:
1. 输入的第一行是一个整数n
2. 接下来n行数据，每行一组测试用例
3. 每组测试用例包含两个正整数a和b，(0 < a < b < 2^31)


输出描述:
每组用例的结果单独输出一行。输出数据结果范围是 [0, 2^63)。

输入例子:
3
1 2
3 6
99 100

输出例子:
1
3
1
*/
#include <iostream>
using namespace std;
// int main() {
//     unsigned n, a, b;
//     unsigned num;
//     unsigned long long temp, p, q;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a >> b;
//         num = b - a;
//         p = 0, q = 1;
//         for (int j = 1; j <= num; j++) {
//             int temp = p + q;
//             p = q;
//             q = temp;
//         }
//         cout << q << endl;
//     }
//     return 0;
// }

int main() {
    long long arr[103] = {1,1,2};
    for (int i = 3; i < 103; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    int n, a, b, d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        d = b - a;
        cout << arr[d] << endl;
    }
}