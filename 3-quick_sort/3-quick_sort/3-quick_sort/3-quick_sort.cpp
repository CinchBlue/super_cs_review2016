// 3-quick_sort.cpp : Defines the entry point for the console application.
//
// 2-merge_sort.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "learning_quick_sort.h"

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
		stringstream ss;
		ss << buf;
		while (!ss.eof()) {
			int i = 0;
			ss >> i;
			v.push_back(i);
			++count;
			if (count >= 1000) {
				break;
			}
		}
		if (count >= 1000) {
			break;
		}
	}

	learning::quick_sort(v.begin(), v.end());

	for (auto it : v) {
		cout << it << ' ';
	}   cout << '\n';

	return 0;
}