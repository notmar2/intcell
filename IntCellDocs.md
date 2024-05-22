# Int Cell

## Descripción

Int Cell es una clase que busca emular el funcionamiento del tipo primitivo **int** de C/C++ haciendo uso del paradigma de programación orientada a objetos. Por tanto implementa funcionalidad de vital importancia para clases dentro de este paradigma como lo que son los 4 constructores primordiales y el destructor; métodos set y get para adherirse a los principios de encapsulación, separación entre implementación e interfaz y sobrecarga de operadores.

---

### Miembros de Datos (Atributos)

```Cpp
private:
    int storedValue;
    int storedValue2;
    int storedValue3;
```

El miembro _storedValue_ guarda el entero dado por el usuario a nuestra clase IntCell. Los miembros _storedValue2_ y _storedValue3_ no tienen métodos implementados y no se encuentran en los constructores por lo que son superfluos, el único efecto de estos miembros en el programa es alocar más memoria de manera innecesaria.

---

### Miembros de Método

#### Constructor sin parámetros:

```C++
IntCell() = default;
```

Este constructor se esta asignando a su valor default. El constructor default inicializa los miembros no estáticos con valores predeterminados, para int dicho valor es 0, por lo que los miembros de datos de IntCell guardarán 0 si se utiliza este constructor.

#### Constructor con int:

```C++
IntCell(int newValue = 0);
```

El constructor con int toma un valor de tipo int con 0 como valor default. Este constructor tiene una definición en el archivo de implementación:

```C++
IntCell::IntCell(int newValue) : storedValue(newValue) {}
```

Toma un parámetro de tipo entero y asigna su valor a _storedValue_.

#### Constructor de copia

```C++
IntCell(const IntCell &rhs);
```

Este constructor toma una referencia de lvalue constante, lo que significa que pasa un alias a un dato existente en el scope en el que se construye el objeto IntCell y utiliza **const** para prevenir cambios en el objeto original.

Este constructor también tiene una definición en el archivo de implementación:

```C++
IntCell::IntCell(const IntCell &rhs)
    : storedValue(rhs.storedValue) {}
```

Básicamente se asigna el valor de _storedValue_ del objeto referenciado a nuestro nuevo objeto. Este constructor es útil ya que permite tomar el valor de _storedValue_ de un objeto del mismo tipo sin necesidad de hacer una copia temporal de todo el objeto, solo del valor de storedValue.

#### Constructor de movimiento

```C++
IntCell(IntCell &&rhs) noexcept;
```

Este constructor toma como parámetro una referencia de rvalue a un objeto de tipo IntCell. En su definición en el archivo de implementación podemos ver que simplemente se copia el valor de nuevo al storedValue nuevo.

```C++
IntCell::IntCell(IntCell &&rhs) noexcept
    : storedValue(rhs.storedValue) {}
```

Pero la diferencia entre estos constructores, es que el move constructor o constructor de movimiento sirve para cambiar la propiedad de valores temporales (rvalues) al método. En este caso simplemente se hace una copia de los valores, pero en situaciones en las que se maneje memoria dinámica se pueden utilizar para optimizar la clase simplemente cambiando el valor de un puntero hacia los datos en memoria en lugar de hacer una copia de dichos datos a un nuevo lugar en memoria lo cual consume más recursos. Por último cabe mencionar que la palabra reservada **noexcept** sirve para indicar al compilador que el método no arrojará excepciones lo cual le permite hacer optimizaciones en operaciones de movimiento.

#### Destructor

```C++
~IntCell() = default;
```

El destructor del objeto simplemente se toma como default. No es necesario realizar operaciones especiales en la destrucción del objeto debido a que todos los miembros de dato son datos primitivos. Al ser default no hay definición en el archivo de implementación.

#### Operador de asignación por copia

```C++
IntCell &operator=(const IntCell &rhs);
```

Aquí se declara la sobrecarga del operador de asignación para el tipo de dato IntCell, en el que el valor a mano deracha (rhs) es un lvalue IntCell. La implementación es la siguiente:

```C++
IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}
```

