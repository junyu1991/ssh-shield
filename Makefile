objects = main.o log.o util.o list.o
target = ssh-shield

#main : main.o add.o minus.o
main : $(objects)
	cc -rdynamic -o $(target) $(objects)
main.o : src/main.c
	cc -I header/ -c src/main.c
log.o : src/log.c
	cc -I header/ -c src/log.c
util.o : src/util.c 
	cc -I header/ -c src/util.c
list.o : src/list.c
	cc -I header/ -c src/list.c
clean : 
	rm $(target) $(objects)
