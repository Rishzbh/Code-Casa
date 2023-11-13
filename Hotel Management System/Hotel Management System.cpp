#include <iostream>
#include <string.h>
#include <conio.h>
#define MAX_ROOMS 100
using namespace std;

class Lodger
{
public:
    char lodgerName[100];
    char lodgerAddress[100];
    char lodgerPhone[12];
    char checkInDate[20];
    char checkOutDate[20];
    float paymentAdvance;
    int bookingId;
};

class Accommodation
{
public:
    char roomType;
    char climateType;
    char airConditioning;
    int roomNumber;
    int rentalCost;
    int reservationStatus;

    class Lodger lodger;
    class Accommodation addAccommodation(int);
    void findAccommodation(int);
    void removeAccommodation(int);
    void displayAccommodation(Accommodation);
};

class HotelSystem : protected Accommodation
{
public:
    void initiateOccupancy();
    void showAvailableRooms();
    void searchLodgerByName(char *);
    void completeCheckOut(int);
    void generateLodgerSummaryReport();
};

class Accommodation rooms[MAX_ROOMS];
int roomCount = 0;

Accommodation Accommodation::addAccommodation(int rno)
{
    class Accommodation accommodation;
    accommodation.roomNumber = rno;
    cout << "\nSpecify AC/Non-AC (A/N) : ";
    cin >> accommodation.airConditioning;
    cout << "\nSpecify Comfort (S/N) : ";
    cin >> accommodation.climateType;
    cout << "\nSpecify Size (B/S) : ";
    cin >> accommodation.roomType;
    cout << "\nDaily Rent : ";
    cin >> accommodation.rentalCost;
    accommodation.reservationStatus = 0;

    cout << "\nAccommodation Added Successfully!";
    getch();
    return accommodation;
}

void Accommodation::findAccommodation(int rno)
{
    int i, found = 0;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "Accommodation Details\n";
        if (rooms[i].reservationStatus == 1)
        {
            cout << "\nAccommodation is Reserved (not available)";
        }
        else
        {
            cout << "\nAccommodation is available";
        }
        displayAccommodation(rooms[i]);
        getch();
    }
    else
    {
        cout << "\nAccommodation not found";
        getch();
    }
}

void Accommodation::displayAccommodation(Accommodation tempAccommodation)
{
    cout << "\nRoom Number: \t" << tempAccommodation.roomNumber;
    cout << "\nSpecify AC/Non-AC (A/N) " << tempAccommodation.airConditioning;
    cout << "\nSpecify Comfort (S/N) " << tempAccommodation.climateType;
    cout << "\nSpecify Size (B/S) " << tempAccommodation.roomType;
    cout << "\nRent: " << tempAccommodation.rentalCost;
}

void HotelSystem::initiateOccupancy()
{
    int i, found = 0, rno;

    class Accommodation accommodation;
    cout << "\nEnter Room number : ";
    cin >> rno;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        if (rooms[i].reservationStatus == 1)
        {
            cout << "\nAccommodation is already Booked";
            getch();
            return;
        }

        cout << "\nEnter booking id: ";
        cin >> rooms[i].lodger.bookingId;

        cout << "\nEnter Lodger Name (First Name): ";
        cin >> rooms[i].lodger.lodgerName;

        cout << "\nEnter Address (only city): ";
        cin >> rooms[i].lodger.lodgerAddress;

        cout << "\nEnter Phone: ";
        cin >> rooms[i].lodger.lodgerPhone;

        cout << "\nEnter Check-In Date: ";
        cin >> rooms[i].lodger.checkInDate;

        cout << "\nEnter Check-Out Date: ";
        cin >> rooms[i].lodger.checkOutDate;

        cout << "\nEnter Advance Payment: ";
        cin >> rooms[i].lodger.paymentAdvance;

        rooms[i].reservationStatus = 1;

        cout << "\nLodger Checked-in Successfully..";
        getch();
    }
}

void HotelSystem::showAvailableRooms()
{
    int i, found = 0;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].reservationStatus == 0)
        {
            displayAccommodation(rooms[i]);
            cout << "\n\nPress enter for the next room";
            found = 1;
            getch();
        }
    }
    if (found == 0)
    {
        cout << "\nAll rooms are reserved";
        getch();
    }
}

void HotelSystem::searchLodgerByName(char *pname)
{
    int i, found = 0;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].reservationStatus == 1 && stricmp(rooms[i].lodger.lodgerName, pname) == 0)
        {
            cout << "\nLodger Name: " << rooms[i].lodger.lodgerName;
            cout << "\nRoom Number: " << rooms[i].roomNumber;

            cout << "\n\nPress enter for the next record";
            found = 1;
            getch();
        }
    }
    if (found == 0)
    {
        cout << "\nPerson not found.";
        getch();
    }
}

