clear
figlet Setup
echo ""

echo "Este programa actualiza el sistema e instala los paquetes: make, g++ además de la libreria conio.h"
echo ""
echo "$(tput setaf 7)[$(tput setaf 1)+$(tput setaf 7)] Realizando cambios..."
echo ""

# Main program
sudo apt-get update -y > /dev/null && sudo apt-get upgrade -y > /dev/null
sudo apt-get install make g++ -y >/dev/null
git clone https://github.com/zoelabbb/conio.h > /dev/null
cd conio.h
sudo make install
cd ../
g++ main.cpp -o ServerTools.out

# Fin
clear
figlet Setup
echo ""
echo "$(tput setaf 7)[$(tput setaf 1)*$(tput setaf 7)] Cambios realizados..."
echo ""
sleep 1
clear
