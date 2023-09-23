#include<iostream>
#include<sstream>
#include<string>
using namespace std;

//Functions
void Menu();
int Code();
int CodeABC();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){

	Menu();
	Code();
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu(){
	
	cout<<"========================================="<<endl;
	cout<<"    PRINCIPIO DE INCLUSION-EXCLUSION"<<endl;
	cout<<"========================================="<<endl;
	cout<<"Integrantes: "<<endl;
	cout<<"-Josue David Ruiz Almeida		358472"<<endl;
	cout<<"-Cesar Enrique Batista Garcia		361432"<<endl;
	cout<<"-Erick Daniel Guerra Cano		348722"<<endl;
	cout<<"-Erick Alejandro Aragon Martinez	363353"<<endl<<endl;
	
	
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Code(){
//Variable Declaration
	int x=5,y=50;
	float Vector[x][y];
	int Nv_Comp[y];
	int Nc=0,Nv=0,NoC;
	char abc[]="ABC";
	int countI2=0;
	bool Repite = false;
	int SumaConjuntos = 0;
	int R1=0,R2=0;
	char SiNo;
	int countI3=0;
	int Count[y];
	int countAnB=0, countAnC=0, countBnC=0;
	
	
//// Code////
	do{
		do{
			cout<<"DIGITE NUMERO DE CONJUNTOS: ";
			cin>>Nc;
			while (cin.fail()){
        		cin.clear();
       			cin.ignore();
    		}
			if (Nc<2 || Nc>3 ){
				cout<<"ERROR. Digite Nuevamente"<<endl;
			}
		}	while(Nc<2 || Nc>3 );
	
	////Asignacion de Valores
		for(int i=0; i<Nc; i++){
			int n=1;
			do{
				cout<<"---------------------------------------------------------------------";
				cout<<"\nDigite Numero Elementos Conjunto '"<<abc[i]<<"': ";
				cin>>Nv;
				while (cin.fail()){
        				cin.clear();
       					cin.ignore();
       					cout<<"ERROR. Digite Nuevamente"<<endl;
    				}
			}	while(Nv<=0);
    			
			
			////Valores De Entrada////	
			for(int j=0; j<Nv; j++){
				cout<<"'"<<abc[i]<<n<<"': ";
				cin>>Vector[i][j];
				if (!cin){
					//Change Int to Char
					cout<<"Cambiando Unas Cositas."<<endl;
					cout<<"Espere Un Momento..."<<endl;
					cout<<"-----------------------------------------------------------------"<<endl;
					sleep(3);
					while (cin.fail()){
        				cin.clear();
       					cin.ignore();
    				}
					CodeABC();
					return 0;
				}
				n++;
			}
			cout<<endl;
			n = 1;
				
			////Verificacion De Valores////
				for(int V=0; V<Nv; V++){
					for (int j=0; j<Nv; j++){
						if(j!=V){
							if (Vector[i][j]==Vector[i][V]){
								do{
									cout<<"ERROR. No Puede Haber Elementos Repetidos. ";
									cout<<"Digite Nuevo Valor En Posicion '"<<abc[i]<<j+1<<"': ";
									cin>>Vector[i][j];
								}	while(Vector[i][j]==Vector[i][V]);
								Repite = true;
							}
						}
					}
				}
			////Repeticion////
			if (Repite == true){
				Repite = false;
				cout<<"\nValores Modificados De '"<<abc[i]<<"':"<<endl;
				for(int j=0; j<Nv; j++){
					cout<<"'"<<abc[i]<<n<<"': ";
					cout<<""<<Vector[i][j]<<endl;
					n++;
				}
			}
			Nv_Comp[i]=Nv;
		}
//Conjuntos Pares//
	if (Nc == 2){
		////Suma Conjuntos Solos////
		for(int i=0; i<Nc; i++){
			SumaConjuntos += Nv_Comp[i];
		}
		////Conteo Conjuntos Intersecciones////
		for(int M=0; M<Nv_Comp[1]; M++){
			for(int i=0; i<Nv_Comp[0]; i++){
				if (Vector[0][i] == Vector[1][M]){
					countI2++;
				}
			}
		}
		////Resultado////
		cout<<"-----------------------------------------------------------------------------"<<endl;
		R1 = SumaConjuntos - countI2;
		cout<<"Suma Conjuntos: "<<SumaConjuntos<<endl;
		cout<<"|AnB|: "<<countI2<<endl;
		cout<<"|AUB| = "<<R1<<endl;	
		cout<<"-----------------------------------------------------------------------------"<<endl;
	} 
	
//Conjuntos Impares//
	if (Nc == 3){
		////Suma Conjuntos Solos////
		for(int i=0; i<Nc; i++){
			SumaConjuntos += Nv_Comp[i];
		}
		////AUB////
		for(int M=0; M<Nv_Comp[1]; M++){
			for(int i=0; i<Nv_Comp[0]; i++){
				if (Vector[0][i] == Vector[1][M]){
					Count[i] = Vector[0][i];
					countAnB++;
				}
			}
		}
		////AnC////
		for(int M=0; M<Nv_Comp[2]; M++){
			for(int i=0; i<Nv_Comp[0]; i++){
				if (Vector[0][i] == Vector[2][M]){
					countAnC++;
				}
			}
		}
		////BnC////
		for(int M=0; M<Nv_Comp[2]; M++){
			for(int i=0; i<Nv_Comp[1]; i++){
				if (Vector[1][i] == Vector[2][M]){
					countBnC++;
				}
			}
		}
		
		////AnBnC////
		for(int L=0; L<Nv_Comp[2]; L++){
			for(int i=0; i<countAnB; i++){
				if(Count[i] == Vector[2][L]){
					countI3++;
				}
			}
		}

		////Resultado////
		cout<<"-------------------------------------------------------------------------"<<endl;
		R2 = SumaConjuntos - countAnB - countAnC - countBnC + countI3;
		cout<<"Suma Conjuntos: "<<SumaConjuntos<<endl;
		cout<<"AnB: "<<countAnB<<endl;
		cout<<"AnC: "<<countAnC<<endl;
		cout<<"BnC: "<<countBnC<<endl;
		cout<<"AnBnC: "<<countI3<<endl;
		
		cout<<"|AUBUC| = "<<R2<<endl;	
		cout<<"-------------------------------------------------------------------------"<<endl;
	}
	                    
	cout<<"\nDESEA REPETIR (s/n): ";
	cin>>SiNo;
	cout<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	
	SumaConjuntos = 0;
	countAnB = 0;
	countAnC = 0;
	countBnC = 0;
	countI3 = 0;
	}	while((SiNo == 's')	||	(SiNo == 'S'));
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int CodeABC(){
//Variable Declaration
	int x=5,y=50;
	char Vector[x][y];
	int Nv_Comp[y];
	int Nc,Nv,NoC;
	char abc[]="ABC";
	int countI2=0;
	bool Repite = false;
	int SumaConjuntos = 0;
	int R1=0,R2=0;
	char SiNo;
	int countI3=0;
	int Count[y];
	int countAnB=0, countAnC=0, countBnC=0;
	char letra;
	
	
//// Code////
	do{
		do{
			cout<<"DIGITE NUMERO DE CONJUNTOS: ";
			cin>>Nc;
			while (cin.fail()){
        		cin.clear();
       			cin.ignore();
    		}
			if (Nc<2 || Nc>3){
				cout<<"ERROR. Digite Nuevamente"<<endl;
			}
		}	while(Nc<2 || Nc>3);
	
	////Asignacion de Valores
		for(int i=0; i<Nc; i++){
			int n=1;
			cout<<"---------------------------------------------------------------------";
			cout<<"\nDigite Numero Elementos Conjunto'"<<abc[i]<<"': ";
			cin>>Nv;
			while (cin.fail()){
				cin.clear();
				cin.ignore();
				cout<<"ERROR. Digite Nuevamente"<<endl;
    		}
			
			////Valores De Entrada////	
			for(int j=0; j<Nv; j++){
				cout<<"'"<<abc[i]<<n<<"': ";
				cin>>Vector[i][j];
				if (cin.fail()){
					//Change Int to Char
					cout<<"Espere Un Momento...";
					sleep(3);
					Code();
					return 0;
				}
				letra = Vector[i][j];
				n++;
			}
			cout<<endl;
			n = 1;
				
			////Verificacion De Valores////
				for(int V=0; V<Nv; V++){
					for (int j=0; j<Nv; j++){
						if(j!=V){
							if (Vector[i][j]==Vector[i][V]){
								do{
									cout<<"ERROR. No Puede Haber Elementos Repetidos. ";
									cout<<"Digite Nuevo Valor En Posicion '"<<abc[i]<<j+1<<"': ";
									cin>>Vector[i][j];
								}	while(Vector[i][j]==Vector[i][V]);
								Repite = true;
							}
						}
					}
				}
			////Repeticion////
			if (Repite == true){
				Repite = false;
				cout<<"\nValores Modificados De '"<<abc[i]<<"':"<<endl;
				for(int j=0; j<Nv; j++){
					cout<<"'"<<abc[i]<<n<<"': ";
					cout<<""<<Vector[i][j]<<endl;
					n++;
				}
			}
			Nv_Comp[i]=Nv;
		}
//Conjuntos Pares//
	if (Nc == 2){
		////Suma Conjuntos Solos////
		for(int i=0; i<Nc; i++){
			SumaConjuntos += Nv_Comp[i];
		}
		////Conteo Conjuntos Intersecciones////
		for(int M=0; M<Nv_Comp[1]; M++){
			for(int i=0; i<Nv_Comp[0]; i++){
				if (Vector[0][i] == Vector[1][M]){
					countI2++;
				}
			}
		}
		////Resultado////
		cout<<"-----------------------------------------------------------------------------"<<endl;
		R1 = SumaConjuntos - countI2;
		cout<<"Suma Conjuntos: "<<SumaConjuntos<<endl;
		cout<<"|AnB|: "<<countI2;
		cout<<"|AUB| = "<<R1<<endl;	
		cout<<"-----------------------------------------------------------------------------"<<endl;
	} 
	
//Conjuntos Impares//
	if (Nc == 3){
		////Suma Conjuntos Solos////
		for(int i=0; i<Nc; i++){
			SumaConjuntos += Nv_Comp[i];
		}
		////AUB////
		for(int M=0; M<Nv_Comp[1]; M++){
			for(int i=0; i<Nv_Comp[0]; i++){
				if (Vector[0][i] == Vector[1][M]){
					Count[i] = Vector[0][i];
					countAnB++;
				}
			}
		}
		////AnC////
		for(int M=0; M<Nv_Comp[2]; M++){
			for(int i=0; i<Nv_Comp[0]; i++){
				if (Vector[0][i] == Vector[2][M]){
					countAnC++;
				}
			}
		}
		////BnC////
		for(int M=0; M<Nv_Comp[2]; M++){
			for(int i=0; i<Nv_Comp[1]; i++){
				if (Vector[1][i] == Vector[2][M]){
					countBnC++;
				}
			}
		}
		
		////AnBnC////
		for(int L=0; L<Nv_Comp[2]; L++){
			for(int i=0; i<countAnB; i++){
				if(Count[i] == Vector[2][L]){
					countI3++;
				}
			}
		}

		////Resultado////
		cout<<"-------------------------------------------------------------------------"<<endl;
		R2 = SumaConjuntos - countAnB - countAnC - countBnC + countI3;
		cout<<"Suma Conjuntos: "<<SumaConjuntos<<endl;
		cout<<"AnB: "<<countAnB<<endl;
		cout<<"AnC: "<<countAnC<<endl;
		cout<<"BnC: "<<countBnC<<endl;
		cout<<"AnBnC: "<<countI3<<endl;
		
		cout<<"|AUBUC| = "<<R2<<endl;	
		cout<<"-------------------------------------------------------------------------"<<endl;
	}
	                    
	cout<<"\nDESEA REPETIR (s/n): ";
	cin>>SiNo;
	cout<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	
	SumaConjuntos = 0;
	countAnB = 0;
	countAnC = 0;
	countBnC = 0;
	countI3 = 0;
	}	while((SiNo == 's')	||	(SiNo == 'S'));
	return 0;
	
	
}
