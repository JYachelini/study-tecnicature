# NotebookLM — Unidad 2: Procesos

Notebook ID: `aced259b-7993-44ec-8cb7-06fd3a72b353`
Sources: `44f7ad13` (Clase_2-_PROCESOS.pdf), `9f617654` (Clase_2.pdf)
Fecha: 2026-04-26

---

## Consulta 1 — Resumen exhaustivo

**Pregunta:** Analizá todo el contenido de la Unidad 2 sobre Procesos y dame un resumen exhaustivo y completo.

**Respuesta:**

### 1. Concepto de Proceso y Pseudoparalelismo
Un proceso es una abstracción de un programa en ejecución. En sistemas multiprogramados, el procesador cambia rápidamente entre programas durante decenas o cientos de milisegundos, dando la ilusión de paralelismo (**pseudoparalelismo**), a diferencia del verdadero paralelismo físico en sistemas multiprocesador.

- **Programa vs. Proceso:** Un programa es una entidad **pasiva** (archivo en disco con instrucciones). Un proceso es una entidad **activa** (tiene hilo de ejecución secuencial, contexto, estado y recursos asociados).

### 2. Imagen del Proceso en Memoria
Cuando un proceso se carga en memoria, su imagen contiene:

- **Contexto:** Registros que el SO y el procesador usan para gestionar el proceso: PC (Contador de Programa), IR (Registro de Instrucción), PSW (Palabra de Estado).
- **Texto (Código):** Las instrucciones que conforman el programa.
- **Datos:** Variables globales y datos del proceso.
- **Pila (Stack):** Datos temporales que crecen y decrecen dinámicamente: variables locales, llamadas a funciones, parámetros y direcciones de retorno.
- **Heap (Montículo):** Asignación dinámica de memoria (estructuras de listas, colas). Crece en sentido inverso a la pila.

### 3. Tablas de Control y el BCP (Bloque de Control de Proceso)
El SO usa cuatro tipos de tablas: Tablas de Memoria, Tablas de Dispositivos (E/S), Tablas de Archivos y **Tablas de Procesos**.

La **Tabla de Procesos** tiene una entrada por cada proceso, representada por el **BCP (Bloque de Control de Proceso / PCB)**. A través del BCP el SO puede proporcionar la multiprogramación.

**Atributos clave del BCP:**
- **PID:** Identificador único del proceso.
- **Estado y Prioridad.**
- **Datos de contexto:** Contenido de los registros del procesador (vital para reanudar un proceso pausado).
- **PC (Contador de Programa).**
- **Información de E/S:** Peticiones pendientes, archivos abiertos.
- **Punteros a memoria** (código, datos).
- **Datos de auditoría:** Tiempo de ejecución.

### 4. Modelos de Estados de un Proceso

**Modelo de 2 estados:**
Un proceso solo puede estar Ejecutando o No Ejecutando. Al crearse, entra a una cola FIFO en "No ejecutando". Un pequeño programa llamado **dispatcher** intercambia los procesos usando estrategia cíclica (*round-robin*).

**Modelo de 5 estados:**
Mejora el anterior separando los procesos que esperan por el procesador de los que esperan por hardware.

- **Nuevo:** El SO crea el BCP y asigna el PID, pero el código aún no se carga en memoria principal (permanece en disco secundario).
- **Listo:** Cargado en memoria y esperando su turno para el procesador.
- **Ejecutando:** Usando el procesador.
- **Bloqueado:** Pausado esperando que ocurra un evento o finalice una operación de E/S.
- **Saliente:** El proceso fue detenido o abortado.

Transiciones clave:
- Ejecutando → Listo: por agotar el tiempo de procesador asignado.
- Listo → Saliente: si el proceso "padre" decide matar al proceso hijo.
- Existen colas separadas para procesos Listos y para cada evento Bloqueante.

**Modelo de 7 estados (con Swapping):**
Si la memoria principal se llena y todos los procesos están Bloqueados, el procesador quedaría ocioso. El SO usa **swapping** (operación de E/S) para mover parcial o totalmente un proceso a disco y hacer espacio.

Dos estados nuevos:
- **Listo / Suspendido:** Proceso en disco, listo para ejecutar si lo traen a RAM.
- **Bloqueado / Suspendido:** Proceso en disco y además esperando un evento.

Transiciones clave:
- Nuevo → Listo/Suspendido: si no hay espacio en RAM al crearlo.
- Bloqueado/Suspendido → Bloqueado: el SO deduce estadísticamente que el evento esperado está por ocurrir y lo trae a RAM anticipadamente.

### 5. Modos de Ejecución
El procesador posee un bit en el registro **PSW** que define el modo:

- **Modo Usuario:** Acceso restringido, protege al sistema. Las referencias a memoria son relativas al registro base (BR). Solo se puede pedir servicios al SO mediante system calls.
- **Modo Núcleo (Kernel):** Control absoluto del sistema y referencias físicas a memoria. El SO ejecuta aquí las funciones críticas: creación de procesos, planificación, swapping, interrupciones y gestión de memoria.

### 6. Cambio de Contexto y Excepciones

Un **cambio de contexto (Context Switch)** ocurre cuando el SO interrumpe al proceso actual, salva su contexto y ejecuta otro. Puede ser provocado por:

- **Interrupciones:** Eventos asíncronos y externos.
  - Por reloj: agota el tiempo del proceso → Ejecutando a Listo.
  - Por E/S: un dispositivo finaliza su tarea → despierta a los procesos bloqueados.
- **Llamadas al Sistema (Syscalls):** Petición voluntaria del programa: abrir/leer un archivo, crear un hilo.
- **Excepciones:** Errores síncronos o condiciones internas. Se dividen en tres:
  1. **Abort:** Errores graves e irreversibles (hardware). El proceso no se reinicia → pasa a Saliente.
  2. **Fault:** Fallos corregibles. El SO interrumpe, corrige el problema y restaura el estado justo antes de la instrucción que falló para reintentarla. Ejemplo clásico: Page Fault.
  3. **Trap:** Se informa justo después de ejecutar la instrucción, el programa puede continuar. Ejemplo: breakpoint, división por cero.

*Nota:* El cambio de contexto implica un **Cambio de Modo** (Usuario → Kernel), pero no siempre un cambio de contexto completo: el SO puede atender la solicitud y reanudar el mismo proceso.

### 7. Ejecución del propio Sistema Operativo
El SO también es software y necesita ejecutarse en el procesador. Tres diseños:

1. **Núcleo sin procesos:** El SO es una única pieza de software que ejecuta fuera de todo proceso de usuario. Cada interrupción genera un cambio de contexto completo.
2. **Dentro de procesos de usuario:** El SO ejecuta sus rutinas virtualmente en el contexto y pila del proceso de usuario que provocó la interrupción o syscall. Evita el doble cambio de contexto → más eficiente.
3. **Basado en procesos:** Las funciones del SO se organizan como una colección de procesos independientes que ejecutan en modo núcleo. Mayor modularidad y permite paralelizar la ejecución de las rutinas del sistema.
