#include <iostream>

using namespace std;

int Answer;
int R, S, E, N;

int main(int argc, char** argv)
{
	int T, test_case;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d %d", &R, &S, &E);
		scanf("%d", &N);
		Answer = 0;
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}