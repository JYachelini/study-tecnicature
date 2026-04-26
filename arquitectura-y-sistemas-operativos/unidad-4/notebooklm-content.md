# NotebookLM — Unidad 4: Concurrencia, Exclusión Mutua y Sincronización

Notebook ID: `aced259b-7993-44ec-8cb7-06fd3a72b353`
Sources: `1048c73c` (Material de Lectura Clase 4), `17c6dc99` (Presentación Unidad 4)
Fecha: 2026-04-26

---

## Consulta 1 — Resumen exhaustivo

**Pregunta:** Analizá todo el contenido de la Unidad 4 sobre Concurrencia y dame un resumen exhaustivo y completo de todo lo que se enseña.

**Respuesta:**

### 1. Introducción y Principios de la Concurrencia
La concurrencia es un pilar fundamental en el diseño de los sistemas operativos modernos, abarcando multiprogramación, multiprocesamiento y procesamiento distribuido. Consiste en la gestión de procesos o hilos que se ejecutan simulando simultaneidad (entrelazándose en el tiempo en un procesador) o con paralelismo real (en múltiples procesadores), compitiendo o compartiendo recursos.

**El Problema Central:** En un sistema concurrente no se puede predecir la velocidad relativa de ejecución de los procesos, ya que esta depende de las políticas de planificación del SO, el manejo de interrupciones y la actividad de otros procesos.

### 2. La Condición de Carrera (Race Condition)
**Ejemplo del material (función eco):** Una función lee un carácter del teclado y lo guarda en una variable global (`vglob = getchar()`), para luego imprimirlo. Si el Proceso A lee el carácter e inmediatamente el SO lo pausa y ejecuta el Proceso B, este último sobrescribirá la variable global. Cuando A retome, imprimirá el carácter de B. Resultado: un carácter perdido y otro impreso dos veces.

**Definición:** Una Condición de Carrera ocurre cuando múltiples procesos leen y escriben sobre un recurso compartido, y el resultado final depende del orden temporal de sus ejecuciones (el último proceso en acceder define el valor final).

### 3. Interacción entre Procesos
1. **No se perciben entre sí (Competencia):** Son independientes y compiten por recursos críticos (ej: impresora). El tiempo de ejecución puede verse afectado por los otros.
2. **Se perciben indirectamente (Cooperación por compartición):** No conocen los PIDs de los otros pero comparten un objeto común (memoria compartida o dispositivo E/S). Las operaciones de escritura deben ser exclusivas.
3. **Se perciben directamente (Cooperación por comunicación):** Conocen sus PIDs y están diseñados para trabajar en conjunto comunicándose mediante mensajes.

### 4. Consecuencias y Desafíos de la Concurrencia
- **Exclusión Mutua:** Solo un proceso a la vez accede a un recurso compartido o crítico.
- **Sección Crítica:** Porción de código donde se usa el recurso compartido. Dos procesos no pueden estar en ella simultáneamente.
- **Starvation (Inanición):** Un proceso nunca termina porque el sistema le niega indefinidamente los recursos. Ejemplo: P1 y P3 se alternan el CPU por prioridad; P2 nunca logra su turno.
- **Deadlock (Interbloqueo):** Dos o más procesos bloqueados permanentemente porque cada uno tiene un recurso que el otro necesita. Ejemplo: P4 tiene el disco y necesita la impresora; P5 tiene la impresora y necesita el disco.

### 5. Soluciones por Hardware
**A) Deshabilitar Interrupciones:** El proceso deshabilita las interrupciones antes de entrar a su sección crítica.
- Desventaja: Solo funciona en monoprocesador. Puede degradar gravemente el rendimiento.

**B) Instrucciones especiales (testAndSet / Exchange):** Operaciones atómicas sobre memoria compartida. Funcionan usando una variable compartida para garantizar exclusión mutua.
- Ventajas: Aplicables a cualquier número de procesos y secciones críticas.
- Desventajas: Generan Espera Activa, riesgo de Starvation (selección arbitraria) y riesgo de Deadlock (proceso de alta prioridad interrumpe a uno de baja que está en la sección crítica).

### 6. Semáforos
Variable entera inicializada a valor no negativo. Operaciones atómicas:
- **semWait:** Decrementa el valor. Si queda negativo, el proceso se bloquea en la cola.
- **semSignal:** Incrementa el valor. Si pasa a ≤ 0, desbloquea un proceso de la cola.

Tipos:
- **Semáforo fuerte:** cola interna con política FIFO (evita Starvation).
- **Semáforo débil:** sin orden definido.
- **Semáforo binario (mutex):** valores 0 o 1 solamente.

