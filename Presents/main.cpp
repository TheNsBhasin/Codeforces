/*input
4
2 3 4 1
*/

//
//  main.cpp
//  Presents
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 102;

int m[MAXN];

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		m[x] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cout << m[i] << " ";
	}
	cout << endl;
	return 0;
}
