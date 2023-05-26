//
// Created by yuvalbs on 5/25/23.
//

#include "PrimeIterator.h"
bool PrimeIterator::isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

PrimeIterator(const MagicalContainer& cont, bool end = false)
        : container(cont) {
    if (end) {
        current = container.elements.end();
    } else {
        current = std::find_if(container.elements.begin(), container.elements.end(),
                               [this](int element) {
                                   return isPrime(element);
                               });
    }
}

PrimeIterator(const PrimeIterator& other)
        : container(other.container), current(other.current) {}

PrimeIterator& operator=(const PrimeIterator& other) {
    if (this != &other) {
        container = other.container;
        current = other.current;
    }
    return *this;
}

bool PrimeIterator::operator==(const PrimeIterator& other) const {
    return current == other.current;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

int PrimeIterator::operator*() const {
    return *current;
}

PrimeIterator& operator++() {
    ++current;
    while (current != container.elements.end() && !isPrime(*current)) {
        ++current;
    }
    return *this;
}

PrimeIterator PrimeIterator::begin() const {
    return PrimeIterator(container);
}

PrimeIterator PrimeIterator::end() const {
    return PrimeIterator(container, true);
}