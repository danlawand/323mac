/*
TABELA DE SÍMBOLOS

void insere (Chave chave, Item valor)
Item devolve (Chave chave)
void remove (Chave chave)
bool pertence (Chave chave)
*/

//1st ideia: Lista ligada desordenada.
	template <class T>
	class No
	{
		private:
			T info; /*info seria o par Chave e Valor*/
			No<T> *prox;
		public:
			No (T info, No<T> *prox);
			/*Como as informações são privadas preciso fazer métodos para acessar essas informações (info, *prox)*/
			T getInfo();
			No<T>* getProx();
			void setInfo(T info);
			void setProx(No<T>*prox);
	};

	template <class par>
	class TSlistaligada
	{
	private:
		No<par> *inicio;
	public:
		TSlistaligada();
		~TSlistaligada();
		void insere ()
	};

	template <class Item>
	class Info
	{
	private:
		Item  item;
	public:
		void setItem(Item item);
		Item getItem();
	}



	Item getItem()
	{
		return item;
	}
	/*
	.
	.
	.
	*/
	Item devolve(Chave chave)
	{
		No<par>* p = inicio;
		while(p != nullptr)
		{
			if (p->getInfo().getChave() == chave)
				return (p->getInfo().getItem())
			p = p->getProx();
		}
		return ('NULL'); /*--->  valor indefinido do tipo Item*/
	}
	/*
		Busca sem Sucesso:  Todos os elementos devem ser procurados. 
							Portanto, linear no tamanho (n).

		Busca com Sucesso:	
			Pior Caso: Linear
			Caso Médio: 1 . 1/n + 2 . 1/n + ... + n . 1/n = n . (n+1)/2 . 1/n = (n+1)/2
	*/


	/*Remover é inserir com chave Null*/
	void insere (Chave chave, Item valor)
	{
		No<par>*p = inicio;
		while (p != nullptr)
		{
			if(p->getInfo().getChave() == chave)
			{
				p->setInfo(valor, chave);
				return;
			}
			p =p->getProx();
		}
		No<par>* novo = new No<par>(valor, chave);
		novo->setProx(inicio);
		inicio = novo;
	}

//2nd ideia: vetor orrdenado pelas chaves
	array tab, initial size n 
Item devolve (Chave chave)
{
	int r = rank(chave); //elem < chave
	if(r < n && tab[r].getChave() == chave)
		return (tab[r].getItem());
	return 'NULL';
}

voidd insere(Item valor, Chave chave)
{
	if (n == tam)
		resize ();
	int r = rank(chave);
	if (r < n  && tab[r].getChave() == chave)
		tab[r].setItem(valor);
		return;
	for(int j = n; j > r; j--)
		tab[j] = tab[j-1];
	tab[r] = <valor, chave>;
	n++;
}
/*
	Consumo de tempo da Função, no  pior caso, é dada pelo tempo  do rank
	mais um tempolinear para "empurrar" os elementos
*/

/*
	Se fizermos n inserções de valores distintos numa tabela iinicialmente vazia,
	o número médio de movimentações é dado por: n(n-1)/4
*/


int rank (Chave chave)
{
	int inicio = 0, fim = n-1;
	while  (inicio <= fim) {
		int meio = (inicio+fim)/2;
		if(tab[meio].getChave() == chave)
			return meio;
		else if (tab[meio]getChave() > chave)
			fim = meio-1;
		else 
			inicio = meio+1;
	}
	return inicio;
}