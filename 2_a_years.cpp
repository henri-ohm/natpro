#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	using year = uint64_t;
	using is_death = bool;
	using event = pair<year, is_death>; // false - birth, true - death
	vector<event> events(2 * n); // birth or death events
	 
	uint64_t a, b;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		events[2 * i    ] = {a, false};
		events[2 * i + 1] = {b, true };
	}
	
	sort(events.begin(), events.end(), [](const event& a, const event& b){
		return a.first == b.first ? a.second > b.second : a.first < b.first;
	});
	
	int max_alive = 0, curr_alive = 0;
	year max_year = 0ULL;
	
	year birth, death;
	for(auto& ev: events)
	{
		curr_alive = curr_alive + (ev.second ? -1 : 1);
		
		if(curr_alive > max_alive)
		{
			max_alive = curr_alive;
			max_year = ev.first;
		}
	}
	
	cout << max_year << " " << max_alive << '\n';
}
