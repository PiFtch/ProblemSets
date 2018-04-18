/*
客似云来
时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述
NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。

于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……

现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。

输入描述:
测试数据包括多组。

每组数据包含两个整数from和to(1≤from≤to≤80)，分别代表开店的第from天和第to天。


输出描述:
对应每一组输入，输出从from到to这些天里（包含from和to两天），需要做多少份早餐。

输入例子:
1 10
2 8
36 80
*/

#include <iostream>
#include <cstdio>
using namespace std;
/*
struct customersPerDay {
    unsigned long Old;
    unsigned long New;
};

customersPerDay CustomersOfNstDay(unsigned long n) {
    customersPerDay customers;
    if (n == 1) {
        customers.Old = 0;
        customers.New = 1;
    } else {
        customersPerDay customersOfPrevDay = CustomersOfNstDay(n - 1);
        customers.Old = customersOfPrevDay.New + customersOfPrevDay.Old;
        customers.New = customersOfPrevDay.Old;
    }

    return customers;
}
*/

/*
int main() {
    int from, to;
    while (scanf("%d %d", &from, &to)) {
        unsigned long sum = 0;

        for (int i = from; i <= to; i++) {
            customersPerDay temp = CustomersOfNstDay(i);
            sum += temp.New + temp.Old;
        }
        cout << sum << endl;
    }
    return 0;
}
*/

unsigned long Fib(int n) {
    int p = 1, q = 1;
    if (n == 1 || n == 2)
        return static_cast<unsigned long>(1);
    else {
        for (int i = 3; i <= n; i++) {
            int temp = p;
            p = q;
            q = temp + p;               // q为斐波那契数列第i个值
        }
        return q;
    }
}
        
/*
int main() {
    int from, to;
    while (~scanf("%d %d", &from, &to)) {
        unsigned long sum;
        //unsigned long prev1 = Fib(from);
        if (from == to || from >= (to - 2)) {   // from to 相距小于等于1
            sum = 0;
            for (int i = from; i <= to; i++) {
                sum += Fib(i);
            }
        } else {        // 相距大于1
            unsigned long prev1 = Fib(from);
            unsigned long prev2 = Fib(from + 1);
            unsigned long current;
            sum = prev1 + prev2;
            for (int i = from + 2; i <= to; i++) {
                current = prev1 + prev2;
                sum += current;
                prev1 = prev2;
                prev2 = current;
            }
        }

        cout << sum << endl;
        
    }
    return 0;
}
*/

int main() {
    int from, to;
    while (cin >> from >> to) {
        unsigned long long sum = 0;
        if (from == to)
            sum = Fib(from);
        else {
            for (int i = from; i <= to; i++)
                sum += Fib(i);
        }
        cout << sum << endl;
    }
    return 0;
}
        
