#include <sstream>
#include <fstream>
#include "../include/Application.h"
#include "../include/BookManager.h"
#include "../include/ClientManager.h"
#include "../include/RoomManager.h"
#include "../include/Room.h"
#include "../include/Book.h"
#include "../include/Address.h"
#include "../include/RoomBasic.h"
#include "../include/RoomPA.h"
#include "../include/RoomPB.h"

#include<iostream>
#include<string>
Application::Application(spCM cm, spBM bm, spRM rm) {
    this->cm = cm;
    this->bm = bm;
    this->rm = rm;
}

Application::~Application() {

}

void Application::start() {

unsigned int pod = 0;
do{
    cout<< "Co chcesz zrobić: \n1. Pokaż listę klientów\n2. Pokaż listę pokojów\n3. Pokaż bieżące rezerwacje\n4. Zakonczone rezerwacje\n5. Dodaj nowego klienta\n"
           "6. Dodaj nowy pokój\n7. Dodaj rezerwację\n8. Usuń rezerwację\n0. Wyjscie\nPodaj odpowiedni numer: ";
    do {
        cin.sync();
        cin.clear();
        cin >> pod;
        if (pod > 8)
            cout << "Nie ma takiej opcji, wybierz jeszcze raz. \n";
    } while (pod > 8);

    switch (pod) {
        case 0: {

        }
            break;
        case 1: {
            cout << "Lista wszystkich klientów: \n";
            cout << cm->clientInfo();
        }
            break;
        case 2: {
            cout << "Lista wszystkich pokojów: \n";
            cout << rm->roomInfo();
        }
            break;

        case 3:{
            cout<<"Bieżące rezerwacje:"<<endl;
            cout<<bm->booksInfo()<<endl;
        }break;

        case 4:{
            cout<<"Zakończone rezerwacje:"<<endl;
            cout<<bm->archiveBooksInfo()<<endl;
        }break;

        case 5: {
            cout << "Dodaj nowego klienta:" << endl;
            cout << "Imię i nazwisko:";
            string name_surname;

            cin.clear();
            cin.ignore();
            getline(cin, name_surname);

            cout << "Adres: " << endl;
            string street, number, city, country;
            cout << "Ulica: ";
            cin >> street;
            cout << "Numer mieszkania: ";
            cin >> number;
            cout << "Miasto: ";
            cin >> city;
            cout << "Kraj: ";
            cin >> country;

            shared_ptr<Address> address(new Address(street, number, city, country));
            shared_ptr<Client> client(new Client(name_surname, address));

            if (cm->addClient(client)) {
                cout << "Pomyślnie dodano klienta." << endl;
            } else cout << "Nie udało się dodać klienta." << endl;


        }
            break;

        case 6: {
            cout << "Dodaj nowy pokoj:" << endl;
            cout << "1.RoomBasic:" << endl;
            cout << "2.RoomPremiumA:" << endl;
            cout << "3.RoomPremiumB:" << endl;
            cout << "Wybierz typ pokoju(1-3):";
            int typ_pokoju, ilosc_osob;
            int temp=0;
            cin >> typ_pokoju;
            cout << "Ilosc osob:";
            cin >> ilosc_osob;
            if (typ_pokoju == 1) {
                shared_ptr<RoomBasic> rB(new RoomBasic(ilosc_osob, 100));
                shared_ptr<Room> room(new Room(rB));
                rm->addRoom(room);
                temp++;

            }
            if (typ_pokoju == 2) {
                shared_ptr<RoomPA> rPA(new RoomPA(ilosc_osob, 200));
                shared_ptr<Room> room(new Room(rPA));
                rm->addRoom(room);
                temp++;
            }
            if (typ_pokoju == 3) {
                shared_ptr<RoomPB> rPB(new RoomPB(ilosc_osob, 150));
                shared_ptr<Room> room(new Room(rPB));
                rm->addRoom(room);
                temp++;
            }
            if(temp==1)
                cout << "Pomyślnie dodano pokój!" << endl;

            else cout << "Nie udało się dodać pokoju!" << endl;

        }
            break;

        case 7: {
            cout << "Wybrano dodanie nowej rezerwacji. Wybierz klienta: \n";
            cout << cm->clientInfo();
            cout << "Podaj odpowiednia cyfre: ";
            unsigned int c, r;

            cin.sync();
            cin.clear();
            cin >> c;
            if (cm->getClientByNumber(c) == nullptr) {
                cout << "Nie ma takiego klienta!" << endl;
                break;
            }
            cout << "\nWybierz pokój: \n";
            cout << rm->roomInfo();
            cout << "Podaj odpowiednia cyfre: ";

            if (rm->getRoomByNumber(c) == nullptr) {
                cout << "Nie ma takiego pokoju!" << endl;
                break;
            }

            cin.sync();
            cin.clear();
            cin >> r;

            unsigned int rok1, rok2, miesiac1, miesiac2, dzien1, dzien2;
            cout << "\nPodaj datę rozpoczęcia wynajęcia: \nrok: ";
            cin >> rok1;
            cout << "miesiąc: \n";
            cout << this->months();
            cin >> miesiac1;
            cout << "dzień: ";
            cin >> dzien1;
            if (this->checkDate(dzien1, miesiac1, rok1) == false) {
                cout << "Taka data nie istnieje. " << endl;
                break;
            }


            cout << "\nPodaj datę zakończenia wynajecia: \nrok: ";
            cin >> rok2;
            cout << "miesiąc: ";
            cout << this->months();
            cin >> miesiac2;
            cout << "dzień: ";
            cin >> dzien2;
            if (this->checkDate(dzien2, miesiac2, rok2) == false) {
                cout << "Taka data nie istnieje. " << endl;
                break;
            }


            shared_ptr<Book> book(
                    new Book(cm->getClientByNumber(c), rm->getRoomByNumber(r), ptime(date(rok1, miesiac1, dzien1)),
                             ptime(date(rok2, miesiac2, dzien2))));
            if (bm->addBook(book))
                cout << "Pomyslnie dodano rezerwację." << endl;
            else
                cout << "Nie dodano rezerwacji, wyjście do menu głównego" << endl;
        }
            break;


        case 8:{
                unsigned int remove_book;
                cout<<"Usuwanie rezerwacji"<<endl;
                cout<<bm->booksInfo()<<endl;
                cout<<"Wybierz, którą rezerwację chcesz usunąć:"<<endl;
                cin>>remove_book;
                if(bm->removeBook(bm->getBookByNumber(remove_book)))
                    cout<<"Pomyslnie usunąłeś rezerwację"<<endl;
                else cout<<"Nie udało się usunąć rezerwacji"<<endl;
            }break;
        default:
        {

        }
        break;

    }
    if (pod == 0)
        cout << "Wyjscie z programu..." << endl;
}
    while(pod!=0);

}

