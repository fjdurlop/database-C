/* 
UNAM Base de Datos en C
*/

#include <stdio.h>			// para usar printf()
#include <stdlib.h>			// para usar system(),
#include <string.h>

#include "basesdatos.h"



main(void)    
{
	
    inicializa();
	int posicion = 0; // Posici?n del arreglo que se cambiar?
	char salir = 'n'; // Variable para saber si el usuario ya no quiere ingresar INEs (n=No, s=S?)
	int opcion  = 0;
	
	do{
        opcion = menu();
        if(opcion==1){ //alta
            printf("\nPosicion del arreglo donde quieres guardar los datos de la credencial INE: (Del 0 al 9) ");
            scanf("%d", &posicion);
            altaRegistro(posicion);              
        }
        else if(opcion==2){ //baja
            printf("\nPosicion para dar de baja (Del 0 al 9) ");
            scanf("%d", &posicion);
            bajaRegistro(posicion); 
        }
        else if(opcion==3){ //cambio
            printf("\nPosicion para cambiar (Del 0 al 9) ");
            scanf("%d", &posicion);
            cambiaRegistro(posicion);
        }
        else if(opcion==4){ //ordena
            printf("\nOrdenando base de datos ");
            ordenaBase();
            printf("\nBase de datos ordenada ");

        }
        else if(opcion==5){ //imprime
            printf("\nPosicion para ver los datos de la credencial INE: (Del 0 al 9) ");
            scanf("%d", &posicion);
            imprimeRegistro(posicion);

        }
        else if(opcion==6){ //imprime
            printf("\nImprimiendo base de datos\n\n ");
            
            imprimeRegistros();

        }
        else if(opcion==7){ //guardar base de datos
            //printf("\nGuardando ");
            guardaBaseDatos();
            
        }
        else if(opcion==8){ //restaurar base de datos
            //printf("\nRestaurando ");
            restauraBaseDatos();
            
        }
        else if(opcion==9){ //terminar
            salir='s';
            
        }
        else {
            printf("\nOpcion invalida\n\n");
            getchar();
        }
		


	}while(salir != 's');

	system("PAUSE");
	return 0;


}
void restauraBaseDatos(){
    if ((fichero = fopen("basedatos.dat", "r")) == NULL)
    {
        printf("Error: el archivo no existe o no sepuede abrir\n");
        return;
    }


    fread(baseDatos, sizeof(struct INE) * SIZE, 1, fichero);
    //printf("%s\n", baseDatos[0].Nombre);

    fclose(fichero);

    int i = 0;
    int numRegistros = 0;
    for(i=0;i<SIZE;i++){
        if(baseDatos[i].lleno == 1){
            numRegistros++;
        }
    }

    printf("Restaurando base de datos...\n");
    printf("Se restauraron %d registros\n",numRegistros);
}

void guardaBaseDatos(){

    int i = 0;
    int numRegistros = 0;
    for(i=0;i<SIZE;i++){
        if(baseDatos[i].lleno == 1){
            numRegistros++;
        }
    }

    fichero = fopen("basedatos.dat", "wt");

    if ( (fichero = fopen("basedatos.dat", "wt")) == NULL )
    {
        printf("Error: el archivo no puede crearse\n");
        return;   
    }

    fwrite(baseDatos, sizeof(struct INE) * SIZE, 1, fichero);
    fclose(fichero);
    printf("Respaldando base de datos...\n");
    printf("Se guardaron %d registros\n",numRegistros);

    return 0;
}

