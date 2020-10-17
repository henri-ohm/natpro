#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;

	char c = s[0];
	int sublen = 0;
	int len = s.length();
	for(auto idx = 0; idx < len; idx++){
		if(c != s[idx]){
			cout << sublen << '\n';
			sublen = 0;
			c = s[idx];
		}

		sublen++;
	}

	cout << sublen;

	return 0;
}
