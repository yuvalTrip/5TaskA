//
// Created by yuvalbs on 5/25/23.
//
#include "doctest.h"
#include "sources/MagicalContainer.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>

using namespace std;


TEST_CASE("Throws checks "){
//    std::cout<<"container.size():"<<container.size()<<std::endl;
    CHECK_NOTHROW(MagicalContainer container);
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(1));
    CHECK(container.size() == 1);
//    std::cout<<"container.size():"<<container.size()<<std::endl;
//    std::cout<<"container.getelements()[0]:"<<container.getElements()[0]<<std::endl;

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
//    std::cout<<"container.size():"<<container.size()<<std::endl;
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
//        std::cout<<"primeIter.begin() :"<<primeIter.begin() <<std::endl;
//    std::cout<<"primeIter.end() :"<<primeIter.end() <<std::endl;

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
    CHECK(*ascIter.end() == 1);

    //SideCrossIterator
    SideCrossIterator sCrossIter(container);
    CHECK(*sCrossIter.begin() == 1);

//    PrimeIterator
    MagicalContainer container_;
    container_.addElement(2);
    CHECK(container_.size()==1);
    PrimeIterator primeIter(container_);
//    std::cout<<"primeIter.begin() :"<<primeIter.begin() <<std::endl;
    CHECK(*primeIter.begin() == 2);//prime and single number
    // and with not prime number
    MagicalContainer container_1;
    container_1.addElement(4);
    PrimeIterator primeIter_(container_1);
    CHECK(primeIter_.begin() == primeIter_.end());
    CHECK(container_1.size()==1);

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
//    std::vector<int> crossOrderElements = crossIter.getSideCrossElements();
//    std::vector<int> crossOrderElements(crossIter.begin(), crossIter.end());
    std::vector<int> crossOrderElements;
    for (int* it = crossIter.begin(); it <= crossIter.end(); it++) {
        std::cout << "it: "<< *it <<std::endl;
        crossOrderElements.push_back(*it);
    }
    std::vector<int> temp_vector=std::vector<int>({1, 5, 2, 4, 3});
//        for (std::vector<int>::size_type i=0;i<container.size();i++) {
////        std::cout << "crossOrderElements" << "[" << i << "]=" << crossOrderElements[i] << std::endl;
////        std::cout << "temp_vector" << "[" << i << "]=" << temp_vector[i] << std::endl;
//
//            CHECK(crossOrderElements[i]==temp_vector[i]);
//    }
    CHECK(crossOrderElements == std::vector<int>({1, 5, 2, 4, 3}));//One from the start, one from the end

    //Even number
    container.addElement(6);
    CHECK(container.size()==6);
    SideCrossIterator crossIter_(container);

    std::vector<int> crossOrderElements_;
    for (int* it = crossIter_.begin(); it <= crossIter_.end(); it++) {
//        std::cout << "it: "<< *it <<std::endl;
        crossOrderElements_.push_back(*it);
    }
    CHECK(crossOrderElements_ == std::vector<int>({1, 6, 2, 5, 3, 4}));//One from the start, one from the end


//    std::vector<int> crossOrderElements_(crossIter_.begin(), crossIter_.end());
//    CHECK(crossOrderElements_ == std::vector<int>({1, 6, 2, 5, 3, 4}));//One from the start, one from the end
//
    //Check operator
    CHECK(crossIter_.operator*() == 1);    //first element
    CHECK(crossIter_.operator++() == 6); // 1, 6, 2, 5, 3, 4
    CHECK(crossIter_.operator++() == 2);
    CHECK(crossIter_.operator++() == 5);
    CHECK(crossIter_.operator++() == 3);
    CHECK(crossIter_.operator++() == 4);
    CHECK_THROWS(crossIter_.operator++()); // out of bounds

////    CHECK(crossIter_.operator--() == 3);
////    CHECK(crossIter_.operator--() == 5);
////    CHECK(crossIter_.operator--() == 2);
////    CHECK(crossIter_.operator--() == 6);
////    CHECK(crossIter_.operator--() == 1);
////    CHECK_THROWS(crossIter_.operator--()); // out of bounds

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

    std::vector<int> primeElements;
    for (int* it = primeIter.begin(); it <= primeIter.end(); it++) {
//        std::cout << "it: "<< *it <<std::endl;
        primeElements.push_back(*it);
    }
    CHECK(primeElements == std::vector<int>({2, 3}));//Only primes number

//    std::vector<int> primeElements(primeIter.begin(), primeIter.end());
//    CHECK(primeElements == std::vector<int>({2, 3}));

    //Operators checks
    CHECK(primeIter.operator*() == 2);    //first element
    CHECK(primeIter.operator++() == 3); // 2 3
////    CHECK(primeIter.operator--() == 2);
////    CHECK_THROWS(primeIter.operator--()); // out of bounds
////    CHECK(primeIter.operator++() == 3);
}
//
TEST_CASE("Ascending Iterator checks") {
    MagicalContainer elements_;
    elements_.addElement(11);
    elements_.addElement(-1);
    elements_.addElement(13);
    elements_.addElement(4);

    //size is 4
    CHECK(elements_.size() == 4);

    AscendingIterator ascIter(elements_);

    std::vector<int> ascendingElements;
    for (int* it = ascIter.begin(); it <= ascIter.end(); it++) {
//        std::cout << "it: "<< *it <<std::endl;
        ascendingElements.push_back(*it);
    }
    CHECK(ascendingElements == std::vector<int>({-1, 4, 11, 13}));//Ascending order

//    std::vector<int> ascendElements(ascIter.begin(), ascIter.end());
//    CHECK(ascendElements == std::vector<int>({-1, 4, 11, 13}));

//    Check operators
    CHECK(ascIter.operator*() == -1);    //first element
    CHECK(ascIter.operator++() == 4); //second element
    CHECK(ascIter.operator++() == 11); //third element
    CHECK(ascIter.operator++() == 13); //fourth element
    CHECK_THROWS(ascIter.operator++()); //out of bounds
////    CHECK(ascIter.operator--() == 11); //third element
////    CHECK(ascIter.operator--() == 4); //second element
////    CHECK(ascIter.operator--() == -1); //first element
////    CHECK_THROWS(ascIter.operator--()); //out of bounds
//
}