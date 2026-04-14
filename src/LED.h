#ifndef LED_h
#define LED_h

#include <Arduino.h>


/** 
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado,
 * piscar continuamente e piscar por quantidade definida.
 *
 * @note O método update() deve ser chamado continuamente dentro do loop().
*/


class Led
{
private:
    uint8_t pino;
    bool estado;
    bool desligarPorTempo;
    uint32_t desligarNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    void funcaoPiscar();
    void funcaoDesligamento();

public:
    Led(uint8_t pino); // metodo construtor, deverá

    void ligar();
    void ligar(uint32_t tempoLigado_ms);

    void desligar();

    void piscar();
    void piscar(float frequencia);
    void piscar(float frequencia, uint16_t repeticoes);

    bool getEstado();
    uint8_t getPino();

    void setEstado(bool estado);

    void alterar();

    void update();
};

#endif