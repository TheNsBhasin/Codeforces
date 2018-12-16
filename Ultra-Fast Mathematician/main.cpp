/*input
1010100
0100101
*/

//
//  main.cpp
//  Ultra-Fast Mathematician
//
//  Created by Nirmaljot Singh Bhasin on 08/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	string a, b;
	cin >> a >> b;
	string ans(a.length(), '0');
	transform(a.begin(), a.end(), b.begin(), ans.begin(), [](unsigned char c1, unsigned char c2){return ((c1 - '0') ^ (c2 - '0')) + '0'; });
	cout << ans << endl;
    return 0;
}
