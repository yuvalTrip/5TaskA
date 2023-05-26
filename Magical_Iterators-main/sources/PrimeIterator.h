    //
// Created by yuvalbs on 5/25/23.
//

#ifndef INC_5TASKA_PRIMEITERATOR_H
#define INC_5TASKA_PRIMEITERATOR_H
#include "MagicalContainer.h"


class PrimeIterator {
private:
    std::vector<int> elements;// Store sorted elements
    std::vector<int>::size_type currentIndex; // Track the current index
    bool isPrime(int num);

public:
    //Constructor
    PrimeIterator(const MagicalContainer& container);

    //Operators
    PrimeIterator& operator++();
    int operator*() const;
    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;

    //begin,end
    int * begin();
    int * end();


};


#endif //INC_5TASKA_PRIMEITERATOR_H
