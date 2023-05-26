//
// Created by yuvalbs on 5/25/23.
//

//#include "AscendingIterator.h"
#include "MagicalContainer.h"
AscendingIterator::AscendingIterator(const MagicalContainer& container)
{
    elements = container.getElements();
    std::sort(elements.begin(), elements.end());
}

AscendingIterator AscendingIterator::begin() const {
    return AscendingIterator(container);
}

AscendingIterator AscendingIterator::end() const {
    return AscendingIterator(container, true);
}