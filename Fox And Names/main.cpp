/*input
3
rivest
shamir
adleman
*/

//
//  main.cpp
//  Fox And Names
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

string s[MAXN];
vector<lli> v[26];
lli vis[26], ans[26];
lli cnt;

bool dfs(lli i) {
	vis[i] = -1;
	for (auto &j : v[i]) {
		if (vis[j] == -1) {
			return false;
		} else if (vis[j] == 1) {
			continue;
		}
		if (!dfs(j)) {
			return false;
		}
	}
	vis[i] = 1;
	ans[--cnt] = i;
	return true;
}

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	bool flag = true;
	for (int i = 1; i < n; ++i) {
		lli pos = 0;
		while (pos < s[i - 1].length() && pos < s[i].length() && s[i - 1][pos] == s[i][pos]) {
			++pos;
		}
		if (pos != s[i - 1].length() && pos == s[i].length()) {
			flag = false;
			break;
		}
		if (pos == s[i - 1].length()) {
			continue;
		}
		v[s[i - 1][pos] - 'a'].push_back(s[i][pos] - 'a');
	}
	for (int i = 0; i < 26 && flag; ++i) {
		sort(v[i].begin(), v[i].end());
		v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
	}
	cnt = 26;
	for (int i = 0; i < 26 && flag; ++i) {
		if (!vis[i]) {
			if (!dfs(i)) {
				flag = false;
				break;
			}
		}
	}
	if (!flag) {
		cout << "Impossible" << endl;
	} else {
		for (int i = 0; i < 26; ++i) {
			cout << char(ans[i] + 'a');
		}
		cout << endl;
	}
	return 0;
}
