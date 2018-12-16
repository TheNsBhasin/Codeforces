/*input
10
1 1 1 1 2 2 2 2 2 2
*/

//
//  main.cpp
//  Fox and Box Accumulation
//
//  Created by Nirmaljot Singh Bhasin on 19/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

lli s[MAXN];
priority_queue< lli, vector<lli>, greater<lli> > q;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	sort(s, s + n);
	for (int i = 0; i < n; ++i) {
		if (!q.empty() && q.top() <= s[i]) {
			s[i] = q.top() + 1;
			q.pop();
			q.push(s[i]);
		} else {
			q.push(1);
		}
	}
	cout << q.size() << endl;
	return 0;
}
