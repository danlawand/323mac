/*\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome: DANIEL ANGELO ESTEVES LAWAND
  NUSP: 10297693

  contador.cpp

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include "aviao.h"
#include "celula.h"
#include "fila.h"
#include "contador.h"
#include <iostream>
using namespace std;

Contador::Contador()
{
	combustivel_Pousado[0] = 0; 
	combustivel_Pousado[1] = 0;

	tempoMedio_esperaPouso[0] = 0;
	tempoMedio_esperaPouso[1] = 0;

	tempoMedio_esperaDecolagem[0] = 0;
	tempoMedio_esperaDecolagem[1] = 0;

	combustivelMedio_esperaPouso[0] = 0;
	combustivelMedio_esperaPouso[1] = 0;

	quantidadeVoos_emergencia = 0;
}
Contador::~Contador(){}