#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>

using namespace std;

template <typename T>
class Lista {
public:
    
    Lista();
    ~Lista();

    
    int longitud();

    
    void agregarAtras(const T& elemento);

    T iesimo(const int posicion);
    
    void borrarUltimo();
    
    void borrarIesimo(const int posicion);
    
    T cursor();
    
    void avanzar();
    
    void retroceder();

private:
    struct nodo {
        nodo(T un_elemento) : elemento(un_elemento), siguiente(nullptr), anterior(nullptr) {}

        T elemento;
        nodo* siguiente;
        nodo* anterior; 
    };

    nodo* _primero;
    int _longitud;
    nodo* _cursor;
};

template <typename T>
Lista<T>::Lista() : _primero(nullptr), _longitud(0), _cursor(nullptr) {}

template <typename T>
int Lista<T>::longitud() {
    return _longitud;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elemento) {
    nodo * nuevo = new nodo(elemento);

    if (_primero == nullptr) {
        _primero = nuevo;
        _cursor = nuevo; 
    } else {
        nodo* actual = _primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->anterior = actual; 
    }
    _longitud++;
}

template <typename T>
T Lista<T>::iesimo(const int posicion) {
    nodo* actual = _primero;
    int i = 0;
    while (i < posicion){
        actual = actual->siguiente;
        i++;
    }
    return actual->elemento;
}

template <typename T>
void Lista<T>::borrarIesimo(const int posicion) {
    

    nodo* a_borrar;

    if (posicion == 0) { 
        a_borrar = _primero;
        _primero = _primero->siguiente;
        if (_primero != nullptr) {
            _primero->anterior = nullptr; 
        }
    } else {
        nodo* nodo_anterior = _primero;
        int i = 0;
        while (i < posicion - 1) {
            nodo_anterior = nodo_anterior->siguiente;
            i++;
        }
        a_borrar = nodo_anterior->siguiente;
        nodo_anterior->siguiente = a_borrar->siguiente;
        if (a_borrar->siguiente != nullptr) {
            a_borrar->siguiente->anterior = nodo_anterior; 
        }
    }
    if (_cursor == a_borrar) {
        if (a_borrar->siguiente != nullptr) { 
            _cursor = a_borrar->siguiente;
        } else if (a_borrar->anterior != nullptr) { 
            _cursor = a_borrar->anterior;
        } else { 
            _cursor = nullptr;
        }
    }

    delete a_borrar;
    _longitud--;
}

template <typename T>
void Lista<T>::borrarUltimo() {
    
    borrarIesimo(_longitud - 1);
}

template <typename T>
T Lista<T>::cursor() {
    return _cursor->elemento;
}

template <typename T>
void Lista<T>::avanzar() {
    if (_cursor != nullptr && _cursor->siguiente != nullptr) {
        _cursor = _cursor->siguiente;
    }
}

template <typename T>
void Lista<T>::retroceder() {
    if (_cursor != nullptr && _cursor->anterior != nullptr) {
        _cursor = _cursor->anterior;
    }
}

template <typename T>
Lista<T>::~Lista() {
    nodo* actual = _primero;
    while (actual != nullptr) {
        nodo* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    _primero = nullptr;
    _longitud = 0;
    _cursor = nullptr; 
}

#endif