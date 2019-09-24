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

bool drawingField(int farmerStartRow, int farmerStartCol, int rowRabbit, int columnRabbit);

void rabbitDirection(int farmerStartRow, int farmerStartCol, int rowRabbit, int columnRabbit);

bool stopRabbit();

int main() {

    int farmerStartRow;
    int farmerStartCol;
    int rowRabbit;
    int columnRabbit;
    int trackRabbitRow;
    int trackRabbitCol;
    int directionOption;
    char answer;
    bool randomStepForRabbit = true;
    bool isRabbitCaught = false;
    srand(time(NULL));
    do {
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

        rowRabbit = rabbitRowStarter();
        columnRabbit = rabbitColStarter();
//        rowRabbit = 2; Testing
//        columnRabbit = 2;

        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, rowRabbit, columnRabbit);
        rabbitDirection(farmerStartRow, farmerStartCol, rowRabbit, columnRabbit);

        while (!isRabbitCaught) {
            randomStepForRabbit = stopRabbit();
            if (randomStepForRabbit) {
                rowRabbit = rabbitRowStarter();
                columnRabbit = rabbitColStarter();
            }
            trackRabbitRow = rowRabbit;
            trackRabbitCol = columnRabbit;
            if (rowRabbit < 9 && rowRabbit > 0) {
                trackRabbitRow--;
            }
            if (columnRabbit > 0 && columnRabbit < 9) {
                trackRabbitRow++;
            }
            askingDirection();
            cin >> directionOption;
            switch (directionOption) {
                case 1:
                    if (farmerStartRow == 0) {
                        cout << "Invalid direction. You still stay at where you are" << endl;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    if (farmerStartRow > 0) {
                        farmerStartRow = farmerStartRow - 1;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    break;
                case 2:
                    if (farmerStartCol == 0) {
                        cout << "Invalid direction. You still stay at where you are" << endl;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    if (farmerStartCol > 0) {
                        farmerStartCol = farmerStartCol - 1;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    break;
                case 3:
                    if (farmerStartCol == 9) {
                        cout << "Invalid direction. You still stay at where you are" << endl;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    if (farmerStartCol < 9) {
                        farmerStartCol = farmerStartCol + 1;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    break;
                case 4:
                    if (farmerStartRow == 9) {
                        cout << "Invalid direction. You still stay at where you are" << endl;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    if (farmerStartRow < 9) {
                        farmerStartRow = farmerStartRow + 1;
                        isRabbitCaught = drawingField(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                        rabbitDirection(farmerStartRow, farmerStartCol, trackRabbitRow, trackRabbitCol);
                    }
                    break;
                default:
                    cout << "Invalid Option. Please enter again" << endl;
            }
        }

        cout << "Do you want to play again? Press any key to play again. Press Q to quit" << endl;
        cin >> answer;
    } while (!(answer == 'Q' || answer == 'q'));
    return 0;
}

bool stopRabbit() {
    int tempNum;
    bool randomBool[10] = {true, false, false, true, false, true, true, false, true, true};
    tempNum = rand() % 9;
    return randomBool[tempNum];
}

/*	North
West					East
    South */
void rabbitDirection(int farmerStartRow, int farmerStartCol, int rowRabbit, int columnRabbit) {
    if (farmerStartRow > rowRabbit && farmerStartCol == columnRabbit) {
        cout << "The rabbit is in the North" << endl;
    }
    if (farmerStartRow < rowRabbit && farmerStartCol == columnRabbit) {
        cout << "The rabbit is in the South" << endl;
    }
    if ((farmerStartRow == rowRabbit && farmerStartCol < columnRabbit)
        || (((farmerStartRow < rowRabbit) || (farmerStartRow > rowRabbit)) && farmerStartCol < columnRabbit)) {
        cout << "The rabbit is in the East" << endl;
    }
    if ((farmerStartRow == rowRabbit && farmerStartCol > columnRabbit)
        || (((farmerStartRow < rowRabbit) || (farmerStartRow > rowRabbit)) && farmerStartCol > columnRabbit)) {
        cout << "The rabbit is in the West" << endl;
    }
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
        cout << "\tThank you" << endl;
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




