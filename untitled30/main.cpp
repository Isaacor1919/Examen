#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    //variables del archivo
    string id, beca, ncv, c0, c1, c2, c3; //must be int
    string nombre, sede, programa, nivel, estatus;
    string cargos, eca, depp, ajustado, pagado, saldo, saldo_vencido, b0, a0, p0, s0, porcentaje0, b1, a1, p1, s1, porcentaje1, b2, a2, p2, s2, porcentaje2, b3, a3, p3, s3, porcentaje3; //must be double
    vector<int>id_unid;
    vector<string>nombre_alumno;
    vector<string>programa_unid;
    vector<double>saldo_vencido_pesos;
    vector<int>col_vencidas;
    vector<bool>check;




    string archivo;//saves the file name
    cout << "Ingresa el nombre del archivo para analizar:";
    cin >> archivo;

    //number of lines
    int i = 0;
    int deudores = 0;

    ifstream read(archivo);//opening file
    if (read.is_open()){
        //ignore first line
        string line;
        getline(read, line);

        while (!read.eof()){
            getline(read,id,',');
            id_unid.push_back(stoi(id));
            getline(read, nombre, ',');
            nombre_alumno.emplace_back(nombre);
            getline(read, sede, ',');
            getline(read, programa, ',');
            programa_unid.emplace_back(programa);
            getline(read, nivel, ',');
            getline(read, estatus, ',');
            getline(read, beca, ',' );
            getline(read, cargos, ',');
            getline(read, eca,',');
            getline(read, depp, ',');
            getline(read, ajustado, ',');
            getline(read, pagado, ',');
            getline(read, saldo, ',');
            getline(read, saldo_vencido, ',');
            saldo_vencido_pesos.push_back(stod(saldo_vencido));
            if (stoi(saldo_vencido) > 0){
                check.emplace_back(true);
                deudores += 1;//contar cuantos deben
            } else check.emplace_back(false);
            getline(read, ncv, ',');
            //col_vencidas.push_back(stoi(ncv));
            getline(read, c0, ',');
            getline(read, b0, ',');
            getline(read, a0, ',');
            getline(read, p0, ',');
            getline(read, s0, ',');
            getline(read, porcentaje0, ',');
            getline(read, c1, ',');
            getline(read,b1,',');
            getline(read,a1,',');
            getline(read,p1,',');
            getline(read, s1,',');
            getline(read,porcentaje1,',');
            getline(read,c2,',');
            getline(read,b2,',');
            getline(read,a2,',');
            getline(read,p2,',');
            getline(read,s2,',');
            getline(read,porcentaje2,',');
            getline(read,c3,',');
            getline(read,b3,',');
            getline(read,a3,',');
            getline(read,p3,',');
            getline(read,s3,',');
            getline(read,porcentaje3,'\n');//new line after this

            i += 1; //increment line
        } //while the end of file is not reached
        read.close(); //closing the file

        cout<<"Numero de entradas: " <<i<<endl;

    } else cout << "No se puede abrir el archivo"<<endl; //error

    //output vectors
    cout << "¿Que operación desea realizar?" << endl;
    cout
            << "1)Contar cuantos deudores hay. 2)Buscar ID de alumno. 3)Ver por programa academico. 4)Ver todos los deudores. 5)Salir"
            << endl;
    cout << "Numero de opcion: ";
    int numero;
    cin >> numero;


    switch(numero) {
        case 1:
            cout << "Numero de Deudores: " << deudores << endl;
            break;
        case 2: {
            cout << "Ingrese el id del alumno: ";
            int id_buscar;
            cin >> id_buscar;
            cout << "ID" << "\t" << "Nombre" << "\t" << "Programa" << "\t" << "Saldo Vencido" << endl;
            for (int j = 0; j < i; j++) {
                if (id_unid[j] == id_buscar)
                    cout << id_unid[j] << "\t" << nombre_alumno[j] << "\t" << programa_unid[j] << "\t"
                         << saldo_vencido_pesos[j]
                         <<  endl;
            }
        }
            break;
        case 3: {
            cout << "Introduza clave del programa: ";
            string buscar_programa;
            cin >> buscar_programa;
            cout << "ID" << "\t" << "Nombre" << "\t" << "Programa" << "\t" << "Saldo vencido" << endl;
            for (int j = 0; j < i; j++) {
                if (programa_unid[j].compare(buscar_programa) == 0)
                    cout << id_unid[j] << "\t" << nombre_alumno[j] << "\t" << programa_unid[j] << "\t"
                         << saldo_vencido_pesos[j]
                         << endl;
            }
        }
            break;
        case 4: {
            for (int j = 0; j < i; j++) {
                cout << "ID" << "\t" << "Nombre" << "\t" << "Programa" << "\t" << "Saldo Vencido" << endl;
                if (saldo_vencido_pesos[j] > 0)
                    cout << id_unid[j] << "\t" << nombre_alumno[j] << "\t" << programa_unid[j] << "\t"
                         << saldo_vencido_pesos[j]  << endl;
            }

        }
        case 5:
        {
            return 0;
        }
    }

}