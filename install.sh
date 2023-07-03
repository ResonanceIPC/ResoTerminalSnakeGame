#!/bin/bash

# Define color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No color

echo -e "${CYAN}Installation has been started"

gcc game.c libs/apple/apple.c  libs/matrice/matrice.c libs/model/model.c libs/screen/screen.c libs/snake/snake.c libs/powered/powered.c libs/requests/requests.c libs/defaults/defaults.c libs/joystick/joystick.c -lncurses -o snake

echo -e "${GREEN}\nInstallation has been finished"
echo -e "${YELLOW}"
read  -p  "Make snake global? (can be run from everywhere by typing snake) [y,n] " feedback 
case $feedback in  
  y|Y) sudo cp snake /bin/ && echo -e "\n${GREEN}Now snake has become global and can be run by typing snake wherever you want\n${YELLOW}" ;; 
  n|N) echo -e "\n${CYAN}Okay, snake will not become global and can be called from its directory.\n${YELLOW}" ;; 
esac


read -n1 -p "Run it now? [y,n] " feedback 
case $feedback in  
  y|Y) ./snake ;; 
esac



echo -e "\n\n${GREEN}[SUCCESS]${YELLOW} Everything has been completed and for running just type ${CYAN}./snake ${GREEN}[SUCCESS]"

