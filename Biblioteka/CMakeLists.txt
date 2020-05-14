#CMakeLists.txt podprojektu Biblioteka

set(SOURCE_FILES
        src/Client.cpp
        src/Room.cpp
        src/RoomType.cpp
        src/RoomBasic.cpp
        src/Premium.cpp
        src/RoomPA.cpp
        src/RoomPB.cpp
        src/RoomRepository.cpp
        src/Address.cpp
        src/ClientRepository.cpp
        src/RoomManager.cpp
        src/ClientManager.cpp
        src/Book.cpp
        src/BookRepository.cpp
        src/BookManager.cpp)

add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)
#######################################################################
enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)
####################################
set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp
        test/AddressTest.cpp
        test/RoomTest.cpp
        test/BookTest.cpp ../Program/src/Application.cpp ../Program/include/Application.h)

add_executable (TestBiblioteki ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries (TestBiblioteki
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_test(TestClient1 TestBiblioteki
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )