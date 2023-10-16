#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "strings.h"
#include "time.h">

#define DIM 5

/*Estructuras*/

/*Prototipado*/
void menu();
void consignas();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();
void ejercicio12();
void ejercicio13();
void ejercicio14();
void ejercicio15();
void ejercicio16();
void ejercicio17();

void mostrarVectorInvertido(int vector[], int validos, int posicion);
void mostrarVectorConRecursividad(int vector[], int validos, int posicion);
int calcularFactorialDeUnNumero(int numeroParaCalcularFactorial);
float calcularPromedioDeUnArreglo(int vector[], int validos, int posicion);
int calcularSumaVector(int vector[], int validos, int j);
void mostrarCaracteresInvertidos();
int encontrarDatoEnVector(int vector[], int validos, int dato, int i);
int contarDigitosDeUnNumero(int numero);
int sumarDigitosDeUnNumero(int num);
int contarDigitosPares(int num);
void mostrarDigitosInvertido(int num);
/*--------------------------------------------------------------------------------------------------------*/
int main(){
menu();
}
/*--------------------------------------------------------------------------------------------------------*/
//Funciones

void menu() {
    srand(time(NULL));
    char eleccion = 's';
    int ejercicio;

    consignas();

    do {
    printf("Ingrese el Numero de ejercicio a dirigirse --> ");
    fflush(stdin);
    scanf("%i", &ejercicio);
    printf("\n");


    switch(ejercicio) {

    case 1:
        ejercicio1();
        break;

    case 2:
        ejercicio2();
        break;

    case 3:
        ejercicio3();
        break;

    case 4:
        ejercicio4();
        break;

    case 5:
        ejercicio5();
        break;

    case 6:
        ejercicio6();
        break;

    case 7:
       ejercicio7();
        break;

    case 8:
        ejercicio8();
        break;

    case 9:
        ejercicio9();
        break;

    case 10:
        ejercicio10();
        break;
    case 11:
        ejercicio11();
        break;
    case 12:
        ejercicio12();
        break;
    case 13:
        ejercicio13();
        break;
    case 14:
        ejercicio14();
        break;
    case 15:
        ejercicio15();
        break;
    case 16:
        ejercicio16();
        break;
    case 17:
        ejercicio17();
        break;

    default:
        printf("Has ingresado un numero incorrecto, vuelve a intentarlo \n\n");
        break;
        }

        printf("\nPulse 's' para ingresar a otro ejercicio --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

    }while(eleccion == 's' || eleccion == 'S');
}

void consignas() {
    printf("1) Calcular el factorial de un numero en forma recursiva\n\n");
    printf("2) Calcular la potencia de un número en forma recursiva\n\n");
    printf("3) Recorrer un arreglo y mostrar sus elementos en forma recursiva\n\n");
    printf("4) Recorrer un arreglo comenzando desde la posicion 0 y mostrar sus elementos en forma invertida (recursivo)\n\n");
    printf("5) Determinar en forma recursiva si un arreglo es capicua\n\n");
    printf("6) Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma\n\n");
    printf("7) Buscar el menor elemento de un arreglo en forma recursiva\n\n");
    printf("8) Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos\n\n");
    printf("9) Determinar si un arreglo contiene un determinado elemento de forma recursiva. (Pueden intentarlo tambien con una funcion void)(Tener en cuenta para un arreglo desordenado y el caso para un arreglo ordenado)\n\n");
    printf("10) Determinar el promedio de un arreglo con Recursividad\n\n");
    printf("11) Funcion suma digitos, recibe un numero entero y me devuelva la suma de sus digitos \n\n");
    printf("12) Funcion que cuente digitos pares. Recibe un numero entero y devuelve cuantos numeros de esos digitos son pares \n\n");
    printf("13) Funcion es primo, recibe el numero y el divisor. Debe retornar si es primo o no el numero \n\n");
    printf("14) Funcion contar mayores. Recibe un arreglo, un numero para fijarnos cuantos numeros hay mayores a ese numero \n\n");
    printf("15) Funcion invertir digitos. Reciba un numero que invierta sus digitos\n\n");
    printf("16) Realizar una funcion que, dado un arreglo de enteros ordenado, busque un elemento en dicho arreglo (implementar metodo de busqueda binaria)\n\n");
    printf("17) Realizar una funcion que cuente los digitos que tiene un numero\n\n");

}
//Ejercicios
void ejercicio1() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 1 \n\n");

    int numeroParaCalcularFactorial = rand()%20 + 1;

    int resultado = calcularFactorialDeUnNumero(numeroParaCalcularFactorial);
    printf("El factorial de %i es -->  |%i| \n", numeroParaCalcularFactorial, resultado);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularFactorialDeUnNumero(int numeroParaCalcularFactorial) {

    int resultado;

    if(numeroParaCalcularFactorial == 0) resultado = 1; //El if es la condición de corte, y el resultado es la solución trivial

    else resultado = numeroParaCalcularFactorial * calcularFactorialDeUnNumero(numeroParaCalcularFactorial - 1);

    printf("El factorial de %i es --> |%i|\n", numeroParaCalcularFactorial, resultado); //Nos muestra la secuencia de recursión

    return resultado;

}

void ejercicio2() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 2 \n\n");

    int numeroBase = rand()%20 + 1;
    int numeroExponente = rand()%10 + 1;

    int resultado = calcularPotenciaDeUnNumero(numeroBase, numeroExponente);

    printf(" \nEl numero %i con el exponente %i da como resultado --> |%i| \n", numeroBase, numeroExponente, resultado);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}
