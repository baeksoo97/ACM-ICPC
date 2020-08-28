#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    int x, y;
    scanf("%d %d",&x,&y);
    int sum =0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    for(int i=0;i<x-1;i++){
        sum += days[i];
    }
    sum += y;
    int num = (sum -1) % 7;
    cout << day[num] << endl;
}
//Input
// 1 1

//Output
// MON