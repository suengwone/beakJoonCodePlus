// 막대기

#include <iostream>

using namespace std;

int main(void) {
	int X, cnt = 0;
	scanf("%d", &X);

  // 64는 2의 6승
	for (int i = 0; i < 7; i++) {
    // 비트 세주기
		if (X & (1 << i)) cnt++;
	}

	printf("%d\n", cnt);
}
