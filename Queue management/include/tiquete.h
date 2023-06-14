#ifndef TIQUETE_H
#define TIQUETE_H

/*
En esta clase se crea un tiquete y sus atributos, como el nombre. Lo primero que debe hacer el controlador es
llamar el constructor de esta clase, el cual crea un nuevo tiquete.
Autores:
Adrián Josué Vega Barrantes
*/

class tiquete {
private:
    time_t horaLlegada;
    time_t horaAtencion;
    string nombre;

public:
    tiquete(time_t horaLlegada, string nombre) {
        this->horaLlegada = horaLlegada;
        this->nombre = nombre;
    }

    time_t getHoraLlegada() {
        return horaLlegada;
    }

    void setHoraLlegada(time_t horaLlegada) {
        this->horaLlegada = horaLlegada;
    }

    time_t getHoraAtencion() {
        return horaAtencion;
    }

    void setHoraAtencion(time_t horaAtencion) {
        this->horaAtencion = horaAtencion;
    }

    string getNombre() {
        return nombre;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }
};

#endif // TIQUETE_H
