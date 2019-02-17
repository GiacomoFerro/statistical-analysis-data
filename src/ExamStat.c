#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Necessita di un file input,txt con matricole e voti nella forma:
con "INS" : voto <=18.
con "30L" : voto == 30 e lode.

12345678-n1
98765432-m1

...


ritorna un file results.txt con i risultati statistici.

*/



int main(void){

    FILE *fd;
    FILE *results;
    char studente[200];
    char * token=malloc(sizeof(studente));
    char * voto=malloc(sizeof(studente));

    int numStudenti=0;

    int contVoti[15]={0};    

    bool lock=true;

	/* apre il file in scrittura */
	fd=fopen("input.txt", "r");

	if( fd==NULL ) {
		perror("Errore in apertura del file");
		exit(1);
	}

    fscanf(fd, "%s", studente);

    while(!feof(fd)){
        
        //printf("studente:%s\n",studente);
        numStudenti++;

        token=strtok(studente, "-");   
        //printf("matricola:%s ",token);                       
        token=strtok(NULL, "-"); 
        //printf("voto:%s\n",token); 
        voto=token;

        //ho il voto che devo catalogare

        if(strcmp(voto,"INS")==0){ contVoti[0]+=1; lock=false;}
        
        if(strcmp(voto,"30L")==0){ contVoti[1]+=1; lock=false;}
        
        if(lock){
            int n=atoi(voto);
            switch(n){

            case 18:
                contVoti[2]+=1;
                break;
            case 19:
                contVoti[3]+=1;
                break;
            case 20:
                contVoti[4]+=1;
                break;
            case 21:
                contVoti[5]+=1;
                break;
            case 22:
                contVoti[6]+=1;
                break;
            case 23:
                contVoti[7]+=1;
                break;
            case 24:
                contVoti[8]+=1;
                break;
            case 25:
                contVoti[9]+=1;
                break;
            case 26:
                contVoti[10]+=1;
                break;
            case 27:
                contVoti[11]+=1;
                break;
            case 28:
                contVoti[12]+=1;
                break;
            case 29:
                contVoti[13]+=1;
                break;
            case 30:
                contVoti[14]+=1;
                break;
        }//fine switch      

    }//fine if
        lock=true;
        fscanf(fd, "%s", studente);

    }//fine while   

    fclose(fd);    

    results=fopen("results.txt","w");


    fprintf(results,"%s","\n*********************************\n");
    fprintf(results,"%s","          STATISTICHE ESAME         \n");

    fprintf(results,"NUM STUDENTI=%d\n", numStudenti);

    
    fprintf(results,"VOTI INS=%d\t(%.2f perc)\n", contVoti[0], ((float)contVoti[0]/numStudenti)*100);
    fprintf(results,"VOTI 18=%d\t(%.2f perc)\n", contVoti[2], ((float)contVoti[2]/numStudenti)*100);
    fprintf(results,"VOTI 19=%d\t(%.2f perc)\n", contVoti[3], ((float)contVoti[3]/numStudenti)*100);
    fprintf(results,"VOTI 20=%d\t(%.2f perc)\n", contVoti[4], ((float)contVoti[4]/numStudenti)*100);
    fprintf(results,"VOTI 21=%d\t(%.2f perc)\n", contVoti[5], ((float)contVoti[5]/numStudenti)*100);
    fprintf(results,"VOTI 22=%d\t(%.2f perc)\n", contVoti[6], ((float)contVoti[6]/numStudenti)*100);
    fprintf(results,"VOTI 23=%d\t(%.2f perc)\n", contVoti[7], ((float)contVoti[7]/numStudenti)*100);
    fprintf(results,"VOTI 24=%d\t(%.2f perc)\n", contVoti[8], ((float)contVoti[8]/numStudenti)*100);
    fprintf(results,"VOTI 25=%d\t(%.2f perc)\n", contVoti[9], ((float)contVoti[9]/numStudenti)*100);
    fprintf(results,"VOTI 26=%d\t(%.2f perc)\n", contVoti[10], ((float)contVoti[10]/numStudenti)*100);
    fprintf(results,"VOTI 27=%d\t(%.2f perc)\n", contVoti[11], ((float)contVoti[11]/numStudenti)*100);
    fprintf(results,"VOTI 28=%d\t(%.2f perc)\n", contVoti[12], ((float)contVoti[12]/numStudenti)*100);
    fprintf(results,"VOTI 29=%d\t(%.2f perc)\n", contVoti[13], ((float)contVoti[13]/numStudenti)*100);
    fprintf(results,"VOTI 30=%d\t(%.2f perc)\n", contVoti[14], ((float)contVoti[14]/numStudenti)*100);
    fprintf(results,"VOTI 30L=%d\t(%.2f perc)\n", contVoti[1], ((float)contVoti[1]/numStudenti)*100);
        

    fprintf(results,"%s","\n*********************************\n\n");
 
    fclose(results);

}

