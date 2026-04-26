# NotebookLM — Unidad 5: Interbloqueo (Deadlock)

Notebook ID: `aced259b-7993-44ec-8cb7-06fd3a72b353`
Sources: `1989a3bb` (Presentación Unidad 5), `17991bd6` (Fundamentos del Interbloqueo)
Fecha: 2026-04-26

---

## Consulta 1 — Resumen exhaustivo

**Pregunta:** Analizá todo el contenido de la Unidad 5 sobre Interbloqueo (Deadlock) y dame un resumen exhaustivo.

**Respuesta:**

### 1. Concepto Fundamental
El interbloqueo o deadlock es el bloqueo permanente de un conjunto de procesos que compiten por recursos del sistema o se comunican entre sí. Cada uno se encuentra bloqueado esperando un evento que solo puede ser generado por otro proceso que también está bloqueado dentro del mismo conjunto.

**Ejemplo clásico:** Cruce de calles donde cuatro autos llegan al mismo tiempo. Cada uno necesita avanzar al cuadrante que está ocupando el auto de su derecha. Ninguno puede avanzar. Deadlock permanente.

### 2. Tipos de Recursos
- **Recursos Reutilizables:** Solo pueden ser usados por un proceso a la vez y no se destruyen con su uso (ej: procesador, memoria, discos, archivos). El deadlock ocurre si cada proceso retiene un recurso y solicita otro.
  - *Ejemplo:* 200KB disponibles. Proceso A pide 80KB, B pide 70KB (quedan 50KB). Luego A pide 60KB más y B pide 80KB más. Ambos quedan bloqueados.
- **Recursos Consumibles:** Se crean y destruyen al ser usados (ej: interrupciones, señales, mensajes).
  - *Ejemplo:* A ejecuta `receive(mensaje_de_B)` bloqueante. B ejecuta `receive(mensaje_de_A)` bloqueante. Ambos esperan un mensaje que el otro nunca puede enviar.

### 3. Condiciones para el Interbloqueo
**Condiciones Necesarias:**
1. **Exclusión mutua:** Solo un proceso puede usar un recurso a la vez.
2. **Retención y espera:** Un proceso retiene recursos mientras espera otros nuevos.
3. **Sin expropiación (no preemption):** El SO no puede quitarle por la fuerza un recurso a un proceso.

**Condición Necesaria y Suficiente:**
4. **Espera circular:** Cadena cerrada de procesos donde cada uno posee un recurso que necesita el siguiente. Las 3 primeras condiciones no garantizan deadlock por sí solas.

### 4. Estrategia A: Prevención
Reglas estrictas de diseño para impedir que ocurra al menos una de las 4 condiciones.

**Métodos Indirectos:**
- *Evitar Exclusión Mutua:* Generalmente imposible (impresoras, archivos en escritura requieren exclusión).
- *Evitar Retención y Espera:* El proceso pide todos los recursos al inicio, o no puede tener ninguno asignado cuando pide más. Problema: muy ineficiente, hardware ocioso.
- *Evitar Sin Expropiación:* Si se le deniega un recurso, el proceso libera todo y vuelve a pedirlo. O el SO expropia recursos a procesos bloqueados. Solo sirve para recursos cuyo estado se puede guardar (no impresoras).

**Métodos Directos (atacan espera circular):**
- Se define un orden o jerarquía lineal para los recursos. Si un proceso pide tipo A, en el futuro solo puede pedir tipo B o superior.

### 5. Estrategia B: Predicción (Algoritmo del Banquero)
Evalúa dinámicamente cada petición en tiempo real. Requiere conocer de antemano las necesidades máximas de todos los procesos.

**Notación:**
- **R:** Vector de recursos totales del sistema.
- **D:** Vector de recursos disponibles actualmente. D = R − Σ A.
- **A:** Matriz de asignaciones actuales (A[i][j] = recursos tipo j asignados al proceso i).
- **N:** Matriz de necesidades máximas (N[i][j] = máximo que el proceso i va a necesitar del recurso j).

**Denegación de inicio:** Un proceso nuevo (n+1) solo inicia si las necesidades máximas de todos los procesos corriendo + las del nuevo ≤ R (recursos totales).

**Denegación de asignación:** Regla: N[i] − A[i] ≤ D. Si esto se cumple, el proceso puede terminar y liberar recursos.

