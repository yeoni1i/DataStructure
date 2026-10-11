#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int N; // 첫줄 수열 크기
	int a; //입력 정수
	int b=1; //오름차수 정수
	stack<int> st;
	vector<char> v; //벡터에 +,- 저장

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a;

		if (a >= b) {
			while (b <= a) {
				st.push(b);
				v.push_back('+');
				b++;
			}
			st.pop();
			v.push_back('-');
		}
		else {
			if (st.top() > a) {
				cout << "NO" << endl;
				return 0;
			}
			else {
				st.pop();
				v.push_back('-');
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}