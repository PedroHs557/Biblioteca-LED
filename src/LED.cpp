#include "LED.h"

Led::Led(uint8_t pin) : pino(pin),
                        estado(LOW),
                        desligarPorTempo(false),
                        desligarNoMomento(0),
                        tempoAnteriorPiscar(0),
                        tempoEspera(0),
                        estadoPiscar(false),
                        repeticoes(0)

{

    pinMode(pino, OUTPUT);
}

void Led::ligar()
{
    estadoPiscar = false;     // reseta os valores
    desligarPorTempo = false; // reseta os valores
    estado = HIGH;
}
void Led::ligar(uint32_t tempoLigado_ms)
{
    estadoPiscar = false; // reseta os valores

    estado = HIGH;
    desligarPorTempo = true;
    desligarNoMomento = (millis() + tempoLigado_ms);
}

void Led::desligar()
{
    estadoPiscar = false;     // reseta os valores
    desligarPorTempo = false; // reseta os valores
    estado = LOW;
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligarPorTempo = false; // reseta os valores
}

void Led::piscar(float frequencia)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    desligarPorTempo = false; // reseta os valores
}

void Led::piscar(float frequencia, uint16_t repeticoes)
{
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
    desligarPorTempo = false; // reseta os valores
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();

        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}

bool Led::getEstado()
{
    return estado;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
    estadoPiscar = false;     // reseta os valores
    desligarPorTempo = false; // reseta os valores
}

void Led::alterar()
{
    estado = !estado;
    estadoPiscar = false;     // reseta os valores
    desligarPorTempo = false; // reseta os valores
}

void Led::update()
{
    if (desligarPorTempo)
        funcaoDesligamento();
    if (estadoPiscar)
        funcaoPiscar();

    digitalWrite(pino, estado);
}

void Led::funcaoDesligamento()
{
    if (millis() >= desligarNoMomento)
    {
        estado = LOW;
        desligarPorTempo = false;
    }
}