struct INE
{
	int lleno;
	char Nombre[10];
	char ApellidoPaterno[10];
	char ApellidoMaterno[10];
	char Direccion[30];
	char ClaveDeElector[17];
	char CURP[18];
	int AnioDeRegistro;
	int Estado;
	int Municipio;
	int Seccion;
	int Localidad;
	int Emision;
	int Vigencia;
};

void restauraBaseDatos();
void guardaBaseDatos();
void prueba();
void altaRegistro(int posicion);
void imprimeRegistro(int posicion);
void imprimeRegistros();
void cambiaRegistro(int posicion);
void ordenaBase();
void burbujaApellidoPaterno(int arr[], int dim);

void bajaRegistro(int posicion);
int menu();
void inicializa(void);

#define SIZE 10 

struct INE baseDatos[SIZE]; // Arreglo de 10 INE

FILE* fichero;



