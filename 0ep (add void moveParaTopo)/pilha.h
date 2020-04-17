#ifndef PILHA_H
#define PILHA_H

template <class Item> 
class Pilha
{
 private:
  Item * P;
  int topo; 
  int tam;
  void resize(); //dobra o tamanho atual de P

 public:
  Pilha();
  ~Pilha();
  void empilha(Item item);
  Item desempilha();
  bool pilhaVazia();
  Item topoDaPilha();
};

template <class Item> 
Pilha<Item>::Pilha(): topo(0), tam(10), P(new Item[10]) {};

template <class Item> 
Pilha<Item>::~Pilha() 
{
  if (P != nullptr)
    delete [] P;
}

template <class Item>
void Pilha<Item>::empilha (Item item)
{
  if(tam == topo)
    resize();
  P[topo] = item;
  topo++;
}

template <class Item>
void Pilha<Item>::resize()
{
  Item * novoVetor = new Item[2*tam];
  for (int i = 0; i < topo; i++)
    novoVetor[i] = P[i];
  delete[] P;
  P = novoVetor; 
  tam = tam * 2;
}

template <class Item>
bool Pilha<Item>::pilhaVazia()
{
  return (topo == 0);
}

template <class Item>
Item Pilha<Item>::desempilha()
{
  if (!pilhaVazia()){
    topo--;
    return (P[topo]);
  }
}

template <class Item> 
Item Pilha<Item>::topoDaPilha()
{
  if (!pilhaVazia())
    return (P[topo - 1]);
}

#endif