#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class representing the Room details
class Room {
public:
    int roomID;
    string booker;
    string start;
    string end;
    int chairs;
    string purpose;
    bool bookedStatus;

    // Constructor to initialize room details
    Room(int roomID, int chairs) {
        this->roomID = roomID;
        this->chairs = chairs;
        this->bookedStatus = false;  // Initially, the room is available
    }

    // Function to book the room with extra "purpose" parameter
    void book(string booker, string start, string end, string purpose) {
        if (!bookedStatus) {
            this->booker = booker;
            this->start = start;
            this->end = end;
            this->purpose = purpose;
            this->bookedStatus = true;
            cout << "Room " << roomID << " successfully booked by " << booker << " for " << purpose << endl;
        } else {
            cout << "Room " << roomID << " is already booked!" << endl;
        }
    }

    // Function to cancel room booking
    void cancelBooking() {
        if (bookedStatus) {
            bookedStatus = false;
            cout << "Room " << roomID << " booking has been canceled." << endl;
        } else {
            cout << "Room " << roomID << " is not currently booked." << endl;
        }
    }

    // Function to display room details
    void displayRoom() {
        cout << "Room ID: " << roomID << endl;
        if (bookedStatus) {
            cout << "Booked by: " << booker << endl;
            cout << "Start Time: " << start << endl;
            cout << "End Time: " << end << endl;
            cout << "Purpose: " << purpose << endl;
            cout << "Chairs Available: " << chairs << endl;
        } else {
            cout << "Room is available for booking." << endl;
        }
    }
};

// Class representing the booking system
class BookingSystem {
private:
    vector<Room> rooms;

public:
    // Constructor to initialize rooms
    BookingSystem(int totalRooms, int chairCount) {
        for (int i = 1; i <= totalRooms; i++) {
            rooms.push_back(Room(i, chairCount));
        }
    }

    // Function to book a room
    void bookRoom(int roomID, string booker, string start, string end, string purpose) {
        if (roomID > 0 && roomID <= rooms.size()) {
            rooms[roomID - 1].book(booker, start, end, purpose);
        } else {
            cout << "Invalid room ID!" << endl;
        }
    }

    // Function to cancel a room booking
    void cancelRoom(int roomID) {
        if (roomID > 0 && roomID <= rooms.size()) {
            rooms[roomID - 1].cancelBooking();
        } else {
            cout << "Invalid room ID!" << endl;
        }
    }

    // Function to check room status
    void checkRoomStatus(int roomID) {
        if (roomID > 0 && roomID <= rooms.size()) {
            rooms[roomID - 1].displayRoom();
        } else {
            cout << "Invalid room ID!" << endl;
        }
    }

    // Function to show all room statuses
    void showAllRooms() {
        for (Room &room : rooms) {
            room.displayRoom();
            cout << "-----------------------------" << endl;
        }
    }
};

// Menu display helper
void menu() {
    cout << "\nRoom Booking System\n";
    cout << "1. Book a Room\n";
    cout << "2. Cancel Room Booking\n";
    cout << "3. Check Room Status\n";
    cout << "4. Show All Rooms\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int totalRooms, chairCount;

    // Get room setup details
    cout << "Enter the number of rooms: ";
    cin >> totalRooms;
    cout << "Enter the number of chairs per room: ";
    cin >> chairCount;

    // Create a booking system with given number of rooms and chairs
    BookingSystem system(totalRooms, chairCount);

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int roomID;
            string booker, start, end, purpose;

            cout << "Enter room ID: ";
            cin >> roomID;
            cin.ignore();  // Clear input buffer
            cout << "Enter booker name: ";
            getline(cin, booker);
            cout << "Enter start time: ";
            getline(cin, start);
            cout << "Enter end time: ";
            getline(cin, end);
            cout << "Enter purpose of booking: ";
            getline(cin, purpose);

            system.bookRoom(roomID, booker, start, end, purpose);
            break;
        }
        case 2: {
            int roomID;
            cout << "Enter room ID to cancel booking: ";
            cin >> roomID;
            system.cancelRoom(roomID);
            break;
        }
        case 3: {
            int roomID;
            cout << "Enter room ID to check status: ";
            cin >> roomID;
            system.checkRoomStatus(roomID);
            break;
        }
        case 4:
            system.showAllRooms();
            break;
        case 5:
            cout << "Exiting... Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
