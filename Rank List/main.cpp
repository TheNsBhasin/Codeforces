/*input
5 4
3 1
3 1
5 3
3 1
3 1
*/

//
//  main.cpp
//  Rank List
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;

bool cmp(const pair<lli, lli> &a, const pair<lli, lli> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(int argc, const char * argv[]) {
	int n, k;
	cin >> n >> k;
	vector< pair<lli, lli> > v;
	for (int i = 0; i < n; ++i) {
		lli p, t;
		cin >> p >> t;
		v.push_back({p, t});
	}
	sort(v.begin(), v.end(), cmp);
	lli st = lower_bound(v.begin(), v.end(), v[k - 1], cmp) - v.begin();
	lli en = upper_bound(v.begin(), v.end(), v[k - 1], cmp) - v.begin();
	cout << en - st << endl;
	return 0;
}
