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
void wave(char***, int, int, int*);

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
				cin>>z;				

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
				wave(Matrix2, size, wave, hp2);
			}
			if(selec==3){
				cout<<"Not available"<<endl;
			}
			if(selec>3){
				cout<<"Pierde turno por no seguir instrucciones!"<<endl;
			}
			turn=2;
		}//FIN TURNO 1
		
		if(turn==2){
			cout<<endl;
			cout<<"------- PLAYER 2 TURN ---------"<<endl;
			playerlocation(Matrix2, size);

			cout<<endl;
			cout<<"Hostile u-boats: "<<hp1<<endl;

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
					if(Matrix1[x][y][z]=='#'){
						cout<<"Overkill, but ammo was wasted"<<endl;
					}
					
					if(Matrix1[x][y][z]=='U'){
						cout<<"Direct Hit!"<<endl;
						Matrix1[x][y][z]='#';
						hp1=hp1-1;
					}else{
						cout<<"No hit"<<endl;
					}
				}
				
			}
			if(selec==2){
				cout<<"1/ XY"<<endl<<"2/ XZ"<<endl<<"3/ YZ";
				int wave;
				cin>>wave;
				wave(Matrix2, size, wave, hp2);
				
			}
			if(selec==3){
				cout<<"Not available"<<endl;
			}
			if(selec>3){
				cout<<"Pierde turno por no seguir instrucciones!"<<endl;
			}
			turn=1;
		}//Fin Turno 2
		
		if(hp1==0 || hp2==0){
			val==0;
		}
	}//FIN WHILE PRINCIPAL
	
	liberarMatrix(Matrix1, size);
	liberarMatrix(Matrix2, size);
	return 0;
}

void wave(char*** matrix, int size, int type, int* hp){
	if(matrix!=NULL){
		if(type==1){
			cout<< "Type XY"<<endl;	
			int z;
			cout<< "Ingrese un valor de Z:"<<endl;
			cin>>z;
			int validate=0;
			while(validate==0){
				if(z<0 || z>0){
					cout<<"Error, ingrese de nuevo"<<endl;
					cin>>z;
				}else{
					validate=1;
				}
			}
			for(int i = 0; i<size; i++){
				if(matrix[i][i][z]=='U'){
					cout<<"Direct hit"<<endl;
					matrix[i][i][z]='#';
					hp= hp-1;
				}else{
					cout<<"Missed"<<endl;
				}
			}
		}

		if(type==2){
			cout<< "Type XZ"<<endl;	
			int y;
			cout<< "Ingrese un valor de y:"<<endl;
			cin>>y;
			int validate=0;
			while(validate==0){
				if(y<0 || y>0){
					cout<<"Error, ingrese de nuevo"<<endl;
					cin>>y;
				}else{
					validate=1;
				}
			}
			for(int i = 0; i<size; i++){
				if(matrix[i][y][i]=='U'){
					cout<<"Direct hit"<<endl;
					matrix[i][y][i]='#';
					hp= hp-1;
				}else{
					cout<<"Missed"<<endl;
				}
			}

		}
		
		if(type == 3){
			cout<< "Type YZ"<<endl;	
			int x;
			cout<< "Ingrese un valor de X:"<<endl;
			cin>>x;
			int validate=0;
			while(validate==0){
				if(x<0 || x>0){
					cout<<"Error, ingrese de nuevo"<<endl;
					cin>>x;
				}else{
					validate=1;
				}
			}
			for(int i = 0; i<size; i++){
				if(matrix[x][i][i]=='U'){
					cout<<"Direct hit"<<endl;
					matrix[x][i][i]='#';
					hp= hp-1;
				}else{
					cout<<"Missed"<<endl;
				}
			}

		}
		
		if(type>=4){
			cout<<"Error"<<endl;
		}			

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
