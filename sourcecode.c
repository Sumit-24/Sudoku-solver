#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int check_row(int sudoku_grid[N][N], int row, int num){
	for (int col = 0; col < 9; col++) {
		if (sudoku_grid[row][col] == num) {
			return 1;
		}
	}
	return 0;
}

int check_col(int sudoku_grid[N][N], int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (sudoku_grid[row][col] == num) {
			return 1;
		}
	}
	return 0;
}
 
int check_box(int sudoku_grid[N][N], int startRow, int startCol, int num){
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (sudoku_grid[row + startRow][col + startCol] == num) {
				return 1;
			} 
		}
	}
	return 0;
}

int check_num(int sudoku_grid[N][N], int row, int col, int num) {
	return !check_row(sudoku_grid, row, num) 
			&& !check_col(sudoku_grid, col, num) 
			&& !check_box(sudoku_grid, row - (row % 3), col - (col %3), num);
}

int is_unassigned(int sudoku_grid[N][N], int *row, int *col) {
	for (*row = 0; *row < N; (*row)++) {
		for (*col = 0; *col < N; (*col)++) {
			if (sudoku_grid[*row][*col] == 0) {
				return 1;
			}
		}
	}
	return 0;
}

int solve(int sudoku_grid[N][N]) {
	
	int row = 0;
	int col = 0;
	
	if (!is_unassigned(sudoku_grid, &row, &col)){
		return 1;
	}
	
	for (int num = 1; num <= N; num++ ) {
		
		if (check_num(sudoku_grid, row, col, num)) {
			sudoku_grid[row][col] = num;
			
			if (solve(sudoku_grid)) {
				return 1;
			}
			
			sudoku_grid[row][col] = UNASSIGNED;
		}
	}
	
	return 0;
}

void print(int sudoku_grid[N][N]) {
    printf("\nSolution of the above SUDOKU is \n\n\n");
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			printf("%2d ", sudoku_grid[row][col]);
		}
		printf("\n");
	}
    printf("\n\n\n");

}

int main() {
	
	int sudoku_grid[N][N] = {{6,0,0, 0,0,9, 0,5,0},
							{0,0,0, 0,5,6,  0,0,3},
							{0,4,0, 8,0,0, 9,2,0},

							{0,0,0, 0,3,0, 6,0,0},
							{0,0,0, 0,9,0, 7,3,4},
							{0,0,0, 0,0,0, 2,0,9},

							{7,8,0, 0,0,0, 0,0,0},
							{3,1,9, 4,0,0, 0,0,0},
							{4,5,0, 0,0,3, 1,0,0}};
             
             printf("\nGiven Sudoku Problem Is\n\n");
             for(int i=0;i<N;i++)
             {for(int j=0;j<N;j++)
             printf(" %d ",sudoku_grid[i][j]);
             printf("\n");}
             printf("--------------------------------------\n");
           
              printf("--------------------------------------\n");
	
	if (solve(sudoku_grid)) {
		print(sudoku_grid);
	} else {
		printf("no solution");
	}
	
	return 0;
}
