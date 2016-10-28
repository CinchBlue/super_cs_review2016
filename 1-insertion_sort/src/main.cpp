#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

namespace learning {

	template <typename T>
	void insertion_sort(std::vector<T>& v) {
		// For the 1st element to the last, sort.
		for (size_t i = 1; i < v.size(); ++i) {
			// If the current element fails the comparison, insert.
			for (size_t j = 0; j < i; ++j) {
				if ((v[i] < v[j])) {
					// Move the element from ith to right before jth element.
					auto temp = v[i];
					v.erase(v.begin() + i);
					v.insert(v.begin()+j, temp);
				}
			}
		}
	}
	
}




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

    learning::insertion_sort(v);

    for (auto it : v) {
        cout << it << ' ';
    }   cout << '\n';

    return 0;
}



