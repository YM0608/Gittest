/*
입력
첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는다.
합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력한다.
*/

#include<iostream>

using namespace std;

int main() {
	int N, M, arr[100], answer = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j< N - 1; ++j)
			for (int k = j + 1; k < N; ++k)
				//M 값을 넘지 않으면서 M 값과 최대한 가까운 3장의 합
				//첫 째 조건 : 3장의합이 M보다 작거나같음, 둘 째 조건 : 3장의합이 M과의 차이가 이전의 답보다 작아야 답 갱신.
				if ((arr[i] + arr[j] + arr[k] <= M) && ((M - (arr[i] + arr[j] + arr[k])) < (M - answer)))
					answer = arr[i] + arr[j] + arr[k];
	}
	
	cout << answer;
}