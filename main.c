//librerias a usar
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
//funciones a trabajar en este proyecto
void menu();
void registro();
void consulta();
void retiro();
void deposito();
void inicio();
void modificacion();
void eliminacion();
//estructura de arreglo para el guardado de informacion de los usuarios del banco
struct clientes{
    float saldo;
    char name[25];
    int nip;
}users[15];
//menu principal
int main()
{
    setlocale(LC_ALL,"spanish");
    menu();
    printf("Pulse enter para salir");
    return 0;
}
//variable global que realiza el conteo de fallos
int fallos = 0;
//variable global que lleva el conteo de los usuarios registrados en el banco
int registrados = 0;
//funcion del menu de incio antes del registro
void menu()
{
    char name[15];
    int nip, opc;
    while(fallos!=3)
    {
        system("cls");
        printf("Banco cashfree\n");
        fflush(stdin);
        printf("Ingrese su nombre de usuario\n");
        gets(name);
        fflush(stdin);
        printf("Ingrese su nip");
        scanf("%d",&nip);

        if((strcmp(name,users[registrados].name)==0)&&(nip == users[registrados].nip))
        {
            system("cls");
            printf("Iniciando secion...");
            Sleep(4000);
            system("cls");
            inicio();
        }
        else
        {
            system("cls");
            printf("Error, el nip y usuario no coinciden con la base de datos, porfavor registrese\n");
            printf("Desea realizar el registro?\n1.si\n2.No");
            scanf("%d",&opc);
            if(opc == 1)
            {
                system("cls");
                Sleep(3000);
                registro();
            }
            if(opc == 2)
            {
                system("cls");
                fallos++;
                printf(" tienes %d/3 intentos, no los desperdicies, registrarte o el sistema te expulsara",fallos);
                Sleep(2000);
                menu();
            }
            else
            {
                system("cls");
                fallos++;
                printf("Error lo que ingresaste no es lo que se te pidio, intenta de nuevo, tienes %d/3 intentos.\n");
                Sleep(2000);
                menu();
            }
        }
    }
    printf("sobrepasate el limite de intentos....");
    system("cls");
    printf("saliendo del systema");
    Sleep(5000);
    return;
}
//funcion de registro del cliente
void registro()
{
    system("cls");
    if(registrados <= 15)
    {
        registrados++;
        fflush(stdin);
        printf("Ingrese su nombre de usuario\n");
        gets(users[registrados].name);
        fflush(stdin);
        printf("ahora  ingrese su nip, este puede ser como maximo 6 numeros");
        scanf("%d",&users[registrados].nip);
        Sleep(3000);
        system("cls");
        printf("El registro se ha realizado exitosamente\n");
        users[registrados].saldo = 0;
        printf("su saldo actual es de %d$",users[registrados].saldo);
        Sleep(5000);
        system("cls");
        menu();
    }
    else
    {
        printf("El limite de usuarios ha llegado, le recomiendo eliminar algun usuario inactivo de la base de datos");
        eliminacion();
    }

}
 int incorrect = 0;
