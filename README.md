# Octave-Simulator

## Overview
The program uses a vector of structures to efficiently store the number of rows, columns, and the sum of matrix elements, along with the actual matrix data. The algorithm starts with a `start=1` variable to check if the Q command has been received. The program then enters a while loop to read characters from standard input and process commands accordingly.

## Features and Functionality

### 1. Loading a Matrix into Memory (L command)
* Reads an L character from input, followed by two integers m and n, representing the number of rows and columns of the matrix.  
* Checks if the structure vector has enough capacity; if not, it doubles the capacity.  
* Reads the matrix from input and appends it to the structure vector.  

### 2. Displaying Matrix Dimensions (D command)
* Reads the D character followed by an integer representing the matrix index.  
* Checks if the index is valid (greater than 0 and within range).  
* If valid, prints the matrix dimensions; otherwise, an error message is displayed.  

### 3. Printing a Matrix (P command)
* Reads the P character and an integer representing the matrix index.  
* Validates the index and prints the matrix; otherwise, an error message is displayed.  

### 4. Matrix Multiplication (M command)
* Reads the M character followed by two integer indices corresponding to the matrices to be multiplied.  
* Uses the classic three-loop nested algorithm for multiplication.  
* Calls `multiply_matrix()` to return the resulting matrix and appends it to the structure vector.  

### 5. Matrix Transposition (T command)
* Reads the T character and the matrix index.  
* Validates the index, then calls `transpose_matrix()` to perform an in-place transposition.  

### 6. Deleting a Matrix from Memory (F command)
* Reads the F character and an index to delete the corresponding matrix.  
* Calls `deallocate_matrix()` to free memory and remove the matrix.  
* Shifts subsequent matrices left by one position to maintain continuity.  
* If too many matrices are removed, the structure vector capacity is reduced by half.  

### 7. Sorting Matrices by Sum of Elements (O command)
* Calls `sum()` to compute the sum of each matrix’s elements and stores it in the structure vector.  
* Uses `sort_matrix()` to sort matrices in ascending order based on their sum (modulo 10^4 + 7).  

### 8. Resizing a Matrix (C command)
* Reads the C character and an index to resize the corresponding matrix.  
* Uses an auxiliary structure new to hold only the selected elements.  
* Calls `redim()` to perform in-place resizing of the matrix at the given index.  

### 9. Exponentiating a Matrix in Logarithmic Time (R command)
* Reads the R character, a matrix index, and the exponent.  
* If the exponent is 0, returns the identity matrix.  
* Uses logarithmic exponentiation: if the exponent is even, the matrix is squared; if odd, it is squared and multiplied by the original matrix.  
* This ensures logarithmic complexity.  

### 10. Matrix Multiplication using Strassen’s Algorithm (S command)
* Reads the S character and two indices for matrices to be multiplied.  
* Ensures sufficient space in the structure vector for the new matrix.  
* Implements a recursive Strassen multiplication algorithm using a structure vector:  
  * The matrices are split into blocks: A1, A2, A3, A4, B1, B2, B3, B4, C1, C2, C3, C4.  
  * Recursive calls compute intermediate matrices M1-M7.  
  * The final matrix is constructed by concatenating C1, C2, C3, C4.  
  * At each step, the block dimension is halved for efficiency.  

### 11. Exiting the Program and Freeing Resources (Q command)
* Reads the Q character, terminates the program, and frees all allocated memory.  
* Sets `start=0` as a safety measure.  

### 12. Handling Unrecognized Commands
* If an invalid character is read, displays the error message: `"Unrecognized command."`.  

## Implementation Details
Uses a resizable array strategy for efficient memory management.  
Ensures in-place operations for transposition, resizing, and exponentiation.  
Implements modular arithmetic to prevent overflow.  
Utilizes recursive methods for Strassen multiplication and exponentiation.  
Uses error handling for invalid indices and operations.  

## Summary
This Octave-Simulator provides an efficient matrix processing environment in C, with support for fundamental matrix operations, advanced multiplication techniques, and dynamic memory management. The program is structured for scalability, performance, and ease of use in a command-line interface.
