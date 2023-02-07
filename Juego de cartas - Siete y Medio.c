//Siete y Medio - programado por Nicolás Quijano
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define APUESTA_MAX 1500
#define APUESTA_MIN 100
#define DINEROINICIAL 5000
#define DINEROBANCA 100000
void mostrarcarta(int posmazo,int *nc,int *pc,int mazo[]);
void mostrarvalor(int posmazo,int *vc,int mazo[]);
int premio1(int njugador, int posmazo, int mazo[], int premios[]);
int premio2y3(int njugador, int posmazo, int mazo[], int premios[]);
int main()
{

    int JUGADORES, RONDAS, temp,pos,posmazo=0,nc,pc,accion,vc,njugador=1,contacc=0,sumaitem4=0,sumaitem6=0,u=0;
    int mazo[40];
    int item1J=0, item1M=0, item2MAX=0,item2J=0,item2R=0,item5PRIM=0;

    char *cartanum[10]={"ANCHO de","DOS de","TRES de","CUATRO de", "CINCO de", "SEIS de","SIETE de","DIEZ de","ONCE de", "DOCE de"};
    char *cartapalo[4]={"BASTO","COPA","ESPADA","ORO"};
    float valores[10]={1,2,3,4,5,6,7,0.5,0.5,0.5};

    for(int i=0;i<1000;i++)
    {
        printf("Ingresar cantidad de jugadores: (minimo 1, maximo 5)\n");
        scanf("%d",&JUGADORES);
        if(JUGADORES>0&&JUGADORES<6)
            break;
        else
            printf("Numero invalido\n");
    }
    printf("Van a jugar %d jugadores.\n",JUGADORES);

    for(int i=0;i<1000;i++)
    {
        printf("Ingresar cantidad de rondas: (minimo 2, maximo 4)\n");
        scanf("%d",&RONDAS);
        if(RONDAS>1&&RONDAS<5)
        {
            break;
        }
        else
            printf("Numero invalido\n");
    }
    printf("Se van a jugar %d rondas.\n",RONDAS);

    int premios[1000];
    int montos[1000];
    int apuestas[1000];
    float jugpunt[1000];
    int item4[1000];
    int item5[1000];
    int item6[1000];

    for(int i=0;i<=JUGADORES+1;i++)
    {
        montos[i]=DINEROINICIAL;
        apuestas[i]=0;
        item4[i]=0;
        item5[i]=0;
        item6[i]=0;
    }
    montos[JUGADORES]=DINEROBANCA;

    for(int i=0;i<RONDAS;i++)
    {
        printf("\nLA RONDA %d HA COMENZADO\n\n",i+1);
        for(int i=0;i<=JUGADORES;i++)
        {
            if(i==JUGADORES)
            {
                printf("\nLa banca ha recibido una carta.\n\n");
            }
            else
            printf("\nEl jugador %d ha recibido una carta.\n",i+1);
        }
        system("pause");

        for(int i=1; i<=40; i++)
        {
            mazo[i-1]=i;
        }

        srand(time(NULL));
        for(int i=1;i<=40;i++)
        {
            pos=rand()%40;                                      //NUMERO RANDOM
            temp=mazo[i-1];                                     //ITERACIÓN-1
            mazo[i-1]=mazo[pos];                                //ITERACIÓN ACTUAL-1 SE IGUALA A LO QUE HAY EN LA POSICIÓN RANDOM
            mazo[pos]=temp;                                     //LO QUE HABÍA EN LA POSICIÓN RANDOM SE IGUALA A LA ITERACIÓN - 1
        }

        for(int i=0;i<=40;i++)                                  //PREVENTOR DE BUGS
        {
        mazo[i]=mazo[i]-1;
        }

        njugador=1;
        for(int x=0;x<JUGADORES;x++)                            //TURNO DE LOS JUGADORES
        {
            printf("\nTURNO DEL JUGADOR %d\n",njugador);
            mostrarcarta(posmazo,&nc,&pc,mazo);                 //MUESTRA LA CARTA
            item5[u]=nc;
            u++;
            printf("\nEl jugador %d ha recibido la siguiente carta: %s %s\n",njugador,cartanum[nc],cartapalo[pc]);
            mostrarvalor(posmazo,&vc,mazo);                     //MUESTRA EL VALOR ACUMULADO DE LAS CARTAS
            jugpunt[posmazo]=valores[vc];
            printf("\nPuntaje acumulado: %.1f\n",jugpunt[posmazo]);
            printf("\nEl jugador %d dispone del siguiente dinero: %d\n",njugador,montos[njugador-1]);

            for(int i=0;i<1000;i++)
            {
                printf("\nIngrese el monto a apostar: (minimo 100, maximo 1500)\n");
                scanf("%d", &apuestas[njugador-1]);
                if(apuestas[njugador-1]>=APUESTA_MIN&&apuestas[njugador-1]<=APUESTA_MAX&&apuestas[njugador-1]<=montos[njugador-1])
                {
                    break;
                }
                else
                    printf("Numero invalido\n");
            }

            montos[njugador-1]=montos[njugador-1]-apuestas[njugador-1];
            printf("\nUsted dispone del siguiente monto: %d\n",montos[njugador-1]);

            for(float x=0;x<40;x++)
            {
                printf("\nElija una de las siguientes opciones: \n");
                printf("\nPresione 1 si desea pedir otra carta\n");
                printf("Presione 2 si desea plantarse \n");
                scanf("%d",&accion);

                if(accion==1)
                {
                    posmazo++;
                    contacc++;
                    mostrarcarta(posmazo,&nc,&pc,mazo);
                    item5[u]=nc;
                    u++;
                    printf("\nEl jugador %d ha recibido la siguiente carta: %s %s\n",njugador,cartanum[nc],cartapalo[pc]);

                    mostrarvalor(posmazo,&vc,mazo);                     //MUESTRA EL VALOR ACUMULADO DE LAS CARTAS
                    jugpunt[posmazo]=valores[vc];
                    jugpunt[posmazo]=jugpunt[posmazo-1]+jugpunt[posmazo];
                    jugpunt[njugador-1]=jugpunt[posmazo];

                    premio1(njugador,posmazo,mazo,premios);
                    premio2y3(njugador,posmazo,mazo,premios);
                    printf("\nPuntaje acumulado: %.1f\n",jugpunt[posmazo]);
                }

                else if(accion==2)
                {
                    jugpunt[njugador-1]=jugpunt[posmazo];
                    posmazo++;
                    printf("\nEl jugador %d se ha plantado\n",njugador);
                    system("pause");
                    break;
                }

                x=jugpunt[posmazo];
                if(x>7.5)
                {
                    posmazo++;
                    printf("\nEl jugador %d ha perdido\n",njugador);

                    system("pause");
                    break;
                }
                else if(x==7.5)
                {
                    jugpunt[njugador-1]=jugpunt[posmazo];
                    posmazo++;
                    if(contacc>=2){
                    premios[njugador-1]=4;
                    }
                    printf("\nEl jugador %d ha llegado a juntar 7.5\n",njugador);
                    system("pause");
                    break;
                }
            }
            contacc=0;
            njugador++;
        }

        printf("\nTURNO DE LA BANCA\n");                            //EMPIEZA A JUGAR LA BANCA
        mostrarcarta(posmazo,&nc,&pc,mazo);
        item5[u]=nc;
        u++;

        mostrarvalor(posmazo,&vc,mazo);                             //MUESTRA EL VALOR ACUMULADO DE LAS CARTAS
        printf("\nLa banca ha recibido la siguiente carta: %s %s\n",cartanum[nc],cartapalo[pc]);
        jugpunt[posmazo]=valores[vc];
        jugpunt[JUGADORES]=jugpunt[posmazo];
        printf("\nPuntaje acumulado: %.1f\n",jugpunt[JUGADORES]);
        system("pause");

        if(jugpunt[JUGADORES]<=5.5)                                 //HACE QUE LA BANCA SIGA PIDIENDO CARTAS
        {
            for(float x=0;x<40;x++)
            {
                posmazo++;
                mostrarcarta(posmazo,&nc,&pc,mazo);
                item5[u]=nc;
                u++;

                mostrarvalor(posmazo,&vc,mazo);                      //MUESTRA EL VALOR ACUMULADO DE LAS CARTAS
                printf("\nLa banca ha recibido la siguiente carta: %s %s\n",cartanum[nc],cartapalo[pc]);

                jugpunt[posmazo]=valores[vc];
                jugpunt[posmazo]=jugpunt[posmazo-1]+jugpunt[posmazo];
                jugpunt[JUGADORES]=jugpunt[posmazo];
                printf("\nPuntaje acumulado: %.1f\n",jugpunt[JUGADORES]);
                system("pause");

                if(jugpunt[JUGADORES]>=6)
                {
                    jugpunt[posmazo]=valores[vc];
                    jugpunt[posmazo]=jugpunt[posmazo-1]+jugpunt[posmazo];
                    jugpunt[JUGADORES]=jugpunt[posmazo];
                    break;
                }
            }
        }

        else if(jugpunt[JUGADORES]>7.5)                             //INDICA CUANDO LA BANCA SUPERA LOS 7.5
        {
            printf("\nLa banca se ha pasado.\n");
        }

        else if(jugpunt[JUGADORES]<=7.5)                            //HACE QUE LA BANCA SE PLANTE
        {
            printf("\nLa banca se planta.\n");
        }
        system("pause");                                            //FIN DEL TURNO DE LA BANCA

        printf("\nLISTA DE PUNTAJES:\n");                           //DATOS DE LA RONDA
        for(int i=0;i<=JUGADORES;i++)                               //MUESTRA LOS PUNTAJES FINALES
        {
            if(i!=JUGADORES)
            {
            printf("Puntaje acumulado del jugador %d: %.1f\n",i+1,jugpunt[i]);
            }
            else
                printf("Puntaje acumulado de la banca: %.1f\n",jugpunt[i]);
        }

        printf("\nLISTA DE APUESTAS:\n");                               //MUESTA LAS APUESTAS REALIZADAS
        for(int i=0;i<JUGADORES;i++)
        {
            printf("Apuesta del jugador %d: %d\n",i+1,apuestas[i]);
        }

        printf("\nRESULTADOS DE LA RONDA %d:\n",i+1);
        for(int i=0;i<JUGADORES;i++)                                        //RECORRE TODOS LOS JUGADORES Y COMPARA CON LA BANCA
        {
            if(jugpunt[i]<=7.5&&jugpunt[JUGADORES]<=7.5)                    //NINGUNO SE PASA
            {
                if(jugpunt[i]>jugpunt[JUGADORES])                           //EL JUGADOR TIENE MAS PUNTOS QUE LA BANCA, EL JUGADOR GANA
                {
                    montos[i]=montos[i]+2*apuestas[i];                      //EL JUAGADOR GANA SU APUESTA
                    montos[JUGADORES]=montos[JUGADORES]-apuestas[i];        //SE LE RESTA A LA BANCA LO QUE GANO EL JUGADOR
                    printf("El jugador %d tiene un puntaje mas alto que la banca, el jugador %d gana.\n",i+1,i+1);
                }
                else if(jugpunt[i]<jugpunt[JUGADORES])                           //LA BANCA TIENE MAS PUNTOS QUE EL JUGADOR, LA BANCA GANA
                {
                    montos[JUGADORES]=montos[JUGADORES]+apuestas[i];
                    printf("El jugador %d tiene un puntaje mas bajo que la banca, el jugador %d pierde.\n",i+1,i+1);
                }
                else if(jugpunt[i]==jugpunt[JUGADORES])                          //NO SE PASA NINGUNO, EMPATAN, LA BANCA GANA
                {
                    montos[JUGADORES]=montos[JUGADORES]+apuestas[i];
                    printf("El jugador %d y la banca tienen el mismo puntaje, el jugador %d pierde.\n",i+1,i+1);
                }

                if(jugpunt[i]==7.5&&jugpunt[JUGADORES]!=7.5)                //PREMIOS SI EL JUGADOR LLEGA A 7.5
                {
                    item4[i]=1;
                    if(premios[i]==1)                                       //SE LE SUMA EL 50% DE LA APUESTA
                    {
                        montos[i]=montos[i]+0.5*apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-0.5*apuestas[i];
                        printf("El jugador %d ha llegado a 7.5 con siete y figura. Bonus: %.0f\n",i+1,0.5*apuestas[i]);
                    }
                    else if(premios[i]==2)                                       //SE LE SUMA EL 75% DE LA APUESTA
                    {
                        montos[i]=montos[i]+0.75*apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-0.75*apuestas[i];
                        printf("El jugador %d ha llegado a 7.5 con siete y figura del mismo palo. Bonus: %.0f\n",i+1,0.75*apuestas[i]);
                    }
                    else if(premios[i]==3)                                       //SE LE SUMA EL 100% DE LA APUESTA
                    {
                        montos[i]=montos[i]+apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-apuestas[i];
                        printf("El jugador %d ha llegado a 7.5 con siete de oro y rey de oro. Bonus: %d\n",i+1,apuestas[i]);
                    }
                    else if(premios[i]==4)                                       //SE LE SUMA EL 25% DE LA APUESTA
                    {
                        montos[i]=montos[i]+0.25*apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-0.25*apuestas[i];
                        item4[i]=0;
                        printf("El jugador %d ha llegado a 7.5 con mas de 2 cartas. Bonus: %.0f\n",i+1,0.25*apuestas[i]);
                    }
                }
            }

            if(jugpunt[i]<=7.5&&jugpunt[JUGADORES]>7.5)                     //LA BANCA SE PASA, EL JUGADOR GANA
            {
                montos[i]=montos[i]+2*apuestas[i];
                montos[JUGADORES]=montos[JUGADORES]-apuestas[i];
                printf("El jugador %d no se pasa pero la banca si, el jugador %d gana.\n",i+1,i+1);

                if(jugpunt[i]==7.5)                                         //PREMIOS SI EL JUGADOR LLEGA A 7.5
                {
                    item4[i]=1;
                    if(premios[i]==1)
                    {
                        montos[i]=montos[i]+0.5*apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-0.5*apuestas[i];
                        printf("El jugador %d ha llegado a 7.5 con siete y figura. Bonus: %.0f\n",i+1,0.5*apuestas[i]);
                    }
                    else if(premios[i]==2)
                    {
                        montos[i]=montos[i]+0.75*apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-0.75*apuestas[i];
                        printf("El jugador %d ha llegado a 7.5 con siete y figura del mismo palo. Bonus: %.0f\n",i+1,0.75*apuestas[i]);
                    }
                    else if(premios[i]==3)
                    {
                        montos[i]=montos[i]+apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-apuestas[i];
                        printf("El jugador %d ha llegado a 7.5 con siete de oro y rey de oro. Bonus: %d\n",i+1,apuestas[i]);
                    }
                    else if(premios[i]==4)
                    {
                        montos[i]=montos[i]+0.25*apuestas[i];
                        montos[JUGADORES]=montos[JUGADORES]-0.25*apuestas[i];
                        item4[i]=0;
                        printf("El jugador %d ha llegado a 7.5 con mas de 2 cartas. Bonus: %.0f\n",i+1,0.25*apuestas[i]);
                    }
                }
            }

            else if(jugpunt[i]>7.5&&jugpunt[JUGADORES]<=7.5)                     //EL JUGADOR SE PASA, LA BANCA GANA
            {
                item6[i]=1;
                montos[JUGADORES]=montos[JUGADORES]+apuestas[i];
                printf("El jugador %d se pasa, el jugador %d pierde.\n",i+1,i+1);
            }
            else if(jugpunt[i]>7.5&&jugpunt[JUGADORES]>7.5)                     //AMBOS SE PASAN, LA BANCA GANA
            {
                item6[i]=1;
                montos[JUGADORES]=montos[JUGADORES]+apuestas[i];
                printf("El jugador %d y la banca se pasan, el jugador %d pierde.\n",i+1,i+1);
            }
        }

        for(int j=0;j<JUGADORES;j++)                                       //COMPARA LAS APUESTAS PARA VER CUAL FUE LA MAYOR DE LA RONDA
        {
            if(apuestas[j]>item2MAX)
            {
                item2MAX=apuestas[j];
                item2J=j;
                item2R=i;
            }
        }

        printf("\nLISTA DE MONTOS ACTUALES:\n");                           //MUESTRA LOS MONTOS MODIFICADOS DESPUES DE LA RONDA
        for(int i=0;i<JUGADORES;i++)
        {
            printf("Dinero del jugador %d: %d\n",i+1,montos[i]);
        }
        printf("Dinero de la banca: %d\n",montos[JUGADORES]);

        printf("\nLA RONDA %d HA TERMINADO\n",i+1);
        system("pause");
        posmazo=0;                                                         //EL MAZO SE REINICIA PARA LA NUEVA RONDA
    }

    printf("\nESTADISTICAS DE LA PARTIDA:\n");
        for(int i=0;i<JUGADORES;i++)
        {
            if(montos[i]>item1M)                                       //ITEM1:SE COMPARAN LOS MONTOS DE LOS JUGADORES PARA VER QUIEN GANO MAS
            {
                item1M=montos[i];
                item1J=i;
            }
        }
        if(montos[JUGADORES]-DINEROBANCA>item1M-DINEROINICIAL)                       //SE COMPARA EL JUGADOR QUE MAS GANO CON LA BANCA
        {
            printf("La banca es quien mas ganancias tuvo\n");
        }
        else
        {
            printf("El jugador %d es quien mas ganancias tuvo\n",item1J+1);
        }

        printf("La apuesta maxima fue %d hecha por el jugador %d en la ronda %d\n",item2MAX,item2J+1,item2R+1);  //ITEM2:MUESTRA LOS VALORES GUARDADOS EN LAS VARIABLES

        if(montos[JUGADORES]>DINEROBANCA)                                   //ITEM3:SE COMPARAN LAS GANANCIAS DE LOS JUGADORES Y LA BANCA
        {
            printf("Los jugadores en conjunto, tuvieron perdidas.\n");
        }
        else if(montos[JUGADORES]<DINEROBANCA)
        {
            printf("Los jugadores en conjunto, tuvieron ganancias.\n");
        }

        for(int i=0;i<=JUGADORES;i++)           //ITEM4 E ITEM 6:SUMA LOS 1 Y LOS 0 GUARDADOS EN EL ARRAY ITEM4[I]
        {
            sumaitem4=sumaitem4+item4[i];       //SUMA LOS 1 Y LOS 0 GUARDADOS EN EL ARRAY ITEM4[I]
            sumaitem6=sumaitem6+item6[i];       //SUMA LOS 1 Y LOS 0 GUARDADOS EN EL ARRAY ITEM6[I]
        }
        if(sumaitem4>1)                                                              //ITEM4: MUESTRA LA CANTIDAD DE JUGADORES QUE CONSIGUIERON 7.5
        {
            printf("%d jugadores han llegado a 7.5 con siete y figura.\n",sumaitem4);       //MOSTRAR SUMATORIA DE VALORES DE ITEM4[I]
        }
        else if(sumaitem4==1)
        {
            printf("%d jugador ha llegado a 7.5 con siete y figura.\n",sumaitem4);  //MOSTRAR SUMATORIA DE VALORES DE ITEM4[I]
        }
        else if(sumaitem4==0)
        {
            printf("Ningun jugador ha llegado a juntar 7.5 con siete y figura.\n");
        }

    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c10=0,c11=0,c12=0;          //ITEM5:MUESTRA EL NUMERO DE CARTA QUE SALIO MAS VECES EN EL JUEGO
        for (int i=0; i<u; i++)
        {
            if (item5[i]==0){
                c1++;
            }
            else if (item5[i]==1){
                c2++;
            }
            else if (item5[i]==2){
                c3++;
            }
            else if (item5[i]==3){
                c4++;
            }
            else if (item5[i]==4){
                c5++;
            }
            else if (item5[i]==5){
                c6++;
            }
            else if (item5[i]==6){
                c7++;
            }
            else if (item5[i]==7){
                c10++;
            }
            else if (item5[i]==8){
                c11++;
            }
            else if (item5[i]==9){
                c12++;
            }
        }
    int item5F[12]={c1,c2,c3,c4,c5,c6,c7,0,0,c10,c11,c12};

        for(int i=0;i<12;i++)
        {
            if(item5F[i]>item5PRIM){
                item5PRIM=i;
            }

        }
        printf("El numero de carta que mas ha salido fue el %d \n",item5PRIM+1);

        if(sumaitem6>1)                                                     //ITEM6: MUESTRAS CUANTOS JUGADORES PERDIERON POR SUPERAR 7.5
        {
            printf("%d jugadores han perdido por pasarse.\n",sumaitem6);    //MOSTRAR SUMATORIA DE VALORES DE ITEM6[I]
        }
        else if(sumaitem6==1)
        {
            printf("%d jugador ha perdido por pasarse.\n",sumaitem6);       //MOSTRAR SUMATORIA DE VALORES DE ITEM6[I]
        }
        else if(sumaitem6==0)
        {
            printf("Ningun jugador ha perdido por pasarse.\n");
        }

    return 0;
}

