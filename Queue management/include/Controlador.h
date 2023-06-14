#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "servicios.h"
#include "area.h"
#include <string.h>

/*
Esta clase se encarga de unir la lógica de cada objeto creado, implementando los métodos de cada una para que los
requerimientos del sistema funcionen adecuadamente.
Autores:
Jose Manuel Granados V
Adrián Josué Vega Barrantes
*/

using namespace std;

class Controlador {
private:
    List<servicios*> *listaDeServicios;
    List<area*> *listaAreas;
    int consecutivoTiquetes;
    int totalTiquetesSistema;

public:
    Controlador() {
        listaDeServicios = new ArrayList<servicios*>(10);
        listaAreas = new ArrayList<area*>(10);
        consecutivoTiquetes = 0;
    }
    ~Controlador() {
        for (listaDeServicios->goToStart(); !listaDeServicios->atEnd(); listaDeServicios->next())
            delete listaDeServicios->getElement();
        delete [] listaDeServicios;
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next())
            delete listaAreas->getElement();
        delete [] listaAreas;
    }
    tiquete* generarTiquete(servicios *servicio, int prioridad) {
        tiquete *nuevoTiquete = nullptr;
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next()){
            if (listaAreas->getElement()->getCodigo() == servicio->getCodigoArea()) {
                string nombre = servicio->getCodigoArea();
                string codigo = "";
                int numero = consecutivoTiquetes;
                codigo += nombre + to_string(numero);
                nuevoTiquete = new tiquete(time(0), codigo);
                consecutivoTiquetes = (consecutivoTiquetes + 1) % 100;
                listaAreas->getElement()->agregarTiquete(nuevoTiquete, prioridad);
                servicio->tiqueteAgregado();
                totalTiquetesSistema++;
            }
        }
        return nuevoTiquete;
    }
    string atender(area *area, string ventanilla) {
        tiquete *atendido;
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next()){
            if (listaAreas->getElement()->getCodigo() == area->getCodigo())
                atendido = listaAreas->getElement()->atender(ventanilla);
        }
        if (atendido != nullptr)
            return "Atendiendo el tiquete: " + atendido->getNombre();
        else
            return "La fila está vacía.";
    }
    bool agregarArea(string nombre, int ventanillas, string descripcion, string codigo){
        area *nuevaArea = nullptr;
        if (listaAreas->getSize() == 0 ) {
            nuevaArea = new area(nombre, ventanillas, descripcion, codigo);
            listaAreas->append(nuevaArea);
            return true;
        }
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next())
            if (listaAreas->getElement()->getCodigo() == codigo)
                return false;
        nuevaArea = new area(nombre, ventanillas, descripcion, codigo);
        listaAreas->append(nuevaArea);
        return true;
    }
    bool eliminarArea(string codigo){
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next())
            if (listaAreas->getElement()->getCodigo() == codigo) {
                listaAreas->remove();
                return true;
            }

        return false;
    }
    void printAreas() {
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next()) {
            cout << listaAreas->getPos() + 1 << ")";
            listaAreas->getElement()->print();
        }
    }

    int getSizeAreas() {
        return listaAreas->getSize();
    }
    area* getArea(int pos) {
        listaAreas->goToPos(pos);
        return listaAreas->getElement();
    }
    int getCantidadTiquetes() {
        return totalTiquetesSistema;
    }
    int cantidadVentanasEnArea(area *area){
        return area->getCantidadVentanas();
    }
    ventanilla* getVentana(area *area, int pos){
        return area->getVentana(pos);
    }
    void esperaPromedio() {
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next())
            cout << listaAreas->getElement()->getNombre() << ") " << listaAreas->getElement()->esperaPromedio() << endl;
    }
    void totalTiquetes(){
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next()) {
            string codigoArea = listaAreas->getElement()->getCodigo();
            int cantidadTiquetes = listaAreas->getElement()->getCantidadTiquetes();
            cout << "Area: " << codigoArea << ", cantidad total de tiquetes: " << cantidadTiquetes << endl;
        }
    }
    void totalTiquetesVentana() {
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next()) {
            string codigoArea = listaAreas->getElement()->getCodigo();
            string tiquetesVentanillas = listaAreas->getElement()->tiquetesPorVentana();
            cout << "Area: " << codigoArea << ", tiquetes por ventanilla: \n" << tiquetesVentanillas << endl;
        }
    }
    void totalTiquetesServicio() {
        for (listaDeServicios->goToStart(); !listaDeServicios->atEnd(); listaDeServicios->next()) {
            cout << listaDeServicios->getPos() + 1 << ") " << listaDeServicios->getElement()->getNombre() << " - " <<listaDeServicios->getElement()->getTiquetes() << endl;
        }
    }
    int tiquetesEspeciales() {
        int totalEspeciales = 0;
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next())
            totalEspeciales += listaAreas->getElement()->getCantidadTiquetesEspeciales();
        return totalEspeciales;
    }

    //Servicios
    bool agregarServicios(string nombre, string area, string descripcion) {
        for (listaDeServicios->goToStart(); !listaDeServicios->atEnd(); listaDeServicios->next()) {
            if (listaDeServicios->getElement()->getNombre() == nombre) {
                return false;
            }
        }
        for (listaAreas->goToStart(); !listaAreas->atEnd(); listaAreas->next()) {
            if (listaAreas->getElement()->getCodigo() == area) {
                servicios *nuevoServicio = new servicios(nombre, area, descripcion);
                listaDeServicios->append(nuevoServicio);
                return true;
            }
        }
        return false;
    }

    bool eliminarServicio(string nombre) {
        for (listaDeServicios->goToStart(); !listaDeServicios->atEnd(); listaDeServicios->next())
            if (listaDeServicios->getElement()->getNombre() == nombre) {
                delete listaDeServicios->remove();
                return true;
            }
        return false;
    }
    void reordenarServicios(int posOriginal, int posDestino) {
        listaDeServicios->goToPos(posOriginal);
        servicios *tempOriginal = listaDeServicios->getElement();
        listaDeServicios->goToPos(posDestino);
        servicios *tempDestino = listaDeServicios->getElement();

        listaDeServicios->goToPos(posOriginal);
        listaDeServicios->inserto(tempDestino);

        listaDeServicios->goToPos(posDestino);
        listaDeServicios->inserto(tempOriginal);
    }

    void printServicios() {
        for (listaDeServicios->goToStart(); !listaDeServicios->atEnd(); listaDeServicios->next())
            cout << listaDeServicios->getPos() + 1 << ") " <<listaDeServicios->getElement()->getNombre() << endl;
    }
    void printVentanas(area *area) {
        area->printVentanillas();
    }

    int getSizeServicios() {
        return listaDeServicios->getSize();
    }

    servicios* getServicio(int pos) {
        listaDeServicios->goToPos(pos);
        return listaDeServicios->getElement();
    }

};

#endif // CONTROLADOR_H
