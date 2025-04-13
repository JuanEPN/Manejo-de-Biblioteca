#include <iostream>
#include <string>
#include <vector>

class clas_usuarios; // Declaración anticipada de la clase clas_usuarios

class clas_menu {
public:
    clas_menu();
    int met_mostrar_opciones();
    int atr_opcion;
};

class clas_libros {
public:
    clas_libros();
    std::string atr_autor, atr_anho, atr_titulo;
    std::string atr_pautor, atr_panho, atr_ptitulo;
    std::string atr_titulo1, atr_autor1, atr_anho1;
    std::string atr_librod, atr_autord, atr_anhod;
    int atr_cantidad;
    void met_registrar();
    void met_prestar_libros();
    void met_buscar_libros();
    void met_eliminar_libros();
    void met_devolver_libros();
    struct Libro {
        std::string atr_autor;
        std::string atr_anho;
        std::string atr_titulo;
        int atr_cantidad;
    };

    std::vector<Libro> libros;
};

class clas_usuarios {
public:
    clas_usuarios();
    std::string atr_nombres, atr_apellidos, atr_identificacion, atr_anho_usu;
    void met_registrar_usuario();
    int met_mostrar_registros(clas_libros& obj_libro);
    struct Usuario {
        std::string atr_nombres;
        std::string atr_apellidos;
        std::string atr_identificacion;
        std::string atr_anho_usu;
    };

    std::vector<Usuario> usuarios;
};

clas_menu::clas_menu() {

}

int clas_menu::met_mostrar_opciones() {
    clas_libros obj_libro;
    clas_usuarios obj_usuario;

    while (true) {
        std::cout << "Menú de opciones: " << std::endl;
        std::cout << "1. Registrar libros. Opción 1" << std::endl;
        std::cout << "2. Registrar usuarios. Opción 2" << std::endl;
        std::cout << "3. Prestar libros. Opción 3" << std::endl;
        std::cout << "4. Buscar libros. Opción 4" << std::endl;
        std::cout << "5. Administrar libros. Opción 5" << std::endl;
        std::cout << "6. Devolver libros. Opción 6" << std::endl;
        std::cout << "7. Mostrar registros. Opción 7" << std::endl;
        std::cout << "Ingrese su opción: ";
        std::cin >> atr_opcion;
        std::cin.ignore(); // Ignorar el carácter de nueva línea dejado por cin

        switch (atr_opcion) {
        case 1: {
            std::cout << "Has seleccionado registrar libros" << std::endl;
            obj_libro.met_registrar();
            break;
        }
        case 2: {
            std::cout << "Has seleccionado registrar usuarios" << std::endl;
            obj_usuario.met_registrar_usuario();
            break;
        }
        case 3:
            std::cout << "Has seleccionado prestar libros" << std::endl;
            obj_libro.met_prestar_libros();
            break;
        case 4:
            std::cout << "Has seleccionado buscar libros" << std::endl;
            obj_libro.met_buscar_libros();
            break;
        case 5:
            std::cout << "Has seleccionado administrar libros" << std::endl;
            obj_libro.met_eliminar_libros();
            break;
        case 6:
            std::cout << "Has seleccionado devolver libros" << std::endl;
            obj_libro.met_devolver_libros();
            break;
        case 7:
            std::cout << "Has seleccionado mostrar registros" << std::endl;
            obj_usuario.met_mostrar_registros(obj_libro);
            break;
        default:
            std::cout << "Opción inválida. Por favor, ingrese una opción válida." << std::endl;
            break;
        }
    }
    return 0;
}

clas_libros::clas_libros() {

}

clas_usuarios::clas_usuarios(){
    
}

void clas_libros::met_registrar() {
    Libro libro;

    std::cout << "Ingrese el autor del libro: ";
    getline(std::cin, libro.atr_autor);
    std::cout << "Ingrese el año de publicación del libro: ";
    getline(std::cin, libro.atr_anho);
    std::cout << "Ingrese el título del libro: ";
    getline(std::cin, libro.atr_titulo);
    std::cout << "Ingrese la cantidad de libros disponibles: ";
    std::cin >> libro.atr_cantidad;
    std::cin.ignore(); // Ignorar el carácter de nueva línea dejado por cin

    libros.push_back(libro);

    std::cout << "El libro ha sido registrado correctamente." << std::endl;
}

