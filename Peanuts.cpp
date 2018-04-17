/*
题目描述
鲁宾逊先生有一只宠物猴，名叫多多。这天，他们两个正沿着乡间小路散步，突然发现路边的告示牌上贴着一张小小的纸条：“欢迎免费品尝我种的花生！——熊字”。

鲁宾逊先生和多多都很开心，因为花生正是他们的最爱。在告示牌背后，路边真的有一块花生田，花生植株整齐地排列成矩形网格。有经验的多多一眼就能看出，每棵花生植株下的花生有多少。
为了训练多多的算术，鲁宾逊先生说:“你先找出花生最多的植株，去采摘它的花生;然后再找出剩下的植株里花生最多的，去采摘它的花生;依此类推，不过你一定要在我限定的时间内回到路边。”

我们假定多多在每个单位时间内,可以做下列四件事情中的一件：

1. 从路边跳到最靠近路边（即第一行）的某棵花生植株；
2. 从一棵植株跳到前后左右与之相邻的另一棵植株；
3. 采摘一棵植株下的花生；
4. 从最靠近路边（即第一行）的某棵花生植株跳回路边。

现在给定一块花生田的大小和花生的分布，请问在限定时间内，多多最多可以采到多少个花生？

注意可能只有部分植株下面长有花生，假设这些植株下的花生个数各不相同。
例如花生田里只有位于(2, 5), (3, 7), (4, 2), (5, 4)的植株下长有花生，个数分别为 13, 7, 15, 9。多多在 21 个单位时间内，只能经过(4, 2)、(2, 5)、(5, 4)，最多可以采到 37 个花生。


输入描述:
输入包含多组数据，每组数据第一行包括三个整数 M（1≤M≤20）、N（1≤N≤20）和 K（0≤K≤1000），用空格隔开；表示花生田的大小为 M * N，多多采花生的限定时间为 K个单位时间。

紧接着 M 行，每行包括 N 个自然数 P（0≤P≤500），用空格隔开；表示花生田里植株下花生的数目，并且除了0（没有花生），其他所有植株下花生的数目都不相同。


输出描述:
对应每一组数据，输出一个整数，即在限定时间内，多多最多可以采到花生的个数。

输入例子:
6 7 21
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0

输出例子:
37

*/
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

#define MAX_NUM 55

int main() {
    int M, N, K;
    int T = 10;
    while(scanf("%d %d %d", &M, &N, &K) == 3) {
    // cin >> M >> N >> K;
    int peanutField[MAX_NUM][MAX_NUM];
    // Initialize array
    for (int row = 0; row < M; row++)
        for (int column = 0; column < N; column++)
            cin >> peanutField[row][column];
    
    // store current position
    int currentRow = 0, currentColumn;
    // state
    int totalPeanuts = 0;
    int totalTime = 0;
    

    // begin
    while (totalTime < K) {         // first step is to jump into the field, so make totalTime < K(not <=)
        // store largest element's position
        int maxPeanuts = 0;
        int maxRow;
        int maxColumn;
        // find the largest element in each round
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (peanutField[i][j] > maxPeanuts) {
                    maxRow = i;
                    maxColumn = j;
                    maxPeanuts = peanutField[i][j];
                }
            }
        }

        if (maxPeanuts == 0)
            break;
        // Initialize position
        if (currentRow == 0)
            currentColumn = maxColumn;

        if (totalTime + abs(static_cast<double>(currentRow - maxRow)) + abs(static_cast<double>(currentColumn - maxColumn)) + 1 + maxRow <= K) {
            // state after each round
            totalTime += (1 + abs(static_cast<double>(currentRow - maxRow)) + abs(static_cast<double>(currentColumn - maxColumn)));
            totalPeanuts += maxPeanuts;
            currentRow = maxRow;
            currentColumn = maxColumn;
            peanutField[maxRow][maxColumn] = 0;
        } else
            break;
    }
    cout << totalPeanuts << endl;
    }
}