void HotelSystem::completeCheckOut(int roomNum)
{
    int i, found = 0, days, rno;
    float billAmount = 0;
    for (i = 0; i < roomCount; i++)
    {
        if (rooms[i].reservationStatus == 1 && rooms[i].roomNumber == roomNum)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "\nEnter Number of Days:\t";
        cin >> days;
        billAmount = days * rooms[i].rentalCost;

        cout << "\n\t-------- CheckOut Details --------\n";
        cout << "\nLodger Name : " << rooms[i].lodger.lodgerName;
        cout << "\nRoom Number : " << rooms[i].roomNumber;
        cout << "\nAddress : " << rooms[i].lodger.lodgerAddress;
        cout << "\nPhone : " << rooms[i].lodger.lodgerPhone;
        cout << "\nTotal Amount Due : " << billAmount << " /";
        cout << "\nAdvance Paid: " << rooms[i].lodger.paymentAdvance << " /";
        cout << "\n*** Total Payable: " << billAmount - rooms[i].lodger.paymentAdvance << "/ only";

        rooms[i].reservationStatus = 0;
    }
    getch();
}

void HotelSystem::generateLodgerSummaryReport()
{
    if (roomCount == 0)
    {
        cout << "\n No Lodger in Hotel !!";
    }
    for (int i = 0; i < roomCount; i++)
    {
        if (rooms[i].reservationStatus == 1)
        {
            cout << "\n Lodger Name: " << rooms[i].lodger.lodgerName;
            cout << "\n Room Number: " << rooms[i].roomNumber;
            cout << "\n Address (only city): " << rooms[i].lodger.lodgerAddress;
            cout << "\n Phone: " << rooms[i].lodger.lodgerPhone;
            cout << "\n---------------------------------------";
        }
    }

    getch();
}

void manageAccommodations()
{
    class Accommodation accommodation;
    int opt, rno, i, flag = 0;
    char ch;
    do
    {
        system("cls");
        cout << "\n--- Manage Accommodations ---";
        cout << "\n1. Add Accommodation";
        cout << "\n2. Search Accommodation";
        cout << "\n3. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\nEnter Room Number: ";
            cin >> rno;
            i = 0;
            for (i = 0; i < roomCount; i++)
            {
                if (rooms[i].roomNumber == rno)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                cout << "\nRoom Number is Present.\nPlease enter a unique Number";
                flag = 0;
                getch();
            }
            else
            {
                rooms[roomCount] = accommodation.addAccommodation(rno);
                roomCount++;
            }
            break;
        case 2:
            cout << "\nEnter room number: ";
            cin >> rno;
            accommodation.findAccommodation(rno);
            break;
        case 3:
            // nothing to do
            break;
        default:
            cout << "\nPlease Enter the correct option";
            break;
        }
    } while (opt != 3);
}

int main()
{
    class HotelSystem hs;
    int i, j, opt, rno;
    char ch;
    char pname[100];

    system("cls");

    do
    {
        system("cls");
        cout << "-------- Hotel System --------\n";
        cout << "\n1. Manage Accommodations";
        cout << "\n2. Check-In Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Lodger";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Lodger Summary Report";
        cout << "\n7. Exit";
        cout << "\n\nEnter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            manageAccommodations();
            break;
        case 2:
            if (roomCount == 0)
            {
                cout << "\nAccommodations data is not available.\nPlease add the accommodations first.";
                getch();
            }
            else
                hs.initiateOccupancy();
            break;
        case 3:
            if (roomCount == 0)
            {
                cout << "\nAccommodations data is not available.\nPlease add the accommodations first.";
                getch();
            }
            else
                hs.showAvailableRooms();
            break;
        case 4:
            if (roomCount == 0)
            {
                cout << "\nAccommodations are not available.\nPlease add the accommodations first.";
                getch();
            }
            else
            {
                cout << "Enter Lodger Name: ";
                cin >> pname;
                hs.searchLodgerByName(pname);
            }
            break;
        case 5:
            if (roomCount == 0)
            {
                cout << "\nAccommodations are not available.\nPlease add the accommodations first.";
                getch();
            }
            else
            {
                cout << "Enter Room Number : ";
                cin >> rno;
                hs.completeCheckOut(rno);
            }
            break;
        case 6:
            hs.generateLodgerSummaryReport();
            break;
        case 7:
            cout << "\nTHANK YOU! FOR USING HOTEL MANAGEMENT SYSTEM\nHAVE A NICE DAY";
            break;
        default:
            cout << "\nPlease Enter correct option";
            break;
        }
    } while (opt != 7);

    getch();
}

