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

    for (int i = 0; i < 3; i++) {
        list_clean(colasTickets[i]);
        free(ColasTickets[i]);
    }
    return 0;
}