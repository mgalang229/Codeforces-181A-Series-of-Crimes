#include <bits/stdc++.h>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	// check every cell with '.' in it if there is an asterisk
	// within the SAME row and SAME column
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {			
			bool checker1 = false;
			bool checker2 = false;
			for (int k = 0; k < m; k++) {
				if (a[i][k] == '*' && a[i][j] != '*') {
					// if there is an asterisk within the same row,
					// then the 'checker1' to true and break the loop
					checker1 = true;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (a[k][j] == '*' && a[i][j] != '*') {
					// if there is an asterisk within the same column,
					// then the 'checker2' to true and break the loop
					checker2 = true;
					break;
				}
			}
			if (checker1 && checker2) {
				// if the 'checker1' and 'checker2' are both true, then
				// this element position must be the fourth vertex
				cout << i + 1 << " " << j + 1 << '\n';
				return 0;
			}
		}
	}
	return 0;
}
