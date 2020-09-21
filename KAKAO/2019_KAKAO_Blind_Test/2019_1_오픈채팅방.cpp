#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map <string, string> users;

void enter(string id, string name) {
    users[id] = name;
}

void change(string id, string name) {
    users[id] = name; 
}

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<string> row;
    for (auto r : record) {
        int first_space = r.find(" ") + 1;
        int second_space = r.find(" ", first_space) + 1;
        string id = r.substr(first_space, second_space - first_space - 1);
        string name = r.substr(second_space);
        if (r[0] == 'E') {
            enter(id, name);
        }
        else if (r[0] == 'C') {
            change(id, name);
        }
        row.push_back(id);
    }

    for (int i = 0; i < record.size(); i++) {
        string id = row[i];
        string name = users[id];
        string s = "";
        if (record[i][0] == 'E') {
            s = name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(s);
        }
        else if (record[i][0] == 'L') {
            s = name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(s);
        }
        cout << s << endl;
    }

    return answer;
}

int main(void) {
    solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
}