//
// Created by yuvalbs on 5/25/23.
//

#include "AscendingIterator.h"
#include <iostream>

AscendingIterator::AscendingIterator(const MagicalContainer& container)
{
    std::vector<int> elements_asc= container.getElements();
//    for (std::vector<int>::size_type i=0;i<elements_asc.size();i++) {
//        std::cout << "elements_asc" << "[" << i << "]=" << elements_asc[i] << std::endl;
//    }
    std::sort(elements_asc.begin(), elements_asc.end());
//    std::cout << "After sort*****" <<std::endl;
//
//    for (std::vector<int>::size_type i=0;i<elements_asc.size();i++) {
//        std::cout << "elements_asc" << "[" << i << "]=" << elements_asc[i] << std::endl;
//    }
    elements=elements_asc;
}
//This is the "AscendingIterator& operator++();" implementation
//AscendingIterator& AscendingIterator::operator++() {
//    ++currentIndex;
//    return *this;
//}
int AscendingIterator::operator++(){
    if(currentIndex<elements.size() -1){
        currentIndex++;
    }
    return elements[currentIndex];
}

int AscendingIterator::operator*() const {
    return elements[currentIndex];;
}

bool AscendingIterator::operator==(const AscendingIterator& other) const {
    if (elements.size()!=other.elements.size())//if 2 vectors have different size, of course they are not the same
    {
        return false;
    }
    else{//If they do have the same size, we will check their values
        for (std::vector<int>::size_type i=0;i<elements.size();i++)
        {
            if (static_cast<std::vector<int>::size_type>(elements[i])==other.elements[i])//if it equal
                //            if (static_cast<std::vector<int>::size_type>(elements[i]) == other.elements[i]) {
            { continue;}//we will continue to check the next element
            else{ return false;}//if not, return false
        }
    }
   return true;//if we finished the for and all elements are equal, return true
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}
int * AscendingIterator::begin() {
    return &elements[0];
}

int * AscendingIterator::end(){
    return &elements[elements.size()];
}

AscendingIterator AscendingIterator::operator=(const AscendingIterator &ascendingIterator){
    //Assignment of the attrubutes
    elements = ascendingIterator.elements;
    currentIndex = ascendingIterator.currentIndex;
//    AscendingIterator ascIter(container);
    return *this;
}