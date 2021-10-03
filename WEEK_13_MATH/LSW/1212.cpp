// 8진수 2진수

#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tmp;
	string N, answer = "";
	char alph;
	cin >> N;

	for (auto j = N.begin(); j != N.end(); j++) {
		tmp = *j - '0';
		for (int i = 0; i < 3; i++) {
			alph = tmp % 2 + '0';
			answer = alph + answer;
			tmp /= 2;
		}
		if (j != N.begin())
			cout << answer;
		else
			cout << stoi(answer);
		answer = "";
	}
	cout << '\n';
}