void prueba(){
    int posicion = 0;
    baseDatos[posicion].lleno = 1;
    strcpy(baseDatos[posicion].Nombre , "Juan");
    strcpy(baseDatos[posicion].ApellidoPaterno , "Salgado");
    strcpy(baseDatos[posicion].ApellidoMaterno , "Mu?oz");
    strcpy(baseDatos[posicion].Direccion , "Juarez 19");
    strcpy(baseDatos[posicion].ClaveDeElector ,"SAMJ12345");
    strcpy(baseDatos[posicion].CURP , "SAMJ12345");
	
	baseDatos[posicion].AnioDeRegistro = 2018;
	baseDatos[posicion].Estado = 3;
	baseDatos[posicion].Municipio =12;
	baseDatos[posicion].Seccion = 12;
	baseDatos[posicion].Localidad = 1000;
	baseDatos[posicion].Emision = 2018;
	baseDatos[posicion].Vigencia = 2023;

    posicion = 1;
    baseDatos[posicion].lleno = 1;

    strcpy(baseDatos[posicion].Nombre , "Aleman");
    strcpy(baseDatos[posicion].ApellidoPaterno , "Becerra");
    strcpy(baseDatos[posicion].ApellidoMaterno , "Dela");
    strcpy(baseDatos[posicion].Direccion , "Alvarez 21");
    strcpy(baseDatos[posicion].ClaveDeElector ,"FEDP12345");
    strcpy(baseDatos[posicion].CURP , "FEDP12345");
	baseDatos[posicion].AnioDeRegistro = 2017;
	baseDatos[posicion].Estado = 4;
	baseDatos[posicion].Municipio =12;
	baseDatos[posicion].Seccion = 13;
	baseDatos[posicion].Localidad = 1001;
	baseDatos[posicion].Emision = 2017;
	baseDatos[posicion].Vigencia = 2022;

    posicion = 2;
    baseDatos[posicion].lleno = 1;

    strcpy(baseDatos[posicion].Nombre , "Pedro");
    strcpy(baseDatos[posicion].ApellidoPaterno , "Alvarez");
    strcpy(baseDatos[posicion].ApellidoMaterno , "Dela");
    strcpy(baseDatos[posicion].Direccion , "Alvarez 21");
    strcpy(baseDatos[posicion].ClaveDeElector ,"FEDP12345");
    strcpy(baseDatos[posicion].CURP , "FEDP12345");
	baseDatos[posicion].AnioDeRegistro = 2017;
	baseDatos[posicion].Estado = 4;
	baseDatos[posicion].Municipio =12;
	baseDatos[posicion].Seccion = 13;
	baseDatos[posicion].Localidad = 1001;
	baseDatos[posicion].Emision = 2017;
	baseDatos[posicion].Vigencia = 2022;

    posicion = 8;
    baseDatos[posicion].lleno = 1;

    strcpy(baseDatos[posicion].Nombre , "Lupe");
    strcpy(baseDatos[posicion].ApellidoPaterno , "Lamp");
    strcpy(baseDatos[posicion].ApellidoMaterno , "Dela");
    strcpy(baseDatos[posicion].Direccion , "Alvarez 21");
    strcpy(baseDatos[posicion].ClaveDeElector ,"FEDP12345");
    strcpy(baseDatos[posicion].CURP , "FEDP12345");
	baseDatos[posicion].AnioDeRegistro = 2017;
	baseDatos[posicion].Estado = 4;
	baseDatos[posicion].Municipio =12;
	baseDatos[posicion].Seccion = 13;
	baseDatos[posicion].Localidad = 1001;
	baseDatos[posicion].Emision = 2017;
	baseDatos[posicion].Vigencia = 2022;

}

void inicializa(void)
{
     int i = 0; 
     //printf("\t\t inicializando \t\t\n");
     for (i = 0; i < SIZE; i++)
    {
    	baseDatos[i].lleno = 0;
        strcpy(baseDatos[i].Nombre , "\0");
        
         strcpy(baseDatos[i].ApellidoPaterno , "\0");
         strcpy(baseDatos[i].ApellidoMaterno , "\0");
         
         strcpy(baseDatos[i].Direccion , "\0");
         strcpy(baseDatos[i].ClaveDeElector , "\0");
         strcpy(baseDatos[i].CURP  , "\0");
         baseDatos[i].AnioDeRegistro = 0;
          baseDatos[i].Estado = 0;
          baseDatos[i].Municipio = 0;
          baseDatos[i].Seccion = 0;
          baseDatos[i].Localidad = 0;
          baseDatos[i].Emision = 0;
          baseDatos[i].Vigencia = 0;

    }
    //getchar();
}

