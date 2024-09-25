#include <iostream>
#include <vector>
#include <thread>

class Tetromino {
	protected:
		std::vector<std::vector<int>> shape;
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
class I_Tetro: public Tetromino{
	public:
		I_Tetro(){
			shape={
				{1, 1, 1, 1}
			};
		}
		
		//sobrescribir el virtual rotate
		void rotate() override {
			if(shape.size() == 1){
				//si es horizontal
				shape={
					{1},
					{1},
					{1},
					{1}
				};
			}else{
				shape={
					{1, 1, 1, 1}
				};
			}
		}
};

class O_Tetro: public Tetromino{
	public:
		o_Tetro(){
			shape={
				{1, 1},
				{1, 1}
			};
		}
		
		//sobrescribir el virtual rotate
		void rotate() override {
			// :)
		}
};
class T_Tetro: public Tetromino{
	public:
		T_Tetro(){
			shape={
				{0, 1, 0},
				{1, 1, 1}
			};
		}
		
		void rotate() override {
			std::vector<std::vector<int>> newShape(shape[0].size()), std::vector<int>(shape.size()))); //invertir
			for(int i = 0; i < shape.size(); i++){
				for(int j = 0; j < shape[0].size(); j++){
					//rotate 90° algo
					newShape[j][shape.size() - 1 - i] =  shape[i][j];
				}
			}
			shape = newShape;
		}
};

class Board{
    private:
		static const int WIDTH = 10;
		static const int HEIGHT = 20;
		char arr[HEIGHT][WIDTH];
		//Pieza actual
	public:
		
	bool state(){
		return false;
	}
	void newPiece(){
		//agregar una nueva pieza al tablero!!!
	}

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
		
		/*
		arr[4][5] = '*';
		arr[4][6] = '*';
		arr[4][7] = '*';
		arr[4][8] = '*';
		*/
		//dibujar la pieza con el arreglo
		for(int i = 0; i < HEIGHT; i++){
			for(int j = 0; j < WIDTH; j++){
				std::cout<<arr[i][j]<<" ";
			}
			std::cout<<'\n';
		}
		//disminuir la altura de la pieza
	}

};


class Game {
private:
    Board b;
public:
    void run(){
		for(int i = 0; i < 10; i++){
			system("cls");
			std::cout<<"Iteracion: "<<i<<std::endl;
			b.message();
			//si la pieza ha llegado al final.
			//Verificar si se ha completado un espacio
			//generar una nueva pieza
			
			if(b.state()){
				b.newPiece();
			}
			
			b.draw();	
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		
    }
};
int main(){
    Game game;
    game.run();
    return 0;
}
