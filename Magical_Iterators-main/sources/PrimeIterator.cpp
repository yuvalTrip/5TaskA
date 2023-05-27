//
// Created by yuvalbs on 5/25/23.
//

#include "PrimeIterator.h"
#include <iostream>
#include <cmath>
using namespace std;
bool PrimeIterator::isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

PrimeIterator::PrimeIterator(const MagicalContainer& container) {
    std::vector<int> elements_asc= container.getElements();
    //First I will sort it
    std::sort(elements_asc.begin(), elements_asc.end());

    //After the sort I will start to take only elements that are prime numbers
    std::vector<int> PrimesArray;
    //Define index
//    std::vector<int>::size_type prime_ind = 0;                            // Left pointer starting from the beginning

    for ( std::vector<int>::size_type i=0;i<elements_asc.size();i++)
    {
//        std::cout<<"i: "<<i<<std::endl;
        if (isPrime(elements_asc[i])==true){
//            std::cout<<"prime_ind: "<<prime_ind<<std::endl;

            PrimesArray.push_back(elements_asc[i]);
        }
    }

    elements=PrimesArray;
}


bool PrimeIterator::operator==(const PrimeIterator& other) const {
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

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

int PrimeIterator::operator*() const {
//    std::cout << "currentIndex: "<< currentIndex <<std::endl;

    return elements[currentIndex];;
}
//This is the "PrimeIterator& operator++();" implementation
//PrimeIterator& PrimeIterator::operator++() {
//    ++currentIndex;
//    return *this;
//}
int PrimeIterator::operator++(){
    if (currentIndex+1>elements.size()-1)
    {
        throw std::invalid_argument("Out of bounds!");
    }
    if(currentIndex<elements.size() -1){
        currentIndex++;
    }
    return elements[currentIndex];
}
int * PrimeIterator::begin() {
    if (elements.size()==0) {
        return NULL;
    }else
    {
        return &elements[0];

    }
}

int * PrimeIterator::end(){
    if (elements.size()==0) {
        return NULL;
    }
    else{
        return &elements[elements.size()-1];

    }
}


PrimeIterator PrimeIterator::operator=(const PrimeIterator &primeIterator){
    //Assignment of the attrubutes
    elements = primeIterator.elements;
    currentIndex = primeIterator.currentIndex;
//    PrimeIterator primeIter(container);
    return *this;
}