int menu()
{ 
     int opcion = 0;
     printf("\n\n\t\t Menu \t\t\n");
     printf("1. Alta registro\n");
     printf("2. Baja registro\n");
     printf("3. Cambio de registro\n");
     printf("4. Ordena base de datos\n");
     printf("5. Imprimir registro\n");
     printf("6. Imprimir base de datos\n");
     printf("7. Guardar base de datos\n");
     printf("8. Restaurar base de datos\n");
     printf("9. Terminar\n");
     printf("\n   Opcion?  ");
     scanf("%d", &opcion);
     return opcion;
     
}

void ordenaBase(){


    int i =0;
    int arr[SIZE];
    for (i=0; i < SIZE; i++){
        arr[i] = i;
        //printf("%d ",arr[i]);
    }
    //printf("\n%d",arr[5]);

    burbujaApellidoPaterno(arr,SIZE);
    /*
    for (i=0; i < SIZE; i++){

        printf(" %d ",arr[i]);
    }*/
}

void burbujaApellidoPaterno(int arr[], int dim)
{
    int n =dim;
    int i,j,temp;
    char tempApellido[10];
    struct INE tempBase;

    for(i=0; i<n; i++){

        for(j=i+1; j<n ; j++){

            /*if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }*/
            if(strcmp(baseDatos[i].ApellidoPaterno,baseDatos[j].ApellidoPaterno)>0){
                //printf("\n-%d",strcmp(baseDatos[i].ApellidoPaterno,baseDatos[j].ApellidoPaterno));
                //printf("\n%s",baseDatos[i].ApellidoPaterno);
                //printf("\n%s",baseDatos[j].ApellidoPaterno);
                if(strcmp(baseDatos[j].ApellidoPaterno,"\0") ==0){
                    printf("");
                }
                else{
                    temp = arr[i];
                    //strcpy( tempApellido,baseDatos[i].ApellidoPaterno);
                    tempBase = baseDatos[i];
                    arr[i] = arr[j];
                    //strcpy( baseDatos[i].ApellidoPaterno,baseDatos[j].ApellidoPaterno);
                    baseDatos[i] = baseDatos[j];
                    arr[j] = temp;
                    //strcpy( baseDatos[j].ApellidoPaterno,tempApellido);
                    baseDatos[j] = tempBase;

                }
                
            }
            
        }
        
    }
    /*
    printf("Imprimiendo metodo");
    for (i=0; i < SIZE; i++){
        printf("%d ",arr[i]);
    }
    printf("acabaImprimiendo metodo");
    */
}

int menuCambioRegistro()
{ 
     int opcion = 0;
     printf("\n\n\t\t Seleccione el campo a modificar \t\t\n");
     printf("1. Direccion\n");
     printf("2. Estado\n");
     printf("3. Municipio\n");
     printf("4. Seccion\n");
     printf("5. Localidad\n");
     printf("6. Vigencia\n");
     printf("7. Cancelar\n");

     printf("\n\tOpcion\n");
     scanf("%d", &opcion);
     return opcion;
     
}

void cambiaRegistro(int posicion)
{    
    int modificar=0;
    int opcion= 7;
    if(baseDatos[posicion].lleno==0){
        //si no ya hay datos en la posicion
        
        printf("El archivo no contiene informacion.\t\t");
        return;
    }
    imprimeRegistro(posicion);
    printf("Desea modificar este registro? [1. Si 2. No]\t\t");
    scanf("%d", &modificar);
    if(modificar==2){
        return;
    }
    opcion = menuCambioRegistro();
    
    if(opcion==1){
        getchar();
        printf("\nNueva Direccion:  ");
        gets(baseDatos[posicion].Direccion);              
    }
    else if(opcion==2){
        printf("\nNuevo Estado:  ");
        scanf("%d", &baseDatos[posicion].Estado);
    }
    else if(opcion==3){
        printf("\nNuevo Municipio:  ");
        scanf("%d", &baseDatos[posicion].Municipio);
    }
    else if(opcion==4){
        printf("\nNueva Seccion:  ");
        scanf("%d", &baseDatos[posicion].Seccion);
    }
    else if(opcion==5){
        printf("\nNueva localidad:  ");
		scanf("%d", &baseDatos[posicion].Localidad);
    }
    else if(opcion==6){
        printf("\nNueva vigencia:  ");
		scanf("%d", &baseDatos[posicion].Vigencia);
    }
    else if(opcion==7){
        return;
    }

    imprimeRegistro(posicion);
    printf("\n\nRegistro cambiado.  ");
    return;     
}