Primero se comprueba que el objeto en cuestion no sea igual a rhs para evitar copiar los datos innecesariamente. El tipo de retorno es IntCell& para permitir la encadenación de operadores [x = y = z; donde x,y y z son IntCells].

#### Operador de asignación por movimiento

```C++
IntCell &operator=(IntCell &&rhs) noexcept;
```

Este operador se utiliza cuando el valor a mano derecha (rhs) es un rvalue de tipo IntCell. Tiene funcionalidad similar al operador de copia:

```C++
IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}
```

Con la diferencia de que el valor se mueve completamente en lugar de guardar la copia. Al ser rhs un rvalue, su valor es temporal y por lo tanto este tipo de operaciones son viables.

#### Operador de asignación con int

```C++
IntCell &operator=(int rhs);
```

Este operador se utiliza cuando rhs es un int. La implementación simplemente asigna el valor de rhs a _storedValue_.

```C++
IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}
```

Nuevamente se regresa una referencia al objeto para permitir encadenación de operadores.

#### Operador de suma con IntCell

```C++
IntCell &operator+(const IntCell &rhs);
```

Este operador se utiliza para sumar valores. Toma como parámetro una referencia de IntCell lvalue y asigna el _storedValue_ del IntCell actual a la suma de los _storedValue_ de ambos IntCell.

```C++
IntCell &IntCell::operator+(const IntCell &rhs) {
    storedValue = storedValue + rhs.storedValue;
    return *this;
}
```

Cabe mencionar que este tipo de comportamiento usualmente es característico del operador de adición-asignación compuesto [+=].

#### Operador de suma con int

```C++
IntCell &operator+(int rhs);
```

Este operador tiene el mismo comportamiento que el operador de suma con IntCell, pero toma un int primitivo en su lugar.

```C++
IntCell &IntCell::operator+(int rhs) {
    storedValue = storedValue + rhs;
    return *this;
}
```

El operador asigna a _storedValue_ el resultado de la suma entre _storedValue_ y el valor del int rhs y retorna una referencia al mismo objeto (nuevamente para permitir encadenación de operadores).

Nuevamente se puede mencionar que este tipo de comportamiento usualmente es visto en operadores de adición-asignación.

#### Operador de resta con IntCell

```C++
IntCell &operator-(const IntCell &rhs);
```

Este operador se utiliza con un IntCell del lado derecho, toma una referencia de lvalue constante.

```C++
IntCell &IntCell::operator-(const IntCell &rhs) {
    storedValue = storedValue - rhs.storedValue;
    return *this;
}
```

El operador toma el resultado de la resta de _storedValue_ del objeto a mano izquierda menos el _storedValue_ del objeto a mano derecha y lo asigna a _storedValue_ del objeto a mano izquierda. Por último retorna una referencia a este objeto para permitir encadenación de operadores.

Este tipo de comportamiento usualmente es visto en el operador de resta-asignación compuesto [-=].

#### Operador de resta con int

```C++
IntCell &operator-(int rhs);
```

Este operador toma un IntCell a mano izquierda y un int primitivo a mano derecha. En la definición en el archivo de implementación podemos ver que toma la resta del _storedValue_ del IntCell menos el int primitivo y la asigna a _storedValue_ nuevamente.

```C++
IntCell &IntCell::operator-(int rhs) {
    storedValue = storedValue - rhs;
    return *this;
}
```

Este es un comportamiento similar al comportamiento del operador de resta-asignación compuesto [-=].

#### Método Get

```C++
int getValue() const;
```

El método get se utiliza para leer el valor de _storedValue_ el cual es un atributo privado.

```C++
int IntCell::getValue() const {
    return storedValue;
}
```

El método regresa el valor de _storedValue_ como constante para poder ser leído fuera de la clase.

#### Método Set

```C++
void setValue(int newValue);
```

El método set se utiliza para editar el valor de _storedValue_ que usualmente no sería editable (ya que es un atributo privado).

```C++
void IntCell::setValue(int newValue) {
    storedValue = newValue;
}
```

Toma como parámetro un valor de tipo int y lo asigna a storedValue.
