#include <iostream>
#include <vector>
class Tetromino {
	protected:
		std::vector<std::vector<int>> shape;
		//Corner position
		int posX, posY;
	public:
		Tetromino() : posX(0), posY(0) {}
		virtual void rotate() = 0;
		std::vector<std::vector<int>> getShape() const { return shape; }
		int getPosX() const { return posX; }
		int getPosY() const { return posY; }
		void setPosition(int x, int y){
			posX = x;
			posY = y;
		}

};
class Board{
    private:
		static const int WIDTH = 10;
		static const int HEIGHT = 20;
		char arr[HEIGHT][WIDTH];
	public:
	void message(){
	    std::cout<<"This work!!!"<<std::endl;
		std::cout<<"WIDTH: "<<WIDTH<<"\tHEIGHT: "<<HEIGHT<<std::endl;	
	}
	//Draws the board with all Pieces...ya know
	
	void draw(){
		for(int i = 0; i < HEIGHT; i++){
			for(int j = 0; j < WIDTH; j++){
				arr[i][j] = '.';
			}
		}
		arr[4][5] = '*';
		arr[4][6] = '*';
		arr[4][7] = '*';
		arr[4][8] = '*';
		

		for(int i = 0; i < HEIGHT; i++){
			for(int j = 0; j < WIDTH; j++){
				std::cout<<arr[i][j]<<" ";
			}
			std::cout<<'\n';
		}
	}

};


class Game {
private:
    Board b;
public:
    void run(){
		b.message();
		b.draw();
    }
};
int main(){
    Game game;
    game.run();
    return 0;
}