void bajaRegistro(int posicion)
{
     int s=0;
     printf("\nEstas seguro de eliminar el registro? [1. Si 2. No]\t\t");
     scanf("%d", &s);
     if(s == 1){
          if(baseDatos[posicion].lleno == 0){
          printf("\nEl registro esta vacio. No hay nada que borrar\t\t");
          }else{
               baseDatos[posicion].lleno = 0;
               printf("\nSe ha borrado el registro");
          }
          
     }
}

void altaRegistro(int posicion)
{    
     int cambiar=0;
     if(baseDatos[posicion].lleno==1){
          //si ya hay datos en la posicion
          
          printf("El archivo contiene informaci?n. ?Desea cambiarla? [1. Si 2. No]\t\t");
          scanf("%d", &cambiar);

          if (cambiar ==2){
               return;
          }
     }
          baseDatos[posicion].lleno = 1;
		printf("Nombre:\t\t");
		scanf("%s", &baseDatos[posicion].Nombre);
		printf("Apellido Paterno:\t\t");
		scanf("%s", &baseDatos[posicion].ApellidoPaterno);
		printf("Apellido Materno:\t\t");
		scanf("%s", &baseDatos[posicion].ApellidoMaterno);

		getchar();
		printf("Direccion: (Calle N?mero)\t\t");
		gets(baseDatos[posicion].Direccion);
		//scanf("%s %s", &baseDatos[posicion].Direccion);
		printf("Clave de elector:\t\t");
		scanf("%s", &baseDatos[posicion].ClaveDeElector);
		printf("CURP:\t\t");
		scanf("%s", &baseDatos[posicion].CURP);
		printf("A?o de registro:\t\t");
		scanf("%d", &baseDatos[posicion].AnioDeRegistro);
		printf("Estado:\t\t");
		scanf("%d", &baseDatos[posicion].Estado);
		printf("Municipio:\t\t");
		scanf("%d", &baseDatos[posicion].Municipio);
		printf("Secci?n:\t\t");
		scanf("%d", &baseDatos[posicion].Seccion);
		printf("Localidad:\t\t");
		scanf("%d", &baseDatos[posicion].Localidad);
        printf("Emisi?n:\t\t");
		scanf("%d", &baseDatos[posicion].Emision);
		printf("Vigencia:\t\t");
		scanf("%d", &baseDatos[posicion].Vigencia);

		getchar();
     
}

void imprimeRegistros(){
    int i = 0;
    for(i=0;i<SIZE;i++){
        if(baseDatos[i].lleno == 1){
            imprimeRegistro(i);
        }
    }
    return;
}

