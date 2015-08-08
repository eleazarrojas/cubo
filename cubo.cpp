// Eleazar Rojas
// C.I. 12715403

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

  bool EsSolucion(char cubo[6][9]);
  void movimiento(char cubo[6][9], int i=6, int j=2);
  void backtraking(char cubo[6][9], int nivel, int pasos[8][2], int max);
  // Los 2 arreglos siguientes almacenan los posibles movimientos del cubo para 
  // generar nuevos estados, el arreglo c son las caras y el arreglo s es el sentido de giro
  int c[]={0,0,1,1,2,2,3,3,4,4,5,5};
  int s[]={0,1,0,1,0,1,0,1,0,1,0,1};
  int pasos[25][2]; 

class cubo_class{ //Creamos la clase cubo.
  public:
  // Esta función se encarga de las rotaciones de las caras
  // tambien se encarga de rotar las posiciones adyacentes a la cara rotada.
  // La rotación viene dada de la siguiente manera:
  // 0 para el sentido horario y 1 para el sentido anti-horario.
  void movimiento(char cubo[6][9], int L, int sentido){ 
    char aux1, aux2, aux3;
    if(sentido==0){
      aux1=cubo[L][0];
      aux2=cubo[L][1];
      cubo[L][1]=cubo[L][3];
      cubo[L][0]=cubo[L][6];
      cubo[L][3]=cubo[L][7];
      cubo[L][6]=cubo[L][8];
      cubo[L][7]=cubo[L][5];
      cubo[L][8]=cubo[L][2];
      cubo[L][5]=aux2;
      cubo[L][2]=aux1;
    }
    if(sentido==1){
      aux1=cubo[L][0];
      aux2=cubo[L][1];
      cubo[L][0]=cubo[L][2];
      cubo[L][1]=cubo[L][5];
      cubo[L][2]=cubo[L][8];
      cubo[L][5]=cubo[L][7];
      cubo[L][8]=cubo[L][6];
      cubo[L][7]=cubo[L][3];
      cubo[L][6]=aux1;
      cubo[L][3]=aux2;
    }
    if(sentido==0){
      switch(L){
        case 0:
          aux1=cubo[1][0];
          aux2=cubo[1][3];
          aux3=cubo[1][6];
          cubo[1][0]=cubo[3][6];
          cubo[1][3]=cubo[3][7];
          cubo[1][6]=cubo[3][8];
          cubo[3][6]=cubo[2][8];
          cubo[3][7]=cubo[2][5];
          cubo[3][8]=cubo[2][2];
          cubo[2][2]=cubo[5][0];
          cubo[2][5]=cubo[5][1];
          cubo[2][8]=cubo[5][2];
          cubo[5][2]=aux1;
          cubo[5][1]=aux2;
          cubo[5][0]=aux3;
        break;
        case 1:
          aux1=cubo[0][2];
          aux2=cubo[0][5];
          aux3=cubo[0][8];
          cubo[0][2]=cubo[5][2];
          cubo[0][5]=cubo[5][5];
          cubo[0][8]=cubo[5][8];
          cubo[5][2]=cubo[4][6];
          cubo[5][5]=cubo[4][3];
          cubo[5][8]=cubo[4][0];
          cubo[4][6]=cubo[3][2];
          cubo[4][3]=cubo[3][5];
          cubo[4][0]=cubo[3][8];
          cubo[3][2]=aux1;
          cubo[3][5]=aux2;
          cubo[3][8]=aux3;
        break;
        case 2:
          aux1=cubo[4][2];
          aux2=cubo[4][5];
          aux3=cubo[4][8];
          cubo[4][2]=cubo[5][6];
          cubo[4][5]=cubo[5][3];
          cubo[4][8]=cubo[5][0];
          cubo[5][6]=cubo[0][6];
          cubo[5][3]=cubo[0][3];
          cubo[5][0]=cubo[0][0];
          cubo[0][6]=cubo[3][6];
          cubo[0][3]=cubo[3][3];
          cubo[0][0]=cubo[3][0];
          cubo[3][6]=aux1;
          cubo[3][3]=aux2;
          cubo[3][0]=aux3;
        break;
        case 3:
          aux1=cubo[2][0];
          aux2=cubo[2][1];
          aux3=cubo[2][2];
          cubo[2][0]=cubo[0][0];
          cubo[2][1]=cubo[0][1];
          cubo[2][2]=cubo[0][2];
          cubo[0][0]=cubo[1][0];
          cubo[0][1]=cubo[1][1];
          cubo[0][2]=cubo[1][2];
          cubo[1][0]=cubo[4][0];
          cubo[1][1]=cubo[4][1];
          cubo[1][2]=cubo[4][2];
          cubo[4][0]=aux1;
          cubo[4][1]=aux2;
          cubo[4][2]=aux3;
        break;
        case 4:
          aux1=cubo[1][2];
          aux2=cubo[1][5];
          aux3=cubo[1][8];
          cubo[1][2]=cubo[5][8];
          cubo[1][5]=cubo[5][7];
          cubo[1][8]=cubo[5][6];
          cubo[5][8]=cubo[2][6];
          cubo[5][7]=cubo[2][3];
          cubo[5][6]=cubo[2][0];
          cubo[2][6]=cubo[3][0];
          cubo[2][3]=cubo[3][1];
          cubo[2][0]=cubo[3][2];
          cubo[3][0]=aux1;
          cubo[3][1]=aux2;
          cubo[3][2]=aux3;
        break;
        case 5:
          aux1=cubo[2][8];
          aux2=cubo[2][7];
          aux3=cubo[2][6];
          cubo[2][8]=cubo[4][8];
          cubo[2][7]=cubo[4][7];
          cubo[2][6]=cubo[4][6];
          cubo[4][8]=cubo[1][8];
          cubo[4][7]=cubo[1][7];
          cubo[4][6]=cubo[1][6];
          cubo[1][8]=cubo[0][8];
          cubo[1][7]=cubo[0][7];
          cubo[1][6]=cubo[0][6];
          cubo[0][8]=aux1;
          cubo[0][7]=aux2;
          cubo[0][6]=aux3;
        break;
      }
    }
    if(sentido==1){
      switch(L){
        case 0:
          aux1=cubo[2][2];
          aux2=cubo[2][5];
          aux3=cubo[2][8];
          cubo[2][2]=cubo[3][8];
          cubo[2][5]=cubo[3][7];
          cubo[2][8]=cubo[3][6];
          cubo[3][8]=cubo[1][6];
          cubo[3][7]=cubo[1][3];
          cubo[3][6]=cubo[1][0];
          cubo[1][6]=cubo[5][0];
          cubo[1][3]=cubo[5][1];
          cubo[1][0]=cubo[5][2];
          cubo[5][0]=aux1;
          cubo[5][1]=aux2;
          cubo[5][2]=aux3;
        break;
        case 1:
          aux1=cubo[0][2];
          aux2=cubo[0][5];
          aux3=cubo[0][8];
          cubo[0][2]=cubo[3][2];
          cubo[0][5]=cubo[3][5];
          cubo[0][8]=cubo[3][8];
          cubo[3][2]=cubo[4][6];
          cubo[3][5]=cubo[4][3];
          cubo[3][8]=cubo[4][0];
          cubo[4][6]=cubo[5][2];
          cubo[4][3]=cubo[5][5];
          cubo[4][0]=cubo[5][8];
          cubo[5][2]=aux1;
          cubo[5][5]=aux2;
          cubo[5][8]=aux3;
        break;
        case 2:
          aux1=cubo[4][2];
          aux2=cubo[4][5];
          aux3=cubo[4][8];
          cubo[4][2]=cubo[3][6];
          cubo[4][5]=cubo[3][3];
          cubo[4][8]=cubo[3][0];
          cubo[3][6]=cubo[0][6];
          cubo[3][3]=cubo[0][3];
          cubo[3][0]=cubo[0][0];
          cubo[0][6]=cubo[5][6];
          cubo[0][3]=cubo[5][3];
          cubo[0][0]=cubo[5][0];
          cubo[5][6]=aux1;
          cubo[5][3]=aux2;
          cubo[5][0]=aux3;
        break;
        case 3:
          aux1=cubo[2][0];
          aux2=cubo[2][1];
          aux3=cubo[2][2];
          cubo[2][0]=cubo[4][0];
          cubo[2][1]=cubo[4][1];
          cubo[2][2]=cubo[4][2];
          cubo[4][0]=cubo[1][0];
          cubo[4][1]=cubo[1][1];
          cubo[4][2]=cubo[1][2];
          cubo[1][0]=cubo[0][0];
          cubo[1][1]=cubo[0][1];
          cubo[1][2]=cubo[0][2];
          cubo[0][0]=aux1;
          cubo[0][1]=aux2;
          cubo[0][2]=aux3;
        break;
        case 4:
          aux1=cubo[1][2];
          aux2=cubo[1][5];
          aux3=cubo[1][8];
          cubo[1][2]=cubo[3][0];
          cubo[1][5]=cubo[3][1];
          cubo[1][8]=cubo[3][2];
          cubo[3][0]=cubo[2][6];
          cubo[3][1]=cubo[2][3];
          cubo[3][2]=cubo[2][0];
          cubo[2][6]=cubo[5][8];
          cubo[2][3]=cubo[5][7];
          cubo[2][0]=cubo[5][6];
          cubo[5][8]=aux1;
          cubo[5][7]=aux2;
          cubo[5][6]=aux3;
        break;
        case 5:
          aux1=cubo[2][6];
          aux2=cubo[2][7];
          aux3=cubo[2][8];
          cubo[2][6]=cubo[0][6];
          cubo[2][7]=cubo[0][7];
          cubo[2][8]=cubo[0][8];
          cubo[0][6]=cubo[1][6];
          cubo[0][7]=cubo[1][7];
          cubo[0][8]=cubo[1][8];
          cubo[1][6]=cubo[4][6];
          cubo[1][7]=cubo[4][7];
          cubo[1][8]=cubo[4][8];
          cubo[4][6]=aux1;
          cubo[4][7]=aux2;
          cubo[4][8]=aux3;
        break;
      }
    }
  }

