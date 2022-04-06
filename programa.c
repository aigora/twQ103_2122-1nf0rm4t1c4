#include <stdio.h>
//Declaración del vector de estructura
struct TJugador {
    char NombreUsuario[50];
//    char Contraseña[50];
};
int main () {
    int i=0;
    int opcion;
    struct TJugador Jugadores[200];//Se guarda espacio para 200 jugadores

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

    printf("                   Iniciar Sesion\n                   Usuario:");
    scanf("%s", &Jugadores[i].NombreUsuario);
    printf("                   Contrasenya:");
//    scanf("%s", &Jugadores[i].Contraseña);


    printf("\n\n                   Su cuenta de Netflix ha sido hackeada.\n                   Si quiere recuperarla debera adivinar la nueva contrasena. Hemos disenado un juego para ver quienes son los usuarios mas fieles a la plataforma.\n");
    printf("                   Superarlo bastará para poder volver a utilizar N3TFL1X. Como ve a continuacion, hay distintos niveles de juego.\n");
    printf("                   Si decide jugar al modo extremo, le regalaremos una suscripcion mensual gratis.\n");
    printf("                   Sin embargo, el modo facil, solo le permitira recuperar su cuenta. Debera contestar correctamente a las preguntas que le sean planteadas.\n");
    printf("                   Conforme vaya acertando, se le proporcionaran pistas acerca de la clave que busca.\n");
    printf("                   Le advertimos que debe pensar bien sus respuestas, porque si falla mas de tres preguntas, se cerrara el juego y nos quedaremos con su cuenta para siempre.\n");
    printf("                   Podra salir del juego en todo momento, pero una vez que lo haga, no habra vuelta atras.\n");


    printf("\n                   Introduzca la opcion deseada:\n                   1) Modo facil\n                   2) Modo dificil\n                   3) Salir del juego\n");




}



//[]{}
