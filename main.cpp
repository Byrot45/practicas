#include <iostream>
#include <stack>
#include <string>

using namespace std;

int prioridad(char operador) {
    if (operador == '*' || operador == '/')
        return 2;
    else if (operador == '+' || operador == '-')
        return 1;
    else
        return 0;
}

string infijaAPostfija(string expresion) {
    stack<char> pila;
    string postfija = "";

    for (int i = 0; i < expresion.length(); i++) {
        char caracter = expresion[i];

        if (caracter >= '0' && caracter <= '9') {
            postfija += caracter;
        } else if (caracter == '(') {
            pila.push(caracter);
        } else if (caracter == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfija += pila.top();
                pila.pop();
            }
            if (!pila.empty() && pila.top() == '(')
                pila.pop();
        } else {
            while (!pila.empty() && prioridad(caracter) <= prioridad(pila.top())) {
                postfija += pila.top();
                pila.pop();
            }
            pila.push(caracter);
        }
    }

    while (!pila.empty()) {
        postfija += pila.top();
        pila.pop();
    }

    return postfija;
}

int main() {
    string expresion;
    cout << "Ingrese una expresion en notacion infija: ";
    cin >> expresion;

    string postfija = infijaAPostfija(expresion);
    cout << "La expresion en notacion postfija es: " << postfija << endl;

    return 0;
}
