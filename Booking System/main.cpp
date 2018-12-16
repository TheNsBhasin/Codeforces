/*input
3
10 50
2 100
5 30
3
4 6 9
*/

//
//  main.cpp
//  Booking System
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long int lli;

struct group {
	lli id, size, income;

	group(lli id, lli size, lli income) {
		this->id = id;
		this->size = size;
		this->income = income;
	}
};

struct table {
	lli id, size;

	table(lli id, lli size) {
		this->id = id;
		this->size = size;
	}
};

bool byIncomeDescending(const group &g1, const group &g2) {
	return g1.income > g2.income;
}

bool bySize(const table &t1, const table &t2) {
	return t1.size < t2.size;
}

bool canFit(const table &t, const group &g) {
	return t.size < g.size;
}

vector<group> groups;
vector<table> tables;

int main(int argc, const char * argv[]) {
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		lli c, p;
		cin >> c >> p;
		groups.push_back(group(i, c, p));
	}
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		lli x;
		cin >> x;
		tables.push_back(table(i, x));
	}
	sort(groups.begin(), groups.end(), byIncomeDescending);
	sort(tables.begin(), tables.end(), bySize);
	lli sum = 0;
	vector< pair<lli, lli> > ans;
	for (int i = 0; i < n; ++i) {
		auto tableToGive = lower_bound(tables.begin(), tables.end(), groups[i], canFit);
		if (tableToGive == tables.end()) {
			continue;
		}
		sum += groups[i].income;
		ans.push_back({groups[i].id, tableToGive->id});
		tables.erase(tableToGive);
	}
	cout << ans.size() << " " << sum << endl;
	for (auto &p : ans) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
