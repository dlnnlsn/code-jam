#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T; cin >> T;
	for (int case_no = 1; case_no <= T; ++case_no) {
		int N, C; cin >> N >> C;
		if (C < N - 1) {
			cout << "Case #" << case_no << ": IMPOSSIBLE" << endl;
			continue;
		}

		if (C > (N * (N + 1)) / 2 - 1) {
			cout << "Case #" << case_no << ": IMPOSSIBLE" << endl;
			continue;
		}
		
		vector<int> sequence;
		for (int i = 1; i <= N; ++i) sequence.push_back(i);

		for (int i = 2; i <= N; ++i) {
			int to_take = min(C - (N - i), i);
			C -= to_take;
			reverse(sequence.end() - i, sequence.end() - i + to_take);
		}

		cout << "Case #" << case_no << ":";
		for (int num : sequence) cout << " " << num;
		cout << endl;
	}

	return 0;
}