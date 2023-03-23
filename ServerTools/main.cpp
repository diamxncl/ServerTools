#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <string>

using namespace std;

void banner () {
    system("clear");
    system("figlet ServerTools");
}

int main () {
    //! DECLARACIÓN DE VARIABLES

    string str_backup = "sudo tar -czvf ./backups/$(date +'%Y-%m-%d_%H-%M-%S')-backup.tar.gz ";
    string backup_folders[6] = {"/home ", "/etc ", "/root ", "/usr/local/bin ", "/usr/local/sbin ", "> /dev/null" };
    char opt[6] = {'a', 'a', 'a', 'a', 'a', 'a'};

    //! FIN DECLARACIÓN DE VARIABLES

    banner();
    cout << endl;
    cout << "1 // DHCP\n";
    cout << "2 // Backup\n";
    cout << "3 // ServerConfig\n";
    cout << "4 // FTP\n";
    cout << "5 // SSH\n";
    cout << "6 // Actualizar sistema\n";
    cout << "\n7 // Salir";

    opt[0] = getch();

        //- DHCP

    switch(opt[0]) {
        case '1': 
            banner();
            cout << "1 // Instalar y configurar DHCP" << endl;
            cout << "2 // Comprobar estado de DHCP" << endl;
            opt[1] = getch();
            switch (opt[1]) {  //* MENÚ OPCIONES
                case '1': //! INSTALACIÓN + CONFIGURACIÓN DHCP
                    banner();
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando DHCP..." << "\033[0m" << endl;
                    system("sudo apt-get install isc-dhcp-server -y > /dev/null");
                    system("sudo cp resources/dhcp-default /etc/default/isc-dhcp-server");
                    system("sudo cp resources/dhcp-etc /etc/dhcp/dhcpd.conf");
                    system("sudo systemctl restart isc-dhcp-server > /dev/null");
                    main();
                    break;
                case '2': 
                    banner(); //! ESTADO DHCP
                    system("sudo systemctl status isc-dhcp-server");
                    cout << "\n\nPresione cualquier botón para continuar...";
                    getch();
                    main();
                    break;
                default:
                    cout << "Ha introducido un valor no válido" << endl;
                    sleep(2);
                    main();
                    break;
            }
            break;

        //- Backup

        case '2': 
            banner();
            cout << "1 // Crear backup" << endl;
            cout << "2 // Ver backups creados" << endl;
            opt[4] = getch();

            switch (opt[4]) { //* MENÚ OPCIONES
                case '1': //! CREACIÓN BACKUP
                    banner();
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Creando backup..." << "\033[0m" << endl;
                    for (int i = 0; i < 6; i++) {
                        str_backup += backup_folders[i];
                    }
                    system(str_backup.c_str());
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "*" << "\033[0m" << "\033[36m" << "] " << "Backup creado." << "\033[0m" << endl;
                    cout << endl;
                    system("ls backups/");
                    cout << "\n\nPresione cualquier botón para continuar...";
                    getch();
                    main();
                    break;
                case '2': //! LISTAR BACKUPS
                    banner();
                    system("ls backups/");
                    cout << "\n\nPresione cualquier botón para continuar...";
                    getch();
                    main();
                    break;
                default:
                    cout << "Ha introducido un valor no válido" << endl;
                    sleep(2);
                    main();
                    break;
            }
            break;

        //- ServerConfig, IP del servidor... (Útiles)

        case '3':
                banner();
                cout << "1 // Mostrar información acerca de la versión del sistema" << endl;
                cout << "2 // Mostrar archivo de configuración de FTP" << endl;
                cout << "3 // Mostrar archivos de configuración de DHCP" << endl;
                cout << "4 // Mostrar información de red" << endl;
                opt[5] = getch();

                switch (opt[5]) { //* MENÚ OPCIONES
                    case '1': //! INSTALACIÓN SCREENFETCH + MOSTRAR INFO
                        banner();
                        system("sudo apt-get install screenfetch -y > /dev/null");
                        system("screenfetch");
                        cout << "\n\nPresione cualquier botón para continuar...";
                        getch();
                        main();
                        break;
                    case '2': //! MOSTRAR INFO FTP
                        banner();
                        system("sudo cat /etc/vsftpd.conf");
                        cout << "\n\nPresione cualquier botón para continuar...";
                        getch();
                        main();
                        break;
                    case '3':
                        banner(); //! MOSTRAR INFO DHCP
                        cout << "----- /etc/default/isc-dhcp-server -----\n\n";
                        system("sudo cat /etc/default/isc-dhcp-server");
                        cout << "\n\n----- /etc/dhcp/dhcpd.conf -----\n\n";
                        system("sudo cat /etc/dhcp/dhcpd.conf");
                        cout << "\n\nPresione cualquier botón para continuar...";
                        getch();
                        main();
                        break;
                    case '4':
                        banner(); //! MOSTRAR INFO RED
                        cout << "\n\nPresione cualquier botón para continuar...";
                        system("sudo ip a");
                        getch();
                        main();
                        break;
                    default:
                        cout << "Ha introducido un valor no válido" << endl;
                        sleep(2);
                        main();
                        break;
                }
            banner();
                cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Mostrando configuraciones del servidor..." << "\033[0m" << endl;
            break;

        //- FTP

        case '4':
            banner();
            cout << "1 // Instalar y configurar servidor FTP" << endl;
            cout << "2 // Comprobar estado del servidor FTP" << endl;
            opt[2] = getch();

            switch(opt[2]) { //* MENÚ OPCIONES
                case '1': //! INSTALACIÓN + CONFIGURACIÓN FTP
                    banner();
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando FTP..." << "\033[0m" << endl;
                    system("sudo apt-get install vsftpd > /dev/null");
                    cout << endl;
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Habilitando e iniciando el servicio." << "\033[0m" << endl;
                    system("sudo cp resources/ftp /etc/vsftpd.conf");
                    system("sudo systemctl enable vsftpd.service > /dev/null");
                    system("sudo systemctl start vsftpd > /dev/null");
                    system("sudo touch /etc/vsftpd.userlist && sudo chmod 777 /etc/vsftpd.userlist");
                    system("sudo echo root > /etc/vsftpd.userlist");
                    banner();
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "*" << "\033[0m" << "\033[36m" << "] " << "FTP Instalado y configurado." << "\033[0m" << endl;
                    cout << endl;
                    cout << "Conéctese a la ip 192.168.79.100.\n\nftp 192.168.79.100";
                    cout << "\n\nPresione cualquier botón para continuar...";
                    getch();
                    main();
                    break;
                case '2': //! MOSTRAR ESTADO FTP
                    banner();
                    system("sudo systemctl status vsftpd");
                    cout << "\n\nPresione cualquier botón para continuar...";
                    getch();
                    main();
                    break;
                default:
                    cout << "Ha introducido un valor no válido" << endl;
                    sleep(2);
                    main();
                    break;
            }
            break;

        //- SSH

        case '5': 
            banner();
            cout << "1 // Instalar y configurar servidor SSH" << endl;
            cout << "2 // Comprobar estado del servidor SSH" << endl;
            opt[3] = getch();

            switch(opt[3]) { //* MENÚ OPCIONES
                case '1': //! INSTALAR Y CONFIGURAR SSH
                    banner();
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando SSH..." << "\033[0m" << endl;
                    system("sudo apt-get install openssh-server -y > /dev/null");
                    cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "SSH Instalado..." << "\033[0m" << endl;
                    cout << "Conéctese a la ip 192.168.79.100\n\nssh 192.168.79.100";
                    cout << "\n\nPresione cualquier botón para continuar...";
                    getch();
                    main();
                    break;
                case '2': //! MOSTRAR ESTADO SSH
                    banner();
                    system("sudo systemctl status sshd");
                    cout << "\n\nPresione cualquier botón para continuar...";
                    getch();
                    main();
                    break;
            }
            break;

        //- Update

        case '6': //! ACTUALIZAR EL EQUIPO
            banner();
            cout << "\033[36m" << "[" << "\033[0m" << "\033[32m" << "+" << "\033[0m" << "\033[36m" << "] " << "Instalando actualizaciones..." << "\033[0m" << endl << endl;
            system("sudo apt-get update -y && sudo apt-get upgrade");
            main();
            break;

        //- Exit

        case '7':
            break;

        //- Opción incorrecta

        default: 
            system("clear && figlet Error");
            cout << "Ha introducido una opción no válida." << endl;
            sleep(2);
            break;
    }

system("clear");

return 0;
}