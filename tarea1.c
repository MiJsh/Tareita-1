#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <time.h>

// Enumero los niveles de prioridad primero
typedef enum {
    Prioridad_baja = 0,
    Prioridad_media = 1,
    Prioridad_alta = 2
} Prioridad;

typedef struct {
    int id;
    char descripcion[256];
    time_t fecha_creacion;
    Prioridad nivel_prioridad;
} Ticket;

List* ColasTickets[3]; // Arreglo de listas para cada nivel de prioridad

//Prototipos :P
void registrar_ticket();
void asignarPrio();
void mostrar_tickets();
void procesarTicket();
void buscarTicket();
void LimpiarPantallita();




const char * prioridad_to_string(Prioridad nivel_prioridad) {
    static const char * textosPrioridad[] = {
        "Prioridad Baja",
        "Prioridad Media",
        "Prioridad Alta"
    };
    if (nivel_prioridad < 0 || nivel_prioridad > 2) {
        return "Prioridad Invalida";
    }
    return textosPrioridad[nivel_prioridad];
}





int main() {
    for (int i = 0; i < 3; i++) {
        ColasTickets[i] = list_create(); // Inicializo cada lista
        if (ColasTickets[i] == NULL) {
            printf("Error: No se pudo inicializar la cola de prioridad %d.\n", i);
            return 1; // Error al crear la lista
        }
    }
    printf("Sistema de gestión de tickets inicializado.\n");

    int opcion;
    do {
        //LimpiarPantallita();
        printf("\nMenu:\n");
        printf("1. Registrar Ticket\n");
        printf("2. Asignar Prioridad\n");
        printf("3. Mostrar Tickets\n");
        printf("4. Procesar Ticket\n");
        printf("5. Buscar Ticket\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                registrar_ticket();
                break;
            case 2:
                asignarPrio();
                break;
            case 3:
                mostrar_tickets();
                break;
            case 4:
                procesarTicket();
                break;
            case 5:
                buscarTicket();
                break;
            case 6:
                printf("Saliendo del sistema.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 6);
    for (int i = 0; i < 3; i++) {
        list_clean(ColasTickets[i]);
        free(ColasTickets[i]);
    }
    return 0;
}

//FUNCIONES 

void registrar_ticket() {
    printf(":P");
}
void asignarPrio() {
    printf(":P");
}
void mostrar_tickets() {
    printf(":P");
}
void procesarTicket() {
    printf(":P");
}
void buscarTicket() {
    printf(":P");
}

void LimpiarPantallita() {
    #ifdef _WIN32
        system("cls"); // Comando para limpiar pantalla en Windows
    #else
        printf("\033[H\033[J"); // Comando ANSI para otros sistemas operativos
    #endif
}