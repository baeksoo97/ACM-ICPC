#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
const int ALPHABETS = 27;
map <string, int> queries_leader;
vector <int> queries_friends[100001];
vector <int> answer; 

class Trie {
private:
    Trie* child[ALPHABETS];
    int finish_idx = -1; 
public:
    Trie() {
        for (int i = 0; i < ALPHABETS; i++) {
            child[i] = NULL;
        }
    }

    ~Trie() {
        for (int i = 0; i < ALPHABETS; i++) {
            if (child[i] != NULL) delete child[i];
        }
    }

    int toIndex(const char word) {
        if (word == '?') return 26;
        else return word - 'a';
    }

    void insert(int idx, const char* words) {
        if (*words == '\0') {
            if (finish_idx == -1) {
                finish_idx = idx; 
            }
            return;
        }
        int next = toIndex(*words);
        if (child[next] == NULL) {
            child[next] = new Trie();
        }
        child[next]->insert(idx, words + 1);
    }

    void find(const char* words) {
        if (*words == '\0') {
            if (this->finish_idx != -1) {
                answer[this->finish_idx]++;
            }
            return;
        }
        int next = toIndex(*words);
        if (child[next] != NULL) {
            child[next]->find(words + 1);
        }
        if (child[26] != NULL) {
            child[26]->find(words + 1);
        }
        return;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    answer.assign(queries.size(), 0);
    Trie *trie = new Trie();

    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        if (queries_leader.count(query)) {
            queries_friends[queries_leader[query]].push_back(i);
        }
        else {
            queries_leader[query] = i;
        }
        trie->insert(i, query.c_str());
    }

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        trie->find(word.c_str());
    }

    for (int i = 0; i < answer.size(); i++) {
        for (auto q : queries_friends[i]) {
            answer[q] = answer[i];
        }
    }

    return answer;
}

int main(void) {
    vector<string> words ={"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = { "?????", "?????", "?????", "fro???", "pro?" };
    solution(words, queries);
}