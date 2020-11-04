#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Function Declarations:
void userRowInit(int array[9][9]);
void displayPuzzle(int array[9][9]);
void solveit(int grid[9][9]);
int allowed(int grid[9][9], int y, int x, int n);
int Dallowed(int grid[9][9], int y, int x, int n);

int puzzle[9][9] = {    {4,0,0,0,0,0,0,0,8},
                         {0,2,6,0,5,0,1,3,0},
                         {0,9,1,2,0,8,4,5,0},
                         {0,0,2,4,0,9,5,0,0},
                         {0,1,0,0,2,0,0,8,0},
                         {0,0,3,5,0,7,6,0,0},
                         {0,3,9,7,0,1,8,6,0},
                         {0,4,8,0,3,0,9,7,0},
                         {7,0,0,0,0,0,0,0,1}};


int main(void){

     //userRowInit(puzzle);   //input puzzle starting point
     cout << endl << "This is your puzzle input:" << endl;
     displayPuzzle(puzzle);//printout of the puzzle input
     solveit(puzzle);
     }


void displayPuzzle(int array [9][9]){
    
    int i,j;

    for (i = 0; i< 9; i++){
         cout << endl << " | ";
          for (j = 0; j < 9; j++){       
                    if (array[i][j] == 0){
                         cout << "  | ";
                    }else{
                         cout << array[i][j] << " | ";
                    }
          }
    }
}
void userRowInit(int array[9][9]){
     
     int i,j,verify;

     cout << "\nEnter numbers each followed by the enter key from left to right" << endl; 
     cout << "Where there are no numbers, enter a \'0\' followed by the enter key" << endl; 
     for ( i = 0; i < 9; i++){
          cout << "\nRow " << i+1 << ": " << endl;
          for (j = 0; j < 9; j++){
               cin >> array[i][j];
          } 

          cout << "Please review row " << i+1 << ":" << endl << " | ";
          for (j = 0; j < 9; j++){
               if (array[i][j] == 0){
                    cout << "  | ";
               }else{
                    cout << array[i][j] << " | ";
               }
          }  

          cout << endl << "If row is entered in correctly, please press '1' then Enter'" << endl;
          cout << "Else, press any other key followed by Enter" << endl;
          cin >> verify;
          if (verify!= 1) i--;

     }

}
void solveit(int grid[9][9]){
     int n, i, j;
     for (i=0; i<9; i++){
          for (j=0; j<9; j++){
               if (grid[i][j]==0){
                    for (n=1; n<10; n++){
                         if (allowed(grid,i,j,n) == 1 && Dallowed(grid,i,j,n) == 1){
                              grid[i][j] = n;
                              solveit(grid);
                              grid[i][j] = 0;
                         }
                    }return;
               }
          }
     }
     cout << endl << "This is the solved puzzle:" << endl;
     displayPuzzle(puzzle);
} 
int allowed (int grid[9][9], int y, int x, int n){
     int i, j;
     //check if n is an allowable input for the given cell

     //check column:
     for (i = 0; i < 9; i++){
          if (grid[i][x]==n) return 0;
     }
     //check row:
     for (j = 0; j < 9; j++){
          if (grid[y][j]==n) return 0;
     }
     //check 3x3 squares:
     if (y < 3){//top-row
          i = 0;
          if (x < 3){ //top-left
               j = 0;
               while (i < 3){
                    while (j < 3){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }else if (x < 6){ //top-middle
               j = 3;
               while (i < 3){
                    while (j < 6){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }else{
               j = 6;
               while (i < 3){ // top-right
                    while (j < 9){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }
     } 
     else if (y < 6){ //middle row
          i = 3;
          if (x < 3){ //mid-left
               j = 0;
               while (i < 6){
                    while (j < 3){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }else if (x < 6){ //mid-middle
               j = 3;
               while (i < 6){
                    while (j < 6){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }else{
               j = 6;
               while (i < 6){ // mid-right
                    while (j < 9){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }
     } 
     else if (y < 9){// bottom row
          i = 6;
          if (x < 3){ //bottom-left
               j = 0;
               while (i < 9){
                    while (j < 3){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }else if (x < 6){ //bottom-middle
               j = 3;
               while (i < 9){
                    while (j < 6){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }else{
               j = 6;
               while (i < 9){ // bottom-right
                    while (j < 9){
                         if (grid[i++][j++]==n) return 0;
                    }
               }
          }
     }




     return 1; //if no conflict occurs return 1 for allowed
}
int Dallowed(int grid[9][9], int y, int x, int n){
     int i=0, j;
     if (x==y){
          while (i < 9){
               if (grid[i][i++] == n) return 0; 
          }
     }
     else if (x+y==8){
          j = 8;
          while (i < 9){
               if (grid[i++][j--] == n) return 0;
          }
     }
     return 1;
}
