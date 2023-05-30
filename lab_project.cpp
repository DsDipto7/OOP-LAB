#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

class Ticket {
protected:

    string movieName;
    double ticketPrice;
    string movieTime;
    string movieDate;
    string viewerName;
    string phoneNumber;
    int numberOfTickets;
    double totalPrice;

public:
    Ticket() {
        movieName = "";
        ticketPrice = 0.0;
        movieTime = "";
        movieDate = "";
        viewerName = "";
        phoneNumber = "";
        numberOfTickets = 0;
        totalPrice = 0.0;
    }

    void getInfo() {
        cout << "Enter movie name: ";
        cin.ignore();
        getline(cin, movieName);
        cout << "Enter ticket price: ";
        cin >> ticketPrice;
        cout << "Enter movie time: ";
        cin.ignore();
        getline(cin, movieTime);
        cout << "Enter movie date: ";
        getline(cin, movieDate);
        cout << "Enter viewer name: ";
        getline(cin, viewerName);
        cout << "Enter phone number: ";
        getline(cin, phoneNumber);
        cout << "Enter number of tickets: ";
        cin >> numberOfTickets;
        calculateTotalPrice();
    }


    void calculateTotalPrice() {
        totalPrice = ticketPrice * numberOfTickets;
    }

    virtual void printInfo() {
        cout << "Movie: " << movieName << endl;
        cout << "Ticket Price: " << ticketPrice << endl;
        cout << "Movie Time: " << movieTime << endl;
        cout << "Movie Date: " << movieDate << endl;
        cout << "Viewer Name: " << viewerName << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Number of Tickets: " << numberOfTickets << endl;
        cout << "Total Price: " << totalPrice << endl;
    }

    friend ofstream& operator<<(ofstream& ofs, const Ticket& ticket);
};

ofstream& operator<<(ofstream& ofs, const Ticket& ticket) {
    ofs << "Movie: " << ticket.movieName << endl;
    ofs << "Ticket Price: " << ticket.ticketPrice << endl;
    ofs << "Movie Time: " << ticket.movieTime << endl;
    ofs << "Movie Date: " << ticket.movieDate << endl;
    ofs << "Viewer Name: " << ticket.viewerName << endl;
    ofs << "Phone Number: " << ticket.phoneNumber << endl;
    ofs << "Number of Tickets: " << ticket.numberOfTickets << endl;
    ofs << "Total Price: " << ticket.totalPrice << endl;
    ofs << "--------------------------------" << endl;
    return ofs;
}


class PremiumTicket : public Ticket {
public:
    void getInfo() {
        Ticket::getInfo();
        
    }

    void printInfo() {
        Ticket::printInfo();
        
    }
};

class TicketManager {
private:
    vector<Ticket*> tickets;

public:
    void buyTicket() {
        int ticketType;
        cout << "Select ticket type: " << endl;
        cout << "1. Regular Ticket" << endl;
        cout << "2. Premium Ticket" << endl;
        cout << "Enter your choice: ";
        cin >> ticketType;

        Ticket* ticket = nullptr;

        if (ticketType == 1) {
            ticket = new Ticket();
            ticket->getInfo();
        } else if (ticketType == 2) {
            ticket = new PremiumTicket();
            ticket->getInfo();
        } else {
            cout << "Invalid ticket type!" << endl;
            return;
        }

        tickets.push_back(ticket);
    }

    void printTickets() {
        if (tickets.empty()) {
            cout << "No tickets available!" << endl;
            return;
        }

        for (const auto& ticket : tickets) {
            ticket->printInfo();
        }
    }

    void saveTicketsToFile() {
        if (tickets.empty()) {
            cout << "No tickets available!" << endl;
            return;
        }

        ofstream outputFile("tickets.txt", ios::app);
        if (!outputFile.is_open()) {
            cout << "Error opening the file!" << endl;
            return;
        }

        for (const auto& ticket : tickets) {
            outputFile << *ticket;
        }

        outputFile.close();
    }

    
    ~TicketManager() {
        for (auto& ticket : tickets) {
            delete ticket;
        }
    }
    
};

int main() {
    TicketManager ticketManager;
    int choice;

    do {
        cout << "Movie Ticket Management System" << endl;
        cout << "1. Buy Ticket" << endl;
        cout << "2. Print Tickets" << endl;
        cout << "3. Save Tickets to File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ticketManager.buyTicket();
                break;
            case 2:
                ticketManager.printTickets();
                break;
            case 3:
                ticketManager.saveTicketsToFile();
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
