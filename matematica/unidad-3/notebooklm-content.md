# NotebookLM Content - Matemática Unidad 3: Lógica Proposicional

## Estructura de videos propuesta

### Video 1: ¿Qué es una Proposición?
- **Concepto:** Afirmación con sentido pleno que puede ser verdadera o falsa (no ambas)
- **Ejemplos de proposiciones:** "García Márquez escribió Cien años de soledad"
- **NO son proposiciones:** Preguntas ("¿Te vas?"), órdenes ("Compra cinco azules")
- **Ejercicios:** Clasificar frases, determinar su valor de verdad

### Video 2: Conectivos Básicos y Tablas de Verdad
- **Tablas de verdad:** Enumeran todas las combinaciones posibles (V/F) de las variables
- **Conectivos:**
  - **Negación (¬):** Invierte el valor. Si p = "Llueve", ¬p = "No llueve"
  - **Conjunción (∧, "y"):** Verdadera SOLO si ambas son verdaderas
  - **Disyunción (∨, "o"):** Verdadera si AL MENOS una es verdadera
  - **Disyunción Exclusiva:** Verdadera si ocurre UNA u otra, pero NO ambas. Ej: semáforo en rojo o verde
- **Construcción de tabla:** 4 combinaciones para p y q: VV, VF, FV, FF

### Video 3: Condicional y Bicondicional
- **Condicional (→, "si...entonces"):**
  - Regla fundamental: SOLO es falso cuando hipótesis es V y conclusión es F
  - Error común: F→F y F→V dan VERDADERO (¡no falso!)
  - Ejemplo: "Si estudio, entonces apruebo"
- **Bicondicional (↔, "si y solo si"):**
  - Verdadero cuando ambas partes tienen el MISMO valor de verdad
  - Ejemplo: "Respiro si y solo si estoy vivo"

### Video 4: Tautologías, Contradicciones y Contingencia
- **Tautología (T):** Resultado verdadero para TODAS las combinaciones posibles
- **Contradicción (C):** Resultado falso en TODOS los casos
- **Contingencia:** Mezcla de verdaderos y falsos
- **Ejemplo completo paso a paso: (p → q) ∧ (¬p ∨ q)**
  - Paso 1: columnas p, q con 4 combinaciones
  - Paso 2: (p → q) - solo F cuando p=V y q=F
  - Paso 3: (¬p) - invertir columna p
  - Paso 4: (¬p ∨ q) - verdadera si al menos una es V
  - Paso 5: Resultado final - conjunción de pasos 2 y 4 → Contingencia

### Video 5: Lógica Aplicada a Teoría de Conjuntos
- **Conexión fundamental:** Operaciones de conjuntos se demuestran con lógica proposicional
  - Intersección ↔ Conjunción (∧)
  - Unión ↔ Disyunción (∨)
- **Método:** Reemplazar pertenencia con 1 (verdadero) y no pertenencia con 0 (falso)
- **Ejercicio de demostración:**
  - Demostrar: (A△B)−C = (A−C)△(B−C) usando tablas de verdad
  - Demostrar: A ∩ (B△C) = (A ∩ B)△(A ∩ C)
- **Proceso:** Calcular ambos lados, si las columnas finales coinciden → la igualdad es verdadera

## Errores típicos de principiantes
1. Confundir condicional F→V con falso (es VERDADERO)
2. Confundir condicional F→F con falso (es VERDADERO)
3. No seguir el orden de resolución en tablas complejas (de adentro hacia afuera)
4. Confundir disyunción inclusiva (∨) con exclusiva (⊕)
