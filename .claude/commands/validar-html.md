# Validador de HTML de Estudio

Preguntame:
1. ¿Qué materia?
2. ¿Qué número de unidad?

Leé el archivo `materias/$MATERIA/unidad-$N/output/unidad-$N.html`

## Qué validar

### Contenido
- [ ] Tiene sección de Resumen General
- [ ] Tiene sección de Conceptos Clave
- [ ] Tiene sección de Explicación Detallada
- [ ] Tiene mínimo 10 Flashcards
- [ ] Tiene mínimo 10 ejercicios de Completar el Espacio
- [ ] Tiene mínimo 5 preguntas de Multiple Choice

### Interactividad
- [ ] Flashcards tienen animación de flip al hacer click
- [ ] Flashcards muestran progreso (ej: 3/10)
- [ ] Completar el espacio valida con Enter o botón
- [ ] Completar el espacio muestra respuesta correcta y explicación tras el intento
- [ ] Multiple choice muestra feedback y explicación al seleccionar

### Diseño
- [ ] No usa fuentes genéricas (Inter, Roboto, Arial, system fonts)
- [ ] Tiene paleta de colores cohesiva con CSS variables
- [ ] Tiene animaciones o micro-interacciones
- [ ] Navegación por tabs entre secciones
- [ ] Es mobile friendly

### Técnico
- [ ] Todo en un solo archivo HTML
- [ ] Sin dependencias externas (funciona offline)
- [ ] No tiene errores de JavaScript en consola obvios

## Resultado

Mostrá un reporte con:
- Qué pasó ✅
- Qué falló ❌
- Lista de correcciones necesarias ordenadas por prioridad

Si hay fallos, preguntame si querés que los corrija automáticamente.
