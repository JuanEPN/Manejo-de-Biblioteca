clas_menu: Esta clase representa el menú principal del programa. Tiene un método met_mostrar_opciones() que muestra las opciones disponibles y permite al usuario seleccionar una opción. Dependiendo de la opción elegida, se invocan los métodos correspondientes de otras clases.

clas_libros: Esta clase se encarga de gestionar los libros. Tiene variables miembro como atr_autor, atr_anho, atr_titulo para almacenar información sobre los libros. Algunos de los métodos incluyen:

met_registrar(): Permite al usuario registrar un nuevo libro proporcionando detalles como el autor, el año de publicación, el título y la cantidad disponible.
met_prestar_libros(): Permite al usuario prestar un libro específico si está disponible.
met_buscar_libros(): Permite al usuario buscar un libro por título y muestra su información si se encuentra.
met_eliminar_libros(): Permite al usuario eliminar un libro específico de la lista.
met_devolver_libros(): Permite al usuario devolver un libro que había sido prestado previamente.
clas_usuarios: Esta clase se encarga de gestionar los usuarios. Tiene variables miembro como atr_nombres, atr_apellidos, atr_identificacion para almacenar información sobre los usuarios. Algunos de los métodos incluyen:

met_registrar_usuario(): Permite al usuario registrar un nuevo usuario proporcionando detalles como el nombre, el apellido, la identificación y el año de registro.
met_mostrar_registros(): Muestra los registros de libros y usuarios almacenados en el sistema.
En la función main(), se crea un objeto de la clase clas_menu y se llama al método met_mostrar_opciones() para iniciar el programa.

En general, este programa permite al usuario interactuar con un sistema básico de registro y administración de libros y usuarios a través de la consola. Cada opción del menú invoca diferentes métodos para realizar tareas específicas, como registrar libros o usuarios, prestar o devolver libros, buscar libros y mostrar registros

En el programa tambien se utilizan estructuras como las estructuras para permitir el ingreso de diferentes tipos de datos, que con un arreglo o vector normal no seria posible