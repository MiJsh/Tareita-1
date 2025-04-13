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

List* ColasTickets[3];

//Prototipos :P
void registrar_ticket();
void asignarPrio();
void mostrar_tickets();
void procesarTicket();
void buscarTicket();
void LimpiarPantallita();
int lower_than();
void pausarPantalla();



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
        ColasTickets[i] = list_create();
        if (ColasTickets[i] == NULL) {
            printf("Error: No se pudo inicializar la cola de prioridad %d.\n", i);
            return 1;
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
        //pausarPantalla();

    } while (opcion != 6);

    for (int i = 0; i < 3; i++) {
        list_clean(ColasTickets[i]);
        free(ColasTickets[i]);
    }
    return 0;
}

//FUNCIONES 

int lower_than(void *data1, void *data2) {
    Ticket *ticket1 = (Ticket *)data1;
    Ticket *ticket2 = (Ticket *)data2;
    return ticket1->fecha_creacion < ticket2->fecha_creacion;
}

void registrar_ticket() {
    //alojo memoria para el ticket
    Ticket *nuevoTicket = (Ticket *)malloc(sizeof(Ticket));
    if (nuevoTicket == NULL) {
        printf("Error, no se alojo memoria");
        return;
    }
    //Asignar ID ticket
    printf("Ingrese el ID del ticket:");
    scanf("%d", &nuevoTicket->id);
    getchar();

    //Asignar descripcion ticket
    printf("Ingrese una descripcion para el ticket: ");
    fgets(nuevoTicket->descripcion, sizeof(nuevoTicket->descripcion), stdin);
    nuevoTicket->descripcion[strcspn(nuevoTicket->descripcion, "\n")] = '\0';

    //Asignar fecha de creacion ticket
    nuevoTicket->fecha_creacion = time(NULL);
    nuevoTicket->nivel_prioridad = Prioridad_baja;
    
    //insertar el ticket en la lista correspondiente
    list_sortedInsert(ColasTickets[Prioridad_baja], nuevoTicket, lower_than);
    printf("Ticket registrado con exito.\n");
}
void asignarPrio() {
    int id;
    printf("Ingrese el ID del ticket cuya prioridad quiera cambiar: ");
    scanf("%d", &id);
    getchar();

    int nuevaPrioridad;
    printf("Seleccione la nueva prioridad (0: Baja, 1: Media, 2: Alta): ");
    scanf("%d", &nuevaPrioridad);
    getchar();

    if (nuevaPrioridad < 0 || nuevaPrioridad > 2) {
        printf("Prioridad invalida.\n");
        return;
    }
    for (int i = 0 ; i < 3 ;i++)
    {
        void *Puntero = list_first(ColasTickets[i]);	
        while (Puntero != NULL) {
            Ticket *ticket = (Ticket *)Puntero;
            if (ticket-> id == id) {
                list_popCurrent(ColasTickets[i]);
                ticket->nivel_prioridad = nuevaPrioridad;
                list_sortedInsert(ColasTickets[nuevaPrioridad], ticket, lower_than);
                printf("Prioridad del ticket con ID %d cambiada a %s.\n", id, prioridad_to_string(nuevaPrioridad));
                return;
            }
            Puntero = list_next(ColasTickets[i]);
        }
    }
    printf("Ticket con ID %d no encontrado.\n", id);
}

void mostrar_tickets() {
    int Aux = 0;
    for (int nivel = Prioridad_alta; nivel >= Prioridad_baja; nivel--) {
        void *Puntero = list_first(ColasTickets[nivel]);
        if (Puntero != NULL) {
            printf("\n=== Tickets con prioridad: %s ===\n", prioridad_to_string((Prioridad)nivel));
            Aux = 1;
        }
        while (Puntero != NULL) {
            Ticket *ticket = (Ticket *)Puntero;
            // Mostrar los detalles del ticket
            printf("ID: %d\n", ticket->id);
            printf("Descripción: %s\n", ticket->descripcion);
            printf("Fecha de creación: %s", ctime(&ticket->fecha_creacion));
            printf("--------------------------\n");
            Puntero = list_next(ColasTickets[nivel]);
        }
    }
    if (!Aux) {
        printf("No hay tickets registrados.\n");
    }
}

void procesarTicket() {
    for (int nivel = Prioridad_alta; nivel >= Prioridad_baja; nivel--) {
        Ticket *ticket = (Ticket *)list_first(ColasTickets[nivel]);
        if (ticket != NULL) {
            printf("Procesando ticket con ID: %d\n", ticket->id);
            printf("Descripción: %s\n", ticket->descripcion);
            printf("Fecha de creación: %s", ctime(&ticket->fecha_creacion));
            printf("Prioridad: %s\n", prioridad_to_string(ticket->nivel_prioridad));
            printf("--------------------------\n");
            free(ticket);
            return;
        }
    }
    printf("No quedan mas tickets para procesar.\n");
}

void buscarTicket() {
    int id;
    printf("Ingrese el ID del ticket a buscar: ");
    scanf("%d", &id);
    getchar();

    for (int nivel = Prioridad_alta; nivel >= Prioridad_baja; nivel--) {
        void *Puntero = list_first(ColasTickets[nivel]);
        while (Puntero != NULL) {
            Ticket *ticket = (Ticket *)Puntero;
            if (ticket->id == id) {
                printf("Ticket encontrado:\n");
                printf("ID: %d\n", ticket->id);
                printf("Descripción: %s\n", ticket->descripcion);
                printf("Fecha de creación: %s", ctime(&ticket->fecha_creacion));
                printf("Prioridad: %s\n", prioridad_to_string(ticket->nivel_prioridad));
                printf("--------------------------\n");
                return;
            }
            Puntero = list_next(ColasTickets[nivel]);
        }
    }

}

void LimpiarPantallita() {
    #ifdef _WIN32
        system("cls"); // Comando para limpiar pantalla en Windows
    #else
        printf("clear");
    #endif
}
void pausarPantalla() {
    printf("Presione Enter para continuar...");
    getchar();
}