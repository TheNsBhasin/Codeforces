/*input
3
abccabccabcc
*/

//
//  main.cpp
//  k-String
//
//  Created by Nirmaljot Singh Bhasin on 15/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	lli k;
	string str;
	cin >> k >> str;
	lli freq[26];
	lli cnt[26];
	fill(freq, freq + 26, 0);
	for (int i = 0; i < str.length(); ++i) {
		++freq[str[i] - 'a'];
	}
	bool flag = true;
	for (int i = 0; i < 26; ++i) {
		if (freq[i] % k) {
			flag = false;
		} else {
			cnt[i] = freq[i] / k;
		}
	}
	if (!flag) {
		cout << -1 << endl;
	} else {
		for (int j = 0; j < k; ++j) {
			for (int i = 0; i < 26; ++i) {
				if (freq[i] > 0) {
					for (int x = 0; x < cnt[i]; ++x) {
						cout << char('a' + i);
						--freq[i];
					}
				}
			}
		}
	}
	return 0;
}
