# Tecnicatura — Base de Conocimiento

Sistema de estudio personal para la Tecnicatura. Genera páginas HTML interactivas a partir de PDFs de cada materia, con resumen de conceptos, ejemplos y mini-quiz.

## Materias

| Materia | Unidades generadas |
|---|---|
| Arquitectura y Sistemas Operativos | 3 / 3 |
| Matemática | 3 / 3 |
| Organización Empresarial | 1 / 3 |
| Programación | en construcción |

## Estructura

```
tecnicatura/
├── index.html                          # Home — listado de todas las materias
├── arquitectura-y-sistemas-operativos/
│   └── unidad-N/
│       ├── material/                   # PDFs fuente
│       └── output/                     # HTML generado
├── matematica/
├── organizacion-empresarial/
├── programacion/
├── cronogramas/                        # PDFs de cronograma por materia
└── template/
    └── base.html                       # Template base para nuevas unidades
```

## Cómo agregar una nueva unidad

1. Colocá los PDFs fuente en `<materia>/unidad-N/material/`
2. Usá el skill `generar-unidad` desde Claude Code para generar el HTML
3. El archivo se guarda automáticamente en `<materia>/unidad-N/output/unidad-N.html`
4. El `index.html` lo detecta y activa el link

> Cada HTML incluye una barra de links al material original (PDFs) para acceso rápido.

## GitHub Pages

El sitio está publicado en: `https://<usuario>.github.io/tecnicatura/`

Cada push a `main` actualiza el sitio automáticamente.
