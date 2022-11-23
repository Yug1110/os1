default:
	gcc cat.c -o cat
	gcc mkdir.c -o mkdir
	gcc ls.c -o ls
	gcc date.c -o date
	gcc rm.c -o rm
	gcc main.c -o main -lpthread
	./main
