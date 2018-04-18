/*
题目描述
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。

输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。


输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。

输入例子:
1
2

输出例子:
1
2

*/

#include <iostream>
#include <cstdio>
using namespace std;
struct day {
    unsigned long mature;
    unsigned long immature;
};

day Rabbits(unsigned long n);

day Rabbits(unsigned long n) {
    day rabbitsAfterNdays;
    if (n == 1) {
        rabbitsAfterNdays.mature = 1;
        rabbitsAfterNdays.immature = 0;
    } else {
        day temp = Rabbits(n - 1);
        rabbitsAfterNdays.mature = temp.mature + temp.immature;
        rabbitsAfterNdays.immature = temp.mature;
    }

    return rabbitsAfterNdays;
}

int main() {
    long n;

    // Get input
    while (scanf("%ul", &n) == 1) {
        day rabbitsAfterNdays = {0, 0};
        rabbitsAfterNdays = Rabbits(n);
        cout << rabbitsAfterNdays.immature + rabbitsAfterNdays.mature << endl;
    }

    return 0;
}