//Funcion que realiza una consulta de informacion y saldo actual del usuario
void consulta()
{
    char name[25];
    int i =0;
    system("cls");
    while(incorrect!=2)
    {
        fflush(stdin);
        printf("Ingrese su nombre de usuario para realizar su consulta\n");
        gets(name);
        for(i;i<=registrados;i++)
        {
            if(strcmp(name,users[i].name)==0)
            {
                system("cls");
                fflush(stdin);
                printf("Nombre: %s\n",users[i].name);
                printf("Nip: %d\n",users[i].nip);
                printf("Tu saldo actual es de: %.2f",users[i].saldo);
                Sleep(7000);
                inicio();
            }
            if(i == registrados)
            {
                system("cls");
                incorrect++;
                printf("El nombre ingresado no coincide con el registro, intente registrarse si es que es nesesario");
                break;
                Sleep(3000);
                consulta();
            }
        }
    }
}
//funcion que realiza una resta del saldo actual con el saldo que se desee retirar
void retiro()
{
    float resta,resultado;
    int nip,i=0;
    system("cls");
    fflush(stdin);
    printf("Ingresa tu nip para realizar su retiro");
    scanf("%d",&nip);
    for(i;i<=registrados;i++)
    {
        if(nip == users[i].nip)
        {
            system("cls");
            printf("Ingrese la cantidad a retirar\n");
            scanf("%f",&resta);
            resultado = users[i].saldo - resta;
            users[i].saldo = resultado;
            system("cls");
            Sleep(3000);
            printf("Retiro realizado exitosamente");
            Sleep(4000);
            inicio();
        }
        if(i == registrados)
        {
            system("cls");
            printf("El nip ingresado no coincide, intente de nuevo porfavor");
            break;
            Sleep(3000);
            retiro();
        }
    }
}
//funcion que realiza una suma del saldo actual con el saldo que se desee depositar
void deposito()
{
    float suma,resultado;
    int nip,i=0;
    system("cls");
    fflush(stdin);
    printf("Ingresa tu nip para realizar tu deposito");
    scanf("%d",&nip);
    fflush(stdin);
    for(i;i<=registrados;i++)
    {
        if(nip == users[i].nip)
        {
            system("cls");
            fflush(stdin);
            printf("Ingrese la cantidad a depositar\n");
            scanf("%f",&suma);
            resultado = suma + users[i].saldo;
            users[i].saldo = resultado;
            system("cls");
            Sleep(3000);
            printf("Deposito realizado exitosamente");
            Sleep(2000);
            inicio();
        }
        if(i == registrados)
        {
            system("cls");
            fflush(stdin);
            printf("El nip ingresado no coincide, intente de nuevo porfavor");
            Sleep(3000);
            deposito();
        }
    }
}
//una vez que el usuario y el ni coinciden con la base de datos redirige al usuario a este menu
void inicio()
{
    int opc;
    do
    {
        system("cls");
        printf("Bienvenido/a\n");
        printf("Que deseas hacer?\n1.Depositar\n2.retirar\n3.Consultar\n4.Modificar informacion\n5.Salir");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            deposito();
            break;
        case 2:
            retiro();
            break;
        case 3:
            consulta();
            break;
        case 4:
            modificacion();
            break;
        case 5:
            system("cls");
            printf("redirigiendo al inicio, vuelva pronto");
            Sleep(3000);
            menu();
            break;
        default:
            system("cls");
            printf("Opcion no valida,%d no eslo que se te pidio que ingresaras",opc);
        }

    }while(opc!=5);
}
// funcion que realiza modificacion en los datos del usuario si este lo desea,ademas el usuario puede elegir que datos desea modificar
void modificacion()
{
    int i=0,opcs,new_nip;
    char name[26],new_name[26];
    system("cls");
    do
    {
        fflush(stdin);
        printf("Ingrese su nombre de usuario para que pueda realizar modificacion en sus datos\n");
        gets(name);
        for(i;i<=registrados;i++)
        {
            if(strcmp(name,users[i].name)==0)
            {
                system("cls");
                fflush(stdin);
                printf("Nombre: %s\n",users[i].name);
                printf("Nip: %d\n",users[i].nip);
                printf("Que campo desea modificar\n1.Nombre\n2.nip\n3.prefiero no modificar\n");
                scanf("%d",&opcs);
                switch(opcs)
                {
                case 1:
                    system("cls");
                    fflush(stdin);
                    printf("escriba el nuevo nombre porfavor\n");
                    gets(new_name);
                    strcpy(users[i].name,new_name);
                    Sleep(3000);
                    system("cls");
                    printf("los cambios fueron efectuados correctamente");
                    Sleep(3000);
                    break;
                case 2:
                    system("cls");
                    fflush(stdin);
                    printf("escriba el nuevo nip porfavor\n");
                    scanf("%d",&new_nip);
                    users[i].nip = new_nip;
                    Sleep(3000);
                    system("cls");
                    printf("los cambios fueron efectuados correctamente");
                    Sleep(3000);
                    break;
                case 3:
                    system("cls");
                    printf("redirigiendo al menu...");
                    Sleep(3000);
                    inicio();
                    break;
                default:
                    system("cls");
                    printf("opcion no valida, intente de nuevo");
                }
            }
       }
    }while(opcs!=3);
}
//solamente los "encargados", de la base de datos pueden realizar la eliminacion
void eliminacion()
{
    int calve = 123;//clave de acceso para loa administradores
    char namep[26];
    while(calve == 123)
    {
        system("cls");
        printf("Solo los administradores de este registro pueden acceder para realizar la eliminacion\n");
        fflush(stdin);
        printf("Ingrese la clave de administrador para poder realizar la eliminacion");
        scanf("%d",calve);
        if(calve == 123)
        {
            system("cls");
            fflush(stdin);
            printf("Bienvenido/a\n");
            printf("Muy bien ingrese el nombre del usuario que desee eliminar\n");
            gets(namep);
            for (int i = 0; i <=registrados; i++)
            {
                if (strcmp(namep,users[i].name) == 0)
                {
                    users[i] = users[i + 1];
                    registrados--;
                    Sleep(1000);
                    return;  // Importante salir de la función después de la eliminación
                }
                else
                {
                    system("cls");
                    printf("El nombre que usted ingreso no coincide, intente de nuevo");
                    Sleep(3000);
                    eliminacion();
                }
            }
        }
        else
        {
            system("cls");
            printf("Error, la clave que ingreso no es correcta");
            Sleep(5000);
            system("cls");
            printf("redirigiendo al menu");
            Sleep(2000);
            break;
        }
    }
}
