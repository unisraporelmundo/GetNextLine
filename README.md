<a href="#" onclick="return false;"><img alt="42 Logo" src="https://github.com/unisraporelmundo/unisraporelmundo/blob/main/unisraporelmundo/getnextlinebanner.gif"></a>


[Click aquí](https://github.com/unisraporelmundo/unisraporelmundo/blob/main/unisraporelmundo/GetnextlineSubject.pdf) para ver el `PDF` del proyecto.


## Get Next Line

El cuarto proyecto en 42 es Get Next Line. El objetivo de este proyecto es que la función `get_next_line` tiene que leer una línea dentro de un fichero, al que accede por medio de un file descriptor `fd` que le entra como parámetro. Es decir, accede a un archivo, que tendrá texto, y comienza a leer caracteres hasta que encuentre un fin de línea `\n`.
La particularidad de la función es que, además de leer una línea hasta `\n`, también tiene que "recordar" hasta que posición del fichero ha leido cada vez que se ejecuta, para que cuando llamemos a la función esta lea la línea siguiente a la de la vez anterior.
Para desarrollar este proyecto hay que aprender a implementar varios conceptos: file descriptors `fd` (Visto en la parte Bonus del proyecto libft), funciones `open` y `read` y `variables estáticas`.

## VARIABLES ESTÁTICAS
Les permite mantener su valor entre llamadas a la función. La variable no se reinicializa cada vez que se llama a la función. 
Cuando una variable estática se declara dentro de una función, su alcance se limita a esa función, y cuando se declara fuera  de una función (a nivel de archivo) su alcance se restringe a ese archivo.
En Get next line es útil usar variables estáticas porque  queremos que la función pueda manejar múltiples archivos simultáneamente recordando en que punto se quedó en cada archivo.

### Declaración:

static char *stack = NULL;      (En get next line)

static char *stack[FD_MAX] = {NULL};     (En get next line bonus)

## FUNCIONES NECESARIAS

### Extract_line;
Función para extraer una línea de texto desde un buffer hasta encontrar un salto de  línea  ‘ \n ’ o el final de  la cadena ‘ \0  ’

### Up_stack;
Función para actualizar  el buffer eliminando los caracteres hasta el primer salto de  línea  ‘ \n ’ (incluido el salto de  línea) y dejando sólo los caracteres que siguen al salto de  línea.

### Joinfree;
Función para unir dos cadenas, almacenar el resultado en una nueva cadena, liberar la memoria previamente asignada al buffer y después retornar el resultado.

### Get_Next_line;
Función para leer una línea completa desde un file  descriptor (fd) en cada llamada, utilizando  un buffer estático para almacenar los datos leídos entre llamadas.

### Get_Next_line_bonus;
Función exactamente igual que la anterior pero esta es capaz de manejar múltiples files descriptor simultáneamente gracias al uso de un  array de punteros estático. 

## FUNCIONES ‘ UTILS ’

Necesitamos tres funciones extras para poder crear este  proyecto. 

### ft_strlen;
Función para calcular la longitud de un string.

### ft_strjoin;
Función para unir dos strings y retornar el string resultante.

### ft_strchr;
Función para buscar la primera aparición de un  carácter  en un string. 
