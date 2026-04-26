# NotebookLM — Unidad 3: Procesos e Hilos

Notebook ID: `aced259b-7993-44ec-8cb7-06fd3a72b353`
Sources: `e41275eb` (Clase_3.pdf), `565650c6` (Material_de_Lectura_Clase_3-_Procesos_e_Hilos.pdf)
Fecha: 2026-04-26

---

## Consulta 1 — Resumen exhaustivo

**Pregunta:** Analizá todo el contenido de la Unidad 3 sobre Procesos e Hilos y dame un resumen exhaustivo y completo.

**Respuesta:**

### 1. Separación de Responsabilidades: Proceso vs. Hilo
En los SO tradicionales, el proceso agrupa dos características inseparables: **propiedad de recursos** (espacio de memoria, datos, archivos abiertos) y **planificación o ejecución**. Los SO modernos las tratan de forma independiente para mejorar el rendimiento.

- **Proceso:** La unidad que posee los recursos.
- **Hilo (Thread) o "proceso liviano":** La unidad que se planifica y ejecuta.

**Multihilo (Multithreading):** Capacidad del SO de dar soporte a múltiples hilos de ejecución simultáneos dentro de un único proceso.

### 2. Justificación y Casos de Uso Reales
Múltiples hilos permiten que varias acciones se ejecuten al mismo tiempo compartiendo la misma memoria — mucho más simple y eficiente que múltiples procesos separados. Ideal para tareas en primer y segundo plano, procesamiento asincrónico y manejo de grandes volúmenes de información, especialmente con procesadores multicore.

**Ejemplos del material:**
- **Procesador de texto:** Un hilo lee los comandos del usuario, otro realiza el guardado preventivo en disco. Con un solo hilo, el programa se "colgaría" mientras guarda datos.
- **Servidor Web:** El servidor crea un hilo distinto para cada request. Si un hilo se bloquea buscando una página en disco, los demás hilos siguen atendiendo otras peticiones de red simultáneamente.

### 3. Qué es Privado y Qué se Comparte
En un entorno multihilo, el proceso mantiene su único espacio de direcciones y su BCP, pero genera múltiples pilas y múltiples PCB de hilo (uno por hilo activo).

**Compartido por todos los hilos del proceso:**
- Espacio de memoria
- Variables globales
- Punteros a archivos
- Punteros a procesos hijos
- Señales
- Información estadística

**Privado de cada hilo:**
- Código
- Program Counter (PC)
- Registros (estado de ejecución)
- Pila (Stack)
- Variables locales

**Regla estricta:** Como todos los hilos residen en el mismo espacio de memoria y pertenecen al mismo usuario, **no existe ningún mecanismo de protección entre ellos** (a diferencia de procesos independientes). Si un hilo modifica una variable global, todos los demás hilos lo ven de inmediato.

### 4. Ventajas de Usar Hilos
- Crear, finalizar o intercambiar un hilo es **entre 10 y 100 veces más rápido** que hacerlo con un proceso.
- Mejoran radicalmente la **eficiencia de la comunicación**: para que dos procesos se comuniquen necesitan la intervención del SO. Como los hilos comparten memoria, se comunican directamente sin intervención del kernel.

### 5. Estados y Planificación de los Hilos
En los sistemas modernos, la planificación recae sobre los hilos, no sobre el proceso general.

**Estados:**
- **Creación:** La creación de un proceso dispara automáticamente la creación de un hilo inicial. Luego, mediante bibliotecas, se crean nuevos hilos.
- **Bloqueo:** Si el hilo espera un evento (leer un disco), guarda sus registros de usuario y se pausa. El procesador puede ejecutar otro hilo.
- **Desbloqueo:** Cuando el evento sucede, el hilo se mueve a la cola de listos.
- **Finalización:** Completa su tarea y se liberan sus datos.

**Reglas de estado importantes:**
- **No tiene sentido hablar de un hilo "Suspendido":** La suspensión aplica solo a nivel de proceso.
- Si el SO **suspende o finaliza un proceso**, esto implica obligatoriamente que **todos sus hilos sean suspendidos o finalizados** de inmediato.

### 6. Modelos de Implementación: ULT vs KLT
Las principales bibliotecas de hilos son: POSIX Pthreads (puede ser ULT o KLT), Win32 (solo KLT en Windows) y Java (usa la del sistema host).

**A. User Level Thread (ULT — Hilos a Nivel de Usuario)**
- **Funcionamiento:** La gestión se hace con una biblioteca en el espacio del usuario. El SO (kernel) **no sabe que los hilos existen**; solo ve un proceso ordinario. La aplicación programa su propio algoritmo de planificación.
- **Ventajas:**
  - Muy veloz: cambiar entre hilos no requiere intervención del núcleo (evita el "doble cambio de modo").
  - Portable: funciona en SO que no soportan hilos de forma nativa.
- **Desventajas (fatal):**
  - Si un hilo hace una syscall bloqueante (ej: pedir datos del disco), el SO bloquea al proceso entero → inutiliza todos los demás hilos del programa.
  - No se beneficia del multiprocesamiento real.

**B. Kernel Level Thread (KLT — Hilos a Nivel de Núcleo)**
- **Funcionamiento:** Toda la gestión la realiza el kernel. La aplicación usa una API con llamadas al SO para crear o manipular hilos. Se ejecuta en el espacio del kernel.
- **Ventajas:**
  - Si un hilo se bloquea, el SO puede asignar otro hilo del mismo proceso para que siga trabajando.
  - El kernel puede asignar múltiples hilos a distintos procesadores (aprovecha multicore).
  - Las propias rutinas del kernel pueden programarse en multihilo para ser más veloces.
- **Desventajas:**
  - Cada gestión requiere pedir permiso al SO → **doble cambio de modo** (usuario → kernel → usuario) → considerablemente más costoso y lento que ULT.

### 7. Concurrencia y Sincronización
La ejecución concurrente y solapada de múltiples hilos trae peligros lógicos. Como comparten datos, pueden sufrir:
- **Condición de carrera:** el resultado final depende del orden de ejecución.
- **Deadlock (interbloqueo):** bloqueo permanente por espera circular de recursos.

Para que un sistema multihilo funcione correctamente deben implementarse técnicas de sincronización (tema de la siguiente unidad).
