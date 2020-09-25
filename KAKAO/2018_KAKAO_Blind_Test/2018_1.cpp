#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getEndTime(string str){
    string s_time = "1";
    for(auto s: str){
        if (s != ':' && s != '.')
            s_time.push_back(s);
    }
    int time = stoi(s_time);
    return time;
}

int getProcessTime(string str){
    string s_time = "";

    for(auto s: str){
        if (s != '.' && s != 's') s_time.push_back(s);
    }
    while(true){
        if (s_time.length() == 4) break;
        s_time.push_back('0');
    }

    int time = stoi(s_time);
    return time;
}

int getStartTime(int endTime, int proTime){
    int startTime = endTime - proTime + 1;

    if (startTime % 100000 - startTime % 1000 >= 60000){
        startTime -= 40000;
    }
    if (startTime % 10000000 - startTime % 100000 >= 6000000){
        startTime -= 4000000;
    }

    return startTime;
}

int getMaxProcessMount(vector<pair<int, int>> timeTable){
    int answer = -1;

    for(int i = 0; i < timeTable.size(); i++){
        int start_area = timeTable[i].second - 1;
        int end_area = start_area + 1000;

        int total = 1;
        for(int j = i + 1; j < timeTable.size(); j++){
            int start = timeTable[j].first;
            int end = timeTable[j].second;
            if (start_area <= end && end <= end_area){
                total++;
            }
            else if (start_area <= start && start <= end_area){
                total++;
            }
            else if (start <= start_area && end_area <= end){
                total++;
            }
        }

        answer = max(answer, total);
    }
    return answer;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> timeTable;
    for(auto line : lines){
        int first_space = line.find(" ");
        int second_space = line.find(" ", first_space + 1);
        string s_time = line.substr(first_space + 1, second_space - first_space - 1);

        int endTime = getEndTime(s_time);
        int proTime = getProcessTime(line.substr(second_space + 1));
        int startTime = getStartTime(endTime, proTime);
        timeTable.push_back({startTime, endTime});
    }
    answer = getMaxProcessMount(timeTable);
    printf("%d\n", answer);
    return answer;
}

int main(void){
    solution({"2016-09-15 01:00:04.001 2.0s",
              "2016-09-15 01:00:07.000 2s"
             });
    solution({"2016-09-15 20:59:57.421 0.351s",
                     "2016-09-15 20:59:58.233 1.181s",
                     "2016-09-15 20:59:58.299 0.8s",
                     "2016-09-15 20:59:58.688 1.041s",
                     "2016-09-15 20:59:59.591 1.412s",
                     "2016-09-15 21:00:00.464 1.466s",
                     "2016-09-15 21:00:00.741 1.581s",
                     "2016-09-15 21:00:00.748 2.31s",
                     "2016-09-15 21:00:00.966 0.381s",
                     "2016-09-15 21:00:02.066 2.62s"
             });
    solution({"2016-09-15 01:00:04.002 2.0s",
                     "2016-09-15 01:00:07.000 2s"});

    return 0;
}