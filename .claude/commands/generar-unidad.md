# Generar Unidad de Estudio

Antes de arrancar, leé estos dos archivos para entender cómo trabajar:
- `.claude/skills/pdf-to-study.md` → cómo extraer contenido desde NotebookLM
- El archivo de la skill de diseño frontend en tu instalación de Claude Code

Luego preguntame:
1. ¿Qué materia? (arquitectura-y-sistemas-operativos, matematica, organizacion-empresarial, programacion)
2. ¿Qué número de unidad?

## Pasos a seguir

### 1. Extraer el contenido desde NotebookLM

Usá el notebook de la materia correspondiente (IDs en `.claude/skills/pdf-to-study.md`).

```bash
# Listar fuentes para identificar los PDFs de la unidad
notebooklm source list --json --notebook <NOTEBOOK_ID>
```

Cruzá los títulos de las fuentes con los archivos en `$MATERIA/unidad-$N/material/`.
Con los source IDs identificados, consultá el contenido completo:

```bash
notebooklm ask "Analizá todo el contenido de la Unidad N y dame un resumen exhaustivo y completo de todo lo que se enseña. No omitas ningún concepto, tema, ejemplo, regla, código o detalle importante." \
  --notebook <NOTEBOOK_ID> -s <SOURCE_ID_1> [-s <SOURCE_ID_2> ...]
```

Si el material es extenso, hacer consultas adicionales sobre código, reglas y advertencias.

### 2. Analizar el contenido

De la respuesta de NotebookLM identificá:
- Tema central de la unidad
- Conceptos y definiciones clave
- Procesos o pasos secuenciales
- Ejemplos y código que aparezcan en el material
- Términos técnicos importantes
- Reglas, restricciones o advertencias

### 3. Diseño

Antes de escribir una línea de CSS, definí una dirección estética clara siguiendo la skill de frontend-design:
- Elegí una paleta de colores cohesiva con variables CSS
- Elegí tipografías distintivas (no Inter, no Arial, no Roboto)
- Definí animaciones y micro-interacciones
- El diseño tiene que ser memorable y production-grade

### 4. Generar el HTML

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
