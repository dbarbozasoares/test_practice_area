#pragma once
#include <string>
#include <string.h>
using namespace std;
static int id = 2;

void display() {
	id += 1;
	cout << id << endl;
}


class BusTourDescription {
	string name;
	string description;
	BusTour *busTourSet;
};

class BusTour {
	string date;
	double price;
	BusTourDescription description;
	OriginStation origin;
	DestinationStation destinationStation;
};

class OriginStation {
	string originStation;
	BusTour *busTourSet;
};

class DestinationStation {
	string destinationStation;
	BusTour *busTourSet;
};

class Ticket {
	BusTour tour;
	Passenger pass;
};

class Passenger {
	string name;
	Phone* phoneSet;
	Address address;
	EmailAddress* emailSet;
	PaymentTransaction* paySet;
};

class Phone {
	int phone;
	Passenger pass;
};

class Address {
	string address;
	Passenger pass;
};

class EmailAddress {
	string emailAddress;
	Passenger pass;
};

class PaymentTransaction {
	string paymentMethod;
	Passenger pass;
};

class Ticket {
	BusTour tour;
	Passenger pass;
};




class Show {
	string name;
	string description;
	Theatre theatre;
	Perfomance* perfomanceSet;
};

class Perfomance {
	string perfomanceDate;
	Show show;
	Ticket* ticketSet;
};

class Theatre {
	Show* showSet;
	PerfomanceSection* sectionSet;
};

class PerfomanceSection {
	double price;
	Theatre theatre;
	PerfomanceSeat seatSet;
};

class PerfomanceSeat {
	int row;
	int seatNumber;
	PerfomanceSection section;
	Ticket* ticketSet;
};

class Ticket {
	Perfomance perfomance;
	PerfomanceSeat seat;
	Patron patron;
};

class Patron {
	string emailAddress;
	Ticket* ticketSet;
	PurchaseTransaction* transSet;
};

class PurchaseTransaction {
	double total;
	string pdfLink;
	Patron patron;
};




