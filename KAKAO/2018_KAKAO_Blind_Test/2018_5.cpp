#include <iostream>
#include <string>
#include <cctype>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
int answer = 0;

class LRUCache
{
    // store keys of cache 
    list<string> dq;

    // store references of key in cache 
    unordered_map<string, list<string>::iterator> ma;
    int csize; //maximum capacity of cache 

public:
    LRUCache(int);
    void refer(string);
    void display();
};

LRUCache::LRUCache(int n)
{
    csize = n;
}

/* Refers key x with in the LRU cache */
void LRUCache::refer(string x)
{
    // not present in cache 
    if (ma.find(x) == ma.end())
    {
        answer += 5;
        // cache is full 
        if (dq.size() == csize)
        {
            //delete least recently used element 
            string last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }

        // present in cache
    else {
        answer ++;
        dq.erase(ma[x]);
    }
    // update reference 
    dq.push_front(x);
    ma[x] = dq.begin();
}

// display contents of cache 
void LRUCache::display()
{
    for (auto it = dq.begin(); it != dq.end();
         it++)
        cout << (*it) << " ";

    cout << endl;
}

int solution(int cacheSize, vector<string> cities) {
    LRUCache ca(cacheSize);
    if (cacheSize == 0) answer = cities.size() * 5;
    else {
        for (int i = 0; i < cities.size(); i++) {
            string city = cities[i];
            for (int j = 0; j < city.length(); j++) {
                city[j] = tolower(city[j]);
            }
            ca.refer(city);
        }
    }
//    ca.display();
    printf("%d\n", answer);
    return answer;
}

// Driver program to test above functions 
int main()
{
    solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"});
    return 0;
} 