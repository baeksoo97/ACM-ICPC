#include <iostream>
using namespace std;
int main(void){
    int num, sum =0, i =1, prev = 0;
    scanf("%d",&num);
    while(1){
        sum += (i++);
        if(num <=sum){
            int down = num - prev ; 
            int up = i - down ;
            if (i%2 == 0)
                cout << up << "/" << down << endl;
            else   
                cout << down << "/" << up << endl;
            break;
        }   
        prev = sum ;
    }
}
//Input
// 14

//Output
//2/4