// Carlos Alberto 
// Carlos Damián 

#include <exception>
#include <iostream>

template <typename T> class Node {
private:
  T data;
  Node<T> *next;
  Node<T> *previous;
  template <typename U> friend class SimpleList;

public:
  /**
   * @brief Constructor para un objeto Node
   * @param data dato del nodo
   */
  Node(T data) {
    this->data = data;
    this->next = NULL;
  }
  /**
   * @brief Constructor para un objeto Nodo
   * @param data dato del nodo
   * @param next apuntador al siguiente nodo
   */
  Node(T data, Node<T> *next, Node<T> *previous) {
    this->data = data;
    this->next = next;
    this->previous = previous;
  }
};

template <typename T> class SimpleList {
private:
  Node<T> *head;
  Node<T> *last;
  int size;

public:
  /**
   * @brief Constructor para el objeto SimpleList
   */
  SimpleList() {
    head = last = NULL;
    size = 0;
  }

  /**
   * @brief Método para agregar un nodo al inicio de la lista.
   * @param dato el dato a agregar
   */
  void addFirst(T dato) {
    size++;
    Node<T> *n = new Node<T>(dato, NULL, NULL);
    if (head == NULL && last == NULL) {
      head = last = n;
    } else {
      n->next = head;
      head->previous = n;
      head = n;
    }
  }

  /**
   * @brief Método imprime todos los nodos de la lista
   */
  void print() {
    Node<T> *aux = head;
    while (aux != NULL) {
      std::cout << aux->data << std::endl;
      aux = aux->next;
    }
  }

  void reverse() {
    Node<T> *aux = last;
    while (aux != NULL) {
      std::cout << aux->data << std::endl;
      aux = aux->previous;
    }
  }
  /**
   * @brief Método que regresa 1, si la lista no tiene elementos.
   * @return 1 si la lista está vacía, 0 en el caso contrario
   */
  bool is_empty() { return (head == NULL ? 1 : 0); }

  /**
   * @brief Método para agregar un nodo al final de la lista.
   * @param dato dato a agregar
   */
  void addLast(T dato) {
    size++;
    Node<T> *n = new Node<T>(dato, NULL, NULL);
    if (head == NULL)
      head = last = n;
    else {
      n->previous = last;
      last->next = n;
      last = n;
    }
  }
  /**
   * @brief Método para calcular el tamaño de la lista, cuántos elementos
   * tenemos.
   * @return el numero de datos
   */

  int getsize() { return this->size; }

  /**
   * @brief Método para revisar si existe un elemento, regresa 1 si  existe o 0
   * sino existe.
   * @param data dato a buscar
   * @return 1 si el dato está en la lista, 0 en el caso contrario
   */
  bool contains(T data) {
    if (is_empty())
      return false;
    else {
      Node<T> *aux = head;
      while (aux->next != NULL) {
        if (aux->data == data)
          return true;
        aux = aux->next;
      }
      return false;
    }
  }

  /**
   * @param Método para obtener un elemento que se encuentra en una  posición:
   * "index". Si index es menor a 0 o mayor al tamaño se lanza exception.
   * @param index el índice del objeto a buscar
   * @return el dato si es que lo encuentra
   */
  T get(int index) {
    if (is_empty())
      return false;
    if (index < 0)
      throw 1;

    Node<T> *aux = head;
    for (int i = 0; i < index; i++) {
      aux = aux->next;
    }
    return aux->data;
  }
  /**
   *@brief Método para remover de la lista el primer elemento, si la lista NO es
   *vacía se puede realizar.
   * @return el elemento eliminado
   */
  T remove_front() {
    if (is_empty())
      throw std::length_error("Empty list");
    Node<T> *aux = head;
    T data = head->data;
    head->next->previous = NULL;
    head = head->next;
    aux->next = NULL;
    delete aux;
    size--;
    return data;
  }

  /**
   * @brief Método para remover de la lista el último elemento, si la lista NO
   * es vacía se puede realizar.
   * @return el elemento eliminado
   */
  T remove_last() {
    if (is_empty())
      throw std::length_error("Empty list");
    Node<T> *aux = last;
    T data = head->data;
    last->previous->next = NULL;
    last = last->previous;
    aux->previous = NULL;
    delete aux;
    size--;
    return data;
  }
  T getFirst() {
    if (is_empty()) {
      throw "vacia";
    }
    return head->data;
  }
  T getLast() {
    if (is_empty()) {
      throw "vacia";
    }
    return last->data;
  }
};
