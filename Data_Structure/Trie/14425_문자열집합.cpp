#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int TrieNode = 26;

class Trie {
private:
	Trie* child[TrieNode];
	bool finish = false;
public:
	Trie() {
		for (int i = 0; i < TrieNode; i++) {
			child[i] = NULL;
		}
	}
	~Trie() {
		for (int i = 0; i < TrieNode; i++)
			if (child[i]) delete child[i];
	}
	void insert(const char* words) {
		//words : like , *words : l
		//cout << *words << " " << endl;
		if (*words == '\0') {
			finish = true;
			return;
		}
		int next = *words - 'a';
		if (child[next] == NULL) {
			//printf("next child %d created\n", next);
			child[next] = new Trie();
		}
		child[next]->insert(words + 1);
	}

	bool find(const char* words) {
		int next = *words - 'a';
		if (*words == '\0') {
			if (finish) return true;
			else return false;
		}
		if (child[next] == NULL)
			return false;

		return child[next]->find(words + 1);
	}
};

int main(void) {
	int n, m, answer = 0;
	scanf("%d %d", &n, &m);
	
	Trie* trie = new Trie;
	char s[501];
	while (n--) {
		scanf("%s", s);
		trie->insert(s);
	}

	while (m--) {
		scanf("%s", s);
		if (trie->find(s)) {
			answer++;
		}
	}
	
	cout << answer << endl;
	return 0;
}