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
		int passoContato
		int passoPermissao;
		bool emergencia;
		bool pouso;
		Aviao();
		~Aviao();
		void informacoes(std::string cia, std::string aeroporto, int numero_voo, int tempo, int passoContato, int passoPermissao, bool pouso, bool emergencia);
};


#endif