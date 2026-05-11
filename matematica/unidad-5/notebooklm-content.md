# NotebookLM Content - Unidad 5: Relaciones Binarias y Grafos

## Fuentes usadas
- CLASE-5-RELACION-BINARIA.pdf (ID: 56008d52-d4e2-4f76-80fe-d05ddcaf5aa1)
- CLASIFICACION-DE-RELACIONES.pdf (ID: 1ccf4d5b-5756-4a51-9fbc-9254bc8e653c)

## Resumen General

La Unidad 5 cubre **Relaciones Binarias y Grafos**.

## Conceptos Clave

### Producto Cartesiano (A × B)
- Conjunto de todos los pares ordenados cuyo primer elemento pertenece a A y el segundo a B
- **NO es conmutativo**: A × B ≠ B × A

### Relación
- Subconjunto del producto cartesiano que verifica una propiedad o condición
- **Dominio**: los primeros elementos de cada par
- **Codominio**: los segundos elementos de cada par

### Operaciones sobre Relaciones
- **Inversa (R⁻¹)**: se obtiene invirtiendo el orden de los pares
- **Complementaria (R̄)**: formada por los pares que NO pertenecen a R

### Representación
- Diagramas de flechas
- **Grafos dirigidos**: los elementos son nodos, las relaciones se marcan con flechas
- "Bucles" si un elemento se relaciona consigo mismo

## Propiedades de las Relaciones

### Reflexiva
- Para todo elemento `a` en el conjunto A, se cumple que `(a,a) ∈ R`
- Gráficamente: todos los nodos deben tener un "bucle"

### Simétrica
- Si `(a,b) ∈ R`, entonces obligatoriamente `(b,a) ∈ R`
- Ejemplo: si la relación tiene el par `(1,2)`, también debe tener `(2,1)`

### Transitiva
- Si `(a,b) ∈ R` y `(b,c) ∈ R`, entonces `(a,c) ∈ R`
- Ejemplo: si se tienen los pares `(1,2)` y `(2,3)`, debe existir el par `(1,3)`

### Antisimétrica
- Condición fundamental para formar relaciones de orden
- Si `(a,b) ∈ R` y `(b,a) ∈ R`, entonces `a = b`

## Tipos Especiales

### Relación de Equivalencia
- Debe ser **reflexiva + simétrica + transitiva**
- Sirve para clasificar y agrupar elementos en "clases de equivalencia"

### Relación de Orden
- Debe ser **reflexiva + antisimétrica + transitiva**
