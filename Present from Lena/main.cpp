/*input
5
*/

//
//  main.cpp
//  Present from Lena
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
	for (int i = 0; i <= n; ++i) {
		lli val = 0;
		for (int j = 0; j <= (n << 1); ++j) {
			if (j > 0 && j <= n + i) {
				cout << " ";
			}
			if (j < n - i) {
				cout << " ";
			} else if (j <= n + i) {
				cout << val;
				if (j < n) {
					++val;
				} else {
					--val;
				}
			}
		}
		cout << endl;
	}
	for (int i = n - 1; i >= 0; --i) {
		lli val = 0;
		for (int j = 0; j <= (n << 1); ++j) {
			if (j > 0 && j <= n + i) {
				cout << " ";
			}
			if (j < n - i) {
				cout << " ";
			} else if (j <= n + i) {
				cout << val;
				if (j < n) {
					++val;
				} else {
					--val;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
