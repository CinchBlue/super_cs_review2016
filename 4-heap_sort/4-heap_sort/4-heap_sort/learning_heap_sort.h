#pragma once

#include <functional>
#include <iterator>

namespace learning {

	template <	typename Iterator,
				typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	typename std::iterator_traits<Iterator>::difference_type heap_sort_parent(
		Iterator begin,
	    Iterator it) {
		auto dist = std::distance(begin, it)+1;
		
		dist = (dist-1) / 2;
		return dist;
	}

	template <	typename Iterator,
				typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	typename std::iterator_traits<Iterator>::difference_type heap_sort_left(
		Iterator begin,
		Iterator it) {
		auto dist = std::distance(begin, it);
		
		dist = dist * 2 + 1;
		return dist;
	}

	template <	typename Iterator,
				typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	typename std::iterator_traits<Iterator>::difference_type heap_sort_right(
		Iterator begin,
		Iterator it) {
		auto dist = std::distance(begin, it);
		
		dist = 2*dist + 2;
		return dist;
	}


	template <	typename Iterator,
				typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	void heap_sort_sift_down(Iterator begin,
						   	 Iterator end,
							 Iterator it,
							 Compare comp = Compare()) {
		auto dist = std::distance(begin, end);

		auto root = it;

		std::cout << "Element index: " << std::distance(begin, it) << std::endl;
		std::cout << "  Left child index: " << heap_sort_left(begin, root) << " < " << dist << "?" << std::endl;
	
		// While we have children nodes
		while (heap_sort_left(begin, root) < dist) {
			//std::cout << "  Root: " << *root << std::endl;
			//std::cout << "  Root index: " << std::distance(begin, root) << std::endl;
			//std::cout << "  Left child index: " << heap_sort_left(begin, root) << std::endl;
			auto child = begin+heap_sort_left(begin, root);
			auto other = root;
			// Check if we need to 
			if (comp(*other, *child)) {
				other = child;
			}
			//std::cout << "  Right child index: " << heap_sort_right(begin, root) << std::endl;
			if (heap_sort_right(begin, root) < dist &&
				comp(*other, *(begin+heap_sort_right(begin, root)))) {
				other = begin+heap_sort_right(begin, root);
			}
			if (*other == *root) {
				return;
			}
			std::iter_swap(root, other);
			//std::cout << "Swap: [" << *root << "," << *other << "]" << std::endl;
			root = other;
		}

		for (auto it = begin; it != end; ++it) {
			std::cout << *it << " ";
		}	std::cout << std::endl;
		
	}

	template <	typename Iterator,
				typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	void heap_sort_make_heap(Iterator begin,
							 Iterator end,
							 Compare comp = Compare()) {
		if (begin >= end) {
			return;
		}

		// Shift up child nodes if fail comp from the leaves back to the root.
		for (auto dist = std::distance(begin, end)-1;
			dist >= 0;
			--dist) {
			heap_sort_sift_down(begin, end, begin + dist, comp);
		}
		// check values
		for (auto it = begin; it != end; ++it) {
			std::cout << *it << ' ';
		}	std::cout << "\n";
	}

	template <	typename Iterator,
				typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
	void heap_sort(Iterator begin,
				   Iterator end,
				   Compare comp = Compare()) {
		if (begin >= end) {
			return;
		}
		// First, make the heap.
		heap_sort_make_heap(begin, end, comp);
		// Then, remove top from heap and restore it until entire heap is gone.
		auto dist = std::distance(begin, end);
		for (auto dist = std::distance(begin, end) - 1; dist >= 0; --dist) {
			std::iter_swap(begin, begin + dist);
			heap_sort_sift_down(begin, begin + dist, begin, comp);
		}
	}
}
