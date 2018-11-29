//Este programa hecho por
//Estefany Vanessa Cerritos Zelaya
//Carnet:CZ18006

//Librerias utlizadas
#include <iostream>
#include <cstdlib>l.
#include <math.h>
#include <fstream> 
#include <string>
#include <sstream> 
#include <conio.h>

#include <windows.h>

using namespace std;

//variable que se utilizaron en el sistema 
void menu();
void fibo(); 
void taylor();
double tay(int n, int x);
double factorial(int n);
void finalizar();
int escribir(int o, string n, string d, string r);
void leer();

int main()
{
 
  menu();
  
}
void menu(){
	
	// sirve para limpiar la pantalla 
    system("cls");

	int n;
	
	//imprime las opciones que tendra el menu
	cout << "\t\t\t----------" <<endl;
	cout<<"\t\t\t|Opciones| "<<endl;
	cout << "\t\t\t----------" <<endl; 
	cout<<"\t\t\t1.Fibonacci"<<endl; 
	cout << "\t\t\t--------------" <<endl; 
	cout<<"\t\t\t2.Serie Taylor"<<endl;
	cout << "\t\t\t--------------" <<endl;  
	cout<<"\t\t\t3.Resultado"<<endl;
	cout << "\t\t\t--------------" <<endl;  
	cout<<"\t\t\t4.Salir"<<endl;
	cout << "\t\t\t--------------" <<endl; 
	cout<<endl;
	cout<<"Elija una opcion: "; cin>>n;
	system("cls");

	// aqui se empieza para el menu 
	switch(n){

		// caso 1 para el fibonacci 
		case 1:

			fibo();

			break;
		
		//caso 2 para taylor 
		case 2:

			taylor();

				break;
		
		//caso 3 leer operaciones 
		case 3:

		leer();

				break;
		
		//caso 4 finalizar 
		case 4:

		    finalizar();
			break;

	}

}

void fibo(){
	
	string nom = "Fibonacci";
	
 	//variables del fibonacci
    int i, n, cont = 0; 
    long long int a[100];
    
    stringstream ss;   
    a[0] = 0;
    a[1] = 1;
 
    cout << "Numero de terminos de la serie "<<endl; 
    cout << "---------------------------------"<<endl;
    cin >> n; 
    cout << "\n";
    
    //ciclo for 
    for(i=1; i < n; i++){
 
        a[i+1] = a[i-1] + a[i]; 
    }
 
     for(i=0; i < n; i++){
 
        if (cont == 10){ 
 
            cout << "\n";
            cont = 0;           
        }
        cout << a[i] << " ";
        cont += 1;  
        
        
    	ss<< a[i] << " ";    
   
     }  
     
    cout << "\n";
     stringstream sq;    
  	sq<<"Terminos de la serie: "<<n;       
    string datos= sq.str();
    string res= ss.str();
    escribir(1, nom, datos, res);
    
    getch();
    menu();
}

//funcion no devuelve ningun valor 
void taylor(){
	
	//variables para la serie de taylor
	int n;
	int x;
	double res;
	string nom = "Serie de Taylor";
	cout<<"Ingrese valor de n: "<<endl;
	cout<<"-------------------"<<endl;
	 cin>> n;
	cout<<"Ingrese valor de x: "<<endl;
	cout<<"-------------------"<<endl;
	 cin>> x;
	cout<<endl;
    res = tay(n,x);
	cout<<"El valor de Taylor para n= "<<n<<" y x= "<<x<<" es igual a: "<<res<<endl;
	
	
    stringstream ss;    
  	ss<<"n= "<<n <<" y x= "<<x;       
    string datos= ss.str();
     stringstream sr;    
  	sr<<"El resultado es: "<<res;       
    string re= sr.str();
	escribir(2, nom, datos, re);
	
	getch();
	menu();
}

double tay(int n, int x){
	
	// variable que sirve para valores decimales 
	double t;
	double s;
	
	for (int i = 0; i < n; i++){
		
		t = pow(x, i) / factorial(i);
		s += t;
	}
	return s;
}

double factorial(int n){
	// variable que sirve para valores decimales 
	double fact =1;
	for(int i= 2; i<=n; i++){
		fact*=i;
	}
	return fact;
}
int escribir(int o, string n, string d, string r){
	
	fstream file("registro.txt", ios::in | ios::out | ios::app);
  
  if (!file.is_open()){
  	
  	cout<<"Error al abrir archivo";
  	
  }else{
  	
  	cout<<"Archivo abierto correctamente"<<endl;
  	
  	cout<<"Escribiendo en el archivo"<<endl;
  
  //guardando en el archivo
  //Convert TO STRING
    
    
    
    stringstream sa;
  	sa<<o;
  	string opcion= sa.str();
          
    string nombre = n;
  	string datos = d;
   
  	string resultado=r;
    	
  	file<<opcion<<" - "<<nombre<<" - "<<datos<<" - "<<resultado<<endl;
}
return 0;
}

void leer(){
	
		fstream file("registro.txt", ios::in | ios::out | ios::app);
  
  if (!file.is_open())
  {
  	
  	cout<<"Error al abrir archivo";
  	
  }
  
  else
  {
  	
  		file.seekg(0);
  	string line;
  	cout<<"-Registro-"<<endl;
  	while(file.good()){
  		
  		getline(file, line);
  		cout << line << endl;
	}
}
getch();
menu();

}
 void finalizar()
 {

	cout<<endl;
	system("pause");
	system("cls"); 

	cout<<"---------------------------------------------"<<endl;
	cout<<"*  GRACIAS POR UTILIZAR NUESTROS SERVICIOS  *"<<endl;
	cout<<"---------------------------------------------"<<endl;

}

