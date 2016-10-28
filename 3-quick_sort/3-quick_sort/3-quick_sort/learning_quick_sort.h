#pragma once

#include <functional>
#include <iterator>

namespace learning {
	template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	Iterator quick_sort_hoare_partition(Iterator begin, Iterator end, Compare comp = Compare()) {
		if (begin >= end) {
			return end;
		}

		auto dist = std::distance(begin, end);

		auto pivot = *begin;
		auto i = 0;
		auto j = dist - 1;
		//std::cout << "[" << i << "," << j << "]\n";
		while (true) {

			while (comp(*(begin+i), pivot) && i < j) {
				//std::cout << "Compare\n";
				++i;
			}	//std::cout << "Compare\n";
			while (!comp(*(begin+j), pivot) && j > i) {
				//std::cout << "Compare\n";
				--j;
			}	//std::cout << "Compare\n";
				

			if (i >= j) {
				return begin + j;
			}
			else {
				//std::cout << "Swap: [" << *(begin+i) << "," << *(begin+j) << "]\n";
				std::iter_swap(begin+i, begin+j);
			}
		}
	}

	template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	void quick_sort(Iterator begin, Iterator end, Compare comp = Compare()) {
		if (begin >= end) {
			return;
		}
		// Compute the length of the iterator sequence.
		auto length = std::distance(begin, end);
		// Partition array such that elements below are less.
		auto pivot = quick_sort_hoare_partition(begin, end);
		// Sort two sub-partitions.
		quick_sort(begin, pivot);
		quick_sort(pivot + 1, end);
	}
}