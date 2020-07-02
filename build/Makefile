attack: attacker.o victim.o helper.o
	g++ -o attack attacker.o victim.o helper.o
attacker.o: ../src/attacker.c ../inc/helper.h ../inc/victim.h
	g++ -c -I../inc -DTRAIN ../src/attacker.c
victim.o: ../src/victim.c ../inc/helper.h ../inc/victim.h
	g++ -c -I../inc -DTRAIN ../src/victim.c
helper.o: ../src/helper.c ../inc/helper.h ../inc/victim.h
	g++ -c -I../inc -DTRAIN ../src/helper.c
clean:
	rm -f attack attacker.o victim.o helper.o
