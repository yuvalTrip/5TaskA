    //
// Created by yuvalbs on 5/25/23.
//

#ifndef INC_5TASKA_PRIMEITERATOR_H
#define INC_5TASKA_PRIMEITERATOR_H


class PrimeIterator {
private:
    const MagicalContainer& container;
    std::vector<int>::const_iterator current;

    bool isPrime(int num);

public:
    PrimeIterator(const MagicalContainer& cont, bool end = false): container(cont) {}

    PrimeIterator(const PrimeIterator& other): container(other.container), current(other.current) {}

    PrimeIterator& operator=(const PrimeIterator& other);

    bool operator==(const PrimeIterator& other) const;

    bool operator!=(const PrimeIterator& other) const;

    int operator*() const;

    PrimeIterator& operator++();

    PrimeIterator begin() const;

    PrimeIterator end() const;
};


#endif //INC_5TASKA_PRIMEITERATOR_H
