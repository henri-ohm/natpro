#include<bits/stdc++.h>
#define FORI(n) for (int i = 0 ; i < (n); i++)
#define LOG(x) cout << (x) << '\n'
using namespace std;


vector<pair<uint64_t, uint64_t>> ST; // the segment tree

pair<uint64_t, uint64_t> largest(int index, int l, int r, int left, int right)
{
	if(l == left && r == right) return ST[index];

	int m = (l + r) / 2;

	if(right <= m) return largest(2 * index,     l,     m, left, right);
	if(left  >  m) return largest(2 * index + 1, m + 1, r, left, right);

	//at this point, left <= m <= right
	vector<uint64_t> ints(4);
	auto left_p  = largest(2 * index,     l,     m, left,  m);
	auto right_p = largest(2 * index + 1, m + 1, r, m + 1, right);

	ints.push_back(left_p.first);
	ints.push_back(left_p.second);
	ints.push_back(right_p.first);
	ints.push_back(right_p.second);	
	sort(ints.begin(), ints.end(), greater<uint64_t>());
	return make_pair(ints[0], ints[1]);
}

void add(int feri, int ocjena, int index, int l, int r)
{
	if(l == r)
	{
		ST[index] = make_pair(ocjena, 0ULL);
		return;
	}

	int m = (l + r) / 2;
	if(feri <= m) add(feri, ocjena, index * 2,     l,     m);
	else          add(feri, ocjena, index * 2 + 1, m + 1, r);

	vector<uint64_t> ints; // contains the max and second max of the left and right trees
	ints.push_back(ST[index * 2    ].first);
	ints.push_back(ST[index * 2    ].second);
	ints.push_back(ST[index * 2 + 1].first);
	ints.push_back(ST[index * 2 + 1].second);
	sort(ints.begin(), ints.end(), greater<uint64_t>());

	ST[index] = make_pair(ints[0], ints[1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, q;
    cin >> n >> q;
	ST = vector<pair<uint64_t, uint64_t>>(4 * n);

	uint64_t gr; //grade
	FORI(n)
	{
		cin >> gr;
		add(i, gr, 1, 0, n-1);
	}

	int num, l, r, x, y;
	FORI(q)
	{
		cin >> num;
		if(num == 1)
		{
			cin >> l >> r;
			cout << largest(1, 0, n - 1, l - 1, r - 1).second << '\n';
		}
		else
		{
			cin >> x >> y;
			add(x - 1, y, 1, 0, n - 1);
		}
	}
}
