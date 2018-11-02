#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>

#include <ctime>

//Provisionar la matriz de chars
char*** provisionarMatrix(int);

//liberar memoria de la matriz
void liberarMatrix(char***&, int);

//Asignar U-boats
void uBoats(char***, int);

//PLAY GAME
void play(char***, int);

//U-Boat position
void playerlocation(char***, int);

//Wave 
void wave(char***, int, int);

int main (){

	int size=12;
	
	char*** Matrix1 = NULL;
	
	char*** Matrix2 = NULL;
	
	Matrix2=provisionarMatrix(size);
	Matrix1=provisionarMatrix(size);

	//Inicia el random
	srand(time(NULL));
	uBoats(Matrix1, size);
	uBoats(Matrix2, size);
	int val= 1;
	int hp1=15;
	int hp2=15;
	while(val==1){
		cout<<"ACQUIRING DATA"<<endl;
		cout<<"            BIENVENIDO AL BATTLESHIP" <<endl;
		//Inicializar Random

		//srand(time(NULL));
		//uBoats(Matrix1, size);
		//uBoats(Matrix2, size);

		int turn=1;
		if(turn==1){
			cout<<endl;
			cout<<"------- PLAYER 1 TURN --------"<<endl;
			playerlocation(Matrix1, size);
			cout<<endl;
			cout<<"Hostile u-boats: "<<hp2<<endl;

			cout<<"1/ Normal Attack"<<endl;
			cout<<"2/ Wave attack"<<endl;
			cout<<"3/ Expansive"<<endl;
			int selec;
			cin>>selec;
			if(selec==1){
				int x;
				int y;
				int z;
				cout<<"Ingrese una coordenada en x (0-12)"<<endl;
				cin>>x;
				cout<<"Ingrese una coordenada en y (0-12)"<<endl;
				cin>>y;
				cout<<"Ingrese una coordenada en z (0-12)"<<endl;

				if(x<0 || x>12 || y<0 || y>12 || z<0 || z>12){
					cout<<"Out of bounds!"<<endl;
				}else{
					if(Matrix2[x][y][z]=='#'){
						cout<<"Overkill, but ammo was wasted"<<endl;
					}
					
					if(Matrix2[x][y][z]=='U'){
						cout<<"Direct Hit!"<<endl;
						Matrix2[x][y][z]='#';
						hp2=hp2-1;
					}else{
						cout<<"No hit"<<endl;
					}
				}
				
			}
			if(selec==2){
				cout<<"1/ XY"<<endl<<"2/ XZ"<<endl<<"3/ YZ";
				int wave;
				cin>>wave;
				
			}
			if(selec==3){

			}
			if(selec>3){
				cout<<"Pierde turno por no seguir instrucciones!"<<endl;
			}
			turn=2;
		}
		
		if(turn==2){
			cout<<endl;
			cout<<"------- PLAYER 2 TURN ---------"<<endl;
			playerlocation(Matrix2, size);
		}
		
		if(hp1==0 || hp2==0){
			val==0;
		}
	}//FIN WHILE PRINCIPAL
	
	liberarMatrix(Matrix1, size);
	liberarMatrix(Matrix2, size);
	return 0;
}

void wave(char*** matrix, int size, int type){
	if(matrix!=NULL){
				

	}//Fin if
}

void playerlocation(char*** matrix, int size){
	if(matrix!=NULL){
		cout<<"RADAR: "<<endl;
		for(int i = 0; i<size; i++){
			for(int j = 0; j<size; j++){
				for(int k = 0; k<size; k++){
					if(matrix[i][j][k]=='U'){
						cout<<"("<<i<<" , " <<j << " , " << k <<")"<<endl;	
					}
				}
			}
		}
	}
}

void uBoats(char*** matrix, int size){
	if(matrix!=NULL){
		//cout<<"ADDING.."<<endl;
		for(int i=0 ; i<size; i++){
		
			for(int j=0; j<size; j++){
				for(int k=0; k<size; k++){
					matrix[i][j][k] = '.';
					//cout<<"added"<<endl;
				}//FIN FOR 3
			}//FIN FOR 2
		}//FIN FOR 1
		cout<<"SUCCESS";
		int value=15;
		while(value>0){
			int r1=rand()%12;
			int r2=rand()%12;
			int r3=rand()%12;
			
			//ASIGNACION DE UBOAT
			bool validator= true;

			while(validator){
				if(matrix[r1][r2][r3]=='.'){
					matrix[r1][r2][r3]='U';
					validator=false;
					value=value-1;
					cout<<"Data added"<<endl;
				}else{
					r1=rand()%12;
					r2=rand()%12;
					r3=rand()%12;
					validator=true;
				}
				cout<<"Data added.."<<endl;
			}//FIN WHILE DE UBICACION

		}//FIN WHILE COLOCACION
	cout<<"DATA COMPLETED!"<<endl;
	}//FIN IF
}

void liberarMatrix(char***& matrix, int size){
	if(matrix!=NULL){
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
	}//FIn if
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
