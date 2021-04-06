#include "Board.hpp"
#include <iostream>
using namespace std;

namespace ariel{
	
				
		void Board::post(unsigned int row, unsigned int col, Direction d, const string &m ){
			if(m.empty()){
				return;
		}
		if(row < this -> minRow){
			this -> minRow = row;
		}
		
		if(col < this -> minCol){
			this -> minCol = col;
		}
		
		if(d == Direction :: Vertical){
			if(this -> maxCol < col){
				this -> maxCol = col;
			}
			
			if(this -> maxRow < row + m.length() - 1){
				this -> maxRow = row + m.length() - 1;
			}
			
			for(unsigned int i = 0, r = row; i < m.length(); i++, r++){
				this -> messages [r][col] = m.at(i);
			}
		}
		
		else{
			if(this -> maxRow < row){
				this -> maxRow = row;
			}
			
			if(this -> maxCol < col + m.length() -1){
				this -> maxCol = col + m.length() -1;;
			}
			
			for(unsigned int i = 0, c = col; i < m.length(); i++, c++){
				this -> messages[row] [c] = m.at(i);
			}
		}
	}	
		string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int length){
			string message;
			if(d == Direction :: Vertical){
				for(unsigned int i = 0, r = row; i < length; r++, i++){
					if(this -> messages [r][col] != 0){
						message += messages [r][col];
					}
					else{
						message += '_';
					}
				}
			}
			else{
				for(unsigned int i = 0, c = col; i < length; c++, i++){
					if(this -> messages [row] [c] != 0){
						message+=messages [row] [c] ;
					}
					else{
						message += '_';
					}
				}
											
			}
			return message;
				
		}
		
		void Board::show(){
			for(unsigned int i = this -> minRow; i <= maxRow; i++){
				for(unsigned int j = this -> minCol; j <= maxCol; j++){
					if(this -> messages [i][j] != 0){
					cout << this -> messages [i][j];
					}
					else{
						cout<< '_';
					}
				}
				cout << endl;
			}
		}
	
};