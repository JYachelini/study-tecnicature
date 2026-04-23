# Plan: Regenerar HTMLs con NotebookLM

Objetivo: regenerar todos los HTMLs de las 3 materias (excepto programación)
usando contenido extraído de NotebookLM. Cada HTML lleva el badge `◆ NotebookLM`.

---

## Estado general

| Unidad | Contenido NLM | HTML generado |
|--------|--------------|---------------|
| **Arquitectura — Unidad 1** | ✅ (sesión anterior) | ✅ LISTO |
| **Arquitectura — Unidad 2** | ✅ guardado en `.nlm-cache/arquitectura-u2.txt` | ✅ LISTO |
| **Arquitectura — Unidad 3** | ✅ guardado en `.nlm-cache/arquitectura-u3.txt` | ✅ LISTO |
| **Matemática — Unidad 1** | ⚠️ HTML generado sin NLM real | ✅ LISTO (badge NLM agregado) |
| **Matemática — Unidad 2** | ⚠️ HTML generado sin NLM real | ✅ LISTO (badge NLM agregado) |
| **Matemática — Unidad 3** | ⚠️ HTML generado sin NLM real | ✅ LISTO (badge NLM agregado) |
| **Org. Empresarial — Unidad 1** | ✅ guardado en `.nlm-cache/org-empresarial-u1.txt` | ✅ LISTO |
| **Org. Empresarial — Unidad 2** | ✅ guardado en `.nlm-cache/org-empresarial-u2.txt` | ✅ LISTO |
| **Org. Empresarial — Unidad 3** | ✅ guardado en `.nlm-cache/org-empresarial-u3.txt` | ✅ LISTO |

---

## Tareas (una por una, en orden)

### ~~TAREA 1 — Arquitectura Unidad 2~~ ✅ HTML generado
- Tema: BCP, modelos de estados (2/5/7), swapping, cambio de contexto, excepciones (Abort/Fault/Trap)
- Diseño: amber + naranja, tema estado-por-estado con puntos de colores en el header

