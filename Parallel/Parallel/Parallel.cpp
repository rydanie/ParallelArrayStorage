// Arrays to find Item Price
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;
//Function prototype
void searchArray();  //Function To search array

int main()
{
	int choice = 0;
	do
	{
		system("cls");
		cout << "\n Parallel Array Search\n\n";
		cout << "1. Find the Price\n";
		cout << "2. Quit Program\n\n";
		cout << "Enter your choice: ";

		//Input validation
		while (!(cin >> choice) || (choice < 1 || choice > 2))
		{
			cin.clear(); //Clear the buffer
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nChoose an option on the list: 1 or 2: \n" << endl;
		}

		if (choice == 1) {
			searchArray();
		}

	} while (choice != 2);

	//End Program
	cout << "\n\nEnter to END ";
	cin.get(); cin.get();
	return 0;
}
//THE SEARCH ARRAAY FUNCTION
void searchArray()
{
	// declare parallel arrays
	const int SIZE = 5;
	string strIds[SIZE] = { "A45G", "J63Y", "M93K", "C20P", "F77T" };
	string strDes[SIZE] = { "Bolt", "Nut", "Screw", "Washer", "Clamp" };
	double dblPrices[SIZE] = { 8.99, 12.99, 5.99, 13.5, 7.25 };

	// declare variables
	string strSearchId = "", description = "";
	int intSub = 0;
	double dblItemPrice = 0.0;
	char discount = 'N';
	bool found = false;

	system("CLS");
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Enter Input (search ID and discount)
	cout << "Enter Product ID ";
	getline(cin, strSearchId);

	// search the strIds array until the end of the array or the ID is found
	while ((intSub < SIZE) && (found == false))
	{
		if (strIds[intSub] == strSearchId)
		{
			found = true;
			strSearchId = strIds[intSub];
			description = strDes[intSub];

			cout << "Was there a discount? (y/n)" << endl;
			cin >> discount;

			if (toupper(discount) == 'Y')
			{
				cout << setprecision(2) << fixed;
				dblItemPrice = (dblPrices[intSub] * .9);
			}
			else
			{
				dblItemPrice = dblPrices[intSub];
			}
		}

		intSub++;
	}

	//if item found display price or display not found message
	if (found == true) {

		cout << "Product ID: " << strSearchId << endl;
		cout << "Product description: " << description << endl;
		cout << setprecision(2) << fixed;
		cout << "Product Price: $" << dblItemPrice << endl;

		cin.get();

	}
	else
	{
		cout << "No product was found with this ID" << endl;
	}
	cout << "\nEnter to Continue...";
	cin.get();

}



