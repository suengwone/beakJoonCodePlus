// 8진수 2진수

#include <string>
#include <iostream>

using namespace std;

int main(void) {
	// cin, cout 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int tmp;
	string N, answer = "";
	char alph;
	cin >> N;

	// 8진수에서 2진수로 변경은 1자리(8진수)에서 3자리(2진수)로 바꾸는 작업
	// ex) 75(8) => 111(2) : 7(8) + 101(2) : 5(8)

	// 주어진 문자열 N을 iterator로 순서대로 조회
	for (auto j = N.begin(); j != N.end(); j++) {
		// 8진수인 N의 한자리를 숫자로 변경 (아스키 코드 사용)
		tmp = *j - '0';

		// 3번 반복하여 인수분해 (8진수 -> 2진수 = 3번의 인수분해)
		for (int i = 0; i < 3; i++) {
			// tmp를 2로 나눈 나머지 값을 아스키코드를 사용하여 char 자료형으로 변경
			alph = tmp % 2 + '0';
			// 문자열 answer 앞에 char 자료형으로 바꾼 값을 더해줌
			answer = alph + answer;
			// tmp를 2로 나눈 몫을 tmp에 넣어줌
			tmp /= 2;
		}

		// 문자열이기 때문에 0으로 시작하는 수가 나올수 있음
		// 가장 처음 나오는 문자열이라면 int로 변경하여 앞에 나오는 0값 제거
		// 3자리씩 출력
		if (j != N.begin())
			cout << answer;
		else
			cout << stoi(answer);

		// 다시 answer 초기화
		answer = "";
	}
	cout << '\n';
}
