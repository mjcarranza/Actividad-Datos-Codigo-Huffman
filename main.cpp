#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

// Nodo del arbol
struct Node{
    char simbolo;
    int frecuencia;
    Node *izq, *der;
};

// funcion para agregar un nuevo nodo en el arbol
Node* getNode(char simbolo, int frecuencia, Node* izq, Node* der){
    Node* nodo = new Node();

    nodo->simbolo = simbolo;
    nodo->frecuencia = frecuencia;
    nodo->izq = izq;
    nodo->der = der;

    return nodo;
}

// Objeto de comparacion que sera usado para ordenar la pila
struct comp{
    bool operator()(Node* i, Node* d){
        return i->frecuencia > d->frecuencia;
    }
};

// Revisa el arbol de Huffmann y gusarda los codigos en un mapa
void encode(Node* raiz, string str, unordered_map<char, string> &CodigoHuffman){
    if (raiz == nullptr)
        return;
    if (!raiz->izq && !raiz->der){
        CodigoHuffman[raiz->simbolo] = str;
    }
    encode(raiz->izq, str+"0", CodigoHuffman);
    encode(raiz->der, str+"1", CodigoHuffman);
}

// Revisa el arbol y decodifica los simbolos codificados
void decode(Node* raiz, int &index, string str){
    if (raiz == nullptr)
        return;
    if (!raiz->izq && !raiz->der){
        cout<< raiz->simbolo;
        return;
    }
    index ++;
    if (str[index] == '0'){
        decode(raiz->izq, index, str);
    }
    else{
        decode(raiz->der, index, str);
    }
}

// Crea el arbol de Huffman y decodifica dados los simbolos
void crearArbol(string text){
    // Cuenta la cantidad de veces que aparece cada simbolo y guarda en el mapa
    unordered_map<char, int> frecuencia;
    for (char simbolo:text){
        frecuencia[simbolo]++;
    }
    // Crea una cola de prioridad para guardar los nodos del arbol
    priority_queue<Node*, vector<Node*>, comp> pq;
    //Agrega a la cola de priuoridad los nodos de cada simbolo
    for(auto pair: frecuencia){
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    // Hacer todoo el proceso hasta que haya mas de un nodo en la cola
    while(pq.size() != 1){
        Node* izq = pq.top(); pq.pop();
        Node* der = pq.top(); pq.pop();
        int sum = izq->frecuencia + der->frecuencia;
        pq.push(getNode('\0',sum, izq, der));
    }
    Node* raiz = pq.top();
    // Imprime los codigos para cada simbolo
    unordered_map<char, string> CodigoHuffman;
    encode(raiz, "", CodigoHuffman);
    cout<<"\n los codigos de Huffman son:\n" << '\n';
    for (auto pair:CodigoHuffman) {
        cout << pair.first << " " << pair.second << '\n';
    }
    // Imprime el mensqaje original que se ingreso, el cofificado y decodifica el coficado y lo imprime de nuevo
    cout << "\n El mensaje original era:\n" << text << '\n';
    string str = "";
    for (char simbolo: text) {
        str += CodigoHuffman[simbolo];
    }
    cout << "\n El texto codificado es:\n" << str << '\n';
    int index = -1;
    cout << "\n El texto decodificado es: \n";
    while (index < (int)str.size() - 2){
        decode(raiz, index, str);
    }
    cout << "\n";
}

int main() {
    cout << "\n--------------------------------------------------------";
    cout << "\n Compresion y Descompresion con el metodo de Huffman";
    cout << "\n--------------------------------------------------------\n";
    string text;
    cout << "\n Ingrese el mensaje que desea comprimir: ";
    getline(cin, text);
    crearArbol(text);
    cout << "\n";
    return 0;
}
