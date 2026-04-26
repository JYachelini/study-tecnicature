# NotebookLM — Unidad 1: Introducción a los Sistemas Operativos

Notebook ID: `aced259b-7993-44ec-8cb7-06fd3a72b353`
Sources: `4c9c0a77` (Clase_1_C2_Medrano.pdf), `e4634384` (Unidad_1__Introduccion_a_los_Sistemas_Operativos.pdf)
Fecha: 2026-04-26

---

## Consulta 1 — Resumen exhaustivo

**Pregunta:** Analizá todo el contenido de la Unidad 1 sobre Introducción a los Sistemas Operativos y dame un resumen exhaustivo y completo.

**Respuesta:**

### 1. ¿Qué es un Sistema Operativo?
Software base fundamental que permite controlar la ejecución de aplicaciones y actúa como interfaz entre estas y el hardware. Cumple dos funciones:

- **Visión Top-Down (Máquina Extendida):** Oculta la complejidad del hardware al programador y presenta una "máquina virtual" con servicios simples mediante llamadas al sistema (system calls).
- **Visión Bottom-Up (Administrador de Recursos):** Proporciona asignación ordenada y controlada de recursos entre programas que compiten por ellos. Administración en el **tiempo** (turnos de procesador) y en el **espacio** (memoria, bloques de disco).

### 2. Objetivos del SO
1. **Facilidad de Uso:** Organización jerárquica en capas (Hardware → SO → Utilidades → Aplicaciones → Usuario). Servicios: desarrollo y ejecución de programas, acceso uniforme a E/S, control de archivos, protección, detección de errores, estadísticas.
2. **Gestión de Recursos:** Dirige al procesador en el uso de los demás recursos. Administra tiempo de procesador, memoria principal y módulos de E/S.
3. **Capacidad para Evolucionar:** Adaptarse a nuevas actualizaciones de hardware, nuevos servicios y corrección de errores.

### 3. Historia y Evolución

**Primera Generación — Procesamiento en Serie (años 40–50):**
No existían los SO. Se interactuaba directamente con el hardware usando código máquina en tarjetas perforadas. Problemas: mala planificación (procesadores ociosos) y enorme tiempo de configuración (cargar compilador, programa y datos).

**Segunda Generación — Sistemas en Lotes Simples:**
Aparecen transistores y mainframes. Surge el **monitor o supervisor** (ancestro del SO). Los programas se pasaban en cintas magnéticas. El **conjunto residente** del monitor siempre estaba en memoria: cargaba el programa, le cedía el control, y al terminar cargaba el siguiente.
Nuevas características de hardware: Protección de memoria, Instrucciones privilegiadas, Temporizador, Modos de ejecución (Usuario y Kernel).

**Tercera Generación — Sistema Multiprogramado:**
Con circuitos integrados. IBM lanzó el System/360. Resolvió el procesador ocioso frente a E/S lenta.
- *Ejemplo del material:* Leer registro (15µs) + ejecutar (1µs) + escribir (15µs) = 31µs. El procesador operó solo 1µs: 96% del tiempo ocioso.
- *Solución (Multiprogramación):* Cargar varios programas en memoria. Si A hace E/S, el procesador ejecuta B.
- Requirió: Interrupciones de E/S y DMA.

**Sistemas de Tiempo Compartido (Time-sharing):**
Múltiples usuarios conectados desde terminales. Entrelaza ejecución con pequeños intervalos de tiempo (cada usuario recibe 1/n de la capacidad). Al llenarse la memoria, el estado se escribe al disco para cargar otro usuario (*swapping*).

### 4. Conceptos Básicos de Hardware

- **Registros del Procesador:** PC (Contador de Programa: dirección de la próxima instrucción), IR (Registro de Instrucción: instrucción que se ejecuta), PSW (Palabra de Estado: estado y modo de ejecución).
- **Shell:** Intérprete de comandos, interfaz entre usuario y SO. Al recibir un comando, crea un proceso hijo, ejecuta el programa y espera. La GUI es esencialmente un shell gráfico.
- **Ciclo de Instrucción:** Bucle infinito de Búsqueda (lee instrucción del PC, incrementa PC, carga en IR) y Ejecución (procesador-memoria, procesador-E/S, procesamiento de datos o salto de control).
- **Llamadas al Sistema (System Calls):** Instrucciones especiales que transfieren el control del programa de usuario al SO (saltando a modo kernel) para pedir un servicio como leer un archivo.

**Interrupciones:** Permiten pausar el secuenciamiento normal. 4 tipos:
1. De Programa (ej: división por cero, desbordamiento)
2. De E/S
3. Por Temporizador
4. Por Fallo de hardware

