#pragma once

#include <vector>
#include <functional>
#include <utility>

namespace learning {
	template <typename Iterator,
			  typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	std::vector<typename std::iterator_traits<Iterator>::value_type> merge(
		Iterator begin1,
		Iterator end1,
		Iterator begin2,
		Iterator end2,
		Compare comp = Compare()) {
		std::vector<typename std::iterator_traits<Iterator>::value_type> v;

		while (begin1 != end1 && begin2 != end2) {
			if (comp(*begin1, *begin2)) {
				v.push_back(*begin1);
				++begin1;
			}
			else {
				v.push_back(*begin2);
				++begin2;
			}
		}
		if (begin1 != end1) {
			v.insert(v.end(), begin1, end1);
		}
		else if (begin2 != end2) {
			v.insert(v.end(), begin1, end1);
		}
		return v;
	}

	template <typename Iterator, typename Compare = std::less<std::iterator_traits<Iterator>::value_type>>
	void merge_sort(Iterator begin, Iterator end, Compare comp = Compare()) {
		auto dist = std::distance(begin, end);
		if (dist < 2) {
			return;
		}

		std::cout << dist << std::endl;

		auto mid = std::next(begin, dist / 2);

		merge_sort(begin, mid);
		merge_sort(mid, end);

		auto&& merged = merge(begin, mid, mid, end, comp);

		std::move(merged.begin(), merged.end(), begin);
	}
}