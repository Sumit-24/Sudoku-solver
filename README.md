# Sudoku-solver
SUDOKU SOLVER
*Using C language*
About the project:
This is a C program aimed to solve Sudoku puzzle.
Sudoku is a puzzle game designed for a single player, much like a crossword puzzle. The puzzle itself is nothing more than a 9X9 matrix/grid of little boxes called “cells”. They are stacked nine horizontally and nine vertically, making 81 cells total. The grid is categorized into 9 3X3 subgrids. The puzzle comes with some of the cells (usually less than half of them) already filled in, like shown below :
 
To solve the game one must fill the empty cells such that each horizontal and vertical lines are completely filled with numbers (1-9) without repetition. Further each subgrid too has numbers from 1 to 9 (without repetition).

Approach to the program
To solve the grid we will first check a cell to see if its empty or not.
If it is already assigned a number, meaning we don’t have to change it, so we will skip and come to next cell.
If the cell is empty then it we will check for numbers from 1 to 9,  if a number between 1-9 is not already in any of intersecting row or column of the cell, then it will check if the number is not in that particular subgrid .
If each condition is matched then the suitable number will be assigned to the cell and we will move to next cell.
After filling a cells we have to check if the grid is safe or not, if not then we will return false and check for other number recursively and keep checking for the suitable digit to  be filled.


Module/functions used:
#1. is_unassigned(int sudoku_grid[N][N], int *row, int *col)
This function takes the parameters sudoku grid, pointer pointing to the row and column. and checks for a particular cell that is it already assigned or not.

#2. int check_row(int sudoku_grid[N][N], int row, int num)
This function’s purpose is to check if a digit is not being repeated in a row by passing the grid, the row of a cell, and the number we want to check.

#3. int check_col(int sudoku_grid[N][N], int col, int num)
Similarly like check_row, this function checks if the number being passed is not repeated in a column.

#4. int check_box(int sudoku_grid[N][N], int startRow, int startCol, int num)
This function verifies if the number is not being repeated in a sub-grid. For this we start a loop from the starting row and column index of the grid till 3 consecutive increment in row and col index such that we get a 3X3 matrix. We check for the number in each cell of this matrix and see if it is being repeated or not.
#5. int check_num(int sudoku_grid[N][N], int row, int col, int num) 
  In this function we pass the number we want to check for assigning. Under this function we  use check_row, check_col, check_box function respectively to check the suitability of the number to be filled.

#6. int solve(int sudoku_grid[N][N])
This is the essential function for solving the sudoku. This is a recursive function. In sudoku very often more than one number seem to be suitable for filling in a cell. This function first fills a number in the cell and procedes further, if the filled number is wrong then at some point, there will be a mistake in the sudoku i.e., some numbers must be repeating. As soon as the program finds such problem it backtracks to the previously filled number and then tries it with next number. This program runs recursively. If the complete sudoku is filled without any problem then this function returns 1.


#7. void print(int sudoku_grid[N][N])
This is a simple function to print the sudoku grid.
We call this function if the solve function returns 1 meaning sudoku have been solved successfully.


 


 

