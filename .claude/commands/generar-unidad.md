# Generar Unidad de Estudio

Antes de arrancar, leé estos dos archivos para entender cómo trabajar:
- `.claude/skills/pdf-to-study.md` → flujo completo de NotebookLM (IDs de notebooks, comandos, archivos a guardar)
- El archivo de la skill de diseño frontend en tu instalación de Claude Code

Luego preguntame:
1. ¿Qué materia? (arquitectura-y-sistemas-operativos, matematica, organizacion-empresarial, programacion)
2. ¿Qué número de unidad?

## Pasos a seguir

### 1. Preparar el material

- Verificar que los PDFs estén en `$MATERIA/unidad-$N/material/` sin espacios en los nombres.
  Si hay espacios, renombrar antes de continuar.
- Verificar que existan las carpetas `material/` y `output/`. Crearlas si no están.

### 2. Extraer contenido desde NotebookLM

Seguir el flujo completo de `.claude/skills/pdf-to-study.md`:

**a) Listar fuentes y encontrar los source IDs de la unidad:**
```bash
notebooklm source list --json --notebook <NOTEBOOK_ID>
```
Si los PDFs no están en NotebookLM, subirlos:
```bash
notebooklm source add "$MATERIA/unidad-$N/material/archivo.pdf" \
  --type file --notebook <NOTEBOOK_ID> --json
```

**b) Consulta inicial al chat:**
```bash
notebooklm ask "Analizá todo el contenido de la Unidad N..." \
  --notebook <NOTEBOOK_ID> -s <SOURCE_ID_1> [-s <SOURCE_ID_2> ...]
```
Guardar la respuesta en `$MATERIA/unidad-$N/notebooklm-content.md`.

**c) Generar guía de estudio (SIEMPRE):**
```bash
notebooklm generate report \
  --format study-guide \
  --append "Incluí todos los conceptos, definiciones, ejemplos y técnicas de la unidad. Exhaustivo." \
  --notebook <NOTEBOOK_ID> \
  -s <SOURCE_ID_1> [-s <SOURCE_ID_2> ...] \
  --json
```
Esperar y descargar:
```bash
notebooklm artifact wait <TASK_ID> -n <NOTEBOOK_ID> --timeout 900
notebooklm download report $MATERIA/unidad-$N/notebooklm-report.md \
  -a <TASK_ID> -n <NOTEBOOK_ID>
```

Al finalizar este paso deben existir:
- `$MATERIA/unidad-$N/notebooklm-content.md`
- `$MATERIA/unidad-$N/notebooklm-report.md`

### 3. Analizar el contenido

Leer ambos archivos (`notebooklm-content.md` y `notebooklm-report.md`) e identificar:
- Tema central de la unidad
- Conceptos y definiciones clave
- Procesos o pasos secuenciales
- Ejemplos y código que aparezcan en el material
- Términos técnicos importantes
- Reglas, restricciones o advertencias

### 4. Diseño

Antes de escribir una línea de CSS, definí una dirección estética clara siguiendo la skill de frontend-design:
- Elegí una paleta de colores cohesiva con variables CSS
- Elegí tipografías distintivas (no Inter, no Arial, no Roboto)
- Definí animaciones y micro-interacciones
- El diseño tiene que ser memorable y production-grade

### 5. Generar el HTML

Creá `$MATERIA/unidad-$N/output/unidad-$N.html` con estas secciones:

**Resumen General**
- Overview de qué trata la unidad (máximo 150 palabras)
- Basado estrictamente en el contenido de NotebookLM

**Conceptos Clave**
- Lista de conceptos con su definición clara y simple
- Extraídos directamente del material

**Explicación Detallada**
- Desarrollo de cada tema con ejemplos concretos
- Si el material tiene ejemplos, usalos. Si no, generá ejemplos simples coherentes con el tema

**Flashcards** (mínimo 10)
- Interactivas: click para dar vuelta la carta con animación de flip
- Pregunta en el frente, respuesta atrás
- Basadas en definiciones y conceptos del material
- Mostrar progreso: 1/10, 2/10, etc.

**Completar el Espacio** (mínimo 10)
- Input de texto para escribir la respuesta
- Validar al presionar Enter o click en "Verificar"
- Mostrar respuesta correcta y explicación tras el intento
- Basadas en términos técnicos y definiciones del material

**Multiple Choice** (mínimo 5)
- 4 opciones por pregunta (A, B, C, D)
- Al seleccionar mostrar si es correcta con explicación
- Basadas en el contenido real del material

**Tab C++ (solo si el material incluye código C++)**
- Detectá si el material contiene ejemplos de C++ (`#include`, `cout`, `cin`, `int main`)
- Si los tiene, agregá un tab extra "C++" con 5–7 ejercicios de completar código
- Cada ejercicio: bloque de código con `___`, campo de texto, validación con Enter o botón, feedback con explicación
- Basá los ejercicios en los ejemplos reales del material

## Requisitos del HTML

- Todo en un solo archivo, sin dependencias externas, funciona offline
- Navegación por tabs entre secciones con transiciones suaves
- Progreso visible en flashcards y completar el espacio
- Aplicar todo lo aprendido de la skill frontend-design: tipografía distintiva, paleta cohesiva, animaciones, layout memorable
- Mobile friendly
- **Botón de regreso al índice**: agregar `<a class="back-btn" href="../../../index.html">← Inicio</a>` con `position: fixed; top: 1rem; left: 1rem; z-index: 200` en todos los HTMLs generados, siempre
- **Barra de material**: agregar `<div class="material-bar">` justo después del `</header>` con un link por cada PDF en `../material/`

## Output

Guardá el archivo en `$MATERIA/unidad-$N/output/unidad-$N.html`
Confirmame cuando esté listo y decime cuántos conceptos, flashcards y preguntas generaste.

## Actualizar index.html (OBLIGATORIO)

Después de generar el HTML, actualizá **todas** las partes del `index.html` raíz:

1. **Nuevo `<li>` en la card de la materia** — dentro de `<ul class="units">` del bloque correspondiente:
   ```html
   <li class="u-item">
     <span class="u-dot ok"></span>
     <a class="u-link" href="$MATERIA/unidad-$N/output/unidad-$N.html">
       <span class="u-label">Unidad N</span>
     </a>
     <span class="u-badge ok">OK</span>
   </li>
   ```

2. **Ratio de la card** (`card-ratio`) — actualizar el número generado. Ej: `3<sup>/3</sup>` → `4<sup>/4</sup>`

3. **Stats bar** — actualizar el número hardcodeado de "Generadas":
   ```html
   <span class="stat-num g">N</span>
   ```

4. **Footer texto** — actualizar el texto hardcodeado:
   ```html
   <strong>N</strong> / M unidades generadas
   ```

5. **Footer JS** — actualizar las constantes del script:
   ```js
   const generated = N, total = M;
   ```

Los puntos 3, 4 y 5 son fáciles de olvidar porque están hardcodeados en lugares distintos. Verificar los 5 siempre.
