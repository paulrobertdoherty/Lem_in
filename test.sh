./generator $1 > output.txt && make re && ./lem_in < output.txt | grep "L" | wc -l && cat output.txt | grep ":"
