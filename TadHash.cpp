#include <iostream>
using namespace std;

//LA GRACIA DE USAR UNA CLASE, ES QUE NO SE NECESITA LLAMAR POR PARAMETRO SIEMPRE AL HASH, DADO QUE AL
//SER UNA CLASE, LA PUEDO LLAMAR EN TODO EL ARCHIVO SIN NECESIDAD DE IR PASANDOME EL HASH COMO PARAMETRO.
//CON UTILIZAR THIS->LoQueMeInteresa YA QUEDA.


template <class T> //NOS CREA LA CLASE DE TIPO T
class nodoHash{ //CLASE DE LOS ELEMENTOS QUE VAN EN LA TABLAHASH, AL DEFINIRL LA LISTA SE CREA EL NODOHASH.

    public: //STRUCT (ME DEFINE LA ESTRUCTURA DE MI NODOHASH)
    int clave; //LA POS EXACTA CALCULADA EN LA CUADRATICA
    T dato;   // DATO ES EL PROMEDIO

    //LE DA FORMA A MI nodoHash
    CrearNodoHash(T dato1, T clave1){
        this->clave = clave1; //EN UN FUTURO SERA EL NOMBRE DE USUARIO CALCULADO POR LA CUADRATICA
        this->dato = dato1; // EN UN FUTURO SERA EL PROMEDIO
    }
};

template <class T> 
class HashCerrado{ //LA BOLSA

    private: //STRUCT (ME DEFINE LA ESTRUCTURA DE MI HASH

        nodoHash<T> *Tablahash; //vector que contiene al hash compuesto de cubos de tipo nodoHash
        int cantElementos; //cantElementos Actual.
        int largoEsperado; //Largo esperado del hash

        bool esPrimo(int largoEsperado){
            if(largoEsperado <=1){
                return false;
            }
            else{           
                for(int i=2; i<= largoEsperado/2;i++){
                    if(largoEsperado % i == 0){ //SI ESTO OCURRE ENTONCES EL NUM ES PAR
                        return false;
                    }
                }
                return true; // SI OCURRE ENTONCES ES IMPAR
            }
        }

        int sigPrimo(int largoEsperado){
            while(!esPrimo(++largoEsperado)); // SI DA FALSE AUMENTA UNO, ENTONCES GENERA QUE SEA IMPAR
            return largoEsperado;
        }
        
        int funcionHash(T dato, int largoEsperado){  //DARME EL VALOR DE LA POS
            //quadratica
            //TODO EL METODO PARA SACAR CUANTO ES posH
        }

        
        
    public:
        //LE DA VIDA A MI HASH, "LO CREA"
        crearHashCerrado(int largoEsperado1){
            this->largoEsperado = sigPrimo(largoEsperado1); //DEFINO EL LARGO DE LA TABLAHASH
            this->Tablahash = new nodoHash<T>* [this->largoEsperado]; //CREO LA TABLAHASH (VECTOR DE TIPO T) CON ESE LARGO (VECTOR)
            this->cantElementos = 0; //SETTEO LA CANT ELEMENTOS

            for(int i=0;i<this->largoEsperado;i++){ // ME ASEGURO QUE EL HASH ESTÉ VACIO.
                this->Tablahash[i] = NULL;
            }
        }

        //datoClave, ES LA KEY A CALCULAR PARA LA FHASH
        void agregarElemento(T datoClave, T datoAGuardar){
            nodoHash<T>* elementoNuevo = new nodoHash<T>(datoClave,datoAGuardar);
            this->Tablahash[funcionHash(datoClave)] = elementoNuevo;  
            this->cantElementos++;  
        } 

};


//DUDAS 
//PORQUE HACER SIGUIENTE PRIMO SI ME DAN EL LARGO EXACTO?? EVITO COLISIONES???

















































int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

 // //POS: ME DEVUELVE EL PROMEDIO DEL NOMBRE
        // T elemento(HashCerrado hash,T datoClave){
        //     return hash[funcionHash(datoClave, hash->largoEsperado)];
        // }