void clas_libros::met_prestar_libros() {
    std::string titulo_prestar;
    std::cout << "Ingrese el título del libro que desea prestar: ";
    getline(std::cin, titulo_prestar);

    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].atr_titulo == titulo_prestar) {
            if (libros[i].atr_cantidad > 0) {
                libros[i].atr_cantidad--;
                std::cout << "El libro ha sido prestado correctamente." << std::endl;
            }
            else {
                std::cout << "No hay disponibilidad de este libro en el momento." << std::endl;
            }
            return;
        }
    }

    std::cout << "No se encontró el libro especificado." << std::endl;
}

void clas_libros::met_buscar_libros() {
    std::string titulo_buscar;
    std::cout << "Ingrese el título del libro que desea buscar: ";
    getline(std::cin, titulo_buscar);

    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].atr_titulo == titulo_buscar) {
            std::cout << "Información del libro encontrado:" << std::endl;
            std::cout << "Autor: " << libros[i].atr_autor << std::endl;
            std::cout << "Año de publicación: " << libros[i].atr_anho << std::endl;
            std::cout << "Cantidad disponible: " << libros[i].atr_cantidad << std::endl;
            return;
        }
    }

    std::cout << "No se encontró el libro especificado." << std::endl;
}

void clas_libros::met_eliminar_libros() {
    std::string titulo_eliminar;
    std::cout << "Ingrese el título del libro que desea eliminar: ";
    getline(std::cin, titulo_eliminar);

    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].atr_titulo == titulo_eliminar) {
            libros.erase(libros.begin() + i);
            std::cout << "El libro ha sido eliminado correctamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontró el libro especificado." << std::endl;
}

void clas_libros::met_devolver_libros() {
    std::string titulo_devolver;
    std::cout << "Ingrese el título del libro que desea devolver: ";
    getline(std::cin, titulo_devolver);

    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].atr_titulo == titulo_devolver) {
            libros[i].atr_cantidad++;
            std::cout << "El libro ha sido devuelto correctamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontró el libro especificado." << std::endl;
}

void clas_usuarios::met_registrar_usuario(){
    std::cout << "Ingrese el nombre del usuario a registrar: ";
    std::getline(std::cin, atr_nombres);
    std::cout << "Ingrese el apellido del usuario a registrar: ";
    std::getline(std::cin, atr_apellidos);
    std::cout << "Ingrese la identificación del usuario a registrar: ";
    std::getline(std::cin, atr_identificacion);
    std::cout << "Ingrese el año de registro del usuario: ";
    std::getline(std::cin, atr_anho_usu);

    for (int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].atr_identificacion == atr_identificacion) {
            // El usuario ya está registrado
            std::cout << "El usuario ya está registrado" << std::endl;
            return;
        }
    }

    Usuario usuario;
    usuario.atr_nombres = atr_nombres;
    usuario.atr_apellidos = atr_apellidos;
    usuario.atr_identificacion = atr_identificacion;
    usuario.atr_anho_usu = atr_anho_usu;

    usuarios.push_back(usuario);

    std::cout << "El usuario ha sido registrado exitosamente" << std::endl;
}

int clas_usuarios::met_mostrar_registros(clas_libros& obj_libro) {
    std::cout << "Registros de libros:" << std::endl;

    for (int i = 0; i < obj_libro.libros.size(); i++) {
        std::cout << "Título: " << obj_libro.libros[i].atr_titulo << std::endl;
        std::cout << "Autor: " << obj_libro.libros[i].atr_autor << std::endl;
        std::cout << "Año de publicación: " << obj_libro.libros[i].atr_anho << std::endl;
        std::cout << "Cantidad disponible: " << obj_libro.libros[i].atr_cantidad << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
    
    std::cout << "Registros de usuarios:" << std::endl;
    for (int i = 0; i < usuarios.size(); i++) {
        std::cout << "Nombre: " << usuarios[i].atr_nombres << std::endl;
        std::cout << "Apellido: " << usuarios[i].atr_apellidos << std::endl;
        std::cout << "Identificación: " << usuarios[i].atr_identificacion << std::endl;
        std::cout << "Año de registro: " << usuarios[i].atr_anho_usu << std::endl;
    }
    
    return 0;
}

int main() {
    clas_menu obj_menu;
    obj_menu.met_mostrar_opciones();
    return 0;
}
