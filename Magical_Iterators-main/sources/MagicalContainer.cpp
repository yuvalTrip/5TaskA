//
// Created by yuvalbs on 5/25/23.
//

#include "MagicalContainer.h"
//void MagicalContainer::addElement(int element) {
//    elements.push_back(element);
//}
//
//void MagicalContainer::removeElement(int element) {
//    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
//}
//
//int MagicalContainer::size() const {
//    return elements.size();
//}

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it == element) {
            elements.erase(it);
            break;
        }
    }
}

int MagicalContainer::size() const {
    return elements.size();
}

AscendingIterator MagicalContainer::begin() {
    return AscendingIterator(*this);
}

AscendingIterator MagicalContainer::end() {
    return AscendingIterator(*this);
}

SideCrossIterator MagicalContainer::begin() {
    return SideCrossIterator(*this);
}

SideCrossIterator MagicalContainer::end() {
    return SideCrossIterator(*this,);
}

PrimeIterator MagicalContainer::begin() {
    return PrimeIterator(*this);
}

PrimeIterator MagicalContainer::end() {
    return PrimeIterator(*this);
}

