#include <iostream>
#include <cstdlib>

using namespace std;

class Guest
{
public:
    string name;
    int cnic;
    Guest *Next;
    Guest *Prev;

    Guest()
    {
        cnic = 0;
        Next = nullptr;
        Prev = nullptr;
    }
};

class Marian
{
public:
    Guest *First_Family;
    int Family_left, Family_Total;

    Guest *First_Business;
    int Business_left, Business_Total;

    Guest *First_Couple;
    int Couple_left, Couple_Total;

    //Guest *PentHouse;
    Guest *penthouseGuest;
    int choice;
    int amount;
    int number_of_rooms;
    int number_of_days;

    Marian()
    {
        Family_left = 0;
        Family_Total = 20;
        Business_left = 0;
        Business_Total = 30;
        Couple_left = 0;
        Couple_Total = 10;
        First_Family = nullptr;
        First_Business = nullptr;
        First_Couple = nullptr;
        penthouseGuest = nullptr;
    }


    void visit_marian();
    void family_room();
    void executive_room();
    void couple_room();
    void PentHouse();
    void display();
    void deleteRecord();
    void working();
};

void Marian::visit_marian()
{
    system("cls");
    cout << "Welcome to Marian Hotel" << endl;
    cout << "1st Floor is for Families with Total 20 Rooms 1-20" << endl;     // Rs 1500
    cout << "2nd Floor is for Business Persons with 30 Rooms 21-50" << endl;  // Rs 2000
    cout << "3rd Floor is for the Couples with total 10 Rooms 51-60" << endl; // Rs 3000
    cout << "4th Floor is for the Penthouse Suite Only One Room" << endl;     // Rs 10,000
    cout << "Press 1 for Family room" << endl;
    cout << "Press 2 for Executive room" << endl;
    cout << "Press 3 for Couple's room" << endl;
    cout << "Press 4 for Penthouse" << endl;
    cout << "\nEnter your Choice:\t ";
    cin >> choice;
    if (choice == 1)
    {
        family_room();
    }
    else if (choice == 2)
    {
        executive_room();
    }
    else if (choice == 3)
    {
        couple_room();
    }
    else if (choice == 4)
    {
        PentHouse();
    }
    else
    {
        visit_marian();
    }
}

