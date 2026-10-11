#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N; // N명
	queue <int> q;
	int K; //제거 K

	cin >> N;
	cin >> K;
		
	// 순열에 값 집어넣기
	for (int i = 1; i <= N; i++) {
		q.push(i);
		}

	//요세푸스 알고리즘
	while (q.size() >0) {
		for (int i = 0; i < K-1; i++) {
			q.push(q.front()); 
			q.pop();

		}
		cout << q.front();
		q.pop();
	}

	return 0;
}