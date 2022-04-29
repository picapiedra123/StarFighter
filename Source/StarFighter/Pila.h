// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template<typename T>
class STARFIGHTER_API Pila
{
private:
	T* Datos;
	int Cima;
	const int numeroElementos;
public:
	//	Pila(int _numeroElementos) : numeroElementos(_numeroElementos) {
	//	Datos = new T[numeroElementos];
	//	Cima = -1;
	//}
	Pila(int = 10);
//	~Pila() { delete[] Datos; }
//	~Pila(){};
	void Insertar(T c);
	T Sacar();
	bool Vacia();
	bool Llena();
};

template < typename T >
Pila<T>::Pila(int s) : numeroElementos(s > 0 ? s : 10), // valida el tamaño
Cima(-1), // al principio la Pila está vacía
Datos(new T[numeroElementos]) // asigna memoria para los elementos
{
}


template<typename T>
void Pila<T>::Insertar(T elementoInsertar) {
	if (!Llena()) {
		Cima++;
		Datos[Cima] = elementoInsertar;

		UE_LOG(LogTemp, Warning, TEXT("Se insertado elemento satisfactoriamente en la pila"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No se pudo ingresar el elemento en la pila"));
	}
}

template<typename T>
T Pila<T>::Sacar() {
	if (!Vacia()) {
		T elementoSacar = Datos[Cima];
		Cima--;
		return elementoSacar;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No se pudo sacar el elemento en la pila"));
	}
}

template<typename T>
bool Pila<T>::Vacia() {
	if (Cima < 0) {
		return true;
	}
	else
		return false;
}

template<typename T>
bool Pila<T>::Llena() {
	if (Cima < numeroElementos - 1) {
		return false;
	}
	else {
		return true;
	}
}
