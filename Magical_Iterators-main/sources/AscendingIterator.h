//
// Created by yuvalbs on 5/25/23.
//

#ifndef INC_5TASKA_ASCENDINGITERATOR_H
#define INC_5TASKA_ASCENDINGITERATOR_H
#include <stdio.h>
//using namespace std;

class AscendingIterator {


private:
    const MagicalContainer& container;
    std::vector<int>::const_iterator elements;

public:
    AscendingIterator(const MagicalContainer& cont, bool end = false): container(cont) {}

    AscendingIterator(const MagicalContainer& container);

    AscendingIterator begin() const ;

    AscendingIterator end() const;


};


#endif //INC_5TASKA_ASCENDINGITERATOR_H
