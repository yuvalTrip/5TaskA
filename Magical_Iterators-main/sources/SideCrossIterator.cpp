//
// Created by yuvalbs on 5/25/23.
//

#include "SideCrossIterator.h"
SideCrossIterator(const MagicalContainer& cont, bool end = false)
        : container(cont), isForward(true) {
    if (end) {
        forwardIterator = container.elements.end();
        backwardIterator = container.elements.begin();
    } else {
        forwardIterator = container.elements.begin();
        backwardIterator = container.elements.end() - 1;
    }
}

SideCrossIterator(const SideCrossIterator& other)
        : container(other.container), forwardIterator(other.forwardIterator),
          backwardIterator(other.backwardIterator), isForward(other.isForward) {}

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