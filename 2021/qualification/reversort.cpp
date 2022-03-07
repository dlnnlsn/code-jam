#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int T; cin >> T;
	for (int case_no = 1; case_no <= T; ++case_no) {
		int N; cin >> N;
		vector<int> nums;
		for (int i = 0; i < N; ++ i) {
			int num; cin >> num; nums.push_back(num);
		}
		int score = 0;
		for (int i = 0; i < N - 1; ++i) {
			auto j = min_element(nums.begin() + i, nums.end()) - nums.begin();
			score += j - i + 1;
			reverse(nums.begin() + i, nums.begin() + j + 1);
		}
		cout << "Case #" << case_no << ": " << score << endl;
	}

	return 0;
}