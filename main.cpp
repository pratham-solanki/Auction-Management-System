/***********
OOP PBL AUCTION
***********/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class item
{
public:
    string name_of_item, name_of_owner, desc;
};

void create(item obj1)
{
    cout << "\nEnter the Name of the Item\n";
    getline(cin, obj1.name_of_item);
    cout << "\nEnter the Name of the Owner\n";
    getline(cin, obj1.name_of_owner);
    cout << "\nEnter Description of Item in less than 50 words\n";
    getline(cin, obj1.desc);

    cout << obj1.name_of_item << "\t" << obj1.name_of_owner << "\t" << obj1.desc << endl;
}

void disp(item objd)
{
    cout << objd.name_of_item << "\t" << objd.name_of_owner << "\t" << objd.desc << endl;
}

void preauc()
{
    int i, no;
    string name[15];
NO:
    cout << "\nEnter the Number of Auctioneers(max 15)\n";
    cin >> no;

    if (no < 1 || no > 15)
    {
        cout << "\nInvalid Input\n";
        goto NO;
    }

    for (i = 1; i <= no; i++)
    {
        cout << "\nEnter Name of Auctioneer number" << i << endl;
        getline(cin, name[(i - 1)]);
        cout << "\nThe Auctioning ID of Auctioneer " << name[(i - 1)] << " is " << i << endl;
    }
}

void auction(item objs[], int n)
{
    char ch;
    int i;

    for (i = 0; i < n; i++)
    {
        cout << "\nItem on sale is:\nName:\t" << objs[i].name_of_item << "\nDesc\t" << objs[i].desc << endl;
    }
    while ((ch != 'n') || (ch != 'N'))
        ;
}

int main()
{
    int n, i;
    item obj[10];

L0:
    cout << "\nCreate a list of items to auction\nEnter total number of items(max 10)\n";
    cin >> n;

    if (n < 1 || n > 10)
    {
        cout << "\nInvalid Input\n";
        goto L0;
    }

    cin.ignore();

    for (i = 0; i < n; i++)
    {
        create(obj[i]);
    }

    while (i != 5)
    {
        cout << "\nEnter Choice\n1. To Create a list of items to auction\n2. To Insert items in the auction\n3. To Display the list of items\n4. To Start the auction\n5. To Exit\n";
        cin >> i;

        switch (i)
        {
        case 1:
        { //Create
        L:
            cout << "\nCreate a list of items to auction\nEnter total number of items(max 10)\n";
            cin >> n;

            if (n < 1 || n > 10)
            {
                cout << "\nInvalid Input\n";
                goto L;
            }

            cin.ignore();

            for (i = 0; i < n; i++)
            {
                create(obj[i]);
            }

            break;
        }

        case 2:
        { //insert
            if (n == 10)
            {
                cout << "\nList is Full\n";
                break;
            }

        L1:
            cout << "\nEnter total number of items to be inserted(max " << (10 - n) << ")\n";
            cin >> i;

            if ((i < 1) || ((i + n) > 10))
            {
                cout << "\nInvalid Input\n";
                goto L1;
            }

            cin.ignore();

            for (int j = 0; j < i; j++) //(i + n) < 11; i++)
            {
                create(obj[(i + n - 1)]);
            }

            n += i;
            break;
        }

        case 3:
        { //Display
            cout << "\nName of item\tName of Owner\tDescription\n";

            for (i = 0; i < n; i++)
            {
                disp(obj[i]);
                //cout<<obj[i].name_of_item<<"\t"<<obj[i].name_of_owner<<"\t"<<obj[i].desc<<endl;
            }

            break;
        }

        case 4:
        { //auction
            preauc();
            auction(obj, n);
            break;
        }

        case 5:
        { //exit
            cout << "\nExitting...\n";
            break;
        }
        default:
        {
            cout << "\nInvalid Input\n";
            break;
        }
        }
    }

    return 0;
}