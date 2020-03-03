#ifndef AVIAO_H
#define AVIAO_H
#include <iostream>

class Aviao
{
	public:
		std::string cia;
		std::string aeroporto;
		int numero_voo;
		int tempo;
		bool emergencia;
		bool pouso;
		Aviao();
		~Aviao();
		void informacoes(std::string cia, std::string aeroporto, int numero_voo, int tempo, bool pouso, bool emergencia);
};


#endif