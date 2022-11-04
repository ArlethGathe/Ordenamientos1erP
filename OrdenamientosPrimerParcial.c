#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Se va a realizar un fichero para poder abrir un archivo de texto (setdatosedades.txt)
int Contar()
{
	FILE *fichero;
	int conta=0;
	char direccion[30];
	printf("Escribe el nombre del archivo y su extensi%cn:",162);  //con la extensión se refiere al .txt para poder abrirlo 
	scanf("%s",direccion);
	fichero=fopen(direccion,"rt");
	while(!feof(fichero))
	{
		if(fgetc(fichero)=='\n')
		{
			conta++;
		}
	}
	fclose(fichero);
	return conta;
}
//Se utiliza otra función para poder ingresar al contenido del archivo y proceder a ordenarlo
void Lectura(int *datos,int *tam)
{
	FILE *fichero;
	char direccion[30];
	printf("Escribe el nombre del archivo y su extensi%cn:",162);
	scanf("%s",direccion);//aquí es donde se escribe el nombre del archivo que se quiere abrir
	fichero=fopen(direccion,"rt");
	for(int a=0;a<(*tam);a++)
	{
		fscanf(fichero,"%d\n",&datos[a]);
	}
	fclose(fichero);
	printf("\nEl set de datos extraido del archivo txt esta de la siguiente manera: \n"); //Se muestra el arreglo original.
	for(int b=0;b<(*tam);b++)
	{
		printf("%d.- %d\n",b+1,datos[b]);
	}
}
//ordenamiento bubble sort
void Burbuja(int *datos,int *copia1,int *tam) //se llama a la función Burbuja con los parámentros que ocupa
{
	int d,e; //Son las variables para comparar las posiciones
	int temporal;
	
	for(int a=0;a<(*tam);a++)
	{
		copia1[a]=datos[a];
	}
	while(f<(*tam))
	{
		for(int d=0,e=1;d<(*tam) & e<(*tam);d++,e++)
		{
			if(copia1[d]>copia1[e])
			{
				temporal=copia1[e];
				copia1[e]=copia1[d];
				copia1[d]=temporal;
			}
		}
		f++;
	}
	printf("\nEl set de datos acomodados de forma ascendente por el Metodo de Burbuja queda asi:");
	for(int a=0;a<(*tam);a++)
	{
		printf("\n%d.- %d",a+1,copia1[a]);
	}
}
//Ordenamiento de inserción
void Insercion(int *datos,int *copia2,int *tam)//SE manda llamar a la función con los parámetros que va a requerir
{
	int temporal,posicion; //temporal es un auxiliar y posición va a marcando la posición que lleve en el arreglo
	
	for(int a=0;a<(*tam);a++)
	{
		copia2[a]=datos[a];
	}
	for(int d=0;d<(*tam);d++)
		{
			posicion=d; //empieza en la posición cero
			temporal=copia2[d];
		while((posicion>0) && (copia2[posicion-1]>temporal)) //Va a hacer el cambio siempre y cuando la posción sea mayor a cero y que el elemento de la izquiera a temporal sea mayor a temporal
		{
			copia2[posicion]=copia2[posicion-1];
			posicion--;
		}
		copia2[posicion]=temporal;
	}
	printf("\n\nEl set de datos acomodados de forma ascendente por el Metodo de Insercion queda asi:");
	for(int a=0;a<(*tam);a++)
	{
		printf("\n%d.- %d",a+1,copia2[a]);
	}
}
//Ordenamiento por selección
void Seleccion(int *datos,int *copia3,int *tam)  // se manda a llamar la función con sus parámetros necesarios
{
	int temporal,menor; //temporal sirve para guardar el valor de manera temporal de una casilla del arreglo en lo que menor encuentra otro más pequeño.
	
	for(int a=0;a<(*tam);a++)
	{
		copia3[a]=datos[a];
	}
	
	for(int b=0;b<(*tam);b++) 
	{
		menor=b;
		for(int c=b+1;c<(*tam);c++)
		{
			if(copia3[c]<copia3[menor])
			{
				menor=c;
			}
		}
		temporal=copia3[b]; //es para realizar el cambio y hacer que el número más pequeño esté en el pricipio del arreglo
		copia3[b]=copia3[menor];
		copia3[menor]=temporal;
	}
	printf("\n\nEl set de datos acomodados de forma ascendente por el Metodo de Seleccion queda asi:");
	for(int a=0;a<(*tam);a++)
	{
		printf("\n%d.- %d",a+1,copia3[a]);
	}
}

int main()
{
	int *datos,*copia1,*copia2,*copia3;
	int tam;
	clock_t t_start, t_finish;			//estas variables son necesarias para contar desde que se empieza el proceso de ordenamiento y, hasta que termine
	double t_interval;	//Esta variable se utilizará para obtener el resultado del tiempo en el que tardó en ordenar cada tipo de ordenamiento.		
	tam=Contar();
	datos=(int *)malloc(tam*sizeof(int));
	copia1=(int *)malloc(tam*sizeof(int));
	copia2=(int *)malloc(tam*sizeof(int));
	copia3=(int *)malloc(tam*sizeof(int));
	Lectura(datos,&tam);
		t_start=clock();		
	Burbuja(datos,copia1,&tam);
		t_finish=clock();					
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;			//Estas operaciones son para poder calcular cuanto tiempo se tarda en realizar el ordenamiento de cada uno de estos.
	printf("\n El tiempo de ordenamiento de burbuja es de: %.5f seconds.", t_interval);
		t_start=clock();		
	Insercion(datos,copia2,&tam);
		t_finish=clock();					
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;			
	printf("\n El tiempo de ordenamiento por seleccion es de: %.5f seconds.", t_interval);
		t_start=clock();	
	Seleccion(datos,copia3,&tam);
		t_finish=clock();					
	t_interval = (double)(t_finish - t_start)/CLOCKS_PER_SEC;			
	printf("\n El tiempo de ordenamiento de insercion es de: %.5f seconds.", t_interval);
}
