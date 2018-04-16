/* 一个学校有100个存物柜，100个学生。开学第一天所有存物柜都是关闭的。
   第一个学生来到学校后，打开所有存物柜。第二个学生S2，从第二个存物柜L2开始，每隔两个存物柜，将它们关闭。
   第三个学生S3从第三个存物柜L3开始，每隔三个将它们的状态改变。S4从L4开始每隔四个改变它们的状态，以此类推，
   直到S100改变L100的状态。   问：当所有学生完成后，哪些存物柜是开着的？    */


/* 使用一个100元数组作为存物柜，初始为0，每个元改变一次，其值加1。
   最后统计每个元的值，若为偶数则关闭，奇数则打开   */

#include <iostream>
#include <iomanip>
using namespace std;
#define STUDENTS 100
#define LOCKER 100
int L[LOCKER];

int main() {
    
    for (int student = 1; student <= STUDENTS; student++) {
        for (int locker = student - 1; locker < LOCKER; locker += student) {
            L[locker]++;
        }
    }

    for (int i = 0; i < LOCKER; i++) {
        if (L[i] % 2 != 0)
            cout << setw(4) << i;
    }

    return 0;
}