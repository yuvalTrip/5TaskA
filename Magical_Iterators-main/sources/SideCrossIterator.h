//
// Created by yuvalbs on 5/25/23.
//

#ifndef INC_5TASKA_SIDECROSSITERATOR_H
#define INC_5TASKA_SIDECROSSITERATOR_H


class SideCrossIterator {
private:
    const MagicalContainer& container;
    std::vector<int>::const_iterator forwardIterator;
    std::vector<int>::const_iterator backwardIterator;
    bool isForward;

public:
    SideCrossIterator(const MagicalContainer& cont, bool end = false): container(cont), isForward(true) {}

    SideCrossIterator(const SideCrossIterator& other): container(other.container), forwardIterator(other.forwardIterator),
              backwardIterator(other.backwardIterator), isForward(other.isForward) {}

    SideCrossIterator& operator=(const SideCrossIterator& other);

    bool operator==(const SideCrossIterator& other) const ;

    bool operator!=(const SideCrossIterator& other) const ;

    int operator*() const ;

    SideCrossIterator& operator++() ;

    SideCrossIterator begin() const;

    SideCrossIterator end() const;

};


#endif //INC_5TASKA_SIDECROSSITERATOR_H
