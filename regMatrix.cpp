// Kevin Lee
// CS 408

// Matrix data structure (n x n matrix of double values)
// including operations for addition, subtraction, and multiplication.

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int rows1, cols1, rows2, cols2, userInput;
string pressAnyKey;
double first[5][5] = { { 1.0, 2.0, 3.0, 4.0, 5.0 },
                       { 2.0, 2.0, 2.0, 2.0, 2.0 },
                       { 3.0, 1.0, 1.0, 1.0, 3.0 },
                       { 0.0, 0.0, 2.0, 3.0, -2.0 },
                       { 4.0, 4.0, -4.0, 0.0, 0.0 } };
double second[5][5] = { { 1.0, 0.0, 0.0, 0.0, 0.0 },
                      { 1.0, 2.0, 1.0, 2.0, 1.0 },
                      { 0.0, 0.0, 1.0, 0.0, 0.0 },
                      { 1.0, 1.0, 1.0, 1.0, 1.0 },
                      { 2.0, 2.0, -2.0, 2.0, 2.0 } };

// Prototype
int menu();
void matrixMenu();
void loadPredefined();
void add();
void subtract();
void multiply();
void clearConsole();
void displayM1();
void displayM2();
//------------------------------------------------------------------------------
void clearConsole() { cout << string(100, '\n'); }
//------------------------------------------------------------------------------
int main()
{
   rows1 = 5, cols1 = 5, rows2 = 5; cols2 = 5;
   matrixMenu();
   return 0;
}
//------------------------------------------------------------------------------
void matrixMenu()
{
   //clearConsole();
   userInput = menu();

   cout << "Matrix\n\n";
   switch(userInput)
   {
      case 1:  // display M1 matrix
               displayM1();
               break;
      case 2:  // display M2 Matrix
               displayM2();
               break;
      case 3:  add();
               break;
      case 4:  subtract();
               break;
      case 5:  multiply();
               break;
      default:
               matrixMenu();
               break;
   }
}
//------------------------------------------------------------------------------
void displayM1()
{
   cout << "------------------- M1 Matrix -------------------\n";
   for(int i = 0; i < rows2; i++)
   {
      for(int j = 0; j < cols2; j++)
         cout << first[i][j] << " ";
      cout << endl;
   }

   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   //cin >> pressAnyKey;
   matrixMenu();
}
//------------------------------------------------------------------------------
void displayM2()
{
   cout << "------------------- M2 Matrix -------------------\n";
   for(int i = 0; i < rows2; i++)
   {
      for(int j = 0; j < cols2; j++)
         cout << second[i][j] << " ";
      cout << endl;
   }

   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   //cin >> pressAnyKey;
   matrixMenu();
}
//------------------------------------------------------------------------------
void add()
{
   if(cols1 != cols2 || rows1 != rows2)
      cout << "Matrices are not the same size.\n\n";
   else
   {
      cout << "------------------- M3 Matrix -------------------\n";
      cout << "                   M3 = M1 + M2                  \n";
      for(int i = 0; i < rows1; i++)
      {
         for(int j = 0; j < cols1; j++)
            cout << first[i][j] + second[i][j] << " ";
         cout << "\n";
      }
   }
   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   //cin >> pressAnyKey;
   matrixMenu();
}
//------------------------------------------------------------------------------
void subtract()
{
   if(cols1 != cols2 || rows1 != rows2)
      cout << "Matrices are not the same size.\n\n";
   else
   {
      cout << "------------------- M4 Matrix -------------------\n";
      cout << "                   M4 = M1 - M2                  \n";
      for(int i = 0; i < rows1; i++)
      {
         for(int j = 0; j < cols1; j++)
            cout << first[i][j] - second[i][j] << " ";
         cout << endl;
      }
   }
   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   //cin >> pressAnyKey;
   matrixMenu();
}
//------------------------------------------------------------------------------
void multiply()
{
   if(cols1 != rows2 || rows2 != cols1)
      cout << "Matrices cannot be multiplied\n\n";
   else
   {
      int prod = 0;
      cout << "------------------- M5 Matrix -------------------\n";
      cout << "                   M5 = M1 * M2                  \n";
      for(int i = 0; i < rows1; i++)
      {
         for(int j = 0; j < cols2; j++)
         {
            for(int k = 0; k < cols1; k++)
              prod = prod + first[i][k] * second[k][j];
            cout << prod << " ";
            prod = 0;
         }
         cout << endl;
      }
   }
   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   //cin >> pressAnyKey;
   matrixMenu();
}
//------------------------------------------------------------------------------
int menu()
{
    int command;

    cout << "Available operations.\n\n";
    cout << "(1) Display M1 Matrix\n";
    cout << "(2) Display M2 Matrix\n";
    cout << "(3) Add two matrices\n";
    cout << "(4) Subtract two matrices\n";
    cout << "(5) Multiply two matrices\n";
    cin >> command;

    return command;
}
////////////////////////////////////////////////////////////////////////////////
