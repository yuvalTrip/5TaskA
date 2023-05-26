//
// Created by yuvalbs on 5/25/23.
//

#ifndef INC_5TASKA_ASCENDINGITERATOR_H
#define INC_5TASKA_ASCENDINGITERATOR_H
//#include <stdio.h>
//using namespace std;
//
//class AscendingIterator {
//
//
//private:
//    const MagicalContainer& container;
//    std::vector<int>::const_iterator elements;
//
//public:
//    AscendingIterator(const MagicalContainer& cont, bool end = false): container(cont) {}
//
//    AscendingIterator(const MagicalContainer& container);
//
//    AscendingIterator begin() const ;
//
//    AscendingIterator end() const;

#include "MagicalContainer.h"

class AscendingIterator {
private:
    std::vector<int> elements;// Store sorted elements
    std::vector<int>::size_type currentIndex; // Track the current index
public:
    //Constructor
    AscendingIterator(const MagicalContainer& container);

    //Operators
    AscendingIterator& operator++();
    int operator*() const;
    bool operator==(const AscendingIterator& other) const;
    bool operator!=(const AscendingIterator& other) const;

    //begin,end
    int * begin();
    int * end();


};


#endif //INC_5TASKA_ASCENDINGITERATOR_H
