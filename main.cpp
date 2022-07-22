#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "Guest Book\n\n";

	string first_name;
	cout << "First name:\t";
	cin >> first_name;             // get first string only

	char middle_initial;
	cout << "Middle initial:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline
	middle_initial = cin.get();    // get first char only

	string last_name;
	cout << "Last name:\t";
	cin.ignore(100, '\n');         // ignore leftover chars and newline
	getline(cin, last_name);       // get entire line

	string address;
	cout << "Address:\t";
	getline(cin, address);            // get entire line

	string city;
	cout << "City:\t\t";
	getline(cin, city);            // get entire line

	string state;
	cout << "State:\t\t";
	state = cin.get();       // get first letter
	state += cin.get();		//get second letter

	string zip;
	cout << "Postal code:\t";
	cin.ignore(100, '\n');
	getline(cin, zip);

	string country;
	cout << "Country:\t";
	getline(cin, country);         // get entire line

	int nights;
	cout << "Nights of stay:\t";
	cin >> nights;

	char tripleA;
	cout << "AAA Member? (y/n):\t";
	cin >> tripleA;
		

	double nightlyRate = 110.00;
	double taxRate, memberDiscount;
	bool membership;


	if (tripleA == 'y' || tripleA == 'Y') {
		membership = true;
	}
	else {
		membership = false;
	}

	memberDiscount = (membership ? .95 : 1.0);

	if (state == "NJ" || state == "CA" || state == "NY") {
		taxRate = 1.15;
	}
	else if (state == "OR" || state == "TX" || state == "NH") {
		taxRate = 1.00;
	}
	else {
		taxRate = 1.10;
	}
	cout<<"------------------------- ";
	cout << "\nCUSTOMER INFORMATION\n"            // display the entry
		<< first_name + ' ' + middle_initial + ". " + last_name + '\n'
		<< address + "\n"
		<< city + ", " + state + " " +zip +'\n'
		<< country + "\n";


	cout << "\nINVOICE\n"		//cost information
		<< "Nights Stayed: " << nights << '\n'
		<< "Room Rate:\t" << nightlyRate << '\n'
		<< "Tax Rate:\t" << (taxRate-1)*100 << "%\n"
		<< "AAA Discount:\t" << tripleA << '\n'
		<< "Room Total:\t" << ((nights* nightlyRate)*memberDiscount)*taxRate << endl;
	cout << "------------------------- ";

	ofstream outFile;//ofstream outFIle
	outFile.open("outfile.txt");
	outFile << "------------------------- "
		<< "\nCUSTOMER INFORMATION\n"            // display the entry
		<< first_name + ' ' + middle_initial + ". " + last_name + '\n'
		<< address + "\n"
		<< city + ", " + state + " " + zip + '\n'
		<< country + "\n"

		<< "\nINVOICE\n"		//cost information
		<< "Nights Stayed: " << nights << '\n'
		<< "Room Rate:\t" << nightlyRate << '\n'
		<< "Tax Rate:\t" << taxRate / 10 << "%\n"
		<< "AAA Discount:\t" << tripleA << '\n'
		<< "Room Total:\t" << ((nights * nightlyRate) * memberDiscount) * taxRate << '\n'

		<< "\nLEGAL DISCLAIMER\n";

	ifstream input_file;
		input_file.open("dummy.txt");
	if (input_file) {
		string line;
		while (getline(input_file, line))
			outFile << line << '\n';
		input_file.close();
	}

	 outFile << "------------------------- ";


	return 0;
}