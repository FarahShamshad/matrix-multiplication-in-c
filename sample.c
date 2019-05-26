#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<math.h>

void * multiplyer(void *);
int mat1[3][3]={0};
int mat2[3][3]={0};
int mat[3][3]={0};
int i=0;
int k=0;
int main()
{
 //  char file1_name[]=args[1];
 //  char file2_name[]=args[2];
   FILE *new;
   new = fopen("s1.txt","r");
   if(new==NULL)
   {
    printf("Cannot oprn file\n");
    exit(0);
   }   
   for(int l=0;l<3;l++)
   {
     for(int j=0;j<3;j++)
     {
       fscanf(new,"%d",&mat1[l][j]);
     } 
   }
   for(int l=0;l<3;l++)
   {
     for(int j=0;j<3;j++)
     {
       printf("%d", mat1[l][j]);
     }
      printf("\n"); 
   }
   fclose(new);
   new = fopen("s2.txt","r");
   if(new==NULL)
   {
    printf("Cannot open file\n");
    exit(0);
   }   
   for(int i=0;i<3;i++)
   {
     for(int j=0;j<3;j++)
     {
       fscanf(new,"%d",&mat2[i][j]);
     } 
   }
   for(int l=0;l<3;l++)
   {
     for(int j=0;j<3;j++)
     {
       printf("%d", mat2[l][j]);
     }
      printf("\n"); 
   }
   fclose(new);
    pthread_t athread,bthread, cthread;
    pthread_create(&athread,NULL,multiplyer,NULL); 
    pthread_create(&bthread,NULL,multiplyer,NULL);
    pthread_create(&cthread,NULL,multiplyer,NULL);
    pthread_join(athread,NULL);
    pthread_join(bthread,NULL);
    pthread_join(cthread,NULL);
     printf("\n"); 
   for(int l=0;l<3;l++)
   {
     for(int j=0;j<3;j++)
     {
       printf("%d", mat[l][j]);
       printf(" ");
     }
      printf("\n"); 
   }
    
   return 0;
}
void * multiplyer(void *arg)
{
   printf("\n executing thread #%d",i++);  
     for(int l=0;l<3;l++)
     {
         for(int j=0;j<3;j++)
            {
                mat[k][l]+=mat1[k][j]*mat2[j][l];
             }
      }
      k=k+1;            
    pthread_exit(NULL);
}
