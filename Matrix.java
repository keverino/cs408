// Kevin Lee
// CS 408

// Matrix data structure (n x n matrix of double values)
// including operations for addition, subtraction, and multiplication.

import java.io.*;
import java.util.*;

public class Matrix
{
	private final int M;             // number of rows
	private final int N;             // number of columns
	private final double[][] data;   // MxN array
	private static Matrix M1, M2;
//----------------------------------------------------------------------------------------
	public Matrix(int M, int N) // create MxN matrix
	{
		this.M = M;
		this.N = N;
		data = new double[M][N];
	}
//----------------------------------------------------------------------------------------
 	public Matrix(double[][] data) // create matrix from 2D array
 	{
		M = data.length;
	   N = data[0].length;
	   this.data = new double[M][N];
	   for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				this.data[i][j] = data[i][j];
 	}
//----------------------------------------------------------------------------------------
 	private Matrix(Matrix A) { this(A.data); } // copy constructor
//----------------------------------------------------------------------------------------
	// Addition, return C = A + B
	public Matrix add(Matrix B)
	{
		  Matrix A = this;
		  if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal matrix dimensions.");
		  Matrix C = new Matrix(M, N);
		  for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
					 C.data[i][j] = A.data[i][j] + B.data[i][j];
		  return C;
	}
//----------------------------------------------------------------------------------------
	// Subtraction, return C = A - B
	public Matrix subtract(Matrix B)
	{
		  Matrix A = this;
		  if (B.M != A.M || B.N != A.N) throw new RuntimeException("Illegal matrix dimensions.");
		  Matrix C = new Matrix(M, N);
		  for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
					 C.data[i][j] = A.data[i][j] - B.data[i][j];
		  return C;
	}
//----------------------------------------------------------------------------------------
	// Multiplication, return C = A * B
	public Matrix multiply(Matrix B)
	{
		  Matrix A = this;
		  if (A.N != B.M) throw new RuntimeException("Illegal matrix dimensions.");
		  Matrix C = new Matrix(A.M, B.N);
		  for (int i = 0; i < C.M; i++)
				for (int j = 0; j < C.N; j++)
					 for (int k = 0; k < A.N; k++)
						  C.data[i][j] += (A.data[i][k] * B.data[k][j]);
		  return C;
	}
//----------------------------------------------------------------------------------------
	public void printMatrix()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
				System.out.printf("%9.4f ", data[i][j]);
			System.out.println();
		}
	}
//----------------------------------------------------------------------------------------
	public static void clearConsole(){ for(int i = 0; i < 50; i++) System.out.println(); }
//----------------------------------------------------------------------------------------
	public static void pressAnyKeyToContinue()
	{
		System.out.println("Press any key to return to the menu.");
		try { System.in.read(); }
		catch(Exception e) {}
	}
//----------------------------------------------------------------------------------------
	public static void menu()
	{
		clearConsole();
		System.out.println("Please select an action:\n");
		System.out.println("(1) View M1 matrix");
		System.out.println("(2) View M2 matrix");
		System.out.println("(3) Addition");
		System.out.println("(4) Subtraction");
		System.out.println("(5) Multiplication");
		System.out.println("(6) Exit");

		Scanner scanner = new Scanner(System.in);
		int userInput = scanner.nextInt();

		switch (userInput)
		{
			case 1:	// View M1 Matrix
						System.out.println("------------------- M1 Matrix -------------------");
						M1.printMatrix();
						System.out.println();
						break;
			case 2:	// View M2 Matrix
						System.out.println("------------------- M2 Matrix -------------------");
						M1.printMatrix();
						System.out.println();
						break;
			case 3:	// Addition
						System.out.println("------------------- M3 Matrix -------------------");
						System.out.println("                   M3 = M1 + M2                  ");
						Matrix M3 = M1.add(M2);
						M3.printMatrix();
						System.out.println();
						break;
			case 4:	// Subtraction
						System.out.println("------------------- M4 Matrix -------------------");
						System.out.println("                   M4 = M1 - M2                  ");
						Matrix M4 = M1.subtract(M2);
						M4.printMatrix();
						System.out.println();
						break;
			case 5:	// Multiplication
						System.out.println("------------------- M5 Matrix -------------------");
						System.out.println("                   M5 = M1 * M2                  ");
						Matrix M5 = M1.multiply(M2);
						M5.printMatrix();
						System.out.println();
						break;
			case 6:	// Exit
						System.exit(0);
			default:
						menu();
						break;
		}// end of switch

		pressAnyKeyToContinue();
		menu();
	}
//----------------------------------------------------------------------------------------
 	public static void main(String[] args)
	{
		double[][] first = { { 1.0, 2.0, 3.0, 4.0, 5.0 },
									{ 2.0, 2.0, 2.0, 2.0, 2.0 },
									{ 3.0, 1.0, 1.0, 1.0, 3.0 },
									{ 0.0, 0.0, 2.0, 3.0, -2.0 },
									{ 4.0, 4.0, -4.0, 0.0, 0.0 } };

		double[][] second = { { 1.0, 0.0, 0.0, 0.0, 0.0 },
									 { 1.0, 2.0, 1.0, 2.0, 1.0 },
									 { 0.0, 0.0, 1.0, 0.0, 0.0 },
									 { 1.0, 1.0, 1.0, 1.0, 1.0 },
									 { 2.0, 2.0, -2.0, 2.0, 2.0 } };

		M1 = new Matrix(first);
	 	M2 = new Matrix(second);
		menu();
	}
//----------------------------------------------------------------------------------------
}// end of Matrix.java
