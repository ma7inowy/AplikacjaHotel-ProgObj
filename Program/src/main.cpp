#include <iostream>
#include <memory>
#include "Client.h"
#include "ClientRepository.h"
#include "ClientManager.h"
#include "Address.h"
#include "Room.h"
#include "Book.h"
#include "Exceptions.h"
#include "RoomRepository.h"
#include "RoomManager.h"
#include "RoomType.h"
#include "RoomBasic.h"
#include "RoomPA.h"
#include "RoomPB.h"
#include "BookRepository.h"
#include "BookManager.h"
#include "Application.h"

using namespace std;


int main()
{
   try {
       spRPB rPB(new RoomPB(6, 300));
       spR room1(new Room(rPB));
       spRR rR(new RoomRepository());
       spRM rM(new RoomManager(rR));
       rM->addRoom(room1);
       spA adres1(new Address("Rymanowska 13", "21", "Łódź", "Polska"));
       spC c1(new Client("Andrzej Nowak", adres1));
       spCR cRepository(new ClientRepository);
       spCM cManager(new ClientManager(cRepository));
       cManager->addClient(c1);
       spB book1(new Book(c1, room1, ptime(date(2018, Nov, 2)), ptime(date(2018, Nov, 5))));
       spB book2(new Book(c1, room1, ptime(date(2018, Nov, 5)), ptime(date(2018, Nov, 7))));
       spBR bookcurrrepo(new BookRepository());
       spBM bookman(new BookManager(bookcurrrepo));
       bookman->addBook(book1);
       bookman->addBook(book2);


       Application application(cManager,bookman,rM);
       application.start();
   }
   catch(ClientCreationException &s)
   {
       cout<<s.what()<<endl;
   }
   catch(BookCreationException &s)
   {
       cout<<s.what()<<endl;
   }

    return 0;

}