int calcularPotenciaDeUnNumero(int base, int exponente) {

    int resultado;

    if(exponente == 0) resultado = 1;

    else  resultado = base * calcularPotenciaDeUnNumero(base, --exponente);

    printf("El numero %i con el exponente %i da como resultado --> |%i| \n", base, exponente, resultado);

    return resultado;
}

void ejercicio3() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 3 \n\n");

    int vector[DIM];

    for(int i = 0; i < DIM; i++) vector[i] = rand()%50 + 1;
    printf("DEBUG- Mostrando arreglo cargado --> ");
    for(int i = 0; i < DIM; i++) printf(" |%i|", vector[i]);
    printf("\n");
    int posicion = 0;
    int validos = DIM;

    mostrarVectorConRecursividad(vector, validos, posicion);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void mostrarVectorConRecursividad(int vector[], int validos, int posicion) {

        if(posicion < validos) {
            printf("|%i|", vector[posicion]);
            mostrarVectorConRecursividad(vector, validos, ++posicion);
        }
}

void ejercicio4() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 4 \n\n");

    int vector[DIM];

    for(int i = 0; i < DIM; i++) vector[i] = rand()%50 + 1;
    printf("DEBUG- Mostrando arreglo cargado --> ");
    for(int i = 0; i < DIM; i++) printf(" |%i|", vector[i]);
    printf("\n");

    int posicion = DIM;
    int validos = DIM;

    mostrarVectorInvertido(vector, validos, posicion);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void mostrarVectorInvertido(int vector[], int validos, int posicion) {

    if(posicion == 0) printf("|%i|", vector[posicion]);

    else mostrarVectorInvertido(vector, validos, --posicion);
}

void ejercicio5() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 5 \n\n");

    int vector[DIM];
    for(int i = 0; i < DIM; i++) vector[i] = rand()%5 + 1;

    int dimension = 4;
    int index = 0;

    int respuesta = calcularVectorCapicua(vector, dimension, index);

    if(respuesta == 1) printf("El vector es capicua\n");
    else printf("El vector no capicua\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularVectorCapicua(int vector[], int j, int i) {

    int respuesta;

    if(i > j) respuesta = 1;

    else if(vector[i] != vector[j]) respuesta = 0;

    else respuesta = calcularVectorCapicua(vector, ++i, --j);

    return respuesta;
}

