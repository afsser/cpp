#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

inline std::vector<size_t> treatedSequence(std::vector<size_t> &seq, size_t n) {
	std::vector<size_t> treatedSeq;
	std::vector<bool> used(n, false);
	for (size_t i = 0; i < seq.size(); ++i) {
		if (!used[seq[i]] && seq[i] < n) {
			treatedSeq.push_back(seq[i]);
			used[seq[i]] = true;
		}
	}
	for (size_t i = 0; i < n; ++i) {
		if (!used[i]) {
			treatedSeq.push_back(i);
			used[i] = true;
		}
	}

	return treatedSeq;
} 

inline std::vector<size_t> jacobsthalSequence(size_t n) {
	std::vector<size_t> seq;
	if (n == 0)
		return seq;
	seq.push_back(0);
	if (n == 1)
		return seq;
	seq.push_back(1);
	for (size_t i = 2; seq.size() < n; ++i) {
		seq.push_back(seq[i - 1] + 2 * seq[i - 2]);
	}
	for (size_t i = 0; i < seq.size(); ++i) {
		if (seq[i] > n) 
			seq[i] = n - 1;
	}
	return treatedSequence(seq, n);
}

template <typename T>
void PmergeMe::fordJohnsonSort(T &container, std::string type) {
	T		minors, majors;
	long	first, second;
	std::vector<size_t> jacobOrder;

	if (container.size() <= 1) {
		return;
	}
	typename T::iterator it = container.begin();
	while (it != container.end()) {
		first = *it;
		++it;
		if (it != container.end()) {
			second = *it;
			if (first <= second) {
				minors.push_back(first);
				majors.push_back(second);
			} else {
				minors.push_back(second);
				majors.push_back(first);
			}
		++it;
		} else {
			majors.push_back(first);
		}

	}

	fordJohnsonSort(majors, type);

	jacobOrder = jacobsthalSequence(minors.size());

	for (size_t i = 0; i < jacobOrder.size(); ++i) {
		typename T::iterator minorIt = minors.begin();
		std::advance(minorIt, jacobOrder[i]);
		if (type == "vector") {
			typename T::iterator pos = std::lower_bound(majors.begin(), majors.end(), *minorIt);
			majors.insert(pos, *minorIt);
		} else if (type == "list") {
			typename T::iterator pos = majors.begin();
			while (pos != majors.end() && *pos < *minorIt)
				++pos;
			majors.insert(pos, *minorIt);
		}
	}
	container = majors;
}

template <typename T>
double PmergeMe::sortContainer(T &container, std::string type) {
	struct timeval start, end;
	gettimeofday(&start, NULL);

	fordJohnsonSort(container, type);

	gettimeofday(&end, NULL);
	double timeTaken = (end.tv_sec - start.tv_sec) * 1000.0;
	timeTaken += (end.tv_usec - start.tv_usec) / 1000.0;

	return timeTaken;
}

template <typename T>
void PmergeMe::printContainer(const T &container) const {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		typename T::const_iterator next = it;
		++next;
		if (next != container.end()) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::printTime(const T &container, double time, const std::string &type) const {
	std::cout << "Time to process a range of " << container.size() << " elements with " 
	          << type << ": " << time << " ms" << std::endl;
}
