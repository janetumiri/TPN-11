#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno {
private:
    string nombre;
    double nota1;
    double nota2;
    double nota3;
    int edad;
    string estado; 

public:
    Alumno(string nombre, double nota1, double nota2, double nota3, int edad)
        : nombre(nombre), nota1(nota1), nota2(nota2), nota3(nota3), edad(edad) {
        actualizarEstado(); 
    }
    string getNombre() const { return nombre; }
    double getNota1() const { return nota1; }
    double getNota2() const { return nota2; }
    double getNota3() const { return nota3; }
    int getEdad() const { return edad; }
    string getEstado() const { return estado; }

    double calcularPromedio() const { return (nota1 + nota2 + nota3) / 3; }

    void actualizarEstado() {
        if (calcularPromedio() >= 7) {
            estado = "Aprobado";
        } else {
            estado = "Desaprobado";
        }
    }
    double getNotaMasAlta() const {
        return max(max(nota1, nota2), nota3);
    }
    double getNotaMasBaja() const {
        return min(min(nota1, nota2), nota3);
    }
};
Alumno* buscarAlumno(const vector<Alumno>& alumnos, const string& nombre) {
    for (const auto& alumno : alumnos) {
        if (alumno.getNombre() == nombre) {
            return const_cast<Alumno*>(&alumno); 
        }
    }
    return nullptr; 
}

int main() {
    vector<Alumno> alumnos;

    string nombre;
    double nota1, nota2, nota3;
    int numAlumnos, edad;
    cout << "Ingrese el número de alumnos: ";
    cin >> numAlumnos;

    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese el nombre del alumno: ";
        cin >> nombre;
        cout << "Ingrese la nota 1 del alumno: ";
        cin >> nota1;
        cout << "Ingrese la nota 2 del alumno: ";
        cin >> nota2;
        cout << "Ingrese la nota 3 del alumno: ";
        cin >> nota3;
        cout << "Ingrese la edad del alumno: ";
        cin >> edad;

        alumnos.push_back(Alumno(nombre, nota1, nota2, nota3, edad));
    }
    cout << "\nDatos de los alumnos:" << endl;
    for (const auto& alumno : alumnos) {
        cout << "Nombre: " << alumno.getNombre() << endl;
        cout << "Nota 1: " << alumno.getNota1() << endl;
        cout << "Nota 2: " << alumno.getNota2() << endl;
        cout << "Nota 3: " << alumno.getNota3() << endl;
        cout << "Edad: " << alumno.getEdad() << endl;
        cout << "Promedio: " << alumno.calcularPromedio() << endl;
        cout << "Estado: " << alumno.getEstado() << endl;
        cout << endl;
    }
    string nombreBuscado;
    cout << "Ingrese el nombre del alumno a buscar: ";
    cin >> nombreBuscado;

    Alumno* alumnoEncontrado = buscarAlumno(alumnos, nombreBuscado);
    if (alumnoEncontrado != nullptr) {
        cout << "\nAlumno encontrado:" << endl;
        cout << "Nombre: " << alumnoEncontrado->getNombre() << endl;
        cout << "Nota más alta: " << alumnoEncontrado->getNotaMasAlta() << endl;
        cout << "Nota más baja: " << alumnoEncontrado->getNotaMasBaja() << endl;
    } else {
        cout << "\nAlumno no encontrado." << endl;
    }
    double sumaPromedios = 0;
    for (const auto& alumno : alumnos) {
        sumaPromedios += alumno.calcularPromedio();
    }
    double promedioGeneral = sumaPromedios / alumnos.size();
    cout << "\nPromedio general de todos los alumnos: " << promedioGeneral << endl;

    return 0;
}
