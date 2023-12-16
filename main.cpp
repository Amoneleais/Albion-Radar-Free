#include "mbed.h"
#include "Jogador.h"
#include <chrono>
#include "Management.h"

using namespace std::chrono;
using namespace std;

// Blinking rate in milliseconds
#define BLINKING_RATE 1000ms

// Simple flag 
#define SAMPLE_FLAG1 1UL

// criação dos jogadores 
Jogador jogador_1(0, 0);
Jogador jogador_2(0, 0);

Timer t;

Thread thread_player1;
Thread thread_player2;

Ticker ticker;
AnalogIn player1_y(PA_4);
AnalogIn player2_y(PA_0);

// Definindo o jogo de forma global
Management management(125, 25, &jogador_1, &jogador_2);

DigitalOut out_3v3(PB_5);

// event flags
EventFlags event_flags;

// ler valores de y do jogador 1
void readPlayer1Y() {
    while(true){
        float yPlayer1 = player1_y.read();
        jogador_1.setY(yPlayer1);
        ThisThread::sleep_for(10ms);
    }
}

// ler valores de y do jogador 2
void readPlayer2Y() {
    while(true){
        float yPlayer2 = player2_y.read();       
        jogador_2.setY(yPlayer2);
        ThisThread::sleep_for(10ms);
    }
}

void flagFunction()
{
    event_flags.set(SAMPLE_FLAG1);
}


int main() {
    out_3v3 = 1;
    
    BufferedSerial pc(USBTX, USBRX, 384000);

    // iniciar thread de jogadores (AnalogIn y)
    thread_player1.start(callback(readPlayer1Y));
    thread_player2.start(callback(readPlayer2Y));

    ticker.attach(flagFunction, 2500ms);

    while (true) {
        event_flags.wait_any(SAMPLE_FLAG1);

        management.run();
    }
}

// THREAD + TIMER BOTÃO READ DEVE SER LIDO APENAS UMA VEZ