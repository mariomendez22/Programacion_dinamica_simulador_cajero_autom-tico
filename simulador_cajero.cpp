#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// Estructura que representa una cuenta del cajero
// Aquí guardamos el número de cuenta, el nombre y el saldo
struct Account {
    int id;
    string name;
    double balance;
};

// Función para leer números enteros con validación
int readInt(const string &msg) {
    int x;
    cout << msg;

    // Si el usuario mete letras u otra cosa, marcamos error
    if (!(cin >> x)) {
        cin.clear(); // limpiamos el error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Entrada no valida.");
    }
    return x;
}

// Leer un número decimal (para montos de dinero)
double readDouble(const string &msg) {
    double x;
    cout << msg;

    // Igual validamos que sea número
    if (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Entrada no valida.");
    }
    return x;
}

// Función para buscar una cuenta por su id
Account* findAccount(Account cuentas[], int tam, int id) {
    // Recorremos el arreglo para ver si encontramos la cuenta
    for (int i = 0; i < tam; i++) {

        // Si coincide el id, regresamos un puntero a esa cuenta
        if (cuentas[i].id == id) {
            return &cuentas[i];
        }
    }

    // Si no existe, regresamos nullptr
    return nullptr;
}

// Consultar el saldo de una cuenta
void consultar(Account *acc) {

    // Si el puntero es nulo, la cuenta no existe
    if (!acc) throw runtime_error("La cuenta no existe.");

    // Mostrar datos
    cout << "Cuenta #" << acc->id
         << " | Titular: " << acc->name
         << " | Saldo: $" << acc->balance << "\n";
}

// Depositar dinero en una cuenta
void depositar(Account *acc) {

    if (!acc) throw runtime_error("La cuenta no existe.");

    // Pedimos el monto a depositar
    double monto = readDouble("Monto a depositar: $");

    // Validamos que el monto sea positivo
    if (monto <= 0) throw runtime_error("Monto invalido.");

    // Sumamos al saldo
    acc->balance += monto;

    cout << "Deposito realizado. Nuevo saldo: $" << acc->balance << "\n";
}

// Retirar dinero
void retirar(Account *acc) {

    if (!acc) throw runtime_error("La cuenta no existe.");

    // Monto que el usuario quiere retirar
    double monto = readDouble("Monto a retirar: $");

    // Verificamos que sea una cantidad válida
    if (monto <= 0) throw runtime_error("Monto invalido.");

    // Revisamos si alcanza el saldo
    if (monto > acc->balance) throw runtime_error("Saldo insuficiente.");

    // Restamos el saldo
    acc->balance -= monto;

    cout << "Retiro realizado. Nuevo saldo: $" << acc->balance << "\n";
}

// Transferir dinero entre dos cuentas
void transferir(Account *origen, Account *destino) {

    // Primero revisamos que ambas cuentas existan
    if (!origen || !destino) throw runtime_error("Alguna cuenta no existe.");

    // Pedimos el monto
    double monto = readDouble("Monto a transferir: $");

    // Validamos el monto
    if (monto <= 0) throw runtime_error("Monto invalido.");

    // Validamos saldo suficiente
    if (monto > origen->balance) throw runtime_error("No hay saldo suficiente.");

    // Restamos de la cuenta origen
    origen->balance -= monto;

    // Sumamos a la cuenta destino
    destino->balance += monto;

    cout << "Transferencia realizada con exito.\n";
}

// Menú principal del cajero
void menu() {
    cout << "\n--- Cajero Simulado ---\n";
    cout << "1. Consultar saldo\n";
    cout << "2. Retirar\n";
    cout << "3. Depositar\n";
    cout << "4. Transferir\n";
    cout << "5. Salir\n";
    cout << "------------------------\n";
}

int main() {

    // Aquí creamos 3 cuentas con saldo inicial
    Account cuentas[3] = {
        {1, "Alumno A", 500.0},  // Cuenta 1
        {2, "Alumno B", 700.0},  // Cuenta 2
        {3, "Alumno C", 300.0}   // Cuenta 3
    };

    bool seguir = true;

    cout << "Bienvenido al cajero de prueba.\n";

    while (seguir) {
        try {
            // Mostramos el menú
            menu();

            // Leemos la opción del usuario
            int op = readInt("Elige una opcion: ");

            // Consultar
            if (op == 1) {
                int id = readInt("Numero de cuenta: ");
                Account *acc = findAccount(cuentas, 3, id);
                consultar(acc);
            }
            // Retirar
            else if (op == 2) {
                int id = readInt("Numero de cuenta: ");
                retirar(findAccount(cuentas, 3, id));
            }
            // Depositar
            else if (op == 3) {
                int id = readInt("Numero de cuenta: ");
                depositar(findAccount(cuentas, 3, id));
            }
            // Transferir
            else if (op == 4) {
                int o = readInt("Cuenta origen: ");
                int d = readInt("Cuenta destino: ");
                transferir(findAccount(cuentas, 3, o),
                        findAccount(cuentas, 3, d));
            }
            // Salir del programa
            else if (op == 5) {
                cout << "Saliendo...\n";
                seguir = false;
            }
            else {
                cout << "Opcion invalida.\n";
            }

        } catch (exception &e) {
            // Si pasa un error, lo mostramos
            cout << "Error: " << e.what() << "\n";
        }

        // Limpiamos el buffer (por si quedaron cosas)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
