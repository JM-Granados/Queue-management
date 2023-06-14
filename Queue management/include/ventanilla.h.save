#ifndef VENTANILLA_H
#define VENTANILLA_H
#include "tiquete.h"

/*
En esta clase se crea una ventanilla y sus atributos, como el codigo de la ventana y el codigo del area. Lo primero que debe hacer el controlador es
llamar el constructor de esta clase, el cual crea una nueva ventana.
Autores:
Adrián Josué Vega Barrantes
*/

using namespace std;

class ventanilla {
private:
    int atendidos = 0;
    string codigoVentana;
    string codigoArea;
    tiquete *ultimoTiquete;

public:
    ventanilla(string codigoVentana, string codigoArea, tiquete *ultimoTiquete = nullptr) {
        this->codigoVentana = codigoVentana;
        this->codigoArea = codigoArea;
        this->ultimoTiquete = ultimoTiquete;
    }
    ~ventanilla(){
        delete [] ultimoTiquete;
    }
    void setCodigoVentana(string codigoVentana){
        this->codigoVentana = codigoVentana;
    }
    string getCodigoVentana() {
        return codigoVentana;
    }
    void setCodigoArea(string codigoArea){
        this->codigoArea = codigoArea;
    }
    string getCodigoArea() {
        return codigoArea;
    }
    int getAtendidos() {
        return atendidos;
    }
    void setUltimoTiquete(tiquete *ultimoTiquete){
        atendidos++;
        this->ultimoTiquete = ultimoTiquete;
    }
    tiquete* getUltimoTiquete() {
        return ultimoTiquete;
    }
};

#endif // VENTANILLA_H
