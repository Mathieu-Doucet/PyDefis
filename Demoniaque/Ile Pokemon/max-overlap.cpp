// https://www.geeksforgeeks.org/maximum-number-of-overlapping-intervals/
// Maximum number of overlap among given ranges
#include <bits/stdc++.h>
using namespace std;

// Nombre maximal d'overlaps
int overlap(const vector<pair<int, int>> &v)
{ 
	int ans = 0, count = 0;

	// On crée des associations first <--> 'x' et second <--> 'y'
	vector<pair<int, char>> data;

	for(size_t i = 0; i < v.size(); i++)
	{
		data.push_back({v[i].first, 'x'});
		data.push_back({v[i].second, 'y'});
	}

	// On trie (selon les 'x')
	sort(data.begin(), data.end()); // O(n x log(n))

	/*for(auto &x: data)
		cout << '(' << x.first << ',' << x.second << ") ";
	cout << '\n';*/

	for(size_t i = 0; i < data.size(); i++)
	{
		// Si on rencontre un 'x', on compte un intervalle de plus comme overlap
		if(data[i].second == 'x')
			count++;

		// Si on rencontre un 'y', on compte un intervalle de moins comme overlap
		if(data[i].second == 'y')
			count--;

		ans = max(ans, count);
	}

	return ans;
} // overlap()

int main() 
{ 
	int n = 0; // nombre d'intervalles
	cin >> n;

	vector<pair<int, int>> v(n); // chaque intervalle = paire {first, second}
	for(int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	cout << overlap(v) << '\n';

	return 0;
} // main()
