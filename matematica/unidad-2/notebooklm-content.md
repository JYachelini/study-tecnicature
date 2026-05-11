# NotebookLM Content - Matemática Unidad 2: Problemas de Conteo

## Estructura de videos propuesta

### Video 1: Fundamentos de Conteo y Cardinalidad
- **Concepto:** Cardinalidad = cantidad de elementos de un conjunto. Notación: |A|
- **Ejemplo cotidiano:** Contar cuántos amigos tienen Netflix = calcular la cardinalidad
- **Técnica:**
  1. Identificar el Universo (total de personas/objetos)
  2. Identificar los conjuntos involucrados
  3. Escribir la cardinalidad con barras verticales: |A|
- **Ejercicios:** Extraer datos de un texto y pasarlos a notación formal (ej: profesores de una universidad)

### Video 2: Problemas con 2 Conjuntos (De adentro hacia afuera)
- **Problema del doble conteo:** Al sumar totales de dos grupos con intersección, contamos el medio dos veces
- **Regla de oro:** Siempre empezar a llenar el diagrama por la intersección (el centro)
- **Fórmula:** |A - B| = |A| - |A ∩ B|
- **Técnica paso a paso:**
  1. Dibujar dos círculos superpuestos dentro de un rectángulo (Universo)
  2. Empezar por la intersección (el medio)
  3. Para "solo A": |A| - intersección
  4. Los que no están en ningún grupo: Universo - todos los del interior
- **Ejemplo:** 62 empleados, algunos faltan por enfermedad y otros por trámites, algunos por ambas cosas
- **Problemas inversos:** Te dan el total y los que están afuera → deducir la intersección

### Video 3: Problemas Complejos con 3 Conjuntos
- **Concepto:** 3 círculos generan 8 regiones. Se convierte el diagrama en sistema de ecuaciones
- **Variables:** Asignar letras (x, y, z, w, u, v, t) a cada región. 't' = centro (los tres)
- **Técnica:**
  1. Dibujar 3 círculos entrelazados, asignar letra a cada región
  2. Armar sistema de ecuaciones con los datos
  3. Despejar desde el centro 't' hacia afuera
- **Fórmula general:** |A∪B∪C| = |A| + |B| + |C| - |A∩B| - |A∩C| - |B∩C| + |A∩B∩C|
- **Ejemplo:** Encuesta sobre marcas de detergentes / tipos de revistas
- **Ejercicio típico:** Calcular "los que consumen A o B pero no C"

## Notas adicionales
- Los problemas de conteo son directamente aplicaciones de Teoría de Conjuntos (Unidad 1)
- La cardinalidad se conecta con los diagramas de Venn ya estudiados
