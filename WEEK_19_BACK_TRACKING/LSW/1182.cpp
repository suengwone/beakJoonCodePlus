// 부분수열의 합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, S, cnt = 0;
	scanf("%d%d", &N, &S);

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	vector<int> check(N,false);

	for (int i = 0; i < N; i++) {
		sort(check.begin(), check.end(),greater<>());
		check[i] = true;
		int sum, rep;
		do {
			sum = 0, rep = i + 1;
			for (int j = 0; j < N; j++) {
				if (check[j]) {
					rep--;
					sum += arr[j];
					if (rep == 0) break;
				}
			}
			if (sum == S) cnt++;
		} while (prev_permutation(check.begin(), check.end()));
	}
	printf("%d\n", cnt);
}
