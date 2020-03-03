#include <iostream>
#include "Aviao.h"

Aviao::Aviao(){}

Aviao::~Aviao(){}

void Aviao::informacoes(std::string comp, std::string ap, int nv, int t, int pContato, int pPermissao, bool p, bool e)
{
	/*No construtor não é preciso digitar
	* Aviao a = new Aviao;
	* a.numero_voo = nv
	*/
	cia = comp;
	aeroporto = ap; 
	numero_voo = nv;
	tempo = t;
	passoContato = pContato;
	passoPermissao = pPermissao;
	pouso = p;
	emergencia = e;
}