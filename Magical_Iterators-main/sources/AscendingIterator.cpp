//
// Created by yuvalbs on 5/25/23.
//

#include "AscendingIterator.h"
//#include "MagicalContainer.h"
AscendingIterator::AscendingIterator(const MagicalContainer& container)
{
    std::vector<int> elements_asc= container.getElements();
    std::sort(elements_asc.begin(), elements_asc.end());
}

AscendingIterator& AscendingIterator::operator++() {
    ++currentIndex;
    return *this;
}

int AscendingIterator::operator*() const {
    return *elements;
}

bool AscendingIterator::operator==(const AscendingIterator& other) const {
    if (elements.size()!=other.elements.size())//if 2 vectors have different size, of course they are not the same
    {
        return false;
    }
    else{//If they do have the same size, we will check their values
        for (int i=0;i<elements.size();i++)
        {
            if (elements[i]==other.elements[i])//if it equal
            { continue;}//we will continue to check the next element
            else{ return false;}//if not, return false
        }
    }
   return true;//if we finished the for and all elements are equal, return true
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

AscendingIterator AscendingIterator::begin(const MagicalContainer& container) {
    return AscendingIterator(container);
}

AscendingIterator AscendingIterator::end(const MagicalContainer& container) {
    return AscendingIterator(container);
}