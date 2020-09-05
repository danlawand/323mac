/*10/03/2020 - MAC323 


Tabela de Sómbolos

		Lista Ligada |Vetor Ordenado
		Desordenada	 |
_____________________|__________________

devolve|   ~n        |     ~log n
insere |   ~n        |     ~ n 
remove |   ~n        |     ~ n


A função rank usa busca binária  para decidir quantos elementos da tabela têm chave
menor que k.

Busca binária em uma tabela com n>= 1 elementos faz <= log n + 1  comparações

Base:
	n=1
	Faz  1 compar. <= log1 + 1

Passo:
	Tome agora uma tabela com n elementos
	o código olha o elemento do meio e temos 3 casos:
		Caso 1: achou 
			Fez 1 compar.<= 2<= log n +1
		Caso 2: o do meio é > x
			Faz 1 compar. e
			Procura numa tabela com <= (n/2)
			Pela hipótese de indução (h.i.)  esta busca faz <= log(n/2) + 1
															<= log n - log2 + 1
															<= log n

*/


/*
ÁRVORE DE BUSCA BINÁRIA

	Uma árvore de busca binária (abb)(bst) é uma árvore binária em que para cada nó da árvore
	as chaves na subárvore esquerda do  nó são menores que sua chave, e as chaves da subárvore direita são
	maiores. Profundidade de um nó é o  número de arestas do caminho da raiz até ele.


	Para implementar a tabela de símbolos usando uma ABB precisamos de uma classe para os nós da árvore:

No: ________________
	|<chave, valor>|
	|______________|
	| esq  | dir   |

	Com isso a tabela de símbolos é implementada com
											No * raiz;

*/
Item devolve (Chave x)
{
	return get(raiz, x);
}
Item get (No* raiz, Chave x)
{
	if (raiz==nullptr) return NULL;
	if(raiz->chave == x) return raiz->valor;
	if(raiz->chave > x)
		return (get(raiz->esq, x));
	else
		return (get(raiz->dir, x));
}
void insere (Chave chave, Item valor)
{
	raiz = put(raiz, chave, valor);
}
No * put (No * raiz, Chave chave, Item valor)
{
	if(raiz==nullptr)
		return (new No (chave, valor));
	if(raiz->chave==chave)
			raiz->valor = valor;
	else if (raiz->chave > chave)
		raiz->esq = put(raiz->esq, chave, valor);
	else
		raiz->dir = put(raiz->dir, chave, valor);
	return (raiz);
}


/*
	Tanto o insere como o devolve consomem tempo proporcional à altura da  árvore que,
	no pior caso, é ~n.

	O numero de comparações para encontrar um elemento na árvore é 1 + profundidade do nó.
	A profundidade média de um nó na árvore é dada pela  soma de todas as profundidades dos nós
	dividida por n.

	Vamos chamar dee Cn o valor esperado da soma das profundidades de uma ABB (BST) construída
	com n inserções em ordem aleatória.
	Com isso, o número esperado de comparações para encontrar um nó é 1 + Cn/n
	C0 = 0
	C1 = 0
	Cn = [ C(0) + C(n-1) ]/n + 1   + [C(1) + C(n-2)]/n + 1   + [C(2) + C(n-3)]/n + 1   + ... + [C(n-1) + C0]/n +1

	Cn = n + 2/n Somatório de  i = 0 à n-1 Ci
(0)	n*Cn = n**2 + 2 * Somatório  de  i = 0 à n-1 Ci
	Aplicando para n-1:
(1)	(n-1)*Cn = (n-1)**2 + 2 * Somatório  de  i = 0 à n-2 Ci

	(0) - (1) = 
	= nCn - (n-1)Cn-1 = 2n -1 + 2Cn-1
	nCn = (n+1)Cn-1 + 2n -1
	Dividindo por n(n+1)
	cn/(n+1) = cn-1/n +2/(n+1) - 1/(n(n+1))
	Cn <= Cn-1/n + 2/n+1

	Cn/n+1 <= Integral de 2 à n+1 2/x dx
	Cn/n+1 <= 2*ln((n+1)/2)
 	
 	A profundidade média é ~ 2log n

 */
