#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
int pontosJogador = 0;
int pontosMaquina = 0;

string selecionarPrimeiro();
int jogadorPrimeiro();
int maquinaPrimeiro();
void localDeChuteMaquina(int opcao, int random);
void localDeChuteJogador(int opcao, int random);


int main() {
  
  int jogador;
  int maquina;
  int teste = 9;
  int i = 0;
  string random;
  srand(time(NULL));

  while(i==0){ 
  random = selecionarPrimeiro();

  if(random == "jogador"){
    cout<< "jogador primeiro" << endl;
    for(int i = 0; i < 5;i++){
      jogadorPrimeiro();
    }
  cout<< "vez da maquina" << endl;
    for(int i = 0; i < 5;i++){
    maquinaPrimeiro();
   }
    
    
    
  } else if(random == "maquina"){
    cout<< "maquina primeiro" << endl;
    for(int i = 0; i < 5;i++){
    maquinaPrimeiro();
   }
  cout << "vez do jogador" << endl;
      for(int i = 0; i < 5;i++){
      jogadorPrimeiro();
    }
  }

  if(pontosJogador > pontosMaquina){
    cout << "Parabens Jogador Você ganhou!!!!!!" <<endl;
    cout <<  "deseja jogar denovo?" << endl;
    cout << "1 - sim" << endl;
    cout << "2 - nao" << endl;
    cin >> teste;

    if(teste == 2){
      i =1;
    }else{
      pontosJogador = 0;
      pontosMaquina = 0;
    }
    
  } else if(pontosMaquina > pontosJogador){
    cout << "A maquina venceu" << endl;
    cout <<  "deseja jogar denovo?" << endl;
    cout << "1 - sim" << endl;
    cout << "2 - nao" << endl;
    cin >> teste;
     if(teste == 2){
      i =1;
    }else{
        pontosJogador = 0;
      pontosMaquina = 0;
    }
    
  } else if( pontosJogador == pontosMaquina){
    int pontosJ = 0, pontosM=0;
    int doisChutes = 0;
    while(doisChutes == 0){ 
    pontosJ =jogadorPrimeiro();
    pontosM = maquinaPrimeiro();

    if( pontosJ > pontosM){
      doisChutes =1;
     cout << "Parabens Jogador Você ganhou!!!!!!" <<endl;
    cout <<  "deseja jogar denovo?" << endl;
    cout << "1 - sim" << endl;
    cout << "2 - nao" << endl;
    cin >> teste;

    if(teste == 2){
      i =1;
    }else{
       pontosJogador = 0;
      pontosMaquina = 0;
    }
    }else if(pontosM > pontosJ){
      doisChutes =1;
        cout << "A maquina venceu" << endl;
    cout <<  "deseja jogar denovo?" << endl;
    cout << "1 - sim" << endl;
    cout << "2 - nao" << endl;
    cin >> teste;
     if(teste == 2){
      i =1;
    }else{
        pontosJogador = 0;
      pontosMaquina = 0;
    }
    }else if(pontosJ == pontosM){
      cout<< "reiniciando as cobrancas alternadas" << endl;
    }
  }
    }
  } 
}


 string selecionarPrimeiro(){
    
  int random;
  string selecionado;
    
  random = (rand() % 2) + 1;

  if(random == 1){
    selecionado = "jogador";
    
  }else{
    selecionado = "maquina";
  }
  
  
  return selecionado; 
}

int jogadorPrimeiro(){
  int pontuou = 0;
  
  int random;
  int opcao;
  random = (rand() % 5) + 1;

  cout << "escolha uma opcao de cobranca" << endl ;
  cout << "1-Canto Superior Esquerdo" << endl;
  cout << "2-Canto Inferior Esquerdo" << endl;
  cout << "3- Centro" << endl;
  cout << "4-Canto Superior Direito" << endl;
  cout << " 5-Canto Inferior Direito" << endl ;

  cin >> opcao;

  if (opcao != random){
    pontosJogador = pontosJogador + 1;
    pontuou =1;
  }

 localDeChuteJogador( opcao, random);
  

  return pontuou;
}

int maquinaPrimeiro(){
    int pontuou = 0;

  int random;
  int opcao;
  random = (rand() % 5) + 1;

  cout << "escolha uma opcao de defesa" << endl ;
  cout << "1-Canto Superior Esquerdo" << endl;
  cout << "2-Canto Inferior Esquerdo" << endl;
  cout << "3- Centro" << endl;
  cout << "4-Canto Superior Direito" << endl;
  cout << " 5-Canto Inferior Direito" << endl ;

  cin >> opcao;

  if (opcao != random){
    pontosMaquina = pontosMaquina + 1;
    pontuou = 1;
  }
  
   localDeChuteMaquina( opcao, random);


  return pontuou;
}


void localDeChuteJogador(int opcao, int random){
  if(opcao == 1){
    cout<< "o jogador chutou no canto superior esquerdo e ";
  }else if(opcao == 2){
        cout<< "o jogador chutou no canto inferior esquerdo e ";
  }else if(opcao ==3){
        cout<< "o jogador chutou no centro e ";
  }else if(opcao == 4){
        cout<< "o jogador chutou no canto superior direito e ";
  }else{
        cout<< "o jogador chutou no canto inferior direito e ";
  }

  
  if(random == 1){
      cout << "a maquina defendeu no canto superior esquerdo"<<endl;
  }else if(random == 2){
          cout << "a maquina defendeu no canto inferior esquerdo" << endl;
  }else if(random ==3){
          cout << "a maquina defendeu no centro" << endl;
  }else if(random == 4){
          cout << "a maquina defendeu no canto superior direito" << endl;
  }else{
          cout << "a maquina defendeu no canto inferior direito" << endl;
  }
}

void localDeChuteMaquina(int opcao, int random){
  if(opcao == 1){
    cout<< "o jogador defendeu no canto superior esquerdo e ";
  }else if(opcao == 2){
        cout<< "o jogador defendeu no canto inferior esquerdo e ";
  }else if(opcao ==3){
        cout<< "o jogador defendeu no centro e ";
  }else if(opcao == 4){
        cout<< "o jogador defendeu no canto superior direito e ";
  }else{
        cout<< "o jogador defendeu no canto inferior direito e ";
  }

  
  if(random == 1){
      cout << "a maquina chutou no canto superior esquerdo"<<endl;
  }else if(random == 2){
          cout << "a maquina chutou no canto inferior esquerdo" << endl;
  }else if(random ==3){
          cout << "a maquina chutou no centro" << endl;
  }else if(random == 4){
          cout << "a maquina chutou no canto superior direito" << endl;
  }else{
          cout << "a maquina chutou no canto inferior direito" << endl;
  }
}