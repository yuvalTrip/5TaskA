//
// Created by yuvalbs on 5/25/23.
//

#include "SideCrossIterator.h"

SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
{
    std::vector<int> elements_asc= container.getElements();
    //First I will sort it
    std::sort(elements_asc.begin(), elements_asc.end());
    //After the sort I will start to take onr index from the start and other from the end
    std::vector<int> sideCrossArray;

    std::vector<int>::size_type left = 0;                            // Left pointer starting from the beginning
    std::vector<int>::size_type  right = elements_asc.size() - 1;      // Right pointer starting from the end

    // Perform side cross operation
    while (left <= right) {
        sideCrossArray.push_back(elements_asc[left]);
        if (left != right) {
            sideCrossArray.push_back(elements_asc[right]);
        }
        left++;
        right--;
    }
    elements=sideCrossArray;
}

SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
        forwardIterator = other.forwardIterator;
        backwardIterator = other.backwardIterator;
        isForward = other.isForward;
    }
    return *this;
}

bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return forwardIterator == other.forwardIterator &&
           backwardIterator == other.backwardIterator &&
           isForward == other.isForward;
}

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

int SideCrossIterator::operator*() const {
    if (isForward)
        return *forwardIterator;
    else
        return *backwardIterator;
}

SideCrossIterator& SideCrossIterator::operator++() {
    if (isForward) {
        ++forwardIterator;
        if (forwardIterator == backwardIterator) {
            isForward = false;
            ++backwardIterator;
        }
    } else {
        --backwardIterator;
        if (backwardIterator == forwardIterator) {
            isForward = true;
            ++forwardIterator;
        }
    }
    return *this;
}

SideCrossIterator SideCrossIterator::begin() const {
    return SideCrossIterator(container);
}

SideCrossIterator SideCrossIterator::end() const {
    return SideCrossIterator(container, true);
}