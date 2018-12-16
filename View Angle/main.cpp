/*input
2
2 0
0 2
*/

//
//  main.cpp
//  View Angle
//
//  Created by Nirmaljot Singh Bhasin on 21/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long int lli;

vector<double> angles;

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		lli x, y;
		cin >> x >> y;
		double angle = atan2(y, x);
		angle = angle * 180 / acos(-1);
		if (angle < 0) {
			angle += 360;
		}
		angles.push_back(angle);
	}

	sort(angles.begin(), angles.end());
	double maxi = 0;
	for (int i = 1; i < n; ++i) {
		maxi = max(maxi, angles[i] - angles[i - 1]);
	}
	maxi = max(maxi, angles.front() + 360 - angles.back());
	cout << fixed << setprecision(6) << 360 - maxi << endl;
	return 0;
}
