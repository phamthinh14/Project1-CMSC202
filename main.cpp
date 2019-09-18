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

void askingDirection();

bool validateDirection(int directionCode, int directionInMatrix);

bool drawingField(int farmerStartRow, int farmerStartCol, int rowRabbit, int columnRabbit);

int main() {

    int farmerStartRow;
    int farmerStartCol;
    int trackFarmerRow;
    int trackFarmerCol;
    int rowRabbit;
    int columnRabbit;
    int trackRabbitRow;
    int trackRabbitCol;
    int directionOption;
    bool isValidDirection;
    bool isRabbitCaught = false;
    srand(time(NULL));

    cout << "Welcome to the Chase The Rabbit" << endl;
    cout << "Where would you like to start the farmer?" << endl;
    cout << "Enter the row (0-9)" << endl;
    cin >> farmerStartRow;
    while (farmerStartRow < 0 || farmerStartRow > 9) {
        cout << "You can only enter from 0 to 9. Please enter again" << endl;
        cin >> farmerStartRow;
    }
    cout << "Enter the column (0-9)" << endl;
    cin >> farmerStartCol;
    while (farmerStartCol < 0 || farmerStartCol > 9) {
        cout << "You can only enter from 0 to 9. Please enter again" << endl;
        cin >> farmerStartCol;
    }
//        rowRabbit = 2;
//        columnRabbit = 2;
    rowRabbit = rabbitRowStarter();
    columnRabbit = rabbitColStarter();
    isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, rowRabbit, columnRabbit);
//    trackFarmerRow = farmerStartRow;
//    trackFarmerCol = farmerStartCol;
    do {
        rowRabbit = rabbitRowStarter();
        columnRabbit = rabbitColStarter();
        trackRabbitRow = rowRabbit;
        trackRabbitCol = columnRabbit;
        askingDirection();
        cin >> directionOption;
        switch (directionOption) {
            case 1:
                if (farmerStartRow == 0) {
                    cout << "Invalid direction. You still stay at where you are" << endl;
                }
                if (farmerStartRow > 0) {
                    farmerStartRow = farmerStartRow - 1;
                    isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                if (farmerStartRow == 9) {
                    cout << "Invalid direction. You still stay at where you are" << endl;
                }
                if (farmerStartRow < 9) {
                    farmerStartRow = farmerStartRow + 1;
                    isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                }
                break;
            default:
                cout << "Please enter again" << endl;
        }
    } while (!isRabbitCaught);

    return 0;
}


void askingDirection() {
    cout << "Which direction do you want to go?" << endl;
    cout << "Press 1 to go to North" << endl;
    cout << "Press 2 to go to West" << endl;
    cout << "Press 3 to go to East" << endl;
    cout << "Press 4 to go to South" << endl;
}

bool drawingField(int farmerStartRow, int farmerStartCol, int rowRabbit, int columnRabbit) {
    const int ROWS = 10;
    const int COLS = 10;
    int verLineTracking = 0;
    bool isRabbitCaught = false;
    char trackingMatrix[ROWS][COLS];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == farmerStartRow && j == farmerStartCol) {
                trackingMatrix[i][j] = 'F';
            }
            if (i == rowRabbit && j == columnRabbit) {
                trackingMatrix[i][j] = 'R';
            }
            if (verLineTracking < 10 && !(i == farmerStartRow && j == farmerStartCol) &&
                !(i == rowRabbit && j == columnRabbit)) {
                trackingMatrix[i][j] = ' ';
            }
        }
    }
    if (!(farmerStartRow == rowRabbit && farmerStartCol == columnRabbit)) {
        displayField(trackingMatrix, 10);
    }
    if (farmerStartRow == rowRabbit && farmerStartCol == columnRabbit) {
        cout << "You caught the Rabbit" << endl;
        isRabbitCaught = true;
    }
    return isRabbitCaught;
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << " | ";
        }
        cout << "\n" << endl;
    }
}




