/*
    PROJETO VOCALIZADOR 
    JULIANA DE ALMEIDA E LEONARDO OLIVEIRA
*/
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...

TMRpcm tmrpcm;   // create an object for use in this sketch

//int voz = 19; 
//Variaveis 

int tempo_delay = 1000; 

//Entradas
int botao1 = 14; // Controle do genero da voz 

int botao2 = 15; //A0
int botao3 = 16; //A0
int botao4 = 17; //A0
int botao5 = 18; //A0
int botao6 = 19; //A0
int botao7 = 2; //A0
int botao8 = 3; //
int botao9 = 5; //

//Saidas 

int led1 = 6; 
int led2 = 7; 
int led3 = 8; 

// the setup function runs once when you press reset or power the board
void setup() {
  // Inicializando os pinos dos botões 
    pinMode(botao1, INPUT);
    pinMode(botao2, INPUT);
    pinMode(botao3, INPUT);
    pinMode(botao4, INPUT);
    pinMode(botao5, INPUT);
    pinMode(botao6, INPUT);
    pinMode(botao7, INPUT);
    pinMode(botao8, INPUT);
    pinMode(botao9, INPUT);

    //saidas
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);

    //Configuração Auto falante
    tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc

     if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
      return;   // don't do anything more if not
     }
     tmrpcm.volume(1);
   
    Serial.begin(9600);
}

int GeneroVoz(){
     if(digitalRead(botao1) == LOW)   //Se estiver ativado retorna 1
          return 1; 
     else return 0; 
}

boolean LeBotao(int botao){
    if(digitalRead(botao) == LOW)
        return true; 
    else return false; 
}

void AcendeLed(int led){
    digitalWrite(led, HIGH); 
}

void ApagaLed(int led){
    digitalWrite(led, LOW); 
}

void ApagaTudo(){
    //digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
}

// ROTINA PRINCIPAL 
void loop() {   

      //São 8 opções de botões a partir do botão 2 

      switch(GeneroVoz()){
              case 0: 
                //Voz masculina
                //No case 0 ficam os ifs para a voz masculina 
                AcendeLed(led1);
                if(LeBotao(botao2)){     //Opção 1 
                    Serial.println("Botão 2 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  
                    tmrpcm.play("1.wav");
                    
                    delay(1000); 
                    while(LeBotao(botao2)) {}
                }

                if(LeBotao(botao3)){     //Opção 2 
                    Serial.println("Botão 3 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  

                    tmrpcm.play("2.wav");
                    delay(1000); 
                    while(LeBotao(botao3)) {}
                }

                if(LeBotao(botao4)){     //Opção 3
                    Serial.println("Botão 4 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  

                    tmrpcm.play("3.wav");
                    delay(1000); 
                    while(LeBotao(botao4)) {}
                }

                if(LeBotao(botao5)){     //Opção 4
                    Serial.println("Botão 5 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  

                    tmrpcm.play("4.wav");
                    delay(1000); 
                    while(LeBotao(botao5)) {}
                }

                if(LeBotao(botao6)){     //Opção 5
                    Serial.println("Botão 6 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  

                    tmrpcm.play("5.wav");
                    delay(1000); 
                    while(LeBotao(botao6)) {}
                }

                if(LeBotao(botao7)){     //Opção 6
                    Serial.println("Botão 7 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  

                    tmrpcm.play("6.wav");
                    delay(1000); 
                    while(LeBotao(botao7)) {}
                }

                if(LeBotao(botao8)){     //Opção 7
                    Serial.println("Botão 8 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  

                    tmrpcm.play("7.wav");
                    delay(1000); 
                    while(LeBotao(botao8)) {}
                }

                if(LeBotao(botao9)){     //Opção 8
                    Serial.println("Botão 9 Masculino");
                     
                    AcendeLed(led2);    //Ação do botão  

                    tmrpcm.play("8.wav");
                    delay(1000); 
                    while(LeBotao(botao9)) {}
                }
                break; 
              case 1:
                //Voz feminina
                //No case 1 ficam os ifs para a voz feminina
                ApagaLed(led1);

                if(LeBotao(botao2)){     //Opção 1 
                    Serial.println("Botão 2 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("1_f.wav");
                    delay(1000); 
                    while(LeBotao(botao2)) {}
                }

                if(LeBotao(botao3)){     //Opção 2 
                    Serial.println("Botão 3 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("2_f.wav");
                    delay(1000); 
                    while(LeBotao(botao3)) {}
                }

                if(LeBotao(botao4)){     //Opção 3
                    Serial.println("Botão 4 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("3_f.wav");
                    delay(1000); 
                    while(LeBotao(botao4)) {}
                }

                if(LeBotao(botao5)){     //Opção 4
                    Serial.println("Botão 5 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("4_f.wav");
                    delay(1000); 
                    while(LeBotao(botao5)) {}
                }

                if(LeBotao(botao6)){     //Opção 5
                    Serial.println("Botão 6 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("5_f.wav");
                    delay(1000); 
                    while(LeBotao(botao6)) {}
                }

                if(LeBotao(botao7)){     //Opção 6
                    Serial.println("Botão 7 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("6_f.wav");
                    delay(1000); 
                    while(LeBotao(botao7)) {}
                }

                if(LeBotao(botao8)){     //Opção 7
                    Serial.println("Botão 8 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("7_f.wav");
                    delay(1000); 
                    while(LeBotao(botao8)) {}
                }

                if(LeBotao(botao9)){     //Opção 8
                    Serial.println("Botão 9 Feminino");
                     
                    AcendeLed(led3);    //Ação do botão  

                    tmrpcm.play("8_f.wav");
                    delay(1000); 
                    while(LeBotao(botao9)) {}
                }
                break; 
          }

      ApagaTudo();   
                      
}