string Application::months() {
    stringstream xd;
    for(int i = 1 ; i < 13 ; i ++)
    {
        xd<<i<<". ";
        if(i==1)
            xd<<"Styczeń";
        else if(i==2)
            xd<<"Luty";
        else if(i==3)
            xd<<"Marzec";
        else if(i==4)
            xd<<"Kwiecień";
        else if(i==5)
            xd<<"Maj";
        else if(i==6)
            xd<<"Czerwiec";
        else if(i==7)
            xd<<"Lipiec";
        else if(i==8)
            xd<<"Sierpień";
        else if(i==9)
            xd<<"Wrzesień";
        else if(i==10)
            xd<<"Październik";
        else if(i==11)
            xd<<"Listopad";
        else if(i==12)
            xd<<"Grudzień";
        xd<<endl;
    }
    return xd.str();
}


bool Application::checkDate(unsigned int dzien1, unsigned int miesiac1, unsigned int rok1)
{

    if(miesiac1==1 || miesiac1==3 || miesiac1==5 || miesiac1==7 || miesiac1==8 || miesiac1==10 || miesiac1==12)
    {
        if(dzien1==0 || dzien1>31)
        {
            return false;
        }
    }
    else if(miesiac1==4 || miesiac1==6 || miesiac1==9 || miesiac1==11)
    {
        if(dzien1==0 || dzien1>30)
        {
           return false;
        }
    }
    else if(miesiac1 == 2)
    {
        if(((rok1 % 4 == 0) && (rok1 % 100 != 0)) || (rok1 % 400 == 0))
        {
            if(dzien1==0 || dzien1>29)
            {
                return false;
            }
        } else{
            if(dzien1==0 || dzien1>28)
            {
                return false;
            }
        }
    }
    return true;
}
