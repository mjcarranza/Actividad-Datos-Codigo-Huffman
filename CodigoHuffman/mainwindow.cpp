#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
    MainWindow w;
    string str1;
    string str2;
    string totalTxt = "";
    int txtsize = str.size();
    int count = 0;
    if (raiz == nullptr)
        return;
    if (!raiz->izq && !raiz->der){
        str1 = raiz->simbolo;
        str2 = totalTxt;
        totalTxt = str1 + str2;
        cout << raiz->simbolo;
        if (count == txtsize){
            w.setDecodedTxt(totalTxt);
        }
        count++;
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
void crearArbol(string text, int id){
    // Cuenta la cantidad de veces que aparece cada simbolo y guarda en el mapa
    unordered_map<char, int> frecuencia;
    unordered_map<char, string> CodigoHuffman;
    // Crea una cola de prioridad para guardar los nodos del arbol
    priority_queue<Node*, vector<Node*>, comp> pq;

    for (char simbolo:text){
        frecuencia[simbolo]++;
    }

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

    cout << "\n El texto codificado es: \n" << str <<endl;

    // establecer texto codificado en la
    if (id == 0){
        QString txt = QString::fromUtf8(str.c_str());
        QMessageBox* msg;
        msg = new QMessageBox();
        msg->setWindowTitle("CODIFIED TEXT");
        msg->setIcon(QMessageBox::Warning);
        msg->setStyleSheet("background-color: rgb(0, 0, 0); color: red");
        msg->setText(txt);
        msg->show();
    }
    if (id == 1){
        int index = -1;
        cout << "\n El texto decodificado es: \n";
        while (index < (int)str.size() - 2){
            decode(raiz, index, str);
        }
    }



    cout << "\n";
}

void MainWindow::setDecodedTxt(string str)
{
//    QString txtbox = ui->toCodeTxt->toPlainText(); // obtiene el texto del text edit
//    string textBx = txtbox.toUtf8().constData(); // convierte el texto del text edit a string
//    string totalTxt = str + textBx; // cocatena el texto del textedit con el nuevo caracter
//    QString text = QString::fromUtf8(totalTxt.c_str()); // convertir a QString

    // establecer texto codificado en la
    QString txt = QString::fromUtf8(str.c_str());
    QMessageBox* msg;
    msg = new QMessageBox();
    msg->setWindowTitle("DECODIFIED TEXT");
    msg->setIcon(QMessageBox::Warning);
    msg->setStyleSheet("background-color: rgb(0, 0, 0); color: red");
    msg->setText(txt);
    msg->show();
}

void MainWindow::decodeText(string text)
{

}
// se obtiene el texto introducido y se manda a comprimir
void MainWindow::on_codeButton_clicked()
{
    QString text = ui->toCodeTxt->toPlainText(); 
    string strtext = text.toUtf8().constData();
    crearArbol(strtext, 0);
}
// se obtiene el texto introducido y se manda a descomprimir
void MainWindow::on_decodeButton_clicked()
{
    QString text = ui->toDecodeTxt->toPlainText();
    string strtext = text.toUtf8().constData();
    crearArbol(strtext, 1);
}

