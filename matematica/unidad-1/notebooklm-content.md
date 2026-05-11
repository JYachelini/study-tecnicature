# NotebookLM Content - Matemática Unidad 1: Teoría de Conjuntos

## Estructura de videos propuesta

### Video 1: Introducción a los Conjuntos
- **Concepto:** Un conjunto es una "caja" que agrupa objetos diferenciables llamados elementos. Relación de pertenencia (∈), definición por extensión y por comprensión.
- **Ejemplo:** A = {a, e, i, o, u} (extensión) o A = {x / x es una vocal} (comprensión)
- **Ejercicios:** Verdadero/Falso sobre pertenencia, identificar si un elemento pertenece a un conjunto (Ejercicios 1 y 2 de Práctica 1)

### Video 2: Conjuntos Especiales e Inclusión
- **Concepto:** Conjunto vacío (∅), Conjunto Universal (U), inclusión (⊆), subconjuntos
- **Ejemplo:** N ⊆ Z (los naturales están incluidos en los enteros)
- **Conjunto de Partes P(A):** Si A = {a, b}, entonces P(A) = {∅, {a}, {b}, {a, b}}
- **Ejercicios:** Demostrar inclusiones, verificar igualdades, construir P(A) (Ejercicios 3 al 9, y 18)

### Video 3: Diagramas de Venn, Unión e Intersección
- **Concepto:** Diagramas de Venn con rectángulo (Universo) y círculos superpuestos
- **Unión (∪):** Agrupa todos los elementos de ambos conjuntos
- **Intersección (∩):** Solo los elementos que tienen en común
- **Ejemplo:** Si A={1,2} y B={2,3}, A∪B={1,2,3}, A∩B={2}
- **Ejercicios:** Calcular uniones e intersecciones entre conjuntos numéricos (Ejercicios 10 al 14)

### Video 4: Operaciones Avanzadas
- **Diferencia (A−B):** Quitarle a A los elementos de B → |A-B| = |A| - |A∩B|
- **Diferencia Simétrica (A△B):** Lo que está en uno u otro, pero no en ambos
- **Complemento (A^c):** Lo que le falta a A para ser igual al Universo
- **Ejemplo:** Universo = días de la semana, complemento de "días hábiles" = "fines de semana"
- **Técnica Diagramas de 3 círculos:** Resolver de adentro hacia afuera, siguiendo paréntesis
- **Ejercicios:** Sombrear áreas en diagramas de Venn de 3 círculos, operaciones combinadas (Ejercicios 15 al 17)

### Video 5: Propiedades y Leyes de De Morgan
- **Propiedades:** Idempotencia, Conmutativa, Asociativa, Absorción
- **Leyes de De Morgan:**
  - (A ∪ B)' = A' ∩ B'
  - (A ∩ B)' = A' ∪ B'
- **Ejemplo numérico verificado:** U={1,2,3,4}, A={1,2}, B={2,3}
  - Lado izquierdo (A∪B)': unión={1,2,3}, complemento={4}
  - Lado derecho A'∩B': A'={3,4}, B'={1,4}, intersección={4} ✓

## Ejercicios clave del material

### Ejercicio representativo 1 (análisis pertenencia/inclusión)
Dado A = {1, 2, {3}, {1, 2}}, determinar cuáles son verdaderas:
- a) 3 ∈ A → FALSO (3 no está, {3} sí)
- b) {3} ⊆ A → FALSO ({3} es elemento, no subconjunto)
- c) {1, 2} ∈ A → VERDADERO

### Ejercicio representativo 2 (operaciones numéricas)
A = {2, 3, 5, 7, 8}, B = {3, 5, 1}, C = {7, 9}, D = {9, 4, 1}
Hallar: (A ∩ B) ∪ (C ∩ D)

### Ejercicio representativo 3 (sombreado Venn)
Representar en diagrama de Venn: (A ∪ B^c) ∩ C