void ejercicio6() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 6 \n\n");

    int vector[DIM];
    int validos = DIM;
    int j = 0;

    for(int i = 0; i < DIM; i++) vector[i] = rand()% 100 + 1;

    for(int i = 0; i < DIM; i++)printf("|%i|", vector[i]);
    printf("\n");

    int respuesta = calcularSumaVector(vector, validos, j);
    printf("\n");
    printf("La suma de los elementos del Vector es --> %i", respuesta);
    printf("\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularSumaVector(int vector[], int validos, int j) {

    if(j >= validos) return 0;

    else return vector[j] + calcularSumaVector(vector, validos, ++j);
}

void ejercicio7() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 7 \n\n");

    int vector[DIM];
    int validos = DIM;

    for(int i = 0; i < DIM; i++) vector[i] = rand()% 100 + 1;

    for(int i = 0; i < DIM; i++)printf("|%i|", vector[i]);
    printf("\n");

     int j = 0;

    int respuesta = calcularMenorVector(vector, validos, j);
    printf("\nEl menor elemento del Vector es %i \n\n", respuesta);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularMenorVector(int vector[], int validos, int i) { //Busco el menor en la vuelta de la función recursiva

    int menor;

    if(i == DIM) menor = vector[validos - 1]; //Condición de corte

    else {
        menor =  calcularMenorVector(vector, validos, i + 1); //Acercamiento a la condición de corte

            if(vector[i] < menor)  menor = vector[i];
    }
    return menor;
}

void ejercicio8() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 8 \n\n");

    mostrarCaracteresInvertidos();

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void mostrarCaracteresInvertidos() {

    char letra;

    printf("Ingrece una letra -- > ");
    fflush(stdin);
    scanf("%c", &letra);

    if(letra != '*') {
        mostrarCaracteresInvertidos(letra);
        printf("%c", letra);
    }
}

void ejercicio9() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 9 \n\n");

    int buscarDato;
    int vector[DIM];
    int validos = DIM;
    int i = 0;

    for(int i = 0; i < DIM; i++) vector[i] = rand()% 100 + 1;

    for(int i = 0; i < DIM; i++)printf("|%i|", vector[i]);
    printf("\n");

    printf("Ingrese el dato a buscar en el Vector --> ");
    fflush(stdin);
    scanf("%i", &buscarDato);
    printf("\n");

    int resultado = encontrarDatoEnVector(vector, validos, buscarDato, i);

    if(resultado == 1) printf("El dato si esta en el Vector \n");
    else printf("El dato no esta en el Vector \n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int encontrarDatoEnVector(int vector[], int validos, int dato, int i) {

    if(i == validos) return  0;

    if(vector[i] == dato) return 1;

    else return  encontrarDatoEnVector(vector, validos, dato, i + 1);
}

void ejercicio10() {

    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 10 \n\n");

    int vector[DIM];
    int posicion = 0;
    int validos = DIM;

    for(int i = 0; i < DIM; i++) vector[i] = rand()% 100 + 1;

    printf("DEBUG- Mostrando arreglo cargado --> ");
    for(int i = 0; i < DIM; i++) printf(" |%i|", vector[i]);
    printf("\n");

    float promedio = calcularPromedioDeUnArreglo(vector, validos, posicion);

    printf("\nEl promedio del Vector es %.2f \n", promedio);

    printf("\n--------------------------------------------------------------------------------------------------\n");

}

float calcularPromedioDeUnArreglo(int vector[], int validos, int posicion) {

    float respuesta;

    if(posicion >= validos) respuesta = 0;

    else respuesta = (float) vector[posicion] / validos + calcularPromedioDeUnArreglo(vector, validos, ++posicion);

    return respuesta;
}

void ejercicio11() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 11 \n\n");

    int num;

    printf("Ingrese un numero --> ");
    fflush(stdin);
    scanf("%i", &num);
    printf("\n");

    int sumaDigitos = sumarDigitosDeUnNumero(num);
    printf("La suma de los digitos del numero es --> %i", sumaDigitos);
    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int sumarDigitosDeUnNumero(int num) {

    if(num < 10) return num;

    else return num % 10 + sumarDigitosDeUnNumero(num / 10);
}

