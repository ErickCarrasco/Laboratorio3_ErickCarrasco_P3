#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Provisionar la matriz de chars
char*** provisionarMatrix(int);

//liberar memoria de la matriz
void liberarMatrix(char***&, int);

//Asignar U-boats
void uBoats(char***, int);

int main (){

	int size=12;
	
	char*** Matrix1 = NULL;
	
	char*** Matrix2 = NULL;
	
	Matrix2=provisionarMatrix(size);
	Matrix1=provisionarMatrix(size);
	int val= 1;
	while(val==1){
		cout<<"ACQUIRING DATA"<<endl;
		cout<<"            BIENVENIDO AL BATTLESHIP" <<endl;
		
	}	
	liberarMatrix(Matrix1, size);
	liberarMatrix(Matrix2, size);
	return 0;
}

void uBoats(char*** matrix, int size){
	
}

void liberarMatrix(char***& matrix, int size){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
				delete[] matrix[i][j];
				matrix[i][j]=NULL;
		}
	}
	for(int i = 0; i<size; i++){
			delete[] matrix[i];
			matrix[i]=NULL;
	}
	delete[] matrix;
	matrix = NULL;
	cout<<"ELIMINATED"<<endl;
}

char*** provisionarMatrix(int size){
	char*** retVal= new char**[size];
	
	//Provisionar Parte 1
	for(int i = 0; i<size; i++){
		retVal[i]=new char*[size];
	}

	//Provisionar parte 2
	for(int i =0 ; i<size; i++){
		for(int j = 0; j<size; j++){
			retVal[i][j]=new char[size];
		}
	}
	return retVal;

}