void mostrarcarta(int posmazo,int *nc,int *pc,int mazo[])
{
    for(int g=0;g<10;g++)                                              //MUESTRA EL NUMERO DE LA CARTA
    {
        if(mazo[posmazo]%10==g)
        {
            *nc=g;
            break;
        }
    }
    for(int h=0;h<=4;h++)                                              //MUESTRA EL PALO DE LA CARTA
    {
            if(mazo[posmazo]>=0&&mazo[posmazo]<10){
                *pc=0;
                break;
            }
            else if(mazo[posmazo]>=10&&mazo[posmazo]<20){
                *pc=1;
                break;
            }
            else if(mazo[posmazo]>=20&&mazo[posmazo]<30){
                *pc=2;
                break;
            }
            else if(mazo[posmazo]>=30&&mazo[posmazo]<40){
                *pc=3;
                break;
            }
        }
    return;
}

void mostrarvalor(int posmazo,int *vc,int mazo[])
{
    for(int g=0;g<10;g++)                                              //MUESTRA EL VALOR DE LA CARTA
    {
        if(mazo[posmazo]%10==g)
        {
            *vc=g;
            break;
        }
    }
    return;
}

int premio1(int njugador, int posmazo, int mazo[], int premios[])
{
    int POS_ACTUAL = mazo[posmazo];                                 //POSICION ACTUAL EN EL MAZO
    int POS_ANTERIOR = mazo[posmazo-1];                             //POSICION ANTERIOR EN EL MAZO
    if((POS_ANTERIOR==6)||(POS_ANTERIOR==16)||(POS_ANTERIOR==26)||(POS_ANTERIOR==36))
    {
        if((POS_ACTUAL>6&&POS_ACTUAL<10)||(POS_ACTUAL>16&&POS_ACTUAL<20)||(POS_ACTUAL>26&&POS_ACTUAL<30)||(POS_ACTUAL>36&&POS_ACTUAL<40))
        {
            premios[njugador-1]=1;
        }
    }
    else if((POS_ANTERIOR>6&&POS_ANTERIOR<10)||(POS_ANTERIOR>16&&POS_ANTERIOR<20)||(POS_ANTERIOR>26&&POS_ANTERIOR<30)||(POS_ANTERIOR>36&&POS_ANTERIOR<40))
    {
        if(POS_ACTUAL==6||POS_ACTUAL==16||POS_ACTUAL==26||POS_ACTUAL==36)
        {
            premios[njugador-1]=1;
        }
    }
    return premios[njugador-1];
}

