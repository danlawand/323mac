#ifndef AVIAO_H
#define AVIAO

class Aviao
{
	public:
		std::string cia;
		std::string aeroporto;
		int numero_voo;
		int tempo;
		bool emergencia;
		bool pouso;
		Aviao(int numero_voo, int tempo, bool pouso, bool emergencia);
		~Aviao();
};


class Celula
{
	public:
		Aviao* aeronave;
		Celula* prox;
		Celula* ante;
		Celula(Aviao *a);
		~Celula();
};


class Fila
{
	private:
		int tam;
	public:	
		Fila();
		~Fila();
		void insere(Aviao);
		Aviao remove();
		Aviao topo();
		int tamanho();
	  	bool filaVazia();
	  	/*Será que faço uma função para pesquisar qual é
	  	o que mais tem urgência?*/

};

#endif