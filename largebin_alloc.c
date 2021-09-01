#include<stdio.h>
#include<stdlib.h>
int main(){
	
    int *p1 =malloc(8); 
    int *p2 =malloc(8);
    fprintf(stderr,"malloc two fastbin chunk: p1=%p p2=%p\n",p1,p2);
      
    //free(p1);     //free p1 into fastbins
    fprintf(stderr,"free p1\n");    
    void * p3 = malloc(0x500); //malloc large chunk from top chunk
    void * p4 = malloc(0x8); //void the freed large chunk consolidated with top chunk 
    void * p5 = malloc(0x600); //malloc another large chunk
    void * p6 = malloc(0x8); //void the freed large chunk consolidated with top chunk
    free(p3);                  //free p3 into unsortedbin
    free(p5);                  //free p5 into unsortedbin
    void * p7 = malloc(0x550); //malloc large chunk, remove p3 into largebin 
    fprintf(stderr,"malloc large chunk:p7=%p\n",p7);
    //free(p1);     //free p1 into fastbins,so p1 will be in fastbin and smallbin at the same time 
   // fprintf(stderr,"double free p1\n");
   
    //fprintf(stderr,"malloc two fastbin chunk:%p %p\n",malloc(8),malloc(8));
    
}


