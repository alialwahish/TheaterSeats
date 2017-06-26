// Ali Bayati
// File: Theatre Seating.cpp 
// Project: 1
// Class: CIS 2541 - Fall 2016
// Date: Ocotober 15, 2016

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>


 
using namespace std;

void loadSeats(char[][30]);
void saveSeats(char[][30]);
void loadPrices(float[]);
void savePrices(float[]);
int menu(float);
void displaySeatingChart(char[][30], float[]);
void changePrices(float[]);
float purchaseTickets(char[][30], float[]);

int main()
{	
	int menuCh;
	const int x = 15;
	float price[x], currentSale,totalsale=0;
	currentSale = 0;
	char seats[x][30];
	cout << fixed << setprecision(2);
	loadSeats(seats);
	
	loadPrices(price);
	
	menuCh = menu(currentSale);
	
	while (menuCh!=4)
	{
		if (menuCh == 1)
		{
			displaySeatingChart(seats, price);
			system("pause");
			system("cls");
			menuCh = menu(currentSale);
			
		}
		else if (menuCh == 2)
		{
			
			currentSale = purchaseTickets(seats, price);
			totalsale += currentSale;
			menuCh = menu(totalsale);
		}

		else if (menuCh == 3)
		{
			changePrices(price);
			menuCh = menu(currentSale);
		}
		
	}
	saveSeats(seats);
	savePrices(price);
	return 0;
}


void loadSeats(char seats[][30])
// Function: void loadSeats(char seats[15][30])
// Parameters: char seats[15][30] (the array that store the seats chars)
// Returns: nothing

{
	int i, j;
	char x ;
	string fileName = "seatingChart.dat";
	ifstream infile;

	infile.open(fileName);
	if (!infile)
	{
		cout << "No Seating File Found. . .\n";
		cout << "Clearing Seating Chart . . .\n";
		for (i = 0; i < 15; i++)

			for (j = 0; j < 30; j++)
			{
				seats[i][j] = '#';
			}
		system("pause");
		system("cls");
	}

	else
	{
		cout << "File found . . .\n";
		cout << "Loading Seating Chart . . .\n";
		system("pause");
		for (i = 0; i < 15; i++)

			for (j = 0; j < 30; j++)
			{
				infile >> seats[i][j];
			}
		system("cls");
	}
}
void saveSeats(char seats[][30])
// Function: void saveSeats(char seats[15][30])
// Parameters: char seats[15][30] (the array that store the seats chars)
// Returns: nothing

{
	int i, j;
	string filename = "seatingChart.dat";
	ofstream outfile;

	outfile.open(filename);
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 30; j++)
		{
			outfile << seats[i][j]<<endl;
		}
	}
	outfile.close();


}
void loadPrices(float price[])
// Function: void loadPrices(float price[15])
// Parameters: float price[15] ( the array that store the price for each row )
// Returns: nothing

{
	int i=0;
	float x = 17.0;
	string filename = "rowPrices.dat";
	ifstream infile;
	infile.open(filename);

	if (!infile)
	{
		cout << "No Pricing File Found. . .\n";
		cout<<"Setting Default Pricing ($15 for each row) . . .\n";
		for (i = 0; i < 15; i++)
		{
			price[i] = 15;
		}
		system("pause");
		system("cls");
	}

	else
	{
		cout << "File found . . .\n";
		cout << "Loading Pricing Chart . . .\n";
		system("pause");
		system("cls");
		for (i = 0; i < 15; i++)
		{
			infile >> price[i];
		}
		
				
	}
}
void savePrices(float price[])
// Function: void savePrices(float price[15])
// Parameters: float price[15] ( the array that store the price for each row )
// Returns: nothing 

{
	int i;
	string filename = "rowPrices.dat";
	ofstream outfile;

	outfile.open(filename);

	for (i = 0; i < 15; i++)
	{
		outfile << price[i]<<endl;
	}
	outfile.close();


}
int menu(float currentSale)
// Function: int menu(float currentSale)
// Parameters: currentSale ( the float that holds the current sale for this session )
// Returns: menu choice as integer

