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

    /**
     * @brief processa a lógica de piscar o led.
     */
    void funcaoPiscar();

    /**
     * @brief processa o desligamento temporarizado do led.
     */
    void funcaoDesligamento();

    public:
    /**
     * @brief constrói um objeto led
     * @param pino o número do pino onde o led está conectado.
     */
    Led(uint8_t pino);

    /**
     * @brief liga o led continuamente.
     */
    void ligar();

    /**
     * @brief liga o led por um tempo determinado
     * @param tempoLigado_ms tempo, em milissegundos, que o LED ficará ligado.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     * @brief desliga o led. e cancela os modos automáticos.
     */
    void desligar();

    /**
     * @brief inicia o modo de piscar continuamente, com frequência de 1Hz.
     */
    void piscar();

    /**
     * @brief inicia o modo de piscar continuamente, com frequência definida.
     * @param frequencia frequência de piscar, em Hz.
     */
    void piscar(float frequencia);

    /**
     * @brief inicia o modo de piscar por quantidade definida, com frequência definida.
     * @param frequencia frequência de piscar, em Hz.
     * @param repeticoes quantidade de vezes que o LED irá acender (ex: 3 acende 3 vezes e apaga 3 vezes).
     */
    void piscar(float frequencia, uint16_t repeticoes);

    /**
     * @brief retorna o estado atual do LED (true para ligado, false para desligado).
     * @return estado do LED
     */
    bool getEstado();

    /**
     * @brief retorna o número do pino onde o led está conectado.
     * @return número do pino
     */
    uint8_t getPino();

    /**
     * @brief define manualmente o estado do LED.
     * @param estado novo estado do LED (true para ligado, false para desligado).
     */
    void setEstado(bool estado);

    /**
     * @brief inverte o estado do LED (se estiver ligado, desliga; se estiver desligado, liga).
     * E cancela os modos automáticos.
     */
    void alterar();

    /**
     * @brief atualiza o estado do led.
     */
    void update();

    /**
     * @brief reseta o estado do LED.
     */
    void reset();
};

#endif