void ejercicio12() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 12 \n\n");

    int num;
    int digitosPares;

    printf("Ingrese un numero --> ");
    fflush(stdin);
    scanf("%i", &num);
    printf("\n");

    digitosPares = contarDigitosPares(num);
    printf("Digitos Pares --> %i \n", digitosPares);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int contarDigitosPares(int num) {

        if (num == 0) return 0; //Si el num = 0 retornamos 0 ya que es impar

        int ultimoDigito = num % 10; //Nos quedamos con el último digito del numero

        if (ultimoDigito % 2 == 0) return 1 + contarDigitosPares(num / 10); //Si ese digito es par, retorna 1

        else return contarDigitosPares(num / 10); //Si el digito es impar, no hace nada
}

void ejercicio13() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 13 \n\n");

    int num;

    printf("Ingrese un numero --> ");
    fflush(stdin);
    scanf("%i", &num);
    printf("\n");

    int esPrimo = calcularSiUnNumEsPrimo(num, num - 1);

    if(esPrimo == 1) printf("El numero es primo\n");

    else printf("El numero no es primo\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int calcularSiUnNumEsPrimo(int num, int divisor) {

    if(divisor == 1) return 1;

    if (num % divisor == 0) return 0;

    return calcularSiUnNumEsPrimo(num, divisor - 1);
}

void ejercicio14() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 14 \n\n");

    int num;
    int vector[DIM];
    int validos = DIM;
    int posicion = 0;

    for(int i = 0; i < DIM; i++) vector[i] = rand()% 100 + 1;

    printf("DEBUG- Mostrando arreglo cargado --> ");
    for(int i = 0; i < DIM; i++) printf(" |%i|", vector[i]);
    printf("\n\n");

    printf("Ingrese un numero --> ");
    fflush(stdin);
    scanf("%i", &num);
    printf("\n");

    int cantidadMayores = contarMayoresVector(vector, validos, posicion, num);

    printf("La cantidad de numeros mayores a %i es de %i \n", num, cantidadMayores);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int contarMayoresVector(int vector[DIM], int validos, int posicion, int num) {

    if(posicion == validos ) return 0;

    int rta = 0;

    if(vector[posicion] > num ) rta++;

    rta += contarMayoresVector(vector, validos, posicion + 1, num);

    return rta;
}

void ejercicio15() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 15 \n\n");

    int num;
    printf("Ingrese un numero --> ");
    fflush(stdin);
    scanf("%i", &num);
    printf("\n");

    mostrarDigitosInvertido(num);

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

void mostrarDigitosInvertido(int num) {

    if(num == 0) return;

    printf("%i",  num % 10);

    mostrarDigitosInvertido(num / 10);
}

void ejercicio16() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 16 \n\n");

    int vector[] = {1,2,3,4,5,6,7,8,9,10};
    int num;
    int posInicio = 0;
    int posFinal = DIM - 1;

    printf("Ingrese un numero a buscar en el vector --> ");
    fflush(stdin);
    scanf("%i", &num);
    printf("\n");

    int verificacion = busquedaBinaria(vector, posInicio, posFinal, num);

    if(verificacion == 1) printf("El numero esta en el arreglo\n");

    else  printf("El numero no esta en el arreglo\n");

    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int busquedaBinaria(int vector[], int posInicio, int posFinal, int num) {

    if(posInicio > posFinal) return 0; //Condición de corte

    int medioVector = (posInicio + posFinal) / 2;

    if(vector[medioVector] == num) {

    return 1;

    }else if(vector[medioVector] < num) {

        return busquedaBinaria(vector, medioVector + 1, posFinal, num);

    } else {
            return busquedaBinaria(vector, posInicio, medioVector - 1, num);
    }
}

void ejercicio17() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("Ejercicio 17 \n\n");

    int numero;

    printf("Ingrese un numero --> ");
    fflush(stdin);
    scanf("%i", &numero);
    printf("\n");

    int cantidadDigitos = contarDigitosDeUnNumero(numero);
    printf("La cantidad de digitos del numero ingresado es --> %i", cantidadDigitos);
    printf("\n--------------------------------------------------------------------------------------------------\n");
}

int contarDigitosDeUnNumero(int numero) {

    if(numero < 10) return 1;

    else return 1 + contarDigitosDeUnNumero(numero / 10);
}