  bool EsSolucion(char cubo[6][9]){ // comprueba si la posicion actual es solución y retorna verdad o falso.
    char r[]={'r','b','g','w','o','y'}; 
    bool salida=true;
    for(int i=0; i<6; i++){
      for(int j=0; j<9; j++){
        if(cubo[i][j]!=r[i]){salida= false;}
      }
    }
    return salida;
  }

  void backtraking(char cubo[6][9], int nivel, int pasos[8][2], int max){
    // Si es solución imprime en pantalla el numero de pasos usados para resolver el cubo.
    if (EsSolucion(cubo)){cout << nivel << endl;}

    // Si el estado de entrada aun no es solución y aun no se completan
    // el numero de pasos a evaluar se crea un nuevo estado y se llama
    // de nuevo a la función backtraking
    if ((!EsSolucion(cubo)) and (nivel < max)){
      for(int k=0; k<12 ;k++){ // esta instrucción genera los nuevos estados a evaluar.
        movimiento(cubo,c[k],s[k]); //
        pasos[nivel][0]=c[k];
        pasos[nivel][1]=s[k];
        nivel++;

        backtraking(cubo,nivel,pasos,max); // Se realiza el llamado al backtraking con un nuevo estado.

        // si el estado retornado es una solución, entonces se cancela la ejecución de nuevos estados
        // si nó, entonces se retrocede el estado evaluado. 
        if (EsSolucion(cubo)){
          k=12;
        }else{
          // los siguientes IF devuelven el cubo a la posición anterior.
          // Si se habia rotado en sentido horario, ahora se gira en sentido anti-horario
          if(s[k]==0){movimiento(cubo,c[k],1);} 
          if(s[k]==1){movimiento(cubo,c[k],0);}
          pasos[nivel][0]=-1;
          pasos[nivel][1]=-1;
          nivel--;
        }
      }
    }
    // Esta linea verifica si no pudo realizar el cubo e incrementa el numeros de pasos a evaluar.
    if((!EsSolucion(cubo)) and (nivel == 0)){max++; backtraking(cubo, nivel,pasos,max);}
  }
};

