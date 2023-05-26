//
// Created by yuvalbs on 5/25/23.
//

#ifndef INC_5TASKA_SIDECROSSITERATOR_H
#define INC_5TASKA_SIDECROSSITERATOR_H
#include "MagicalContainer.h"


class SideCrossIterator {
private:
    std::vector<int> elements;// Store sorted elements
    std::vector<int>::size_type currentIndex; // Track the current index

public:
    //Constructor
    SideCrossIterator(const MagicalContainer& container);

    //Operators
    SideCrossIterator& operator++();
    int operator*() const;
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;

    //begin,end
    int * begin();
    int * end();


};


#endif //INC_5TASKA_SIDECROSSITERATOR_H
