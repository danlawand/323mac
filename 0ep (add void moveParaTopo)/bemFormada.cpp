#include <iostream> 
#include "pilha.h"
#include <string> 
using namespace std; 

bool fechaCerto(char a, char b)
{
  if (((a == '(' && b == ')') || (a == ')' && b == '(')) ||
      ((a == '[' && b == ']') || (a == ']' && b == '[')) ||
      ((a == '{' && b == '}') || (a == '}' && b == '{')))
    return true; 
  return false;
}

int main()
{
  Pilha<char> P; 
  bool bf = true; 
  string entrada; 

  cout << "Digite sequência: ";
  getline (cin, entrada);

  for (int i = 0; entrada[i] != '\0' && bf; i++)
    if (entrada[i] == '(' || entrada[i] == '[' || entrada[i] == '{')
      P.empilha(entrada[i]);
    else if (entrada[i] == ')'|| entrada[i] == ']' || entrada[i] == '}')
      if (P.pilhaVazia()){
	bf = false; 
      }
      else if (!fechaCerto(entrada[i], P.topoDaPilha())){
	bf = false; 
      }
      else char c = P.desempilha(); 

  if (bf && P.pilhaVazia())
    cout << "sequência bem formada" << endl; 
  else
    cout << "sequência não é bem formada" << endl; 
  return (0); 
} 