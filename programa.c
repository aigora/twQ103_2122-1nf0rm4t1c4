#include <stdio.h>
//Declaración de las estructuras
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


//Para tener un código mas legible se extraen en funciones aparte el banner y la explicacion del juego
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
    struct TPregunta Preguntas[10];//Hay un máximo de 10 preguntas
    int i=0, j=0, YaExiste=0; //i y j son iteradores y YaExiste es una variable bandera para detectar si un usuario ya ha sido registrado
    int opcion, seguro; //Opciones del menu
    char opcionelegida; //Para guardar la opcion del usuario en las preguntas tipo test
    FILE * ppreguntasfacil; //fichero de preguntas
    FILE * pDatosUsuarios; //fichero de usuarios

    banner();

    printf("                   Iniciar Sesion\n                   Usuario:");
    scanf("%s", &Jugadores[i].NombreUsuario);
    printf("                   Contrasenya:");
    scanf("%s", &Jugadores[i].Contrasenya);

/*
    pDatosUsuarios = fopen ("datos usuarios.txt", "w");
    if (pDatosUsuarios == NULL){
        printf ("Error en la apertura de fichero\n");
        return 0;
    }
    for(i=0; i<200; i++){
        for (j=1; j<199; j++){
            if (Jugadores[i].NombreUsuario==Jugadores[j].NombreUsuario){
                YaExiste=1;
            }
        }
    }
    if (YaExiste==1){
        printf("Ya ha perdido su cuenta\n");
        return 0;
    }

    fclose (pDatosUsuarios);*/

    explicacion();

    do {
    printf("\n                   Introduzca la opcion deseada:\n                   1) Modo facil\n                   2) Modo dificil\n                   3) Salir del juego\n");
    scanf("%d", &opcion);
            switch (opcion){
        case 1 :
            printf("\n                   Ha elegido el modo facil\n");

            ppreguntasfacil = fopen ("/Users/violetacaride/Desktop/ejercicioficheros/preguntasdemo.txt", "r");
            ppistas = fopen ("pistas.txt", "r");
    //Se hace un bucle para ir imprimiendo las preguntas mientras queden vidas
    do {
        for (i=0; i<6; i++){
            if (ppreguntasfacil == NULL){
                printf("Error en la apertura de fichero\n");
                return 0;
            }

            // esto irá en una función pero todavía lo estamos programando
           printf ("PREGUNTA %d\n", i+1);

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
            printf("Correcto\n Buen trabajo. Aqui tiene su %d pista\n",j+1);
                if (fgets(pistas, 150, ppistas)){
                printf ("%s",pistas);
                }
            j++;
           }
            else {
               printf ("Incorrecto\n");
               vidas--;
               printf("Ha perdido una vida y no recibira pista. Pongase las pilas.\n");
               printf ("Vidas restantes: %d\n", vidas);
           }
          }
    } while (vidas>0 && i<6);//mientras que queden vidas o preguntas por hacer

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
                    //Que vuelva introducir al menu de facil/dificil/salir
                } while  (seguro!=2 && seguro!= 1);
                }


            break;
        default:
            printf("ERROR, Introduzca un valor válido");
    }
    } while (opcion==3 && seguro==2 );




}



//[]{}
