//
// Created by yuvalbs on 5/25/23.
//
#include "doctest.h"
//#include "sources/Team.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>

using namespace std;

using namespace ariel;

TEST_CASE("Throws checks "){

    CHECK_NOTHROW(MagicalContainer container);
    CHECK_NOTHROW(container.addElement(1));
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);
}

TEST_CASE("Different orders"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    std::cout << "Ascending order: ";
    for (AscendingIterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}


TEST_CASE("Cowboy initiation and shooting") {
    Point a(1.5, 4.5);
//    //CHECK_NOTHROW(Cowboy * evgeni = new Cowboy("evgeni", a));//Problem in valgrind!
    Cowboy * evgeni = new Cowboy("evgeni", a);
//    //CHECK_NOTHROW(Cowboy * harel = new Cowboy("harel", a)); //Problem in valgrind!
    Cowboy * harel = new Cowboy("harel", a);
//
    CHECK(evgeni->bullets == 6);
    CHECK(evgeni->hits == 110);
    CHECK("evgeni"==evgeni->getName());
    CHECK(evgeni->getLocation().getX()==a.getX());
    CHECK(evgeni->getLocation().getY()==a.getY());
//    CHECK_NOTHROW(evgeni->print());
//    CHECK(evgeni->print()=="evgeni,110,(1.5,4.5)");// Print: character name, number of hits, point of the character
    CHECK(evgeni->hasBoolets()==true);
    evgeni->shoot(harel);
    CHECK(evgeni->bullets == 5);
    evgeni->reload();// Reload the gun with 6 new bullets
    CHECK(evgeni->hasBoolets() == true);// Check if there is more bullets
    CHECK(evgeni->bullets == 11);// Check how many bullets
    //Add to team
    CHECK_NOTHROW(Team team_A(evgeni));
    CHECK(evgeni->isAlive()==true);
//
    delete evgeni;
    delete harel;
}