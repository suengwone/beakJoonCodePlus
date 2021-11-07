// 집합

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, num, answer=0;
	string command;
	cin >> M;

	while (M--) {
		cin >> command;
		
		if (command != "all" && command != "empty") {
			cin >> num;
		} else if (command == "all") {
			for (int i = 1; i <= 20; i++) {
				answer |= 1 << i;
			}
			continue;
		}
		else if (command == "empty") {
			answer = 0;
			continue;
		}

		if (command == "add") {
			answer += 1 << num;
		}
		else if (command == "check") {
			if (answer & (1 << num))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "remove") {
			if (answer & (1 << num))
				answer -= 1 << num;
		}
		else if (command == "toggle") {
			if (answer & (1 << num))
				answer -= 1 << num;
			else
				answer += 1 << num;
		}
	}
}
