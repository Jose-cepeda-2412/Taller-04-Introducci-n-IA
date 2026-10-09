# Triqui con Inteligencia Artificial - C++

Juego de **Triqui (Tres en raya)** desarrollado en C++, en el que un jugador humano se enfrenta a una Inteligencia Artificial (IA) que utiliza el algoritmo **Minimax con poda Alfa-Beta** para determinar la mejor jugada posible.

El proyecto permite aplicar conceptos de inteligencia artificial, búsqueda de soluciones, recursividad y optimización de algoritmos.

## Características

- Juego de Triqui en un tablero de 3x3.
- Interacción mediante la consola.
- Jugador humano representado por `X`.
- Inteligencia Artificial representada por `O`.
- Implementación del algoritmo Minimax.
- Optimización mediante poda Alfa-Beta.
- Función heurística para evaluar oportunidades de victoria.
- Validación de movimientos y casillas ocupadas.
- Detección de victorias y empates.

## Tecnologías utilizadas

- **Lenguaje:** C++
- **Librería:** iostream
- **Interfaz:** Consola

## Funcionamiento del juego

El juego comienza con un tablero vacío de 3x3. El jugador humano realiza el primer movimiento seleccionando una fila y una columna entre 1 y 3.

Después de cada movimiento, el programa verifica si existe un ganador o si el tablero está lleno.

Si la partida continúa, la Inteligencia Artificial analiza las posibles jugadas utilizando Minimax con poda Alfa-Beta y selecciona la mejor opción.

El juego termina cuando:

- El jugador humano consigue tres `X` consecutivas.
- La IA consigue tres `O` consecutivas.
- El tablero se llena sin que exista un ganador.

## Algoritmo Minimax

Minimax es un algoritmo de búsqueda utilizado en juegos de dos jugadores que permite seleccionar la mejor decisión considerando las posibles respuestas del oponente.

En este proyecto:

- **Maximizador (IA):** busca obtener el mayor puntaje posible.
- **Minimizador (Humano):** busca obtener el menor puntaje posible.

Los estados finales reciben las siguientes puntuaciones:

| Resultado | Puntuación |
|---|---|
| Victoria de la IA | +100 |
| Victoria del humano | -100 |
| Empate | 0 |

El algoritmo explora recursivamente las posibles jugadas hasta encontrar estados finales, permitiendo que la IA seleccione una jugada óptima.

### Poda Alfa-Beta

La poda Alfa-Beta optimiza Minimax evitando explorar ramas del árbol de decisiones que no pueden mejorar el resultado obtenido.

Se utilizan dos valores:

- **Alfa (α):** mejor valor encontrado para el jugador maximizador.
- **Beta (β):** mejor valor encontrado para el jugador minimizador.

Cuando se cumple la condición `beta <= alfa`, se interrumpe la exploración de la rama actual.

Esto permite reducir la cantidad de estados evaluados sin modificar el resultado de Minimax.

## Función heurística

El proyecto también implementa una función heurística que calcula las oportunidades inmediatas de victoria de cada jugador.

Se considera una oportunidad de victoria cuando una fila, columna o diagonal contiene dos símbolos del mismo jugador y una casilla vacía.

La evaluación se calcula mediante:

`h = oportunidadesIA - oportunidadesHumano`

Donde:

- Un resultado positivo indica más oportunidades para la IA.
- Un resultado negativo indica más oportunidades para el humano.
- Un resultado de cero indica igualdad de oportunidades inmediatas.

**Nota:** La función heurística está implementada, pero actualmente no se utiliza dentro de Minimax. El algoritmo evalúa los estados terminales de la partida.

## Funciones principales

| Función | Descripción |
|---|---|
| `imprimirTablero()` | Muestra el tablero en consola. |
| `hayGanador()` | Verifica si un jugador ganó. |
| `tableroLleno()` | Comprueba si quedan casillas disponibles. |
| `contarOportunidadesDeGanar()` | Cuenta oportunidades inmediatas de victoria. |
| `funcionHeuristica()` | Calcula una puntuación basada en las oportunidades de ambos jugadores. |
| `minimax()` | Evalúa las posibles jugadas mediante Minimax con poda Alfa-Beta. |
| `mejorJugadaIA()` | Determina la mejor posición para la IA. |
| `turnoIA()` | Ejecuta el movimiento de la IA. |
| `turnoHumano()` | Solicita y valida el movimiento del jugador. |

## Ejecución del proyecto

### Requisitos

- Compilador de C++ compatible con C++11 o superior.
- Terminal o consola.

### Compilación

Desde la carpeta del proyecto, ejecutar:

```bash
g++ main.cpp -o triqui
```

### Ejecución

En macOS o Linux:

```bash
./triqui
```

En Windows:

```bash
triqui.exe
```

> Si el archivo principal tiene otro nombre, reemplazar `main.cpp` por el nombre correspondiente.

## Ejemplo de ejecución

```text
Triqui: Humano = X, IA = O

  |  |
--+--+--
  |  |
--+--+--
  |  |

Fila (1-3): 1
Columna (1-3): 1

IA juega en: 2 2

X |  |
--+--+--
  |O |
--+--+--
  |  |
```

El jugador continúa ingresando las posiciones de sus movimientos hasta que se determine un ganador o se produzca un empate.

## Objetivo del proyecto

Implementar un juego de estrategia utilizando el algoritmo Minimax con poda Alfa-Beta, comprendiendo cómo una Inteligencia Artificial puede evaluar diferentes estados, anticipar movimientos del oponente y seleccionar decisiones óptimas.

El proyecto permite estudiar conceptos como árboles de búsqueda, recursividad, funciones de evaluación y optimización de algoritmos.
