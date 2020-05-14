#include <boost/test/unit_test.hpp>
#include "Room.h"
#include "RoomType.h"
#include "RoomBasic.h"
#include "RoomRepository.h"
#include "RoomManager.h"
#include "RoomPA.h"
#include "RoomPB.h"
#include <memory>
using namespace std;

BOOST_AUTO_TEST_CASE(RoomTest) {
    shared_ptr<RoomBasic>rB (new RoomBasic(5,1000));
    shared_ptr<Room>r1(new Room(rB));
    BOOST_CHECK(rB->getPeople()==5);
    BOOST_CHECK(rB->typeName()=="RoomBasic");
}

BOOST_AUTO_TEST_CASE(RoomRepositoryTest_RoomManagerTest) {
    shared_ptr<RoomBasic>rB (new RoomBasic(3,1000));
    shared_ptr<RoomPA>rPA (new RoomPA(4,2000));
    shared_ptr<RoomPB>rPB (new RoomPB(6,3000));
    shared_ptr<Room>room1(new Room(rB));
    shared_ptr<Room>room2(new Room(rPA));
    shared_ptr<Room>room3(new Room(rPB));


    shared_ptr<RoomRepository> rR(new RoomRepository());
    shared_ptr<RoomManager> rM(new RoomManager(rR));
    rM->addRoom(room1);
    rM->addRoom(room2);


    BOOST_CHECK(rB->getPeople()==3);
    BOOST_CHECK(rPA->getPeople()==4);
    BOOST_CHECK(rPB->getPeople()==6);
    BOOST_CHECK(rB->getBaseBookPrice()==1000);
    BOOST_CHECK(rPA->getBaseBookPrice()==2000);
    BOOST_CHECK(rPB->getBaseBookPrice()==3000);
    BOOST_CHECK(rM->getRoom(room1)==room1);
    BOOST_CHECK(rM->getRoom(room2)==room2);
    BOOST_CHECK(rM->getRoom(room3)==room3);
    BOOST_CHECK(rM->addRoom(room1)==false);
    BOOST_CHECK(rM->removeRoom(room2)==true);
    BOOST_CHECK(rM->removeRoom(room3)==false);






}