int premio2y3(int njugador, int posmazo, int mazo[], int premios[])
{
    int POS_ACTUAL = mazo[posmazo];                                 //POSICION ACTUAL EN EL MAZO
    int POS_ANTERIOR = mazo[posmazo-1];                             //POSICION ANTERIOR EN EL MAZO
    if(mazo[posmazo-1]==6)
    {
        if(POS_ACTUAL>6&&POS_ACTUAL<10)
        {
                premios[njugador-1]=2;
        }
    }
    else if(POS_ANTERIOR>6&&POS_ANTERIOR<10)
    {
        if(POS_ACTUAL==6)
        {
                premios[njugador-1]=2;
        }
    }
    else if(POS_ANTERIOR==16)
    {
        if(POS_ACTUAL>16&&POS_ACTUAL<20)
        {
            premios[njugador-1]=2;
        }
    }
    else if(POS_ANTERIOR>16&&POS_ANTERIOR<20){
        if(POS_ACTUAL==16)
        {
            premios[njugador-1]=2;
        }
    }
    else if(POS_ANTERIOR==26)
    {
        if(POS_ACTUAL>26&&POS_ACTUAL<30)
        {
            premios[njugador-1]=2;
        }
    }
    else if(POS_ANTERIOR>26&&POS_ANTERIOR<30)
    {
        if(POS_ACTUAL==26)
        {
            premios[njugador-1]=2;
        }
    }
    else if(POS_ANTERIOR==36)
    {
        if(POS_ACTUAL>36&&POS_ACTUAL<39)
        {
            premios[njugador-1]=2;
        }
        else if(POS_ACTUAL==39)
        {
            premios[njugador-1]=3;
        }
    }
    else if(POS_ANTERIOR>36&&POS_ANTERIOR<39)
    {
        if(POS_ACTUAL==36)
        {
            premios[njugador-1]=2;
        }
    }
    else if(POS_ANTERIOR==39)
    {
        if(POS_ACTUAL==36)
        {
            premios[njugador-1]=3;
        }
    }

    return premios[njugador-1];
}
