sh clean.sh
cd ..
rm paths.txt
make re
./lem_in < $1
chmod 777 paths.txt
make fclean
cd Visualizer
javac Main.java
java Main ../$1 ../paths.txt $2 $3
open $3
rm ../paths.txt
sh clean.sh
