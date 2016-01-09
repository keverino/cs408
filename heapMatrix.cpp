// Kevin Lee
// CS 408

// Heap dynamic array matrix data structure (n x n matrix of double values)
// including operations for addition, subtraction, and multiplication.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class heapMatrix
{
	private:
		int size;
		double **matrix;
	public:
		heapMatrix();
		heapMatrix(int n);
		heapMatrix(string matrix);
		~heapMatrix();
		heapMatrix operator+(heapMatrix& m);
		heapMatrix operator-(heapMatrix& m);
		heapMatrix operator*(heapMatrix& m);
		void setSize(int);
		int getSize();
		void customCreateWithSize(int);
		void loadPredefined(string);
		friend int menu();
		friend void matrixMenu(heapMatrix, heapMatrix);
		void printMatrix();
		friend void clearConsole();
};
//------------------------------------------------------------------------------
void heapMatrix::setSize(int n){ size = n; }
//------------------------------------------------------------------------------
int heapMatrix::getSize(){ return size; }
//------------------------------------------------------------------------------
void heapMatrix::customCreateWithSize(int n)
{
	size = n;
	matrix = new double*[n];
	for(int i = 0; i < n; i++) *(matrix+i) = new double[n];
	
   	cout << "Enter the matrix.\n";
   	cout << "Separate the numbers with spaces.\n";
   	for(int i = 0; i < n; i++)
      	for(int j = 0; j < n; j++)
         	cin >> *(*(matrix+i)+j);
}
//------------------------------------------------------------------------------
void heapMatrix::loadPredefined(string name)
{
	size = 5;
	matrix = new double*[5];
	for(int i = 0; i < 5; i++) *(matrix+i) = new double[5];
	
	if( !name.compare("first") ) 
	{
		matrix[0][0] = 1.0; matrix[0][1] = 2.0; matrix[0][2] = 3.0; matrix[0][3] = 4.0; matrix[0][4] = 5.0;
	    matrix[1][0] = 2.0; matrix[1][1] = 2.0; matrix[1][2] = 2.0; matrix[1][3] = 2.0; matrix[1][4] = 2.0;
	    matrix[2][0] = 3.0; matrix[2][1] = 1.0; matrix[2][2] = 1.0; matrix[2][3] = 1.0; matrix[2][4] = 3.0;
	    matrix[3][0] = 0.0; matrix[3][1] = 0.0; matrix[3][2] = 2.0; matrix[3][3] = 3.0; matrix[3][4] = -2.0;
	    matrix[4][0] = 4.0; matrix[4][1] = 4.0; matrix[4][2] = -4.0; matrix[4][3] = 0.0; matrix[4][4] = 0.0;
	}
	if( !name.compare("second") ) 
	{
		matrix[0][0] = 1.0; matrix[0][1] = 0.0; matrix[0][2] = 0.0; matrix[0][3] = 0.0; matrix[0][4] = 0.0;
	    matrix[1][0] = 1.0; matrix[1][1] = 2.0; matrix[1][2] = 1.0; matrix[1][3] = 2.0; matrix[1][4] = 1.0;
	    matrix[2][0] = 0.0; matrix[2][1] = 0.0; matrix[2][2] = 1.0; matrix[2][3] = 0.0; matrix[2][4] = 0.0;
	    matrix[3][0] = 1.0; matrix[3][1] = 1.0; matrix[3][2] = 1.0; matrix[3][3] = 1.0; matrix[3][4] = 1.0;
	    matrix[4][0] = 2.0; matrix[4][1] = 2.0; matrix[4][2] = -2.0; matrix[4][3] = 2.0; matrix[4][4] = 2.0;
	}
}
//------------------------------------------------------------------------------
heapMatrix::heapMatrix() // creates an empty matrix of size 5x5
{
	matrix = new double*[5];
	for(int i = 0; i < 5; i++) *(matrix+i) = new double[5];
}
//------------------------------------------------------------------------------
heapMatrix::~heapMatrix(){ delete matrix; }
//------------------------------------------------------------------------------
heapMatrix heapMatrix::operator+(heapMatrix& m)	// + operator overload
{
	heapMatrix newMatrix;
	newMatrix.setSize(m.getSize());
	for (int i = 0; i < m.getSize(); i++)
		for (int j = 0; j < m.getSize(); j++)
			*(*(newMatrix.matrix+i)+j) = *(*(matrix+i)+j) + *(*(m.matrix+i)+j);

	return newMatrix;
}
//------------------------------------------------------------------------------
heapMatrix heapMatrix::operator-(heapMatrix& m) // - operator overload
{
	heapMatrix newMatrix;
	newMatrix.setSize(m.getSize());
	for (int i = 0; i < m.getSize(); i++)
		for (int j = 0; j < m.getSize(); j++)
			*(*(newMatrix.matrix+i)+j) = *(*(matrix+i)+j) - *(*(m.matrix+i)+j);

	return newMatrix;
}
//------------------------------------------------------------------------------
heapMatrix heapMatrix::operator*(heapMatrix& m) // * operator overload
{
	heapMatrix newMatrix;
	newMatrix.setSize(m.getSize());

	for (int i = 0; i < m.getSize(); i++)
		for (int j = 0; j < m.getSize(); j++)
		{
			*(*(newMatrix.matrix+i)+j) = 0;
			for(int k = 0; k < m.getSize(); k++)
				 	*(*(newMatrix.matrix+i)+j) += *(*(matrix+i)+k) * *(*(m.matrix+k)+j);
		}
	return newMatrix;
}
//------------------------------------------------------------------------------
void clearConsole() { cout << string(100, '\n'); }
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
//------------------------------------------------------------------------------
void matrixMenu(heapMatrix M1, heapMatrix M2)
{
   //clearConsole();
   int userInput = menu();
   heapMatrix result;
   
   string pressAnyKey;
   switch(userInput)
   {
      case 1:  // display M1 matrix
     		   cout << "------------------- M1 Matrix -------------------\n";
               M1.printMatrix();
   			   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   			   //cin >> pressAnyKey;
               break;
      case 2:  // display M2 Matrix
      		   cout << "------------------- M2 Matrix -------------------\n";
      		   M2.printMatrix();
               //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   			   //cin >> pressAnyKey;
               break;
      case 3:  //add();
      		   cout << "------------------- M3 Matrix -------------------\n";
      		   result = M1 + M2;
      		   result.printMatrix();
      		   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   			   //cin >> pressAnyKey;
               break;
      case 4:  //subtract();
      		   cout << "------------------- M4 Matrix -------------------\n";
      		   result = M1 - M2;
      		   result.printMatrix();
      		   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   			   //cin >> pressAnyKey;
               break;
      case 5:  //multiply();
      		   cout << "------------------- M5 Matrix -------------------\n";
               result = M1 * M2;
      		   result.printMatrix();
      		   //cout << "\nEnter any key then hit enter to return to the operation menu.\n";
   			   //cin >> pressAnyKey;
               break;
      default:
               matrixMenu(M1, M2);
               break;
   }
   	matrixMenu(M1, M2);
}
//------------------------------------------------------------------------------
void heapMatrix::printMatrix()
{
   for(int i = 0; i < size; i++)
   {
      for(int j = 0; j < size; j++)
         cout << *(*(matrix+i)+j) << " ";
      cout << endl;
   }
}
//------------------------------------------------------------------------------
int main()
{
   int userInput;
   heapMatrix M1, M2;

   //clearConsole();
   cout << "HEAP DYNAMIC WITH CLASSES (Version 3)\n";
   cout << "Select an action.\n";
   cout << "(1) Enter matrices (User defined)\n";
   cout << "(2) Load predefined M1 and M2 matrices\n";
   cin >> userInput;
   switch (userInput)
   {
      case 1:  // user defined input
               int size1, size2;
	
			   //clearConsole();
			   cout << "Enter the dimension of the first matrix.\n";
			   cout << "(Here, your entering the 'n' for an n x n matrix)\n";
			   cin >> size1;
			   M1.customCreateWithSize(size1);
			
			   //clearConsole();
			   cout << "Enter the dimension of the second matrix.\n";
			   cout << "(Here, your entering the 'n' for an n x n matrix)\n";
			   cin >> size2;
			   M2.customCreateWithSize(size2);
               break;
      case 2:  // load predefined matrices
               M1.loadPredefined("first");
   			   M2.loadPredefined("second");
               break;
      default:
               main();
               break;
   }
   matrixMenu(M1, M2);
   return 0;
}
////////////////////////////////////////////////////////////////////////////////
