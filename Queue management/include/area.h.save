#ifndef AREA_H
#define AREA_H
#include <string>
#include "time.h"
#include "List.h"
#include "ArrayList.h"
#include "PriorityQueue.h"
#include "LinkedPriorityQueue.h"
#include "servicios.h"
#include "ventanilla.h"
#include "tiquete.h"

/*
En esta clase se crea un área y sus atributos, como el nombre y código. Lo primero que debe hacer el controlador es
llamar el constructor de esta clase, el cual crea una nueva área.
Autores:
Jose Manuel Granados V
Adrián Josué Vega Barrantes
*/
using namespace std;


class area {
private:
    int tiquetesEspeciales = 0;
    int cantidadTiquetes = 0;
    int tiempoEspera = 0;
    string descripcion;
    string nombre;
    string codigo;
    int ventanas;
    LinkedPriorityQueue<tiquete*> *fila;
    List<ventanilla*> *listaVentanillas;

public:
    area(string nombre, int ventanas, string descripcion, string codigo) {
        this->descripcion = descripcion;
        this->codigo = codigo;
        this->ventanas = ventanas;
        this->nombre = nombre;
        fila = new LinkedPriorityQueue<tiquete*>(2);
        listaVentanillas = new ArrayList<ventanilla*>(ventanas);
        for (int i = 0; i < ventanas; i++){
            string codigoVentana = "";
            codigoVentana += codigo + to_string(i);
            ventanilla *ventana = new ventanilla(codigoVentana, codigo);
            listaVentanillas->append(ventana);
        }
    }
    ~area() {
        for (listaVentanillas->goToStart(); !listaVentanillas->atEnd(); listaVentanillas->next())
            delete listaVentanillas->getElement();
        delete [] listaVentanillas;
        fila->~LinkedPriorityQueue();
        delete [] fila;
    }
    void setDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }
    string getDescripcion(){
        return descripcion;
    }
    string getNombre() {
        return nombre;
    }
    void setCodigo(string codigo) {
        this->codigo = codigo;
    }
    string getCodigo() {
        return codigo;
    }
    tiquete* getTiquete() {
        return fila->min();
    }
    int getCantidadTiquetes() {
        return cantidadTiquetes;
    }
    int getCantidadVentanas() {
        return ventanas;
    }
    int getCantidadTiquetesEspeciales(){
        return tiquetesEspeciales;
    }
    ventanilla* getVentana(int pos) {
        listaVentanillas->goToPos(pos);
        return listaVentanillas->getElement();
    }
    bool nuevaVentanilla(ventanilla *ventana) {
        if (listaVentanillas->contains(ventana))
            return false;
        listaVentanillas->append(ventana);
        return true;
    }
    bool eliminarVentanilla(ventanilla *ventana){
        for (listaVentanillas->goToStart(); !listaVentanillas->atEnd(); listaVentanillas->next())
            if (listaVentanillas->getElement()->getCodigoVentana() == ventana->getCodigoVentana()) {
                delete listaVentanillas->remove();
                return true;
            }
        return false;
    }
    void agregarTiquete(tiquete *tiquete, int prioridad) {
        if (prioridad == 0)
            tiquetesEspeciales++;
        fila->insert(tiquete, prioridad);
        cantidadTiquetes++;
    }
    tiquete* atender(string ventanilla){
        if (fila->isEmpty())
            return nullptr;
        tiquete *atendido;
        for (listaVentanillas->goToStart(); !listaVentanillas->atEnd(); listaVentanillas->next())
            if (listaVentanillas->getElement()->getCodigoVentana() == ventanilla) {
                atendido = fila->removeMin();
                listaVentanillas->getElement()->setUltimoTiquete(atendido);
            }
        time_t horaAtencion = time(0);
        atendido->setHoraAtencion(horaAtencion);
        tiempoEspera = atendido->getHoraAtencion() - atendido->getHoraLlegada();
        return atendido;
    }
    int esperaPromedio(){
        if (cantidadTiquetes == 0 || tiempoEspera == 0)
            return 0;
        return (tiempoEspera / cantidadTiquetes);
    }
    string tiquetesPorVentana(){
        string resultado = "";
        for (listaVentanillas->goToStart(); !listaVentanillas->atEnd(); listaVentanillas->next()) {
            resultado += listaVentanillas->getElement()->getCodigoVentana() + ") ";
            resultado += to_string(listaVentanillas->getElement()->getAtendidos()) + "\n";
        }
        return resultado;
    }
    void printVentanillas() {
        for (listaVentanillas->goToStart(); !listaVentanillas->atEnd(); listaVentanillas->next()) {
            cout << listaVentanillas->getPos() + 1 << ")" << listaVentanillas->getElement()->getCodigoVentana() << endl;
        }
    }
    void print() {
        cout << "Área: " << nombre << ", " << codigo << ", descripcion: " << descripcion <<
        ", cantidad de ventanillas: " << ventanas << ", tiquetes: ";
        fila->print();
    }
};

#endif // AREA_H
