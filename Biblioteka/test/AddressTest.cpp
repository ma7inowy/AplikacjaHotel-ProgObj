#include <boost/test/unit_test.hpp>

#include "Address.h"

using namespace std;
BOOST_AUTO_TEST_CASE(AddressTest) {
    Address adres1("Szeroka 1","2","Tomaszów Mazowiecki","Polska");
    Address adres2("Warszawska 1","13","Tomaszów Mazowiecki","Polska");
    BOOST_CHECK(adres1.getStreet()=="Szeroka 1");
    BOOST_CHECK(adres1.getNumber()=="2");
    BOOST_CHECK(adres1.getCity()=="Tomaszów Mazowiecki");
    BOOST_CHECK(adres1.getCountry()=="Polska");
    BOOST_CHECK(adres2.getStreet()!=adres1.getStreet());
    BOOST_CHECK(adres2.getNumber()!=adres1.getNumber());
    BOOST_CHECK(adres2.getCity()==adres1.getCity());
    BOOST_CHECK(adres2.getCountry()==adres1.getCountry());
    BOOST_CHECK(adres2.stringInfo()!=adres1.stringInfo());
}