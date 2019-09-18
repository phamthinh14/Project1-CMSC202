// Project1-CMSC202-UMBC.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;
//Make a two dimensional array of char [13][11]?
//Ha`ng ko co F or R thi la` 11
//Ha`ng co F or R thi la` 12
//Ha`ng co F and R thi la` 13
//ctrl k + ctrl c to comment
//Must have a two dimensional array to track the farmers and rabbit
		/*	North
West					East
			South */
void displayField(char[][10], int);
int rabbitRowStarter();
int rabbitColStarter();

int main()
{
	const int ROWS = 10;
	const int COLS = 10;
	int verLineTracking = 0;
	int farmerStartRow;
	int farmerStartCol;
	int rowRabbit;
	int columnRabbit;
	bool isRabbitCaught = false;
	char trackingMatrix[ROWS][COLS];
	srand(time(NULL));

	do
	{
		cout << "Welcome to the Chase The Rabbit" << endl;
		cout << "Where would you like to start the farmer?" << endl;
		cout << "Enter the row (0-9)" << endl;
		cin >> farmerStartRow;
		cout << "Enter the column (0-9)" << endl;
		cin >> farmerStartCol;

		rowRabbit = rabbitRowStarter();
		columnRabbit = rabbitColStarter();

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (i == farmerStartRow && j == farmerStartCol)
				{
					trackingMatrix[i][j] = 'F';
				}
				if (i == rowRabbit && j == columnRabbit)
				{
					trackingMatrix[i][j] = 'R';
				}
				if (verLineTracking < 10 && !(i == farmerStartRow && j == farmerStartCol) && !(i == rowRabbit && j == columnRabbit)) {
					trackingMatrix[i][j] = ' ';
				}
			}


		}
		if (!(farmerStartRow == rowRabbit && farmerStartCol == columnRabbit))
		{
			displayField(trackingMatrix, 10);
		}
		if (farmerStartRow == rowRabbit && farmerStartCol == columnRabbit)
		{
			cout << "You caught the Rabbit" << endl;
			isRabbitCaught = true;
		}
	} while (!isRabbitCaught);

	return 0;
}

int rabbitRowStarter() {
	int row;
	row = rand() % 9;
	return row;
}

int rabbitColStarter() {
	int column;
	column = rand() % 9;
	return column;
}

void displayField(char matrix[][10], int rows) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << matrix[i][j] << " | ";

		}
		cout << "\n" << endl;
	}
}