El ciclo modificado: tras ejecutar, el procesador verifica si hay interrupciones → salva estado del proceso → ejecuta el manejador de interrupciones → restaura el contexto.

**Técnicas de E/S:**
1. **E/S Programada:** El procesador interviene en toda la transferencia y espera en un bucle (busy waiting).
2. **E/S por Interrupciones:** El procesador da la orden y hace otra cosa. El módulo avisa con una interrupción al terminar, pero el procesador aún extrae las palabras una a una hacia memoria.
3. **DMA:** El procesador envía los parámetros base (operación, dispositivo, dirección, cantidad de palabras). El módulo DMA se encarga de todo el traspaso por el bus e interrumpe al procesador solo al principio y al final.

### 5. Los 5 Pilares del SO

**I. Procesos**
Un proceso = "un programa en ejecución". Posee espacio de direcciones con: Instrucciones, Datos y Contexto de ejecución (registros PC, IR, PSW + registros base y límite para protección de memoria).
Para cambios de contexto, el SO guarda los registros y punteros de archivos en la **Tabla de Procesos**.

**II. Gestión de Almacenamiento**
5 responsabilidades: 1) Aislamiento de procesos, 2) Asignación automática, 3) Soporte a programación modular, 4) Protección/control de acceso, 5) Almacenamiento a largo plazo.

- **Archivos y Directorios:** Un archivo es un concepto lógico jerárquico. Los programas tienen un directorio de trabajo actual (working directory). Al abrir un archivo con permiso, se devuelve un descriptor de archivo (entero).
- **Memoria Virtual:** Permite direccionar memoria lógicamente sin importar cuánta RAM física exista. Fragmenta programas en **Páginas** (bloques fijos). Si el procesador pide una instrucción y la página está en disco en lugar de RAM → **Page Fault**: el SO trae esa página reemplazando otra.

**III. Seguridad y Protección**
4 aspectos: Disponibilidad (proteger frente a caídas), Confidencialidad (evitar lectura por no autorizados), Integridad (evitar modificación por no autorizados), Autenticidad (verificar identidad).

**IV. Planificación y Gestión de Recursos**
Garantizar: Equitatividad, Respuesta diferencial (prioridades) y Eficiencia (minimizar tiempos de respuesta).
Usa colas de prioridad: colas a largo plazo (procesos esperando E/S o recién llegados) y colas a corto plazo (procesos listos para ejecutar).

**V. Estructura del Sistema**
Requiere Modularidad, Interfaces bien definidas y Estructura jerárquica (cada capa da servicios a la superior). Propuesta teórica de 13 niveles:
- Niveles 1–4 (Hardware): 1. Circuitos, 2. Set de instrucciones, 3. Procedimientos, 4. Interrupciones.
- Niveles 5–13 (Software): 5. Procesos primitivos, 6. Almacenamiento secundario (bloques), 7. Memoria virtual (páginas), 8. Comunicaciones (tuberías), 9. Sistema de archivos, 10. Dispositivos, 11. Directorios, 12. Procesos de usuario, 13. Shell.

### 6. Diseños Arquitectónicos del SO

Componentes internos: Sistema ejecutivo (servicios básicos), Núcleo o Kernel (planificación, fallos — no se puede expulsar a disco), HAL (capa de abstracción de HW), Drivers, GUI.

**Tipos de diseño:**
1. **Monolítico:** Gran colección de procedimientos donde cualquiera llama a cualquiera. Rápido pero todo acoplado. Sin ocultamiento de información. Estructura: procedimiento principal + procedimientos de servicio + procedimientos de utilidad.
2. **En capas:** Basado en anillos concéntricos. Primero fue THE de Dijkstra (6 capas, 0 a 5). También MULTICS. Para invocar un anillo más interno hay que hacer una system call.
3. **Microkernel:** Solo las funciones esenciales en el kernel. Drivers y sistemas de archivos corren como procesos de usuario. Alta confiabilidad: si falla el driver de audio, no cae todo el SO. Ejemplos: QNX, Symbian, L4, MINIX 3.
4. **Cliente-Servidor:** Derivado del microkernel. Comunicación entre clientes y procesos del SO (servidores) por paso de mensajes.
5. **Máquina Virtual:** Nació con VM/370. El "monitor de la MV" clona una copia exacta del hardware base. Permite correr diferentes SO simultáneamente sobre el mismo hardware. Si un SO ejecuta una instrucción de E/S, es "atrapada" y simulada por VM/370.
6. **Exokernel:** En lugar de clonar la máquina, particiona los recursos físicos y otorga subconjuntos a cada MV. Ahorra la capa de traducción de direcciones, solo verifica que ninguna MV invada los recursos de otra.