void imprimeRegistro(int posicion)
{    
     if(baseDatos[posicion].lleno ==0){
		printf("\nRegistro vacio. No hay informacion que imprimir\t\t");
          return;
     }

     printf("%c",218);
     int i=0;
     int largo = 70;
	for (i = 0; i <= largo; i++)
     {
           printf("%c", 196);
      }
    printf("%c\n",191);
    char pal[] = "Juan";
    //INE
    printf("%c",179);
    char ineString[] = "       INSTITUTO NACIONAL ELECTORAL";
    printf("%s",ineString);
	for (i = 0; i <= largo-strlen(ineString); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    printf("%c",179);
    char credencialString[] = "       Credencial para votar";
    printf("%s",credencialString);
	for (i = 0; i <= largo-strlen(credencialString); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    //nombre
    printf("%c",179);
    printf("%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,191);
    char nombreString[] = " Nombre:";
    printf("%s",nombreString);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(nombreString)-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    // nombre valor
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,'F',32,32,32,32,179);
    //baseDatos[posicion].Nombre
    //char nombre[] = " Nombre:";
    printf("%s",baseDatos[posicion].Nombre);
	for (i = 0; i <= (largo-strlen(baseDatos[posicion].Nombre)-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    // nombre
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,'O',32,32,32,32,179);
    //char apellidop[] = " Nombre:";
    printf("%s",baseDatos[posicion].ApellidoPaterno);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(baseDatos[posicion].ApellidoPaterno)-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    // nombre
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,'T',32,32,32,32,179);
    //char direccion[] = " Nombre:";
    printf("%s",baseDatos[posicion].ApellidoMaterno);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(baseDatos[posicion].ApellidoMaterno)-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    // nombre
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,'O',32,32,32,32,179);
    char direccionString[] = " Direccion:";
    printf("%s",direccionString);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(direccionString)-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,32,32,32,32,32,179);
    //char direccionString[] = " Direccion:";
    printf("%s",baseDatos[posicion].Direccion);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(baseDatos[posicion].Direccion)-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,32,32,32,32,32,179);
    char claveString[] = " Clave de elector: ";
    printf("%s%s",claveString,baseDatos[posicion].ClaveDeElector);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(claveString)-strlen(baseDatos[posicion].ClaveDeElector)-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,32,32,32,32,32,179);
    char curpString[] = " CURP: ";
    char registroString[] = " Registro: ";
    printf("%s%s%s%d",curpString,baseDatos[posicion].CURP,registroString,baseDatos[posicion].AnioDeRegistro);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(curpString)-strlen(baseDatos[posicion].CURP)-strlen(registroString)-4-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",179,32,32,32,32,32,32,32,32,179);
    char estadoString[] = " Estado: ";
    char municipioString[] = " Municipio: ";
    char seccionString[] = " Seccion: ";
    printf("%s%d%s%d%s%d",estadoString,baseDatos[posicion].Estado,municipioString,baseDatos[posicion].Municipio,seccionString,baseDatos[posicion].Seccion);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(estadoString)-strlen(municipioString)-strlen(seccionString)-1-2-2-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    printf("%c",179); // | |     |                |
    printf("%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217);
    char localidadString[] = " Localidad: ";
    char emisionString[] = " Emision: ";
    char vigenciaString[] = " Vigencia: ";
    printf("%s%d%s%d%s%d",localidadString,baseDatos[posicion].Localidad,emisionString,baseDatos[posicion].Emision,vigenciaString,baseDatos[posicion].Vigencia);
    //printf("%d",largo-strlen(nombreString)-10);
	for (i = 0; i <= (largo-strlen(localidadString)-strlen(emisionString)-strlen(vigenciaString)-4-4-4-10); i++)
     {
           printf("%c", 32);//espacio
      }
    printf("%c\n",179);
    
    
    
    printf("%c",192);
	for (i = 0; i <= largo; i++)
     {
           printf("%c", 196);
      }
    printf("%c\n",217);
     /*
     printf("%c%c",218,196);
     printf("\nNombre:\t %s",baseDatos[posicion].Nombre);
		printf("\nApellido Paterno:\t %s",baseDatos[posicion].ApellidoPaterno);
		printf("\nApellido Materno:\t %s",baseDatos[posicion].ApellidoMaterno);
		printf("\nDirecci?n:\t %s",baseDatos[posicion].Direccion);
		printf("\nClave de elector:\t %s",baseDatos[posicion].ClaveDeElector);
		printf("\nCURP:\t %s",baseDatos[posicion].CURP);
		printf("\nRegistro:\t %d",baseDatos[posicion].AnioDeRegistro);
		printf("\nEstado:\t %d",baseDatos[posicion].Estado);
		printf("\nMunicipio:\t %d",baseDatos[posicion].Municipio);
		printf("\nSecci?n:\t %d",baseDatos[posicion].Seccion);
		printf("\nEmisi?n:\t %d",baseDatos[posicion].Emision);
		printf("\nVigencia:\t %d",baseDatos[posicion].Vigencia);*/
}



