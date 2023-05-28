//
// Created by yuvalbs on 5/25/23.
//

#include "MagicalContainer.h"
#include <iostream>

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
    elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

const std::vector<int>& MagicalContainer::getElements() const
{
    return elements;
}
int MagicalContainer::contains(int number) const
{
    for (std::vector<int>::size_type i=0;i<elements.size();i++) {
        if (elements[i]==number){return true;}
    }
    return false;
}


//
//AscendingIterator MagicalContainer::begin() {
//    return AscendingIterator(*this);
//}
//
//AscendingIterator MagicalContainer::end() {
//    return AscendingIterator(*this);
//}
//
//SideCrossIterator MagicalContainer::begin() {
//    return SideCrossIterator(*this);
//}
//
//SideCrossIterator MagicalContainer::end() {
//    return SideCrossIterator(*this,);
//}
//
//PrimeIterator MagicalContainer::begin() {
//    return PrimeIterator(*this);
//}
//
//PrimeIterator MagicalContainer::end() {
//    return PrimeIterator(*this);
//}

