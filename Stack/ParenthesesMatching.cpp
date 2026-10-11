#include<iostream>
#include <stack>
using namespace std;

int main()
{
	int N;
	string s;
	stack<char> st;
	bool success = true;

	cin >> N;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s.at(i);
		if (ch == '(') st.push(ch);

		else if (ch == ')')
			if (st.empty()) {
				success = false;
				break;
			}
			else if (st.top() == '(')
				st.pop();
	}

	if (success && st.empty())
		cout << "Yes" << endl;
	else
		cout << "NO" << endl;
}