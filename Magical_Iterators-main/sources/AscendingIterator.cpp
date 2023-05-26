//
// Created by yuvalbs on 5/25/23.
//

#include "AscendingIterator.h"

AscendingIterator(const MagicalContainer& cont, bool end = false)
        : container(cont) {
    if (end)
        current = container.elements.end();
    else
        current = container.elements.begin();
}

AscendingIterator(const AscendingIterator& other)
        : container(other.container), current(other.current) {}

AscendingIterator& operator=(const AscendingIterator& other) {
    if (this != &other) {
        container = other.container;
        current = other.current;
    }
    return *this;
}

bool AscendingIterator::operator==(const AscendingIterator& other) const {
    return current == other.current;
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

int AscendingIterator::operator*() const {
    return *current;
}

AscendingIterator& operator++() {
    ++current;
    return *this;
}

AscendingIterator AscendingIterator::begin() const {
    return AscendingIterator(container);
}

AscendingIterator AscendingIterator::end() const {
    return AscendingIterator(container, true);
}