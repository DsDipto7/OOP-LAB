# OOP-LAB
#include <iostream>
#include <fstream>

using namespace std;

class Ticket {
public:
  string name;
  string event;
  string date;
  string time;
  int seatNumber;

  Ticket() {}

  Ticket(string name, string event, string date, string time, int seatNumber) {
    this->name = name;
    this->event = event;
    this->date = date;
    this->time = time;
    this->seatNumber = seatNumber;
  }

  void print() {
    cout << "Name: " << name << endl;
    cout << "Event: " << event << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Seat Number: " << seatNumber << endl;
  }

  void saveToFile(string filename) {
    ofstream file(filename);
    file << name << endl;
    file << event << endl;
    file << date << endl;
    file << time << endl;
    file << seatNumber << endl;
    file.close();
  }
};

int main() {
  cout << "Welcome to the Ticket Management System!" << endl;

  string name;
  cout << "Enter your name: ";
  cin >> name;

  string event;
  cout << "Enter the event name: ";
  cin >> event;

  string date;
  cout << "Enter the event date: ";
  cin >> date;

  string time;
  cout << "Enter the event time: ";
  cin >> time;

  int seatNumber;
  cout << "Enter the seat number: ";
  cin >> seatNumber;

  Ticket ticket(name, event, date, time, seatNumber);

  ticket.print();

  ticket.saveToFile("ticket.txt");

  cout << "Ticket saved successfully!" << endl;

  char choice;
  do {
    cout << "Would you like to add another ticket? (Y/N): ";
    cin >> choice;

    choice = toupper(choice);

    if (choice == 'Y') {
      string newName;
      cout << "Enter your name: ";
      cin >> newName;

      string newEvent;
      cout << "Enter the event name: ";
      cin >> newEvent;

      string newDate;
      cout << "Enter the event date: ";
      cin >> newDate;

      string newTime;
      cout << "Enter the event time: ";
      cin >> newTime;

      int newSeatNumber;
      cout << "Enter the seat number: ";
      cin >> newSeatNumber;

      Ticket newTicket(newName, newEvent, newDate, newTime, newSeatNumber);

      newTicket.print();

      newTicket.saveToFile("new_ticket.txt");

      cout << "New ticket saved successfully!" << endl;
    }
  } while (choice != 'N');

  return 0;
}
