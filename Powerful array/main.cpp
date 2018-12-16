/*input
3 2
1 2 1
1 2
1 3
*/

//
//  main.cpp
//  Powerful array
//
//  Created by Nirmaljot Singh Bhasin on 21/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int MAXN = 1000006;
const int BLOCK_SIZE = 447;

lli freq[MAXN];

typedef struct query {
	int idx;
	int left, right;

	query() {
		idx = left = right = -1;
	}

	query(int idx, int left, int right) : idx(idx), left(left), right(right) {}
} query;

bool cmp(query& q1, query& q2) {
	int blk1 = q1.left / BLOCK_SIZE;
	int blk2 = q2.left / BLOCK_SIZE;

	if (blk1 != blk2) {
		return blk1 < blk2;
	} else {
		return q1.right < q2.right;
	}
}

int main(int argc, const char * argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(freq, 0, sizeof(freq));
	int n, t;
	cin >> n >> t;
	lli arr[n], ans[t];
	query qu[t];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < t; ++i) {
		int l, r;
		cin >> l >> r;
		qu[i] = query(i, l - 1, r - 1);
	}
	sort(qu, qu + t, cmp);

	int start = qu[0].left;
	int end = start;
	++freq[arr[start]];
	lli cnt = arr[start];

	for (int i = 0; i < t; ++i) {
		while (start < qu[i].left) {
			--freq[arr[start]];
			cnt = cnt - (((freq[arr[start]] << 1) + 1) * arr[start]);
			++start;
		}

		while (start > qu[i].left) {
			--start;
			cnt = cnt + (((freq[arr[start]] << 1) + 1) * arr[start]);
			++freq[arr[start]];
		}

		while (end < qu[i].right) {
			++end;
			cnt = cnt + (((freq[arr[end]] << 1) + 1) * arr[end]);
			++freq[arr[end]];
		}

		while (end > qu[i].right) {
			--freq[arr[end]];
			cnt = cnt - (((freq[arr[end]] << 1) + 1) * arr[end]);
			--end;
		}

		ans[qu[i].idx] = cnt;
	}

	for (int i = 0; i < t; ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}
