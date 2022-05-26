#include <string.h>
#include <stdio.h>
#define MODOFACIL 7
#define MODODIFICIL 10
//Declaración de las estructuras
struct TJugador {
    char NombreUsuario[50];
    char Contrasenya[50];
    //int vidas;
};

struct TPregunta {
    char pregunta[150];
    char opcion1[100];
    char opcion2[100];
    char opcion3[100];
    char opcioncorrecta;
};

struct TPista {
    int codigo;
    char pista[150];
};

//Para tener un código mas legible se extraen en funciones aparte el banner y la explicacion del juego
void banner () {
    printf("\n");
    printf("\n");
    printf("\n");
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

void codigofinal (int modo) { //si modo=1 facil y si modo=2 dificil
    int codigo;
    int codigocorrecto=3841;
    printf("\nProporcionadas todas las pistas, introduzca cual cree que es el nuevo codigo\n");
    scanf("%d", &codigo);
    if(codigo==codigocorrecto){
        banner();
        if (modo==1){
                printf("Enhorabuena por recuperar su contrasenya, puede seguir disfrutrando de la plataforma.\n");}
        else if (modo==2){
                printf("Enhorabuena por recuperar su contrasenya, ha obtenido ademas 1 mes gratis :) \n");}
        }
        else {
            printf("El codigo introducido no es correcto. Ha perdido su cuenta de netflix\n");
        }
        return;
}

int main () {
    struct TJugador Jugadores[200];//Se guarda espacio para 200 jugadores
    struct TPregunta Preguntas[10];//Hay un máximo de 10 preguntas
    struct TPista Pistas[7];
    int i=0, j=0, resultado; //i y j son iteradores y resultado es para comparar
    int usuarios;
    int opcion, seguro; //Opciones del menu
    int vidas=3;
    char opcionelegida; //Para guardar la opcion del usuario en las preguntas tipo test
    char nuevonombre[50], nuevacontrasenya[50];
    char pistas[10];
    FILE * ppreguntasfacil; //fichero de preguntas modo facil
    FILE * ppreguntasdificil; //fichero de preguntas modo dificil
    FILE * pDatosUsuarios; //fichero de usuarios
    FILE * ppistas; //fichero de pistas

    banner();

    //guardo los datos del fichero USUARIOS en la estructura y cierro el fichero

    pDatosUsuarios = fopen("datos usuarios.txt","r");
    if (pDatosUsuarios == NULL){
        printf ("Error en la apertura de fichero\n");
        return 0;
    }
    while (fscanf(pDatosUsuarios, "%s %s", Jugadores[i].NombreUsuario, Jugadores[i].Contrasenya)!=EOF){
        //printf("%s %s\n", Jugadores[i].NombreUsuario, Jugadores[i].Contrasenya);
        i++;
    }
    usuarios = i;
    fclose(pDatosUsuarios);

    printf("                   Iniciar Sesion\n                   Usuario:");
    scanf("%s", nuevonombre);
    fflush(stdin);
    printf("                   Contrasenya:");
    scanf("%s", nuevacontrasenya);

    for(i=0; i<usuarios; i++){
        resultado = strcmp(nuevonombre, Jugadores[i].NombreUsuario);
    }
        if(resultado==0){
            printf("Ya lo has intentado, no puedes recuperar tu cuenta\n");
            return 0;
        } else if (resultado==-1||resultado==1){
            strcpy(Jugadores[i].NombreUsuario, nuevonombre);
            strcpy(Jugadores[i].Contrasenya, nuevacontrasenya);

            pDatosUsuarios = fopen ("datos usuarios.txt", "w");
                if (pDatosUsuarios == NULL){
                    printf ("Error en la apertura de fichero\n");
                    return 0;
                }
                else {
                    for(j=0; j<usuarios+1; j++){
                        fprintf(pDatosUsuarios, "%s %s", Jugadores[j].NombreUsuario, Jugadores[j].Contrasenya);
                        fprintf(pDatosUsuarios, "\n");
                        }
                }
        fclose (pDatosUsuarios);
        }


    explicacion();

    do {
    printf("\n                   Introduzca la opcion deseada:\n                   1) Modo facil\n                   2) Modo extremo\n                   3) Salir del juego\n");
    scanf("%d", &opcion);
            switch (opcion){
        case 1 :
            printf("\n                   Ha elegido el modo facil\n");

            ppreguntasfacil = fopen ("preguntas facil.txt", "r");
            ppistas = fopen ("pistas codigo.txt", "r");
            j=0;
    //Se hace un bucle para ir imprimiendo las preguntas mientras queden vidas
        for (i=0; i<MODOFACIL; i++){
            if (ppreguntasfacil == NULL){
                printf("Error en la apertura de fichero\n");
                return 0;
            }

           printf ("\nPREGUNTA %d\n", i+1);

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
            printf("Correcto\nBuen trabajo. Aqui tiene su %d pista\n",j+1);
                fscanf(ppistas, "%d", &Pistas[j].codigo);
                printf("%d", Pistas[j].codigo);
                if (fgets(Pistas[j].pista, 150, ppistas)){
                printf ("%s",Pistas[j].pista);
                }
            j++;
           }

            else {
               printf ("Incorrecto\n");
               vidas--;
               printf("Ha perdido una vida y no recibira pista. Pongase las pilas.\n");
               printf ("Vidas restantes: %d\n", vidas);
           }
           if(vidas==0){
            printf("No le quedan vidas.\n");
            break;
           }
          }

    if (vidas>=0){
        codigofinal(opcion);
    }

            break;
        case 2 :
            printf("                   Ha elegido el modo extremo\n");

            ppreguntasdificil = fopen ("preguntas dificil.txt", "r");
            ppistas = fopen ("pistas codigo.txt", "r");
            j=0;
    //Se hace un bucle para ir imprimiendo las preguntas mientras queden vidas
        for (i=0; i<MODODIFICIL; i++){
            if (ppreguntasdificil == NULL){
                printf("Error en la apertura de fichero\n");
                return 0;
            }

           printf ("\nPREGUNTA %d\n", i+1);

           if (fgets(Preguntas[i].pregunta, 150, ppreguntasdificil)){
            printf ("%s",Preguntas[i].pregunta);
           }

            if (fgets(Preguntas[i].opcion1, 150, ppreguntasdificil)){
            printf ("%s",Preguntas[i].opcion1);
           }

            if (fgets(Preguntas[i].opcion2, 150, ppreguntasdificil)){
            printf ("%s",Preguntas[i].opcion2);
           }

            if (fgets(Preguntas[i].opcion3, 150, ppreguntasdificil)){
            printf ("%s",Preguntas[i].opcion3);
           }

           fscanf(ppreguntasdificil, "%c", &Preguntas[i].opcioncorrecta);

           fflush(stdin);
           scanf("%c", &opcionelegida);

           if (opcionelegida==Preguntas[i].opcioncorrecta){
            printf("Correcto\nBuen trabajo.");
                if (i%2==0){
                printf(" Aqui tiene su %d pista\n",j+1);
                fscanf(ppistas, "%d", &Pistas[j].codigo);
                printf("%d", Pistas[j].codigo);
                if (fgets(Pistas[j].pista, 150, ppistas)){
                printf ("%s",Pistas[j].pista);
                }} else printf("\n");
            j++;
           }

            else {
               printf ("Incorrecto\n");
               vidas--;
               printf("Ha perdido una vida y no recibira pista. Pongase las pilas.\n");
               printf ("Vidas restantes: %d\n", vidas);
           }
           if(vidas==0){
            printf("No le quedan vidas.\n");
            break;
           }
          }

    if (vidas>=0){
        codigofinal(opcion);
    }

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
            printf("ERROR, Introduzca un valor válido\n");
    }
    } while (opcion==3 && seguro==2 );




}



//[]{}