int main(){
  cubo_class miCUBO;
  int i, j;
  char cubo[6][9];
  int nivel=0, max=1;
  for(i=0; i<25; i++){
    pasos[i][0]=-1;
    pasos[i][1]=-1;
  }
  // El siguiente for realiza la lectura de las posiciones iniciales del cubo
  for(i=0; i<6; i++){
    for(j=0; j<9; j++){
      cin >> cubo[i][j];
    }
  }
  // La siguiente linea realiza el llamado a la función backtraking
  // contenida en la clase miCUBO, para eso requiere que se le suministre 
  // el cubo a resolver, el nivel que se encarga de almacenar el numero de pasos 
  miCUBO.backtraking(cubo,nivel,pasos,max); // Llamada al Backtraking.
  // El siguiente for se encarga de mostrar en pantalla los pasos a seguir para resolver el cubo
  i=0;
  while(pasos[i][0]!=-1){ 
    switch(pasos[i][0]){
      case 0:
        cout << "r " << pasos[i][1] << endl;
      break;
      case 1:
        cout << "b " << pasos[i][1] << endl;
      break;
      case 2:
        cout << "g " << pasos[i][1] << endl;
      break;
      case 3:
        cout << "w " << pasos[i][1] << endl;
      break;
      case 4:
        cout << "o " << pasos[i][1] << endl;
      break;
      case 5:
        cout << "y " << pasos[i][1] << endl;
      break;
    }
    i++;
  }
  return 0;
}
