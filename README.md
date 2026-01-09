# Simulador Cajero Automático 

## Descripción del Programa

Este programa simula el funcionamiento básico de un **cajero automático**, permitiendo a los usuarios realizar operaciones bancarias comunes desde la consola.

El sistema maneja cuentas predefinidas y permite **consultar saldo, retirar dinero, depositar y transferir fondos entre cuentas**. Además, valida las entradas del usuario y controla errores como montos inválidos, cuentas inexistentes o saldo insuficiente.

---

## Funcionalidades

- Menú interactivo en consola.
- Manejo de múltiples cuentas bancarias.
- Operaciones disponibles:
  - Consultar saldo.
  - Retirar dinero.
  - Depositar dinero.
  - Transferir dinero entre cuentas.
- Validación de entradas:
  - No permite valores no numéricos.
  - No permite montos negativos o iguales a cero.
  - Verifica la existencia de cuentas.
  - Verifica saldo suficiente para retiros y transferencias.
- Manejo de errores mediante excepciones.
- Ejecución continua hasta que el usuario decide salir.


## Capturas de Pantalla (Ejemplo)
  # Consulta de saldo
<img width="1430" height="884" alt="consultar saldo" src="https://github.com/user-attachments/assets/90b98494-2c22-428a-b74d-4350ed4e90a4" />
  # Depositar y Retirar
<img width="1430" height="884" alt="deposito y retiro" src="https://github.com/user-attachments/assets/eccc95d8-d2b7-472d-b823-aae30d039a34" />
  # Transferir
<img width="1430" height="884" alt="transferir" src="https://github.com/user-attachments/assets/b42d1dbb-5021-4d75-930c-fac87d4e983a" />
  # Saldo Insuficiente
<img width="1430" height="884" alt="saldo insuficiente" src="https://github.com/user-attachments/assets/80a377ba-9309-4a00-ace7-2fa82845ba49" />

## Instrucciones de Uso

Clonar o descargar el repositorio:
```bash
git clone https://github.com/mariomendez22/Programacion_dinamica_simulador_cajero_autom-tico.git
```


Compilar el programa:
```bash
g++ simulador_cajero.cpp -o cajero
```


Ejecutar el programa:
```bash
./cajero
```
