//
// Created by yuvalbs on 5/25/23.
//
#include "doctest.h"
#include "sources/MagicalContainer.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>

using namespace std;


TEST_CASE("Throws checks "){

    CHECK_NOTHROW(MagicalContainer container);
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(1));
    CHECK(container.size() == 1);
    CHECK_NOTHROW(container.removeElement(1));
}

TEST_CASE("Add, Remove and Size"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(1);//1
    CHECK(container.size() == 1);
    container.addElement(2);// 1 2
    CHECK(container.size() == 2);
    container.removeElement(2);// 1
    CHECK(container.size() == 1);
    //Add same element
    container.addElement(1);//1 1
    CHECK(container.size() == 2);
    //Remove element that do not exist in the container
    CHECK(container.contains(2) == false);
    container.removeElement(2);// Do nothing
    CHECK(container.size() == 2);// 1 1
    // Remove element appears in few instances")
    container.removeElement(1);// now the container should be empty
    CHECK(container.size() == 0);

}

TEST_CASE("MagicalContainer contains checks")
{
    MagicalContainer container;
    container.addElement(1);// 1
    container.addElement(2);// 1 2
    CHECK(container.contains(1)==true);
    CHECK(container.contains(2)==true);
    CHECK(container.contains(0)==false);
    container.removeElement(2);//1
    CHECK(container.size()==1);
    CHECK(container.contains(2)==false);//because we removed it
}

TEST_CASE("Iterators with empty containers checks")
{
    MagicalContainer container;

    //AscendingIterator
    AscendingIterator ascIter(container);
    CHECK(ascIter.begin() == ascIter.end());
    CHECK(container.size()==0);
    //SideCrossIterator
    SideCrossIterator crossIter(container);
    CHECK(crossIter.begin() == crossIter.end());
    CHECK(container.size()==0);
    //PrimeIterator
    PrimeIterator primeIter(container);
    CHECK(primeIter.begin() == primeIter.end());
    CHECK(container.size()==0);


}


TEST_CASE("Iterators with single element in containers checks")
{
    MagicalContainer container;
    container.addElement(1);
    CHECK(container.size()==1);

    //AscendingIterator
    AscendingIterator ascIter(container);
    CHECK(*ascIter.begin() == 1);
    CHECK(*ascIter.end() == 1);////////////////////////////

    //SideCrossIterator
    SideCrossIterator sCrossIter(container);
    CHECK(*sCrossIter.begin() == 1);

    //PrimeIterator
    PrimeIterator primeIter(container);
    CHECK(*primeIter.begin() == 1);//prime and single number
    // and with not prime number
    MagicalContainer container_;
    container_.addElement(4);
    PrimeIterator primeIter_(container_);
    CHECK(primeIter_.begin() == primeIter_.end());
    CHECK(container_.size()==0);

}

TEST_CASE("SideCrossIterator odd and even number of elements")
{
    //Odd number
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    CHECK(container.size()==5);

    SideCrossIterator crossIter(container);
    std::vector<int> crossOrderElements(crossIter.begin(), crossIter.end());
    CHECK(crossOrderElements == std::vector<int>({1, 5, 2, 4, 3}));//One from the start, one from the end

    //Even number
    container.addElement(6);
    CHECK(container.size()==6);
    SideCrossIterator crossIter_(container);
    std::vector<int> crossOrderElements_(crossIter_.begin(), crossIter_.end());
    CHECK(crossOrderElements_ == std::vector<int>({1, 6, 2, 5, 3, 4}));//One from the start, one from the end

    //Check operator
    CHECK(crossIter_.operator*() == 1);    //first element
    CHECK(crossIter_.operator++() == 6); // 1, 6, 2, 5, 3, 4
    CHECK(crossIter_.operator++() == 2);
    CHECK(crossIter_.operator++() == 5);
    CHECK(crossIter_.operator++() == 3);
    CHECK(crossIter_.operator++() == 4);
    CHECK_THROWS(crossIter_.operator++()); // out of bounds

}
TEST_CASE("PrimeIterator with prime and not prime elements  ")
{
    MagicalContainer container;
    container.addElement(4);
    container.addElement(3);
    container.addElement(6);
    container.addElement(9);
    container.addElement(2);

    PrimeIterator primeIter(container);
    std::vector<int> primeElements(primeIter.begin(), primeIter.end());
    CHECK(primeElements == std::vector<int>({2, 3}));

    //Operators checks
    CHECK(primeIter.operator*() == 2);    //first element
    CHECK(primeIter.operator++() == 3); // 2 3

}

TEST_CASE("Ascending Iterator checks") {
    MagicalContainer elements_;
    elements_.addElement(11);
    elements_.addElement(-1);
    elements_.addElement(13);
    elements_.addElement(4);

    //size is 4
    CHECK(elements_.size() == 4);

    AscendingIterator ascIter(elements_);

    std::vector<int> ascendElements(ascIter.begin(), ascIter.end());
    CHECK(ascendElements == std::vector<int>({-1, 4, 11, 13}));

    //Check operators
    CHECK(ascIter.operator*() == -1);    //first element
    CHECK(ascIter.operator++() == 4); //second element
    CHECK(ascIter.operator++() == 11); //third element
    CHECK(ascIter.operator++() == 13); //fourth element
    CHECK_THROWS(ascIter.operator++()); //out of bounds


}