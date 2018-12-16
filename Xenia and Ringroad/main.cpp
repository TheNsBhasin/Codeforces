/*input
4 3
2 3 3
*/

//
//  main.cpp
//  Xenia and Ringroad
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int n, m;
	cin >> n >> m;
	lli arr[m];
	lli pos = 1, ans = 0;
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		if (arr[i] < pos) {
			ans += (n - pos + arr[i]);
		} else {
			ans += (arr[i] - pos);
		}
		pos = arr[i];
	}
	cout << ans << endl;
	return 0;
}
