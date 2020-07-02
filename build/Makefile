attack: attacker.o victim.o helper.o
	gcc -o attack attacker.o victim.o helper.o
attacker.o: ../src/attacker.c
	gcc -c -I../inc -DTRAIN ../src/attacker.c
victim.o: ../src/victim.c
	gcc -c -I../inc -DTRAIN ../src/victim.c
helper.o: ../src/helper.c
	gcc -c -I../inc -DTRAIN ../src/helper.c
clean:
	rm -f attack attacker.o victim.o helper.o
