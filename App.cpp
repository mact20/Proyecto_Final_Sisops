#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
Mauricio Alejandro Garza Martínez A00825042
Lourdes Montserrat Cruz Castillo A01283101
Marco Aurelio Cepeda Treviño A00824947
*/

int main() {
  //Se va implementar un menu de opciones para ver el control de este logaritmo
  string alg; //string que va a guardar el nombre del algoritmo
  char letras[10]={'A','B','C','D','E','F','G','H','I','J'}; //Procesos
  char solicitudes[30]; //Lista de solicitudes
  char marcos[5]; //Aqui se van a asignar los marcos
  int nMarcos=5; //No. de marcos disponibles
  queue<char> marcoFIFO; //Queue que nos ayudara en la implementacion FIFO
  char marcoLRU[30]; //Arreglo aud nox ayudara en la implementacion de LR
  
  for(int i=0;i<30;i++){
    solicitudes[i]= letras[rand() % 10];//Al arreglo solicitudes se le asigna una letra random del arreglo letras
  }
  //for(int i=0;i<30;i++){
  //  cout << solicitudes[i]; //Se imprime el arreglo de 30 letras
  //}
  
}