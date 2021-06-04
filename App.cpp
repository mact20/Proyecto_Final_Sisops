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
  char marcos[5]={' ',' ',' ',' ',' '}; //Aqui se van a asignar los marcos
  int nMarcos=5; //No. de marcos disponibles
  queue<char> marcoFIFO; //Queue que nos ayudara en la implementacion FIFO
  queue<char> marcoLRU; //Arreglo aud nox ayudara en la implementacion de LRU
  queue<char> auxLRU;//queue auxiliar para el algoritmo de LRU
  srand (time(NULL)); //Se reinicia la función de random
  bool cond=false;//Condicion universal
  bool fallo=false; //Indica cuando hay un fallo de pagina
  float nFallos = 0; //Numero de fallos de pagina

  //En consola escribe el algoritmo que se va a usae FIFO o LRU
  cout<<"¿Qué algoritmo se va a usar?"<<endl;
  cin>>alg;
  
  for(int i=0;i<30;i++){
    solicitudes[i]= letras[rand() % 10];//Al arreglo solicitudes se le asigna una letra random del arreglo letras
  }
  cout<<"Las solicitudes que se van a aplicar tienen este arreglo"<<endl;
  for(int i=0;i<30;i++){
    cout << solicitudes[i]<<" "; //Se imprime el arreglo de 30 letras
  }
  cout<<endl;
  
  //Algoritmo FIFO
  if(alg=="FIFO"){
    for(int i=0;i<30;i++){

      for(int j=0;j<5;j++){ //Checamos si el proceso se encuentra en los marcos de pagina
        if(solicitudes[i]==marcos[j])
          cond=true;
      }

       //Si se encuentra entonces no hacemos nada
      if(cond){
      }

      //Si no se encuentra entonces lo colocamos
      else{
        fallo=true;//Hay fallo de pagina
        nFallos++;//Sumamos uno a los fallos
        //Checamos que no haya marcos vacios
        if(nMarcos>0){
          for(int j=0;j<5;j++){
            if(marcos[j]==' '){
              marcos[j]=solicitudes[i]; //Metemos el proceso en el marco de pagina
              marcoFIFO.push(solicitudes[i]);//Lo metemos tambien en el queue
              nMarcos--;//Este numero baja a uno
              break;
            }
          }
        }
        //Si no hay marcos vacios va a haber un remplazo
        else{
          for(int j=0;j<5;j++){ //Checamos en que marco esta el mas antiguo
            if(marcos[j]==marcoFIFO.front()){
              marcos[j]=solicitudes[i];//Se remplaza el mas antiguo
              marcoFIFO.pop();//Quitamos este en el queue
              marcoFIFO.push(solicitudes[i]);//Lo agrefamos al queue
              break;
            }
      }
        }
      }
      //Desplegamos resultados
      cout<<"Tiempo ="<<i+1<<endl;
      for(int j=0;j<5;j++){
        cout<<"Marco "<<j+1<<":"<<marcos[j]<<endl;
      }
      if(fallo){
        cout<<"Hay Fallo de Pagina"<<endl;
        cout<<"Numeros de Fallo de pagina: "<< nFallos<< endl;
      }
      //reiniciamos variables
      cond=false;
      fallo=false;
    }
  }

  else if(alg=="LRU"){
    for(int i=0;i<30;i++){

      for(int j=0;j<5;j++){ //Checamos si el proceso se encuentra en los marcos de pagina
        if(solicitudes[i]==marcos[j])
          cond=true;
      }

       //Si se encuentra entonces cambiamos el queue para que se actualice
      if(cond){
        //pasar marcoLRU a auxLRU
        while(!marcoLRU.empty()){
          auxLRU.push(marcoLRU.front());
          marcoLRU.pop();
        }

        //Actualizamos marcoLRU
        while(!auxLRU.empty()){
          if(solicitudes[i] != auxLRU.front()){
            marcoLRU.push(auxLRU.front());//Si no es igual lo colocamos a marcoLRU
            auxLRU.pop();
          }
          else{
            auxLRU.pop();//Si es igual solo hacemos pop al auxLRU
          }
        }
        marcoLRU.push(solicitudes[i]); //Acabando hacemso push a la solicitud actual 
      }

      //Si no se encuentra entonces lo colocamos
      else{
        fallo=true;//Hay fallo de pagina
        nFallos++;//Sumamos uno a los fallos
        //Checamos que no haya marcos vacios
        if(nMarcos>0){
          for(int j=0;j<5;j++){
            if(marcos[j]==' '){
              marcos[j]=solicitudes[i]; //Metemos el proceso en el marco de pagina
              marcoLRU.push(solicitudes[i]);//Lo metemos tambien en el queue
              nMarcos--;//Este numero baja a uno
              break;
            }
          }
        }
        //Si no hay marcos vacios va a haber un remplazo
        else{
          for(int j=0;j<5;j++){ //Checamos en que marco esta el ultimo que se uso
            if(marcos[j]==marcoLRU.front()){
              marcos[j]=solicitudes[i];//Se remplaza el ultimo que se uso
              marcoLRU.pop();//Quitamos este en el queue
              marcoLRU.push(solicitudes[i]);//Lo agregamos al queue
              break;
            }
          }
        }
      }

      //Desplegamos resultados
      cout<<"Tiempo = "<<i+1<<endl;
      for(int j=0;j<5;j++){
        cout<<"Marco "<<j+1<<":"<<marcos[j]<<endl;
      }
      if(fallo){
        cout<<"Hay Fallo de Pagina"<<endl;
        cout<<"Numeros de Fallo de pagina: "<< nFallos<< endl;
      }
      //reiniciamos variables
      cond=false;
      fallo=false;
    }
  }
  
  float rendimiento=1-nFallos/30; //Calculamos rendimiento
  cout<<"Rendimiento : "<<rendimiento*100<<"%"<<endl;
}