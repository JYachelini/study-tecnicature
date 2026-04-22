# Skill: NotebookLM → Study HTML

## Notebooks disponibles

| Materia | Notebook ID |
|---|---|
| programacion | `33785965-09e9-4dfd-a732-5aff17ffe8f9` |
| arquitectura-y-sistemas-operativos | `aced259b-7993-44ec-8cb7-06fd3a72b353` |
| matematica | `8c3ece48-943b-404c-b0df-6e813518e403` |
| organizacion-empresarial | `89d2acb7-be99-4a46-aa0d-09fc8e100528` |

## Cómo extraer el contenido de una unidad

### 1. Encontrar los source IDs de la unidad

Primero listá las fuentes del notebook para identificar qué PDFs corresponden a la unidad:

```bash
notebooklm source list --json --notebook <NOTEBOOK_ID>
```

Cruzá los títulos con los archivos en `$MATERIA/unidad-$N/material/`. Si hay varios PDFs para la unidad, anotá todos sus IDs.

### 2. Consulta exhaustiva del contenido

Pedile a NotebookLM todo el contenido sin acotar los temas:

```bash
notebooklm ask "Analizá todo el contenido de la Unidad N y dame un resumen exhaustivo y completo de todo lo que se enseña. No omitas ningún concepto, tema, ejemplo, regla, código o detalle importante que aparezca en el material. Quiero que sea lo suficientemente completo para que un estudiante pueda estudiar toda la unidad únicamente con tu respuesta." \
  --notebook <NOTEBOOK_ID> \
  -s <SOURCE_ID_1> [-s <SOURCE_ID_2> ...]
```

### 3. Consultas de seguimiento (si es necesario)

Si el material es extenso o tiene código, hacer consultas adicionales:

```bash
# Ejemplos de código
notebooklm ask "Listá todos los ejemplos de código que aparecen en el material, tal como están en el apunte." \
  --notebook <NOTEBOOK_ID> -s <SOURCE_ID>

# Reglas y advertencias
notebooklm ask "¿Cuáles son las reglas, restricciones, advertencias o errores comunes que menciona el material? No omitas ninguna." \
  --notebook <NOTEBOOK_ID> -s <SOURCE_ID>
```

## Qué hacer con el contenido extraído

Con la respuesta de NotebookLM generá un HTML con estas secciones:
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
