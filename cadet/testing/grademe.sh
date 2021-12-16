#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette ./*.c ./*.h
echo -e "\033[32;1m"LIBFT TEST"\033[m"
read $a
git clone https://github.com/jtoty/Libftest
cd Libftest/
./grademe.sh
sed -i "" 's/~\/libft/..\//' my_config.sh
./grademe.sh
cd ..
echo -e "\033[32;1m"WAR MACHINE"\033[m"
read $a
git clone https://github.com/ska42/libft-war-machine
cd libft-war-machine/
bash grademe.sh 