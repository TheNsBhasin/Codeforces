/*input
5
3 4 3 2 4
*/

//
//  main.cpp
//  Caisa and Pylons
//
//  Created by Nirmaljot Singh Bhasin on 09/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	lli h[n];
	lli ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		ans = max(ans, h[i]);
	}
	cout << ans << endl;
	return 0;
}