void Marian::family_room()
{
    system("cls");
    cout << "Welcome to the First Floor" << endl;
    cout << "Family Rooms cost Rs 1500 Per Night and are only 20 in total (1-20)" << endl;
    cout << "Available Family Rooms are " << Family_Total << endl;

    do
    {
        cout << "How many Rooms do you want:\t";
        cin >> number_of_rooms;
        cout << "How many Days do you want to stay:\t";
        cin >> number_of_days;

        if (number_of_rooms <= 0 || number_of_rooms > Family_Total || number_of_days <= 0)
        {
            cout << "Invalid input. Please enter a valid number of rooms and days." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    amount = number_of_days * number_of_rooms * 1500;
    system("cls");
    cout << "Your Total Amount for " << number_of_rooms << "\nRooms for " << number_of_days << " Days is: " << amount;

    for (int i = 0; i < number_of_rooms; i++)
    {
        if (First_Family == nullptr)
        {
            First_Family = new Guest();
            cout << "\nEnter Your Name: ";
            cin >> First_Family->name;
            cout << "Enter Your CNIC: ";
            cin >> First_Family->cnic;
            Family_Total--;
            Family_left++;
        }
        else
        {
            Guest *temp = First_Family;
            while (temp->Next != NULL)
            {
                temp = temp->Next;
            }
            Guest *temp2 = new Guest();
            cout << "Enter Your Name: ";
            cin >> temp2->name;
            cout << "Enter Your CNIC: ";
            cin >> temp2->cnic;
            temp->Next = temp2;
            temp2->Prev = temp;
            Family_Total--;
            Family_left++;
        }
    }

    if (Family_left == 20)
    {
        Guest *temp = First_Family;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = First_Business;
        First_Business->Prev = temp;
    }

    working();
}


void Marian::executive_room()
{
    system("cls");
    cout << "Welcome to the Second Floor" << endl;
    cout << "Executive Rooms cost Rs 2000 Per Night and are only 30 in total (21-50)" << endl;
    cout << "Available Executive Rooms are " << Business_Total << endl;

    do
    {
        cout << "How many Rooms do you want:\t";
        cin >> number_of_rooms;
        cout << "How many Days do you want to stay:\t";
        cin >> number_of_days;

        if (number_of_rooms <= 0 || number_of_rooms > Business_Total || number_of_days <= 0)
        {
            cout << "Invalid input. Please enter a valid number of rooms and days." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    amount = number_of_days * number_of_rooms * 2000;
    system("cls");
    cout << "Your Total Amount for " << number_of_rooms << "\nRooms for " << number_of_days << " Days is: " << amount;

    for (int i = 0; i < number_of_rooms; i++)
    {
        if (First_Business == nullptr)
        {
            First_Business = new Guest();
            cout << "\nEnter Your Name: ";
            cin >> First_Business->name;
            cout << "Enter Your CNIC: ";
            cin >> First_Business->cnic;
            Business_Total--;
            Business_left++;
        }
        else
        {
            Guest *temp = First_Business;
            while (temp->Next != NULL)
            {
                temp = temp->Next;
            }
            Guest *temp2 = new Guest();
            cout << "Enter Your Name: ";
            cin >> temp2->name;
            cout << "Enter Your CNIC: ";
            cin >> temp2->cnic;
            temp->Next = temp2;
            temp2->Prev = temp;
            Business_Total--;
            Business_left++;
        }
    }

    if (Business_left == 30)
    {
        Guest *temp = First_Business;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = First_Couple;
        First_Couple->Prev = temp;
    }

    working();
}

void Marian::couple_room()
{
    system("cls");
    cout << "Welcome to the Third Floor" << endl;
    cout << "Couple Rooms cost Rs 3000 Per Night and are only 10 in total (51-60)" << endl;
    cout << "Available Couple Rooms are " << Couple_Total << endl;

    do
    {
        cout << "How many Rooms do you want:\t";
        cin >> number_of_rooms;
        cout << "How many Days do you want to stay:\t";
        cin >> number_of_days;

        if (number_of_rooms <= 0 || number_of_rooms > Couple_Total || number_of_days <= 0)
        {
            cout << "Invalid input. Please enter a valid number of rooms and days." << endl;
        }
        else
        {
            break;
        }
    } while (true);

    amount = number_of_days * number_of_rooms * 3000;
    system("cls");
    cout << "Your Total Amount for " << number_of_rooms << "\nRooms for " << number_of_days << " Days is: " << amount;

    for (int i = 0; i < number_of_rooms; i++)
    {
        if (First_Couple == nullptr)
        {
            First_Couple = new Guest();
            cout << "\nEnter Your Name: ";
            cin >> First_Couple->name;
            cout << "Enter Your CNIC: ";
            cin >> First_Couple->cnic;
            Couple_Total--;
            Couple_left++;
        }
        else
        {
            Guest *temp = First_Couple;
            while (temp->Next != NULL)
            {
                temp = temp->Next;
            }
            Guest *temp2 = new Guest();
            cout << "Enter Your Name: ";
            cin >> temp2->name;
            cout << "Enter Your CNIC: ";
            cin >> temp2->cnic;
            temp->Next = temp2;
            temp2->Prev = temp;
            Couple_Total--;
            Couple_left++;
        }
    }

    if (Couple_left == 10)
    {
        Guest *temp = First_Couple;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = penthouseGuest;
        penthouseGuest->Prev = temp;
    }

    working();
}

void Marian::PentHouse()
{
    system("cls");
    if (penthouseGuest == nullptr)
    {
        system("cls");
        cout << "Welcome to PentHouse" << endl;
        cout << "For How many days do you want to rent PentHouse? " << endl;
        cin >> number_of_days;
        amount = number_of_days * 10000;
        cout << "Your Total Amount is: " << amount << endl;
        penthouseGuest = new Guest();  // Update to penthouseGuest
        cout << "Enter Your Name: ";
        cin >> penthouseGuest->name;  // Update to penthouseGuest
        cout << "Enter Your CNIC: ";
        cin >> penthouseGuest->cnic;  // Update to penthouseGuest
        working();
    }
    else
    {
        cout << "Cannot Book PentHouse as it is already occupied\n";
        system("pause");
        working();
    }
}

void Marian::display()
{
    if (First_Family == NULL && First_Business == NULL && First_Couple == NULL && penthouseGuest == NULL)
    {
        cout << "Nothing to Show!" << endl;
        system("pause");
        working();
    }

    if (Business_left == 30 && Family_left == 20 && Couple_left == 10 && penthouseGuest != NULL)
    {
        Guest *temp = First_Family;
        while (temp->Next != NULL)
        {
            cout << "Person: " << temp->name << endl;
            cout << "CNIC: " << temp->cnic << endl;
            temp = temp->Next;
        }
    }
    if (First_Family != NULL)
    {
        Guest *temp = First_Family;
        while (temp != NULL)
        {
            cout << "Person: " << temp->name << endl;
            cout << "CNIC: " << temp->cnic << endl;
            temp = temp->Next;
        }
    }
    if (First_Business != NULL)
    {
        Guest *temp = First_Business;
        while (temp != NULL)
        {
            cout << "Person: " << temp->name << endl;
            cout << "CNIC: " << temp->cnic << endl;
            temp = temp->Next;
        }
    }
    if (First_Couple != NULL)
    {
        Guest *temp = First_Couple;
        while (temp != NULL)
        {
            cout << "Person: " << temp->name << endl;
            cout << "CNIC: " << temp->cnic << endl;
            temp = temp->Next;
        }
    }
    if (penthouseGuest != NULL)
    {
        Guest * temp=penthouseGuest;
        cout << "Person: " << temp->name << endl;
        cout << "CNIC: " << temp->cnic << endl;
    }
    cout << "\n\n Do You Want to go to Main Menu?";
    cout << "Press 1 to start again program otherwise the program will terminate\n";
    cin >> choice;
    if (choice == 1)
    {
        working();
    }
    else
    {
        exit(0);
    }
}

void Marian::deleteRecord() {
    system("cls");
    int cnicToDelete;

    cout << "Enter the CNIC to delete the record: ";
    cin >> cnicToDelete;
    
    Guest* current = First_Family;
    Guest* prev = nullptr;

    // Search in Family Rooms
    while (current != nullptr) {
        if (current->cnic == cnicToDelete) {
            if (prev != nullptr) {
                prev->Next = current->Next;
            } else {
                First_Family = current->Next;
            }
            delete current;
            cout << "Record deleted successfully!\n";
            Family_left--;
            Family_Total++;
            working();
            return;
        }
        prev = current;
        current = current->Next;
    }

    // Search in Business Rooms
    current = First_Business;
    prev = nullptr;
    while (current != nullptr) {
        if (current->cnic == cnicToDelete) {
            if (prev != nullptr) {
                prev->Next = current->Next;
            } else {
                First_Business = current->Next;
            }
            delete current;
            cout << "Record deleted successfully!\n";
            Business_left--;
            Business_Total++;
            working();
            return;
        }
        prev = current;
        current = current->Next;
    }

    // Search in Couple Rooms
    current = First_Couple;
    prev = nullptr;
    while (current != nullptr) {
        if (current->cnic == cnicToDelete) {
            if (prev != nullptr) {
                prev->Next = current->Next;
            } else {
                First_Couple = current->Next;
            }
            delete current;
            cout << "Record deleted successfully!\n";
            Couple_left--;
            Couple_Total++;
            working();
            return;
        }
        prev = current;
        current = current->Next;
    }

    // Search in Penthouse
    if (penthouseGuest != nullptr && penthouseGuest->cnic == cnicToDelete) {
        delete penthouseGuest;
        penthouseGuest = nullptr;
        cout << "Record deleted successfully!\n";
        working();
        return;
    }

    cout << "Record not found!\n";
    system("pause");
    working();
}

void Marian::working()
{
    system("cls");
    cout << "Main Menu                " << endl;
    cout << "Press 1 to Book the Room(s) in Marian Hotel       " << endl;
    cout << "Press 2 to Delete the Record of the Room" << endl;
    cout << "Press 3 to Display the Record of Marian Hotel" << endl;
    cout << "Any other number to Exit" << endl;
    cout << "\nEnter your Choice :\t ";
    cin >> choice;
    if (choice == 1)
    {
        visit_marian();
    }
    else if (choice == 2)
    {
        deleteRecord();
    }
    else if (choice == 3)
    {
        display();
    }
    else
    {
        exit(0);
    }
}

int main()
{
    Marian HMS;
    HMS.working();

    return 0;
}
