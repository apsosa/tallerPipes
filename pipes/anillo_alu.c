#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// ./anillo n c s
int main(int argc, char **argv)
{	
	int c, start, pid, n, tmp;
	int buffer[1];
	char buf_father;

	if (argc != 4){ printf("Uso: anillo <n> <c> <s> \n"); exit(0);}
    
  	/* COMPLETAR */
	n = *argv[1] - '0';
	c = *argv[2] - '0';
	start = *argv[3] - '0';
	int p = 0;
	tmp = n;

    printf("Se crearán %i procesos, se enviará el caracter %i desde proceso %i \n", n, buffer[0], start);
    
    /* COMPLETAR */
	
	int pipes_frodo[2];
    if (pipe(pipes_frodo) == -1) {
		perror("pipe");
		exit(1);
	}
    write(pipes_f= rodo[1], &p, 1);
	vector<pipe> pipes; 

	while(n != 0){
		pid_t pid = fork();
		printf("%d\n", n);
		if(pid == 0){
			printf("soy hijo %d\n", n);
			if(n <= start){
				while(c != p){
					char buf;			
					if(read(pipes_frodo[0],&buf,1) != -1 ){
						int value = buf;
						value++;
						printf("Ejecutando proceso con %i\n",value);
						write(pipes_frodo[1], &value,1);
					};
				}
				return 0;		
			}
			break;
		}
		n--;
	}

	if( read(pipes_frodo[0],&buf_father,1)  == p){
		printf("termine con valor %d\n", p);		
		close(pipes_frodo[0]);          /* Close unused read end */
		close(pipes_frodo[1]);          /* Reader will see EOF */
	}
	return 0;
}
