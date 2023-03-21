#include <iostream>
#include <conio.h>

using namespace std;

void banner () {
    system("clear");
    system("figlet ServerTools");
}

int main () {
    //! DECLARACIÓN DE VARIABLES

    char opt;

    //! FIN DECLARACIÓN DE VARIABLES

    system("clear");
    cout << "Cargando...";
    cout << endl;
    system("sudo apt-get install figlet -y > /dev/null");

    banner();
    cout << "1 // DHCP\n";
    cout << "2 // Backup\n";
    cout << "3 // ServerConfig\n";
    cout << "4 // FTP\n";
    cout << "5 // SSH\n";
    cout << "6 // Actualizar sistema\n";

    opt = getch();

    switch(opt) {
        case '1': //- DHCP
            banner();
            cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando DHCP..." << "\033[0m" << endl;
            system("sudo apt-get install isc-dhcp-server > /dev/null");
            system("sudo cp resources/dhcp-default /etc/default/isc-dhcp-server");
            system("sudo cp resources/dhcp-etc /etc/dhcp/dhcpd.conf");
            system("sudo systemctl restart isc-dhcp-server");
            main();
            break;
        case '2': //- Backup
            banner();
                cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Creando backup..." << "\033[0m" << endl;
            break;
        case '3': //- ServerConfig, IP del servidor... (Útiles)
            banner();
                cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Mostrando configuraciones del servidor..." << "\033[0m" << endl;
            break;
        case '4': //- FTP
            banner();
                cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando FTP..." << "\033[0m" << endl;
                system("sudo apt-get install vsftpd > /dev/null");
                cout << endl;
                cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "*" << "\033[0m" << "\033[36m" << "] " << "FTP Instalado." << "\033[0m" << endl;
                cout << endl;
                cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Habilitando e iniciando el servicio." << "\033[0m" << endl;
                system("systemctl enable vsftpd.service");
                system("systemctl start vsftpd");
            break;
        case '5': //- SSH
            banner();
                cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando SSH..." << "\033[0m" << endl;
                system("sudo apt install openssh-server -y ");
            break;
        case '6': //- Update
            banner();
            cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando actualizaciones..." << "\033[0m" << endl << endl;
            system("sudo apt-get update -y && sudo apt-get upgrade");
            main();
        default: //- Opción incorrecta
            system("clear && figlet Error");
            cout << "Ha introducido una opción no válida." << endl;
            return 1;
    }

return 0;
}