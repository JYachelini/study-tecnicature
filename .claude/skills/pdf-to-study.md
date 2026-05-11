# Skill: NotebookLM → Study HTML

## Notebooks disponibles

| Materia | Notebook ID |
|---|---|
| programacion | `33785965-09e9-4dfd-a732-5aff17ffe8f9` |
| arquitectura-y-sistemas-operativos | `aced259b-7993-44ec-8cb7-06fd3a72b353` |
| matematica | `8c3ece48-943b-404c-b0df-6e813518e403` |
| organizacion-empresarial | `89d2acb7-be99-4a46-aa0d-09fc8e100528` |

## Flujo estándar para extraer contenido de una unidad

### 1. Encontrar los source IDs de la unidad

```bash
notebooklm source list --json --notebook <NOTEBOOK_ID>
```

Cruzá los títulos con los archivos en `$MATERIA/unidad-$N/material/`.
Si los PDFs no están en NotebookLM, subirlos primero:

```bash
notebooklm source add "$MATERIA/unidad-$N/material/archivo.pdf" \
  --type file --notebook <NOTEBOOK_ID> --json
```

### 2. Consulta inicial (chat)

Pedile a NotebookLM un resumen del contenido de la unidad:

```bash
notebooklm ask "Analizá todo el contenido de la Unidad N y dame un resumen exhaustivo y completo de todo lo que se enseña. No omitas ningún concepto, tema, ejemplo, regla, código o detalle importante. Quiero que sea lo suficientemente completo para que un estudiante pueda estudiar toda la unidad únicamente con tu respuesta." \
  --notebook <NOTEBOOK_ID> \
  -s <SOURCE_ID_1> [-s <SOURCE_ID_2> ...]
```

Guardá la respuesta en `$MATERIA/unidad-$N/notebooklm-content.md`.

### 3. Generar guía de estudio (OBLIGATORIO)

Siempre generar un reporte tipo study-guide con `--append` para instrucciones específicas de la unidad:

```bash
notebooklm generate report \
  --format study-guide \
  --append "Incluí todos los conceptos, definiciones, ejemplos y técnicas de la unidad. Exhaustivo." \
  --notebook <NOTEBOOK_ID> \
  -s <SOURCE_ID_1> [-s <SOURCE_ID_2> ...] \
  --json
```

Guardá el `task_id` del output JSON.

### 4. Esperar y descargar el reporte

```bash
notebooklm artifact wait <TASK_ID> -n <NOTEBOOK_ID> --timeout 900
notebooklm download report $MATERIA/unidad-$N/notebooklm-report.md \
  -a <TASK_ID> -n <NOTEBOOK_ID>
```

El reporte se guarda en `$MATERIA/unidad-$N/notebooklm-report.md`.

### 5. Consultas de seguimiento (si el material tiene código)

```bash
notebooklm ask "Listá todos los ejemplos de código que aparecen en el material, tal como están en el apunte." \
  --notebook <NOTEBOOK_ID> -s <SOURCE_ID>
```

## Archivos que deben quedar guardados

| Archivo | Contenido |
|---|---|
| `notebooklm-content.md` | Respuesta del chat (resumen exhaustivo) |
| `notebooklm-report.md` | Guía de estudio descargada de NotebookLM |

Ambos sirven como base para generar el HTML. El reporte (`notebooklm-report.md`) suele ser más estructurado y exhaustivo que el chat.

## Qué hacer con el contenido extraído

Con el `notebooklm-content.md` y el `notebooklm-report.md`, generá un HTML con estas secciones:
1. Resumen general
2. Conceptos clave
3. Explicación detallada con ejemplos
4. Flashcards (mínimo 10, interactivas con flip)
5. Completar el espacio (mínimo 10, con input y validación)
6. Multiple choice (mínimo 5, con feedback y explicación)

## Reglas

- Todo en un solo archivo HTML sin dependencias externas
- Funciona offline
- Navegación por tabs
- Progreso visible en flashcards (ej: 3/10)
- Output siempre en `$MATERIA/unidad-$N/output/`