**Estado Seguro:** Existe al menos una secuencia donde todos los procesos pueden terminar sin bloquearse.
**Estado Inseguro:** No garantiza deadlock inmediato, pero existe la posibilidad. Si el estado simulado es inseguro, se deniega el recurso.

**Ejemplo del material:**
- R = {9,3,6}. D = {0,1,1}.
- P2 tiene asignado {6,1,2}, necesidad máxima {6,1,3}. Le falta {0,0,1}.
- {0,0,1} ≤ {0,1,1} → P2 puede terminar. Devuelve {6,1,2}. Nuevo D = {6,2,3}.
- Con ese D, P1 también puede terminar. Sistema seguro.

### 6. Estrategia C: Detección
Permisiva: recursos se conceden siempre que estén disponibles. Periódicamente el SO ejecuta el algoritmo de detección.

**Algoritmo:** Usa D (disponibles), A (asignaciones), S (solicitudes pendientes).
1. Crear vector temporal T = D.
2. Marcar filas de A completamente en cero (procesos sin recursos asignados).
3. Buscar proceso sin marcar cuyas Solicitudes S ≤ T. Si no hay, terminar.
4. Marcarlo, sumar su A a T, volver al paso 3.
**Conclusión:** Procesos sin marcar al final = interbloqueo.

**Ejemplo del material:**
- R={2,1,1,2,1}. D={0,0,0,0,1}.
- A: P1={1,0,1,1,0} P2={1,1,0,0,0} P3={0,0,0,1,0} P4={0,0,0,0,0}
- S: P1={0,1,0,0,1} P2={0,0,1,0,1} P3={0,0,0,0,1} P4={1,0,1,0,1}
- Paso 1: T={0,0,0,0,1}.
- Paso 2: P4 tiene A={0,0,0,0,0} → se marca.
- Paso 3: P3 solicita {0,0,0,0,1} ≤ T={0,0,0,0,1} → se marca. T = {0,0,0,1,1}.
- Paso 4: P1 solicita {0,1,0,0,1} → falta R2. P2 solicita {0,0,1,0,1} → falta R3. Nadie más puede terminar.
- **Resultado: P1 y P2 están en interbloqueo.**

Frecuencia del chequeo: cada petición (detecta rápido, consume mucho CPU) vs esporádico (ahorra CPU, el deadlock dura más).

### 7. Estrategia D: Recuperación
Una vez detectado el deadlock, el SO debe romperlo:
1. **Abortar todos los procesos:** La solución más adoptada por los SO comerciales.
2. **Rollback:** Volver a un punto de control previo. Riesgo: el deadlock puede volver a formarse.
3. **Abortar sucesivamente:** Matar procesos uno a uno hasta que el algoritmo confirme que desapareció.
4. **Expropiar recursos:** Quitarle recursos a un proceso por la fuerza uno a uno hasta deshacer la espera circular.

**Criterios para elegir la víctima (menor costo):**
- El que consumió menos tiempo de CPU.
- El que produjo menor cantidad de salida.
- El que tiene mayor tiempo restante estimado.
- El que tiene menos recursos asignados.
- El que tiene menor prioridad.

---

## Consulta 2 — Seguimiento: matrices del Banquero, ejemplo de Detección y cuándo usar cada estrategia

**Pregunta:** Explicá la notación completa del Algoritmo del Banquero, mostrá un ejemplo paso a paso del algoritmo de detección, y cuándo conviene usar cada estrategia.

**Respuesta:** (ver secciones 5 y 6 arriba — la respuesta de seguimiento confirmó y expandió los mismos contenidos con el ejemplo numérico de detección P1–P4 y las recomendaciones de uso por estrategia)

**¿Cuándo usar cada estrategia?**
- **Prevención:** cuando se pueden imponer reglas estrictas de diseño. Costo: ineficiencia en uso de recursos.
- **Predicción (Banquero):** cuando se conocen de antemano las necesidades máximas. Limitante: en sistemas reales rara vez se conocen.
- **Detección:** cuando se prefiere ser permisivo y no se conocen las necesidades máximas. Se ejecuta periódicamente.
- **Recuperación:** siempre reactiva, se usa después de que Detección confirma el deadlock.

**En la práctica:** La mayoría de los SO comerciales usan Detección + Recuperación (abortar todos), porque la Prevención es muy restrictiva y el Banquero requiere información difícil de obtener.
