#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct Time{
    int hour, minute;
};

Time addTime(Time curr, int t){
    curr.minute += t;
    if (curr.minute >= 60){
        curr.minute -= 60;
        curr.hour++;
    }
    return curr;
}

Time minusTime(Time curr, int t){
    curr.minute -= t;
    if (curr.minute < 0){
        curr.minute += 60;
        curr.hour--;
    }
    return curr;
}

bool comp(Time first, Time second){
//    if (first.hour == second.hour) return first.minute < second.minute;
//    return first.hour < second.hour;
    if (first.hour < second.hour) return true;
    else if (first.hour == second.hour){
        if (first.minute <= second.minute) return true;
        else return false;
    }
    return false;
}

bool checkWait(Time shuttle, Time crew){
    if (crew.hour < shuttle.hour) return true;
    else if (crew.hour == shuttle.hour) {
        if (crew.minute <= shuttle.minute) return true;
        else return false;
    }
    return false;
}

string solution(int n, int t, int m, vector<string> s_timetable) {
    string answer = "";

    vector<Time> timetable;
    for(int i = 0; i < s_timetable.size(); i++){
        string time = s_timetable[i];
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int minute = (time[3] - '0') * 10 + (time[4] - '0');
        timetable.push_back(Time{hour, minute});
    }
    sort(timetable.begin(), timetable.end(), comp);

    int num_crew = (int)timetable.size();
    Time shuttle = Time{9, 0};
    Time corn = minusTime(timetable[0], 1);

    int idx = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if (i != 0)
            shuttle = addTime(shuttle, t);

        if (idx < num_crew){
            while(true){
                if (checkWait(shuttle, timetable[idx])){
                    idx++;
                    cnt++;
                    if (idx == num_crew) break;
                    if (cnt == m) break;
                }
                else {
                    break;
                }
            }
        }

        // last shuttle
        if (i == n - 1){
            if (cnt < m){
                corn = shuttle;
                break;
            }
            else{
                if (idx > 0 && idx <= num_crew)
                    corn = minusTime(timetable[idx - 1], 1);
            }
        }


        cnt = 0;

    }

    answer.push_back(corn.hour/10 + '0');
    answer.push_back(corn.hour%10 + '0');
    answer.push_back(':');
    answer.push_back(corn.minute/10 + '0');
    answer.push_back(corn.minute%10 + '0');

    cout<<answer<<endl;

    return answer;
}

int main(void){
    solution(2, 10, 2, {"09:10", "09:09", "08:00"});
}