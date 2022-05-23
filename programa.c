#include <stdio.h>
//Declaración del vector de estructura
struct TJugador {
    char NombreUsuario[50];
    char Contrasenya[50];
    int vidas;
};

struct TPregunta {
    char pregunta[150];
    char opcion1[100];
    char opcion2[100];
    char opcion3[100];
    char opcioncorrecta;
};

void banner () {
    printf("               .....       ....     ..............    ...............   ...............   .....             .....     .....      .....     \n ");
    printf("               .,,,'.     .,,,'.    .,,,,,,,,,,,,'   .,,,,,,,,,,,,,,.   .,,,,,,,,,,,,,.   .,,,'             ',,,.     .,,,'.    .',,,'  \n  ");
    printf("               .,'','.    .,,,'.    .,,,'''''''''.   .'''''',,,'''''.   .,'','''''''''.   .,,,'             .,',.     .',,,'   .',,,'.     \n ");
    printf("               .,,,,,.    .,,,'.    .,','.                .',,,.        .,'','.           .,','             .,',.      .',',.  .,,,'.    \n ");
    printf("               .,,,',,.   .,,,'.    .,','.                .',,,.        .,,,,.            .,','             .,',.       .,,,'..,,,'.    \n ");
    printf("               .,',,,,'.  .,','.    .,','                 .',,'.        .,,,,.            .,','             .,',.        .,,,,,,,'.     \n ");
    printf("               .,,,,,','  .,','.    .,,,'.......          .',,,.        .,',,'.......     .,','             .,',.         ',',,,,.   \n  ");
    printf("               .,',''',,. .,','.    .,,,,,,,,,,.          .',,,.        .,,,,,,,,,,,.     .,','             .,',.         .',,,,.    \n ");
    printf("               .,','.',,'..,,,'.    .,,,''......          .',,,.        .,,,,'.......     .,','             .,',.         .',,,,.   \n");
    printf("               .,',. .',,''',,'.    .,','.                .',,,.        .,',,.            .,','             .,',.        .',,,,,'.     \n ");
    printf("               .,','  .,,,,,','.    .,','                 .',,,.        .,'',.            .,','             .,',.        .,,,,,','.   \n");
    printf("               .,','   .,,,,,,'.    .,','                 .',,'.        .,,,,.            .,,,'.            .,',.       .,,,'.',','      \n");
    printf("               .,',.   .',,,,,'.    .,','.........        .',,'.        .,',,.            .,,,''........    ',',.      .,,,'. .',,,.  \n");
    printf("               .,,,'    .,,,,,'.    .,',,,,,,,,,,'        .,,,,.        .,,,,.            .,,,,,,,,,,,,.    .,',.     .,,,,.   .,,',.  \n");
    printf("               .,,,.     .,,,,'.    .''''''.......         ....          ....             ..............    .'''.    .',,,.     .,','.   \n");
    printf("               .,,,.      .....                                                                                      .....       .'','.  \n");
    printf("                ..                                                                                                                  ..      \n");
    printf("\n");
    return;
}

void explicacion () {
    printf("\n\n                   Su cuenta de Netflix ha sido hackeada.\n                   Si quiere recuperarla debera adivinar la nueva contrasena. Hemos disenado un juego para ver quienes son los usuarios mas fieles a la plataforma.\n");
    printf("                   Superarlo bastara para poder volver a utilizar N3TFL1X. Como ve a continuacion, hay distintos niveles de juego.\n");
    printf("                   Si decide jugar al modo extremo, le regalaremos una suscripcion mensual gratis.\n");
    printf("                   Sin embargo, el modo facil, solo le permitira recuperar su cuenta. Debera contestar correctamente a las preguntas que le sean planteadas.\n");
    printf("                   Conforme vaya acertando, se le proporcionaran pistas acerca de la clave que busca.\n");
    printf("                   Le advertimos que debe pensar bien sus respuestas, porque si falla mas de tres preguntas, se cerrara el juego y nos quedaremos con su cuenta para siempre.\n");
    printf("                   Podra salir del juego en todo momento, pero una vez que lo haga, no habra vuelta atras.\n");

    return;
}



int main () {
    struct TJugador Jugadores[200];//Se guarda espacio para 200 jugadores
    struct TPregunta Preguntas[20];
    int i=0, vidas=3;
    int opcion, seguro;
    char opcionelegida;
    char pistas[5];
    FILE * ppreguntasfacil;
    FILE * ppistas;

    banner();

    printf("                   Iniciar Sesion\n                   Usuario:");
    scanf("%s", &Jugadores[i].NombreUsuario);
    printf("                   Contrasenya:");
    scanf("%s", &Jugadores[i].Contrasenya);

    explicacion();

    do {
    printf("\n                   Introduzca la opcion deseada:\n                   1) Modo facil\n                   2) Modo dificil\n                   3) Salir del juego\n");
    scanf("%d", &opcion);
    switch (opcion){
        case 1 :
            printf("\n                   Ha elegido el modo facil\n");
            ppreguntasfacil = fopen ("preguntasdemo.txt", "r");

            if (ppreguntasfacil == NULL){
                printf("Error en la apertura de fichero\n");
                return 0;
            }
        for (i=0; i<6; i++){
                   fflush(stdin);
            // esto irá en una función pero todavía lo estamos programando
            if (fgets(Preguntas[i].pregunta, 150, ppreguntasfacil)){
            printf ("%s",Preguntas[i].pregunta);
           }

            if (fgets(Preguntas[i].opcion1, 150, ppreguntasfacil)){
            printf ("%s",Preguntas[i].opcion1);
           }

            if (fgets(Preguntas[i].opcion2, 150, ppreguntasfacil)){
            printf ("%s",Preguntas[i].opcion2);
           }

            if (fgets(Preguntas[i].opcion3, 150, ppreguntasfacil)){
            printf ("%s",Preguntas[i].opcion3);
           }

           fscanf(ppreguntasfacil, "%c", &Preguntas[i].opcioncorrecta);

           fflush(stdin);
           scanf("%c", &opcionelegida);

           if (opcionelegida==Preguntas[i].opcioncorrecta){
            printf("Correcto\n Buen trabajo. Aqui tiene su %d pista\n",i+1);
            ppistas = fopen ("pistas.txt", "r");
                if (fgets(pistas, 150, ppistas)){
                printf ("%s",pistas);
                }


           } else {
               printf ("Incorrecto\n");
               vidas--;
               printf("Ha perdido una vida y no recibira pista. Pongase las pilas.\n");
               printf ("Vidas restantes: %d\n", vidas);
           }
          }


            // En este modo de juego, habrá 7 preguntas tipo test
            break;
        case 2 :
            printf("                   Ha elegido el modo dificil\n");
            //En este modo habrá 10 preguntas



            break;
        case 3 :
            printf("                   Va a perder su cuenta de netflix, ¿esta seguro que quiere salir?\n                    1) Si\n                    2) No\n");
            scanf("%d", &seguro);
                switch (seguro){
                do {
                    case 1 :
                    printf ("                   Ha perdido su cuenta de netflix.\n");
                    break;
                    case 2 :
                    break;
                } while  (seguro!=2 && seguro!= 1);
                }


            break;
        default:
            printf("ERROR, Introduzca un valor válido");
    }
    } while (opcion==3 && seguro==2 );




}



//[]{}
