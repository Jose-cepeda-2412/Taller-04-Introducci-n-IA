#include <iostream>


using namespace std;

void imprimirTablero(char matrixz[][3]);
bool hayGanador(char matriz[][3], char opcion); //opcion h = X , i (ia) = O
bool tableroLleno(char matriz[][3]);
int contarOportunidadesDeGanar(char matriz[][3], char opcion);
int funcionHeuristica(char matriz[][3]);
int minimax(char matriz[][3], bool turnoIa, int alfa, int beta);
void mejorJugadaIA(char matriz[][3], int &fila, int &col);
void turnoIA(char matriz[][3]);
void turnoHumano(char matriz[][3]);


int main(){

    char matriz[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    cout << "Triqui: Humano = X, IA = O\n\n";

    while(true){

        imprimirTablero(matriz);
        cout << endl;

        // humano
        turnoHumano(matriz);

        if(hayGanador(matriz,'X')){
            imprimirTablero(matriz);
            cout << "\nGanaste!\n";
            break;
        }

        if(tableroLleno(matriz)){
            imprimirTablero(matriz);
            cout << "\nEmpate.\n";
            break;
        }

        // IA
        turnoIA(matriz);

        if(hayGanador(matriz,'O')){
            imprimirTablero(matriz);
            cout << "\nGana la IA.\n";
            break;
        }

        if(tableroLleno(matriz)){
            imprimirTablero(matriz);
            cout << "\nEmpate.\n";
            break;
        }
    }

    return 0;
}



void imprimirTablero(char matriz[][3]){

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            cout<<matriz[i][j]<<" ";

            if (j < 2)
            {
                cout<<"|";
            }
        }
        cout<<endl;
        if (i < 2)
        {
            cout<<"--+--+--"<<endl;
        }
        
    }
}

bool hayGanador(char matriz[][3], char opcion){
    // filas
    for (int i = 0; i < 3; i++){
        if (matriz[i][0] == opcion && matriz[i][1] == opcion && matriz[i][2] == opcion){
            return true;
        }
    }

    // columnas
    for (int j = 0; j < 3; j++){
        if (matriz[0][j] == opcion && matriz[1][j] == opcion && matriz[2][j] == opcion){
            return true;
        }
    }

    // diagonales
    if (matriz[0][0] == opcion && matriz[1][1] == opcion && matriz[2][2] == opcion){
        return true;
    }

    if (matriz[2][0] == opcion && matriz[1][1] == opcion && matriz[0][2] == opcion){
        return true;
    }

    return false;
}

bool tableroLleno(char matriz[][3]){

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] == ' ')
            {
                return false; //no esta lleno
            }
            
        }
        
    }
    //esta lleno el tablero
    return true;
}


int contarOportunidadesDeGanar(char matriz[][3], char opcion){
    //se guardan cuantas oportunidades de ganar se encuentran
    int contador = 0;

    //revisar filas
    for (int i = 0; i < 3; i++)
    {
        int j = 0, vacio = 0; //j sirve para saber la cantidad de simbolos del jugador en el tablero y vacio para saber cuantos espacios hay

        for (int k = 0; k < 3; k++)
        {
            //un simbolo del jugador suma en j y un vacio en el tablero suma vacio
            if (matriz[i][k] == opcion)
            {
                j++;
            }
            if (matriz[i][k] == ' ')
            {
                vacio++;
            }
        }
        //verifica si esa fila es una oportunidad de ganar 
        if (j == 2 && vacio == 1)
        {
            contador++;
        }
        
    }

    //revisar colummnas
    for (int i = 0; i < 3; i++)
    {
        int j = 0, vacio = 0;
        for (int k = 0; k < 3; k++)
        {
            //un simbolo del jugador suma en j y un vacio en el tablero suma vacio
            if (matriz[k][i] == opcion)
            {
                j++;
            }
            if (matriz[k][i] == ' ')
            {
                vacio++;
            }
        }
        //verifica si esa fila es una oportunidad de ganar 
        if (j == 2 && vacio == 1)
        {
            contador++;
        }
    }

    //diagonal principal 
    //un simbolo del jugador suma en j y un vacio en el tablero suma vacio
    int j = 0, vacio = 0;

    for (int i = 0; i < 3; i++)
    {
        if (matriz[i][i] == opcion)
        {
            j++;
        }
        if (matriz[i][i] == ' ')
        {
            vacio++;
        }
    }
    //verifica si esa fila es una oportunidad de ganar 
    if (j == 2 && vacio == 1)
    {
        contador++;
    }
    
    //diagonal secundaria
    j = 0, vacio = 0;
    for (int i = 0; i < 3; i++)
    {
        if (matriz[i][2-i] == opcion)
        {
            j++;
        }
        if (matriz[i][2-i] == ' ')
        {
            vacio++;
        }
    }
    //verifica si esa fila es una oportunidad de ganar 
    if (j == 2 && vacio == 1)
    {
        contador++;
    }
    
    return contador;
}


