# Tarea 1: Sistema de Gestión de Tickets de Soporte Técnico

## Descripción
Este proyecto implementa un sistema de gestión de tickets para un servicio de soporte técnico. Permite registrar tickets, asignar prioridades, mostrar los tickets registrados, procesar tickets y buscar tickets por su ID.

El sistema organiza los tickets en colas según su prioridad: **baja**, **media** y **alta**. Los tickets se procesan en orden de prioridad y antigüedad(fecha y hora de ingreso).

---

### Funciones implementadas:
1. **Registrar Ticket:**
   - Permite registrar un nuevo ticket con un ID único, descripción y fecha de creación.
   - Si el ID ya existe, solicita al usuario que ingrese otro ID.

2. **Asignar Prioridad:**
   - Cambia la prioridad de un ticket existente.
   - Los tickets se mueven automáticamente a la cola correspondiente según la nueva prioridad.

3. **Mostrar Tickets:**
   - Muestra todos los tickets registrados, organizados por prioridad (alta, media, baja).

4. **Procesar Ticket:**
   - Procesa (elimina) el ticket con mayor prioridad y más antiguo.
   - Si no hay tickets, muestra un mensaje indicando que no hay más tickets para procesar.

5. **Buscar Ticket:**
   - Busca un ticket por su ID y muestra sus detalles.
   - Si el ticket no existe, muestra un mensaje de error.

6. **Salir:**
   - Finaliza el programa.

---

## Opciones que no funcionan correctamente
Actualmente, las unicas funciones que presentan error son las LimpiarPantallita() y pausarPantalla Si encuentras algún error o comportamiento inesperado anexo a estas funciones, por favor, revisa el código o contacta al autor.

---

## Cómo ejecutar el programa
1. **Compilación:**
   - Asegúrate de tener un compilador de C instalado (por ejemplo, GCC).
   - Compila el programa con el siguiente comando:
     ```bash
     gcc -o tarea1 tarea1.c list.c
     ```

2. **Ejecución:**
   - Ejecuta el programa con el siguiente comando:
     ```bash
     ./tarea1
     ```

---

## Estructura del proyecto
- **`tarea1.c`:** Archivo principal que contiene la lógica del sistema de gestión de tickets.
- **`list.c` y `list.h`:** Implementación de una lista enlazada utilizada para manejar las colas de tickets.
- **`README.md`:** Documentación del proyecto.

---

## Casos de prueba (recomendados)
### Caso 1: Registrar un ticket
1. Selecciona la opción `1. Registrar Ticket`.
2. Ingresa un ID único y una descripción.
3. Verifica que el ticket se registre correctamente.

### Caso 2: Registrar un ticket con ID duplicado
1. Intenta registrar un ticket con un ID que ya exista.
2. El programa debe mostrar un mensaje de error y solicitar un nuevo ID.

### Caso 3: Mostrar tickets
1. Selecciona la opción `3. Mostrar Tickets`.
2. Verifica que los tickets se muestren organizados por prioridad.

### Caso 4: Procesar un ticket
1. Selecciona la opción `4. Procesar Ticket`.
2. Verifica que el ticket con mayor prioridad y más antiguo sea procesado.

### Caso 5: Buscar un ticket
1. Selecciona la opción `5. Buscar Ticket`.
2. Ingresa un ID existente y verifica que se muestren los detalles del ticket.

---

## Autor
- **Nombre:** Miguel Santibañez
- **Rol:** Desarrollador único
- **Fecha:** 13/04/2025

---

## Notas adicionales
- Asegúrate de que los archivos `list.c` y `list.h` estén en el mismo directorio que `tarea1.c` al compilar.
- Si encuentras algún error, revisa las funciones relacionadas o contacta al autor.
- De preferencia no rajar en su totalidad al autor de este contenido, muchas gracias.