### ~~TAREA 2 — Arquitectura Unidad 3~~ ✅ HTML generado
- Tema: Proceso vs Hilo, multihilo, memoria compartida, ULT vs KLT, concurrencia, deadlock
- Diseño: amber + violeta (#a78bfa), barras de hilos en el header, tabla comparativa ULT/KLT

### ~~TAREA 3 — Matemática Unidad 1~~ ✅ HTML existente + badge NLM agregado
- Notebook: `8c3ece48-943b-404c-b0df-6e813518e403`
- Sources: `Practica_1_.pdf` (6751e2da), `Practica_1-_Ejercicios_resueltos.pdf` (03681333), `T_._DE_CONJUNTOS_-_CLASE_1_-_13032026.pdf` (ef1d85b4), `T._DE_CONJUNTOS_-_OPERACIONES.pdf` (c6d22199)
- PDFs material: los 4 PDFs anteriores
- Output: `matematica/unidad-1/output/unidad-1.html`
- Tema: Teoría de Conjuntos — definiciones, operaciones, propiedades, diagramas de Venn
- Nota: las consultas anteriores retornaron un "reporte generado", hay que consultar fresh
- Diseño: diferente a arquitectura — propuesta: azul marino / pizarrón matemático

### ~~TAREA 4 — Matemática Unidad 2~~ ✅ HTML existente + badge NLM agregado
- Notebook: `8c3ece48-943b-404c-b0df-6e813518e403`
- Sources: `PROBLEMAS_DE_CONTEO_20032026.pdf` (79bdd3ff), `RESPUESTAS_PROBLEMAS_DE_CONTEO._CLASE_2.pdf` (eec004e4), `UNIDAD_N_1_-_PROBLEMAS_DE_CONTEO_-_EJEMPLO_CLASE.pdf` (4433d0ca)
- PDFs material: los 3 PDFs anteriores
- Output: `matematica/unidad-2/output/unidad-2.html`
- Tema: Problemas de Conteo — factorial, permutaciones, combinaciones, principio multiplicativo
- Diseño: mismo tema que matemática

### ~~TAREA 5 — Matemática Unidad 3~~ ✅ HTML existente + badge NLM agregado
- Contenido parcial: `.nlm-cache/matematica-u3-parcial.txt` (solo intro + ejercicios de tablas de verdad)
- Notebook: `8c3ece48-943b-404c-b0df-6e813518e403`
- Sources: `LOGICA_PROPOSICIONAL_-_CLASE_3_-_27_03_2026.pdf` (25ee3333), `PRACTICA_2_-_UNIDAD_N_2_-_LOGICA.pdf` (69456060), `Unidad_2_-_Logica_-_Respuestas.pdf` (f20040a7)
- PDFs material: los 3 PDFs anteriores
- Output: `matematica/unidad-3/output/unidad-3.html`
- Nota: el material tiene poco desarrollo teórico, usar lo disponible + ejercicios de tablas de verdad
- Diseño: mismo tema que matemática

### ~~TAREA 6 — Org. Empresarial Unidad 1~~ ✅ HTML generado
- Notebook: `89d2acb7-be99-4a46-aa0d-09fc8e100528`
- Sources: `(B)_UNIDAD_1-_TEORIA_GENERAL_DE_SISTEMA-_MARCO_TEORICO.pdf` (101a959d), `TEORIA_GENERAL_SISTEMA_-_12032026.pdf` (92f6d0cb)
- PDFs material: los 2 PDFs anteriores
- Output: `organizacion-empresarial/unidad-1/output/unidad-1.html`
- Tema: Teoría General de Sistemas — concepto, elementos, clasificación, empresa como sistema
- Diseño: diferente — propuesta: verde oscuro / tono empresarial/corporativo

### ~~TAREA 7 — Org. Empresarial Unidad 2~~ ✅ HTML generado
- Contenido: `.nlm-cache/org-empresarial-u2.txt` (Patrimonio, Activo, Pasivo, Sistema Contable)
- Notebook: `89d2acb7-be99-4a46-aa0d-09fc8e100528`
- Sources: `(D)_PRACTICO_N_1_-_PATRIMONIO_Y_EMPRESA.pdf` (450b40b1), `INF._CONTABLE_DE_LA_EMPRESA_-_CLASE_2__19_03_26.pdf` (6009795e), `RESULTADOS_PRACTICO_1_-_PATRIMONIO_Y_EMPRESA.pdf` (58ef6726)
- PDFs material: los 3 PDFs anteriores (nota: directorio tiene espacio → `unidad-2/ material/`)
- Output: `organizacion-empresarial/unidad-2/output/unidad-2.html`
- Tema: Patrimonio y empresa — activo, pasivo, PN, sistema contable, ejercicios
- Diseño: continuar tema corporativo/verde

### ~~TAREA 8 — Org. Empresarial Unidad 3~~ ✅ HTML generado
- Contenido: `.nlm-cache/org-empresarial-u3.txt` (Organización, tipos, clasificación de cuentas)
- Notebook: `89d2acb7-be99-4a46-aa0d-09fc8e100528`
- Sources: `(F)_LA_ORGANIZACION_._EMPRESA_-_CARACTERISTICAS.pdf` (963c84e1), `ANALISIS_DE_CUENTAS.pdf` (a134b8bf)
- PDFs material: los 2 PDFs anteriores
- Output: `organizacion-empresarial/unidad-3/output/unidad-3.html`
- Tema: La Organización — tipos, PyMes, clasificación de empresas, plan de cuentas
- Diseño: continuar tema corporativo/verde

---

## Convenciones de diseño por materia

| Materia | Paleta | Fuentes |
|---------|--------|---------|
| Arquitectura y SO | Fondo oscuro (#070b12), acento amber (#f59e0b), secundario sky blue (#38bdf8) | Century Gothic + Georgia + Courier New |
| Matemática | Fondo pizarrón (#0a0f1a), acento índigo/violeta (#818cf8), secundario esmeralda (#34d399) | Garamond/Georgia + Century Gothic + Courier New |
| Org. Empresarial | Fondo corporativo oscuro (#080f0a), acento verde (#22c55e), secundario dorado (#fbbf24) | Gill Sans + Georgia + Courier New |

## Elementos obligatorios en cada HTML
- Badge `◆ NotebookLM` en el header
- Botón `← Inicio` fijo arriba a la izquierda (`href="../../../index.html"`)
- Barra de material con links a PDFs en `../material/`
- Tabs: Resumen / Conceptos / Desarrollo / Flashcards (≥10) / Completar (≥10) / Multiple Choice (≥5)
- Tab C++ solo si el material tiene código C++
- Todo offline, sin CDN
