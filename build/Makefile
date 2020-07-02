all: attack example
attack: attacker.o victim.o helper.o
	g++ -o attack attacker.o victim.o helper.o
attacker.o: ../src/attacker.c ../inc/helper.h ../inc/victim.h
	g++ -c -I../inc -DTRAIN ../src/attacker.c
victim.o: ../src/victim.c ../inc/helper.h ../inc/victim.h
	g++ -c -I../inc -DTRAIN ../src/victim.c
helper.o: ../src/helper.c ../inc/helper.h ../inc/victim.h
	g++ -c -I../inc -DTRAIN ../src/helper.c
example: example_attacker.o example_victim.o example_helper.o
	g++ -o example example_attacker.o example_victim.o example_helper.o
example_attacker.o: ../example/example_attacker.c ../example/example_helper.h ../example/example_victim.h
	g++ -c -I../example  ../example/example_attacker.c
example_victim.o: ../example/example_victim.c ../example/example_helper.h ../example/example_victim.h
	g++ -c -I../example  ../example/example_victim.c
example_helper.o: ../example/example_helper.c ../example/example_helper.h ../example/example_victim.h
	g++ -c -I../example  ../example/example_helper.c
clean:
	rm -f attack example attacker.o victim.o helper.o example_attacker.o example_victim.o example_helper.o 
