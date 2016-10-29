#include "stdafx.h"
#include "learning_heap_sort.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {

	using namespace std;

	vector<int> v;
	int count = 0;
	string buf;

	while (getline(cin, buf) && buf != "") {
		stringstream ss(buf);
		while (!ss.eof()) {
			int i = 0;
			ss >> i;
			if (!ss.fail()) {
				v.push_back(i);
				++count;
			}
			else {
				std::cout << "Invalid input.\n";
				return 1;
			}
			if (count >= 1000) {
				break;
			}
		}
		if (count >= 1000) {
			break;
		}
	}

	learning::heap_sort(v.begin(), v.end());

	for (auto it : v) {
		cout << it << ' ';
	}   cout << '\n';

	return 0;
}
