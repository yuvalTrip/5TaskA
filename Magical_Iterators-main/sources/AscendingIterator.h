//
// Created by yuvalbs on 5/25/23.
//

#ifndef INC_5TASKA_ASCENDINGITERATOR_H
#define INC_5TASKA_ASCENDINGITERATOR_H


class AscendingIterator {


private:
    const MagicalContainer& container;
    std::vector<int>::const_iterator current;

public:
    AscendingIterator(const MagicalContainer& cont, bool end = false): container(cont) {}

    AscendingIterator(const AscendingIterator& other): container(other.container), current(other.current) {}

    AscendingIterator& operator=(const AscendingIterator& other) {}

    bool operator==(const AscendingIterator& other) const {}

    bool operator!=(const AscendingIterator& other) const {}

    int operator*() const {}

    AscendingIterator& operator++() {}

    AscendingIterator begin() const {}

    AscendingIterator end() const {}


};


#endif //INC_5TASKA_ASCENDINGITERATOR_H
