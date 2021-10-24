#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int height, width, input;
	cin >> height >> width;

	vector<int> block;
	for (int i = 0; i < width; i++) {
		cin >> input;
		block.push_back(input);
	}

	int rain = 0;
	if (block.size() >= 2) {
		for (int i = 1; i < width-1; i++) {
			int left_max = 0, right_max = 0;
			for (int j = 0; j < i; j++) left_max = max(left_max, block[j]);
			for (int j = width - 1; j > i; j--) right_max = max(right_max, block[j]);
			rain += max(0, min(left_max, right_max) - block[i]);
		}
		
	}
	cout << rain;
}
// https://hwan-shell.tistory.com/276