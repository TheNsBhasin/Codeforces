/*input
6 6
......
......
..SE..
......
......
......
01232123212302123021
*/

//
//  main.cpp
//  New Year and Buggy Bot
//
//  Created by Nirmaljot Singh Bhasin on 29/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int lli;
const int MAXN = 52;

char board[MAXN][MAXN];
pair<int, int> st, en;
string dir;
int n, m;

int main(int argc, const char * argv[]) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j) {
			board[i][j] = str[j];
			if (board[i][j] == 'S') {
				st = make_pair(i, j);
			}
			if (board[i][j] == 'E') {
				en = make_pair(i, j);
			}
		}
	}
	cin >> dir;
	char directions[] = {'0', '1', '2', '3'};
	lli cnt = 0;
	map<int, char> rev;
	do {
		rev[directions[0]] = 'U';
		rev[directions[1]] = 'D';
		rev[directions[2]] = 'L';
		rev[directions[3]] = 'R';
		int x = st.first;
		int y = st.second;
		for (int i = 0; i < dir.length(); ++i) {
			if (rev[dir[i]] == 'U') {
				x--;
			} else if (rev[dir[i]] == 'D') {
				x++;
			} else if (rev[dir[i]] == 'L') {
				y--;
			} else {
				y++;
			}
			if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] == '#') {
				break;
			}
			if (board[x][y] == 'E') {
				++cnt;
				break;
			}
		}
	} while (next_permutation(directions, directions + 4));
	cout << cnt << endl;
	return 0;
}
