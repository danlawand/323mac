/*

* emergências (Os Dois) Min - heap -> emergência == -1

* aviões que estão circulando o aeroporto e ficam sem combustı́vel (Aterrisagem) == 0

* aviões que estão esperando para decolar por mais de 10% do tempo estimado de seu voo. (Decolagem)

objeto avião 

1 fila

Olha os 4 itens


*/


		typedef struct node Node;
		struct node{
			int data;
			int key;
			Node *pai;
			Node *esq;
			Node *dir;
		};
		typedef Node *Arvore;
		Arvore r;

		string cia;			//duas letras
		string numero_voo;	//3 numeros
		string codigo;		//3 letras preferentes para/de onde vão/vem
		int tcombustivel;	//pouso: se chegar a zero. deve pousar	
		int tvoo;			//decolagem: tempo estimado de voo
		int emergencia; 	//-1 se é, 1 se não
		Aviao* next;