**Advertencia:** Usar semáforos directamente es propenso a errores humanos.

### 7. Monitores
- **Privacidad:** datos internos solo accesibles mediante métodos del monitor.
- **Exclusión nativa:** solo un proceso ejecuta dentro del monitor a la vez. Si otro intenta ingresar, se suspende automáticamente.
- Maneja variables de condición y colas internas.

### 8. Paso de Mensajes
Primitivas: `send(destino, mensaje)` y `receive(origen, mensaje)`. Funciona en monoprocesador, multiprocesador y distribuido.

**Configuraciones de bloqueo:**
1. Envío bloqueante + Recepción bloqueante: ambos esperan.
2. **Envío no bloqueante + Recepción bloqueante (la más utilizada):** el emisor sigue trabajando, el receptor espera.
3. Envío no bloqueante + Recepción no bloqueante: ninguno frena.

**Advertencia envío no bloqueante:** ante un error, el emisor puede saturar el sistema. La responsabilidad de confirmar recepción queda en el programador. Si la recepción es bloqueante y el mensaje nunca llega, el proceso queda bloqueado indefinidamente.

**Direccionamiento:**
- **Directo:** los procesos usan el PID del otro.
- **Indirecto (buzón/mailbox):** mensajes a estructuras compartidas. Desacopla emisor y receptor. N emisores → 1 receptor = puerto.

**Formato del mensaje:**
- Longitud fija: mínimo overhead.
- Longitud variable: Cabecera (origen, destino, tipo, longitud) + Cuerpo/Payload.

---

## Consulta 2 — Reglas, restricciones y advertencias

**Pregunta:** ¿Cuáles son las reglas, restricciones, advertencias y errores comunes de la Unidad 4?

**Respuesta:**

- **Velocidad impredecible:** No se puede predecir la velocidad relativa de ejecución de los procesos.
- **Intervención del SO:** Para aplicar exclusión mutua, es requisito estricto la intervención del SO.
- **Consistencia en escritura:** En cooperación por compartición, solo las operaciones de escritura deben ser mutuamente excluyentes.
- **Condición de carrera:** Error donde el resultado depende del orden temporal. Síntoma: pérdida o duplicación de datos.
- **Inanición:** Un proceso nunca termina porque el sistema arbitrariamente le niega el acceso a recursos.
- **Interbloqueo:** Falla crítica donde dos o más procesos tienen recursos que el otro necesita.
- **Deshabilitar interrupciones:** Solo funciona en monoprocesador. Puede degradar gravemente el rendimiento.
- **Espera activa (testAndSet/Exchange):** Consume inútilmente tiempo y ciclos del procesador.
- **Inicialización de semáforos:** Solo puede inicializarse a valor no negativo.
- **Atomicidad:** semWait y semSignal deben ser siempre atómicas.
- **Semáforos propensos a errores:** Usarlos directamente en el código es difícil y propenso a errores.
- **Privacidad en Monitores:** Los datos no son públicos; solo se acceden mediante funciones internas. Un proceso a la vez.
- **Envío no bloqueante:** Riesgo de saturar el sistema ante errores. Responsabilidad de confirmación recae en el programador.
- **Recepción bloqueante con mensaje perdido:** El proceso queda bloqueado indefinidamente.

---

## Consulta 3 — Seguimiento: testAndSet, Exchange y Productor-Consumidor

**Pregunta:** Explicá en detalle cómo funcionan testAndSet y Exchange. También explicá el problema del Productor-Consumidor con semáforos.

**Respuesta:**

**testAndSet y Exchange:** El material confirma que son instrucciones especiales del procesador que funcionan con memoria compartida para garantizar exclusión mutua. Son indivisibles a nivel de hardware. El pseudocódigo específico NO está en el material de la unidad.

**Productor-Consumidor:** Este tema NO está en el material de la Unidad 4. La respuesta de NotebookLM lo marcó explícitamente como conocimiento externo. Incluido en el HTML como ejemplo ilustrativo con esa aclaración implícita.

Resolución con 3 semáforos:
- `mutex` (init=1): exclusión mutua sobre el buffer.
- `vacíos` (init=N): cuenta espacios libres.
- `llenos` (init=0): cuenta elementos disponibles.

Productor: `semWait(vacíos)` → `semWait(mutex)` → inserta → `semSignal(mutex)` → `semSignal(llenos)`.
Consumidor: `semWait(llenos)` → `semWait(mutex)` → retira → `semSignal(mutex)` → `semSignal(vacíos)`.
