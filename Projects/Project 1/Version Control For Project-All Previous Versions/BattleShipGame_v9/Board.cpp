/*  File:   Board.cpp
 * Author: Noel Perez
 * Created on October 29, 2023, 9:16 PM
 */
#include "Board.h"

Board::Board() {
    
        Grid = new char*[B_SIZE];
        for (int i = 0; i < B_SIZE; ++i) {
            Grid[i] = new char[B_SIZE];
            for (int j = 0; j < B_SIZE; ++j) {
                Grid[i][j] = '~';
            }
        }
    
//    for(int r=0; r<B_SIZE; r++){
//        
//        for(int c=0; c<B_SIZE; c++){
//            Grid[r][c] = '~';
//        }
//    }
}

Board::Board(const Ship& orig){
}

Board::~Board() {
        for (int i = 0; i < B_SIZE; ++i) {
            delete[] Grid[i];
        }
        delete[] Grid;
}

// Function 
char**::Board::getGrid() {
        return Grid;
    }

// Function 
void::Board::displayBoard(){
        cout<<"\n";
    for(int j = 0 ; j < B_SIZE ; j++){ // Column numbers
        cout<<setw(5)<<j;
    }
    // Rows with letters
    for(int i = 0; i < B_SIZE; i++){
        cout<<"\n";
        cout << static_cast<char>('A' + i) <<"|";
        for(int j = 0; j < B_SIZE; j++){
        cout<<"[ "<<Grid[i][j]<<" ]";       
        }
    }
}

// Function 
bool::Board::isValidPlacement( char **Grid, int r, int c ,char o, int size){
    
    if(o == 'H' || o == 'h'){
        
        for(int i =c; i< c +size; i++){
            if(i >= B_SIZE || Grid[r][i] =='A'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='B'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='C'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='D'){
               return false;
            }
            if(i >= B_SIZE || Grid[r][i] =='S'){
               return false;
            }
        }  
    }
    else{
        for(int j = r; j<  r+size; j++){
            
            if(j >= B_SIZE || Grid[j][c] == 'A'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'B'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'C'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'D'){
               return false;
            }
            if(j >= B_SIZE || Grid[j][c] == 'S'){
               return false;
            }
        }
    }
    return true;
}

// Bool function to check if there is a ship at coordinate
bool::Board::isShipAtCoord(int key, char row, int col) const {
        return ship.isShipAtCoord(key, row, col);
}  

