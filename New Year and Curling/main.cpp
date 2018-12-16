/*input
6 2
5 5 6 8 3 12
*/

//
//  main.cpp
//  New Year and Curling
//
//  Created by Nirmaljot Singh Bhasin on 29/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;

float dist[MAXN];
float ans[MAXN];
int arr[MAXN];

int main(int argc, const char * argv[]) {
	int n, r;
	cin >> n >> r;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		int x = arr[i];
		float maxi = dist[x];
		for (int j = max(0, x - 2 * r); j <= min(MAXN, x + 2 * r); ++j) {
			if (dist[j] == 0) {
				continue;
			}
			float d = sqrt((4 * r * r) - ((x - j) * (x - j)));
			maxi = max(maxi, dist[j] + d);
		}
		if (maxi == 0) {
			dist[x] = r;
		} else {
			dist[x] = maxi;
		}
		ans[i] = dist[x];
	}
	for (int i = 0; i < n; ++i) {
		printf("%.6f ", ans[i]);
	}
	cout << endl;
	return 0;
}
