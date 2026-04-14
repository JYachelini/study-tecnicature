# Generador de HTMLs de estudio

Este proyecto genera páginas HTML de estudio a partir de PDFs de materias de la tecnicatura.

## Objetivo

Cada HTML generado debe incluir:
- Resumen de conceptos clave
- Ejemplos ilustrativos
- Mini-quiz interactivo

## Estructura

```
tecnicatura/
├── arquitectura-y-sistemas-operativos/
│   └── Unidad-x/
│       ├── material/   # PDFs fuente de la unidad
│       └── output/     # HTMLs generados de la unidad
├── matematica/
│   └── Unidad-x/
│       ├── material/
│       └── output/
├── organizacion-empresarial/
│   └── Unidad-x/
│       ├── material/
│       └── output/
├── programacion/
│   └── Unidad-x/
│       ├── material/
│       └── output/
├── cronogramas/        # PDFs de cronograma de cada materia
└── template/
    └── base.html       # Template base para los HTMLs
```

## Reglas

- Los HTMLs generados van siempre en la carpeta `output/` dentro de cada `Unidad-x/`.
- El estilo debe ser limpio, legible y funcionar completamente offline (sin CDNs externos).
- El template base está en `template/base.html`.
