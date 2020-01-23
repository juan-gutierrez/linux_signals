#!/bin/bash

RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
GRAY='\033[0;37m'
NC='\033[0m' # No Color

echo -e "${YELLOW}"
echo "Removing old software"
echo -e "${NC}"
rm myplayer
sleep 1

echo -e "${YELLOW}"
echo "Downloading updates ..."
echo -e "${NC}"
wget https://github.com/juan-gutierrez/linux_signals/releases/download/$1/myplayer
sleep 1

echo -e "${YELLOW}"
echo "Installing updates..."
echo -e "${NC}"
chmod +x myplayer

echo -e "${GREEN}"
echo "Succesfull instalation..."
echo -e "${NC}"




