// // ex 2
// #include <iostream>
// #include <vector>

// class ParkingLot
// {
// private:
//     std::vector<bool> parkingSpaces;
//     int totalSpaces;

//     int findFirstAvailableSpot()
//     {
//         for (int i = 0; i < totalSpaces; i++)
//         {
//             if (!parkingSpaces[i])
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }

//     int findFirstOccupiedSpot()
//     {
//         for (int i = 0; i < totalSpaces; i++)
//         {
//             if (parkingSpaces[i])
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }

//     void displayParkingStatus()
//     {
//         std::cout << "Parking lot status:\n";
//         for (int i = 0; i < totalSpaces; i++)
//         {
//             std::cout << "Spot " << (i + 1) << ": "
//                       << (parkingSpaces[i] ? "Occupied" : "Available") << "\n";
//         }
//     }

// public:
//     ParkingLot(int spaces) : totalSpaces(spaces)
//     {
//         parkingSpaces.resize(spaces, false);
//     }

//     void handleCommand(const std::string &command)
//     {
//         if (command == "P")
//         {
//             int availableSpot = findFirstAvailableSpot();
//             if (availableSpot != -1)
//             {
//                 parkingSpaces[availableSpot] = true;
//                 std::cout << "Car parked at spot " << availableSpot + 1 << "\n";
//             }
//             else
//             {
//                 std::cout << "No available parking spots.\n";
//             }
//         }
//         else if (command == "L")
//         {
//             int occupiedSpot = findFirstOccupiedSpot();
//             if (occupiedSpot != -1)
//             {
//                 parkingSpaces[occupiedSpot] = false;
//                 std::cout << "Car left from spot " << occupiedSpot + 1 << "\n";
//             }
//             else
//             {
//                 std::cout << "No cars to leave. Parking lot is empty.\n";
//             }
//         }
//         else if (command == "S")
//         {
//             displayParkingStatus();
//         }
//         else
//         {
//             std::cout << "Commands: P - Park a car, L - Leave a spot, S - Show parking status, Q - Quit\n";
//         }
//     }
// };

// int main()
// {
//     int spaces;
//     std::cout << "Enter the number of parking spaces: ";
//     std::cin >> spaces;

//     ParkingLot parkingLot(spaces);
//     std::string command;

//     while (true)
//     {
//         std::cout << "(P - Park, L - Leave, S - Status, Q - Quit): ";
//         std::cin >> command;

//         if (command == "Q" || command == "q")
//         {
//             break;
//         }

//         parkingLot.handleCommand(command);
//     }

//     return 0;
// }

// // ex1

#include <iostream>

using namespace std;

enum Stare
{
    q0, // Starea inițială
    q1, // Selectarea cafelei
    q2, // Selectarea ceaiului
    q3, // Selectarea cappuccino-ului
    q4  // Selectarea ciocolatei calde
};

Stare SimulareAutomat(char intrare, Stare stareCurenta)
{
    switch (stareCurenta)
    {
    case q0:
        switch (intrare)
        {
        case 'C':
            return q1;
        case 'T':
            return q2;
        case 'A':
            return q3;
        case 'H':
            return q4;
        default:
            return q0;
        }
    case q1:
    case q2:
    case q3:
    case q4:
        return (intrare == 'O') ? q0 : stareCurenta;
    default:
        return q0;
    }
}

int main()
{
    Stare stareCurenta = q0;

    cout << "Selectati o bautura: (C - Cafea, T - Ceai, A - Cappuccino, H - Ciocolata calda)" << endl;
    cout << "Apasati O pentru a confirma." << endl;

    char intrare;
    do
    {
        cout << "Intrare: ";
        cin >> intrare;

        stareCurenta = SimulareAutomat(intrare, stareCurenta);

        cout << "Stare curenta: " << stareCurenta << endl;
    } while (stareCurenta != q0);

    return 0;
}