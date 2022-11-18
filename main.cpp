// Carlos Alberto 
// Carlos Damián 
#include <cstddef>
#include <iostream>
using namespace std;
#include "lista.h"

int main() {
  SimpleList<int> lista;

  lista.addFirst(9);
  lista.addFirst(8);
  lista.addFirst(7);

  lista.addLast(10);
  lista.addLast(11);

  cout << "Lista normal" << endl;
  lista.print();
  cout<<endl;
  cout << "Lista en reversa" << endl;
  lista.reverse();

  lista.remove_front();
  cout<<endl;
  cout << "Remove first" << endl;
  lista.print();
  cout<<endl;
  lista.remove_last();
  cout << "Remove last" << endl;
  lista.print();

  cout << "\nPrimer elemento: " << lista.getFirst() << endl;
  cout << "Ultimo elemento: " << lista.getLast() << endl;
}
