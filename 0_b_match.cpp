#include <iostream>
#include <vector>
using namespace std;

void input(vector<int>& arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}
}

int compare(vector<int>& a, vector<int>& b, int len_b, int start_index)
{
	int ret = 0;
	for(int i = 0; i < len_b; i++)
	{
		if(a[start_index + i] != b[i]) 
		{
			ret++; 
			if(ret > 1) return 2;
		}
		
	}
	return ret;
}

int main()
{
	int a, b;
	cin >> a >> b;

	vector<int> sub_a(a);
	vector<int> sub_b(b);

	input(sub_a, a);
	input(sub_b, b);

	int loc = -1;

	for(int i = 0; i <= a - b; i++)
	{
		int res = compare(sub_a, sub_b, b, i);
		if(res <= 1)
		{
			loc = i + 1;
			break;	
		}
	}

	cout << loc;

	return 0;
}