int funcionHeuristica(char matriz[][3]){
    
    int ind1 = contarOportunidadesDeGanar(matriz, 'X');
    int ind2 = contarOportunidadesDeGanar(matriz, 'O');

    int h = ind2 - ind1;

    return h;
}

int minimax(char matriz[][3], bool turnoIa, int alfa, int beta){

    //primero verifica si alguno ya gano
    //si la IA gano (valor alto)
    if (hayGanador(matriz, 'O'))
    {
        return 100;
    }
    //si el humano gano debe ser un valor bajo
    if (hayGanador(matriz, 'X'))
    {
        return -100;
    }
    //si no hay mas espacio reotrna 0
    if (tableroLleno(matriz))
    {
        return 0;
    }
    
    //turno de la ia (la ia intenta maximizar el valor)
    if (turnoIa)
    {
        //inicializamos con un valor bajo porque la ia quiere el mayor posible
        int mejor = -100000;

        //recorre el tablero completo 
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                //solo prueba con las casillas vacias
                if (matriz[i][j] == ' ')
                {
                    matriz[i][j] = 'O';
                    //llama recursivamente a minimax, ahora sera el tueno del humano
                    int valor = minimax(matriz,false,alfa,beta);
                    
                    //deshacer la jugada para volver al estado originial
                    matriz[i][j] = ' ';

                    //la ia escoge el mejor valor (el mas grande)
                    if (valor > mejor)
                    {
                        mejor = valor;
                    }
                    //actualizar alfa, guarda la mejor opcion encontrada por la ia
                    if (mejor > alfa)
                    {
                        alfa = mejor;
                    }
                    //poda alfa-beta
                    if (beta <= alfa)
                    {
                        return mejor;
                    }
                    
                }
            }
        }//devuelve la mejor opcion que encontro
        return mejor;
    }
    //turno humano (el humano intenta minimizar el valor)
    //se inicia con un valor muy alto 
    int mejor = 10000;

    //recorre todo el tablero
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //solo prueba las casillas vacias
            if (matriz[i][j] == ' ')
            {
                //simula jugada humano
                matriz[i][j] = 'X';
                //llama recursivamente a minimax y vuelve a ser el turno de la ia
                int valor = minimax(matriz,true,alfa,beta);
                //deshacer la jugada
                matriz[i][j] = ' ';

                //el humano trata de escoger el valor mas pequeño
                if (valor < mejor)
                {
                    mejor = valor;
                }
                //actualiza beta
                if (mejor < beta)
                {
                    beta = mejor;
                }
                //poda alfa-beta
                if (beta <= alfa)
                {
                    return mejor;
                } 
            }
        }
    }    
    return mejor;    
}



void mejorJugadaIA(char matriz[][3], int &fila, int &col){
    //mejor guarda el resultado encontrado
    int mejor = -100000;
    //guarda la fila y la columna
    fila = -1;
    col = -1;
    //recorre todo el tablero
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //solo prueba en espacios vacios
            if(matriz[i][j]==' '){
                //simula la jugada de la ia
                matriz[i][j] = 'O';
                //evalua la jugada con minimax
                int valor = minimax(matriz, false, -100000, 100000);
                //deshacer la jugada
                matriz[i][j] = ' ';
                //compara si es la mejor opcion
                if(valor > mejor){
                    mejor = valor;
                    fila = i;
                    col = j;
                }
            }
        }
    }
}

void turnoIA(char matriz[][3]){
    int f, c;
    mejorJugadaIA(matriz, f, c);   //obtiene la mejor casilla
    matriz[f][c] = 'O';           //la ia va a jugar ahi
    cout << "IA juega en: " << (f+1) << " " << (c+1) << endl;
}


void turnoHumano(char matriz[][3]){
    int f, c;

    while(true){
        cout << "Fila (1-3): ";
        cin >> f;
        cout << "Columna (1-3): ";
        cin >> c;

        f--; c--;

        if(f>=0 && f<3 && c>=0 && c<3 && matriz[f][c]==' '){
            matriz[f][c] = 'X';
            break;
        }else{
            cout << "Movimiento invalido, intenta de nuevo"<<endl;
        }
    }
}