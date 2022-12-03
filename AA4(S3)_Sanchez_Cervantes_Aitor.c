#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdbool.h>



// Prototipos de funciones
void funcionControl(bool pasaControl1, bool pasaControl2, int tiempoPorcentajeEvaluar1, double cotizacionPorcentajeEvaluar1, int tiempoPorcentajeEvaluar2, double cotizacionPorcentajeEvaluar2, int tiempoBaja1, double cotizacionValorBaja1, int tiempoBaja2, double cotizacionValorBaja2, double media, int contadorCotizacionMenor, int* cotizacionInicial, int cotizacionFinal, bool tendenciaAlcista);

// Inicio Programa principal Main
int main() {

    // Declaracion de variables
    int tiempo, tiempoPorcentajeEvaluar1, tiempoPorcentajeEvaluar2, tiempoBaja1, tiempoBaja2, penultimoTiempo, i, contador, contadorCotizacionMenor, contadorCotizacionBaja, contadorCotizacionAlta;
    double cotizacion, sumaCotizacion, cotizacionInicial, penultimaCotizacion, cotizacionFinal, cotizacionValorBaja1, cotizacionValorBaja2, cotizacionPorcentajeEvaluar1, cotizacionPorcentajeEvaluar2, tiempoAlta1, cotizacionAlta1, tiempoAlta2, cotizacionAlta2, media;
    bool pasaControl1, pasaControl2, tendenciaAlcista;


    // Inicializamos las variables
    tiempo = 0;
    i = 0;
    cotizacion = 0;
    sumaCotizacion = 0;
    media = 0;
    cotizacionInicial = 0;
    contadorCotizacionMenor = 0;
    penultimaCotizacion = 0;
    contadorCotizacionBaja = 0;
    penultimoTiempo = 0;
    pasaControl1 = true;
    pasaControl2 = true;
    tendenciaAlcista = false;
    contadorCotizacionAlta = -1; // Le damos valor negativo porque en la condicion siempre de inicio va a ser true


    // Creamos el bucle donde pediremos el tiempo y las cotizaciones
    while (i >= 0) {

        penultimoTiempo = tiempo; //Almacenamos el penultimo tiempo

        //Pedimos el tiempo
        printf("Introduce tiempo\n");
        scanf("%d", &tiempo);

        // Si introducimos el valor -1 salimos del bucle
        if (tiempo == -1) {
            break;
        }

        penultimaCotizacion = cotizacion; // Almacenamos la penultima cotizacion

        // Pedimos la cotizacion
        printf("Introduce cotizacion\n");
        scanf("%lf", &cotizacion);

        contador = i + 1;
        sumaCotizacion = sumaCotizacion + cotizacion;

        // Almacenamos la primera cotizacion 
        if (i == 0) {
            cotizacionInicial = cotizacion;
        }
        // Creamos un contador para las cotizaciones que estan por debajo de la primera cotizacion
        if (cotizacion < cotizacionInicial) {
            contadorCotizacionMenor = contadorCotizacionMenor + 1;
        }

        cotizacionFinal = cotizacion;  //Almacenamos la ultima cotizacion 
        i++;


        //CONTROL 3 COTIZACIONES A LA BAJA
        // Condicion para evaluar si hay cotizaciones a la baja
        if (cotizacion < penultimaCotizacion) {

            contadorCotizacionBaja = contadorCotizacionBaja + 1;
            if (contadorCotizacionBaja == 1) {
                cotizacionValorBaja1 = penultimaCotizacion;
                tiempoBaja1 = penultimoTiempo;
            }
            if (contadorCotizacionBaja == 3) {
                cotizacionValorBaja2 = cotizacion;
                tiempoBaja2 = tiempo;
            }
        }
        else {
            contadorCotizacionBaja = 0; // Si no hay cotizaciones a la baja seguidas reiniciamos el contador

        }

        // Condicion por la cual si se producen 3 cotizaciones a la baja no se ha superado el control
        if (contadorCotizacionBaja == 3) {
            cotizacionValorBaja1;
            cotizacionValorBaja2;
            tiempoBaja1;
            tiempoBaja2;
            pasaControl2 = false;
        }

        // CONTROL DE 2 COTIZACIONES AL ALZA
        // Condicion para evaluar si hay cotizaciones a la alza
        if (cotizacion > penultimaCotizacion) {

            contadorCotizacionAlta = contadorCotizacionAlta + 1;
        }
        else {
            contadorCotizacionAlta == 0; // Si no hay cotizaciones a la alza seguidas reiniciamos el contador
        }

        // Guardamos la cotizacion para evaluar porcentaje de incremento
        if (contadorCotizacionAlta == 1) {
            cotizacionPorcentajeEvaluar1 = penultimaCotizacion;
            tiempoPorcentajeEvaluar1 = penultimoTiempo;
        }

        // Guardamos la otra  cotizacion para evaluar porcentaje de incremento siempre que sea superior al 10% 
        if ((contadorCotizacionAlta == 2)) {
            cotizacionPorcentajeEvaluar2 = cotizacion;
            tiempoPorcentajeEvaluar2 = tiempo;

            // Evaluamos si entre una cotizacion y otra hay un incremento mayor al 10%
            if ((contadorCotizacionAlta == 2) && (cotizacionPorcentajeEvaluar2 > (cotizacionPorcentajeEvaluar1 + (cotizacionPorcentajeEvaluar1 * 0.1)))) {
                tiempoAlta1 = tiempoPorcentajeEvaluar1;
                cotizacionAlta1 = cotizacionPorcentajeEvaluar1;
                tiempoAlta2 = tiempoPorcentajeEvaluar2;
                cotizacionAlta2 = cotizacionPorcentajeEvaluar2;
                pasaControl1 = false;
                contadorCotizacionAlta = 0;
            }
            // Si no es superior al 10 % volvemos a poner el contador a 1 para poder guardar la primera cotizacion al alza
            else {
                contadorCotizacionAlta = 1;
                if (contadorCotizacionAlta == 1) {
                    cotizacionPorcentajeEvaluar1 = penultimaCotizacion;
                    tiempoPorcentajeEvaluar1 = penultimoTiempo;
                }
            }
        }


    }

    media = sumaCotizacion / (double)contador; //Calculamos la media de todas las cotizaciones

    // Condicion para evaluar la tendencia si es alcista
    if ((cotizacionFinal > cotizacionInicial) && (cotizacionFinal > cotizacionInicial)) {
        tendenciaAlcista = true;
    }


    // Llamada a las funciones
    funcionControl(pasaControl1, pasaControl2, tiempoAlta1, cotizacionAlta1, tiempoAlta2, cotizacionAlta2, tiempoBaja1, cotizacionValorBaja1, tiempoBaja2, cotizacionValorBaja2, media, contadorCotizacionMenor, &cotizacionInicial, cotizacionFinal, tendenciaAlcista);

    system("pause");
    return 0;

}
void funcionControl(bool pasaControl1, bool pasaControl2, int tiempoAlta1, double cotizacionAlta1, int tiempoAlta2, double cotizacionAlta2, int tiempoBaja1, double cotizacionValorBaja1, int tiempoBaja2, double cotizacionValorBaja2, double media, int contadorCotizacionMenor, double* cotizacionInicial, double cotizacionFinal, bool tendenciaAlcista) {

    if ((pasaControl1 == false) || (pasaControl2 == false)) {
        printf("No se ha superado el control, puesto que:\n");

        if (pasaControl1 == false) {
            printf("Se han producido dos cotizaciones consecutivas al alza y la ultima respecto a la primera supone un incremento de un 10 por ciento en la cotizacion, concretamente entre %d: %lf y %d: y %lf.\n", tiempoAlta1, cotizacionAlta1, tiempoAlta2, cotizacionAlta2);
        }
        if (pasaControl2 == false) {
            printf("Se han producido tres cotizaciones a la baja consecutivas, concretamente entre %d: %lf y %d: %lf.\n", tiempoBaja1, cotizacionValorBaja1, tiempoBaja2, cotizacionValorBaja2);

        }
    }
    else {
        printf("La media de cotizacion durante el dia a sido: %lf.\n", media);
        printf("Se han introducido %d por debajo de la primera que fue %lf.\n", contadorCotizacionMenor, *cotizacionInicial);

        // Condicion para evaluar la tendencia si es alcista
        if (tendenciaAlcista == true) {
            printf("Se considera que la cotizacion esta al alza.\n");
        }
    }
}

