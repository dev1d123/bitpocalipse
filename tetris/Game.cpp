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
		void fall(){
			posY--;
		}
};
class I_Tetro: public Tetromino{
	public:
		I_Tetro(){
			shape={
				{1, 1, 1, 1}
			};
		}
		
		void rotate() override {
			if(shape.size() == 1){
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
		O_Tetro(){
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
			std::vector<std::vector<int>> newShape(shape[0].size(), std::vector<int>(shape.size())); //invertir
			for(int i = 0; i < shape.size(); i++){
				for(int j = 0; j < shape[0].size(); j++){
					//rotate 90° algo
					newShape[j][shape.size() - 1 - i] =  shape[i][j];
				}
			}
			shape = newShape;
		}
};

class S_Tetro: public Tetromino{
	public:
		S_Tetro(){
			shape={
				{0, 1, 1},
				{1, 1, 0}
			};
		}
		
		void rotate() override {
			std::vector<std::vector<int>> newShape(shape[0].size(), std::vector<int>(shape.size())); //invertir
			for(int i = 0; i < shape.size(); i++){
				for(int j = 0; j < shape[0].size(); j++){
					newShape[j][shape.size() - 1 - i] =  shape[i][j];
				}
			}
			shape = newShape;
		}
};
class Z_Tetro: public Tetromino{
	public:
		Z_Tetro(){
			shape={
				{1, 1, 0},
				{0, 1, 1}
			};
		}
		
		void rotate() override {
			std::vector<std::vector<int>> newShape(shape[0].size(), std::vector<int>(shape.size())); //invertir
			for(int i = 0; i < shape.size(); i++){
				for(int j = 0; j < shape[0].size(); j++){
					newShape[j][shape.size() - 1 - i] =  shape[i][j];
				}
			}
			shape = newShape;
		}
};
class J_Tetro: public Tetromino{
	public:
		J_Tetro(){
			shape={
				{1, 0, 0},
				{1, 1, 1}
			};
		}
		
		void rotate() override {
			std::vector<std::vector<int>> newShape(shape[0].size(), std::vector<int>(shape.size())); //invertir
			for(int i = 0; i < shape.size(); i++){
				for(int j = 0; j < shape[0].size(); j++){
					newShape[j][shape.size() - 1 - i] =  shape[i][j];
				}
			}
			shape = newShape;
		}
};
class L_Tetro: public Tetromino{
	public:
		L_Tetro(){
			shape={
				{0, 0, 1},
				{1, 1, 1}
			};
		}
		void rotate() override {
			std::vector<std::vector<int>> newShape(shape[0].size(), std::vector<int>(shape.size())); //invertir
			for(int i = 0; i < shape.size(); i++){
				for(int j = 0; j < shape[0].size(); j++){
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
		
		Tetromino* actualPiece;
	
	public:
		Board(){
				
			for(int i = 0; i < HEIGHT; i++){
				for(int j = 0; j < WIDTH; j++){
					arr[i][j] = '.';
				}
			}
			
		}
	    char getCell(int row, int col) const {
	        return arr[row][col];
	    }
	
	    void setCell(int row, int col, char value) {
	        arr[row][col] = value;
	    }
	    
	    
		bool state(){
			return true;
		}
		void printShape(const Tetromino& tetro) {
		    std::vector<std::vector<int>> sh = tetro.getShape();
		    for(int i = 0; i < sh.size(); i++) {
		        for(int j = 0; j < sh[0].size(); j++) {
		            if(sh[i][j] == 1) std::cout << '#';
		            else std::cout << ' ';
		        }
		        std::cout << std::endl;
		    }
		    std::cout << std::endl;
		    std::cout << "Creado " << sh.size() << std::endl;
		}
		
		void newPiece() {
		    int pieza = (std::rand() % 7);
		    Tetromino* tetromino = nullptr;
		
		    switch (pieza) {
		        case 0: 
		            std::cout << "I" << std::endl;
		            tetromino = new I_Tetro();
		            break;
		        case 1: 
		            std::cout << "O" << std::endl;
		            tetromino = new O_Tetro();
		            break;
		        case 2: 
		            std::cout << "T" << std::endl;
		            tetromino = new T_Tetro();
		            break;
		        case 3: 
		            std::cout << "S" << std::endl;
		            tetromino = new S_Tetro();
		            break;
		        case 4: 
		            std::cout << "Z" << std::endl;
		            tetromino = new Z_Tetro();
		            break;
		        case 5: 
		            std::cout << "J" << std::endl;
		            tetromino = new J_Tetro();
		            break;
		        case 6: 
		            std::cout << "L" << std::endl;
		            tetromino = new L_Tetro();
		            break;
		    }
		    if (tetromino) {
		    	actualPiece = tetromino;
		        printShape(*tetromino);
		        delete tetromino;  // Liberar memoria
		    }
		}

	
		void message(){
		    std::cout<<"This work!!!"<<std::endl;
			std::cout<<"WIDTH: "<<WIDTH<<"\tHEIGHT: "<<HEIGHT<<std::endl;	
		}
		//Draws the board with all Pieces...ya know
	    char* getArray() {
	        return &arr[0][0];  // Retorna un puntero al primer elemento del arreglo 2D
	    }
	    
	    
	    
		void draw(){
	
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
			
        	//b.setCell(3+i, 4, 'X');
        	
			b.message();
			//si la pieza ha llegado al final.
			//Verificar si se ha completado un espacio
			//generar una nueva pieza
			
			if(b.state()){
				std::cout<<"Creando nueva pieza"<<std::endl;
				b.newPiece();
			}
			
			b.draw();	
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		
    }
};
int main(){
    Game game;
    game.run();
    return 0;
}
