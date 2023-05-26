//
// Created by yuvalbs on 5/25/23.
//

#include "SideCrossIterator.h"

SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
{
    std::vector<int> elements_asc= container.getElements();
    //First I will sort it
    std::sort(elements_asc.begin(), elements_asc.end());
    //After the sort I will start to take one index from the start and other from the end
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
//This is the "SideCrossIterator& operator++();" implementation
//SideCrossIterator& SideCrossIterator::operator++() {
//    ++currentIndex;
//    return *this;
//}
int SideCrossIterator::operator++(){
    if(currentIndex<elements.size() -1){
        currentIndex++;
    }
    return elements[currentIndex];
}

int SideCrossIterator::operator*() const {
    return elements[currentIndex];;
}

bool SideCrossIterator::operator==(const SideCrossIterator& other) const {

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

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}


int * SideCrossIterator::begin() {
    return &elements[0];
}

int * SideCrossIterator::end(){
    return &elements[elements.size()];
}


SideCrossIterator SideCrossIterator::operator=(const SideCrossIterator &sideCIterator){
    //Assignment of the attributes
    elements = sideCIterator.elements;
    currentIndex = sideCIterator.currentIndex;
//    sideCIterator sideCIter(container);
    return *this;
}