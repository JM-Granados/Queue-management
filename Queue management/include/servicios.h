#ifndef SERVICIOS_H
#define SERVICIOS_H

/*
En esta clase se crea un servicio y sus atributos, como el nombre y codigo de área a la que corresponde. Lo primero que debe
hacer el controlador es llamar el constructor de esta clase, el cual crea un nuevo servicio.
Autores:
Jose Manuel Granados V
Adrián Josué Vega Barrantes
*/

using namespace std;

class servicios {
private:
    string nombre;
    string codigoArea;
    string descripcion;
    int tiquetes;

public:
    servicios(string nombre, string codigoArea, string descripcion) {
        this->nombre = nombre;
        this->codigoArea = codigoArea;
        this->descripcion = descripcion;
        tiquetes = 0;
    }

    ~servicios() {}

    string getNombre() {
        return nombre;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    string getCodigoArea(){
        return codigoArea;
    }
    void setCodigoArea(string codigoArea){
        this->codigoArea = codigoArea;
    }
    void tiqueteAgregado() {
        tiquetes += 1;
    }
    int getTiquetes() {
        return tiquetes;
    }
};

#endif // SERVICIOS_H