{
	int choice=0;
	while (choice < 1 || choice>4)
	{

		cout << "\t*** Main Menu ***\n";
		cout << "*** Sales This Session($" << currentSale << ") ***" << endl << endl;
		cout << "1. Display Seating Chart\n";
		cout << "2. Purchase Tickets\n";
		cout << "3. Change Ticket Prices\n";
		cout << "4. Exit\n";
		cout << "Enter Choice :";
		cin >> choice;
		if (choice < 1 || choice>4)
		{
			cout << "*** Invalid Choice ***\n";
			system("pause");
			system("cls");
		}
	}
		

	return choice;
	
}
void displaySeatingChart(char seats[][30], float price[])
// Function: displaySeatingChart(char seats[15][30], float price[15])
// Parameters: char seats[15][30] (the array that store the seats chars)
//             float price[15] ( the array that store the price for each row )
// Returns: nothing

{
	system("cls");
	int i, j;
	char ch;
	cout << "\t\tSeats\n";
	cout << "\t123456789012345678901234567890\tPrice\n";

	for (i = 0; i < 15; i++)
	{
		cout << "Row:"<<i+1 <<"\t";
		for (j = 0; j < 30; j++)
		{
			cout << seats[i][j];
		}

		cout <<"\t$"<<price[i]<< endl;
	}
		
	
}
void changePrices(float price[])
// Function: void changePrices(float price[15])
// Parameters: float price[15] ( the array that store the price for each row )
// Returns: nothing

{
	system("cls");
	int i,t,newrow,x;
	
	char te = 'y';
	while (te != 'n')		
	{
		t = 1;
	for (i = 0; i < 15; i++)
	{
		cout << "Row" << t << ":\t$" << price[i];
		t++;
		cout << endl;
	
	}
	cout << "\n\n";

	
		cout << "Enter Row Number to Change:";
		cin >> newrow;
		cout << "Enter New Price:";
		cin >> price[newrow - 1];
			
		cout << "Do you want to change another (y/n):";
		cin >> te; 
		if (te != 'n')
		{
			while (te != 'y')
			{
					cout << " Error input can be(y/n) only! Enter (y) to change another enter(n)to exit :";
					cin >> te;
					if (te == 'n')
				break;
			}
		}
		system("cls");
		
	}
	
	system("cls");
}
float purchaseTickets(char seats[][30], float price[])
// Function: float purchaseTickets(char seats[15][30], float price[15])
// Parameters: char seats[15][30] (the array that store the seats chars)
//             float price[15] ( the array that store the price for each row )
// Returns:  totalsale ( the total sale for the current session )

{
	int row, seat, numoftek,i;
	char te = 'y';
	float totalsale=0,currsal ;
	
	while (te != 'n')
	{
		
		displaySeatingChart(seats, price);
		
		cout << "Enter Row:";
		cin >> row;
		while (row >15||row<=0)
		{
			cout << "Enter Error try again:";
			cin >> row;
		}
				cout << "Enter Seat:";
		cin >> seat;
		while (seat>30||seat<=0)
		{
			cout << "Entery Error try again:";
			cin >> seat;
		}
		seat = seat - 1;
		row =row-1;
		cout << "Enter Number of Tickets:";
		cin >> numoftek;
		
		while (seat+numoftek>30)
		{
			cout << "Entery Error try again:";
			cin >> numoftek;
		}
		if(seats[row][seat] == '*')
			{
				currsal = 0;
				cout << endl;
				cout << "Sorry one or more of those seats are already sold !\n";
			}
		else
		{
			
			currsal = numoftek*price[row];
			while (numoftek > 0)
			{
				seats[row][seat] = '*';
				numoftek--;
				seat++;
			}
			cout << endl;
			cout << seat << " @ $"<<price[row]<<" = $"  << currsal << endl;
		}
		
		
		cout << "Do you want to purchase more (y/n):";
		cin >> te;
		if (te != 'n')
		{
			while (te != 'y')
			{
				cout << " Error input can be(y/n) only!\n Enter (y) to purchase more,Enter(n)to exit :";
				cin >> te;
				if (te == 'n')
					break;
			}
		}
		
		system("cls");
		totalsale += currsal;
		
	}
	return totalsale;

	
}