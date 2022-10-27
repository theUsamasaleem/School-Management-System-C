
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  


    struct emp{
        char name[40]; //name of employee
        int age; // age of employee
        float bs; // basic salary of employee
    }; 

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
 
  
int main(){
    FILE *fp, *ft; // file pointers
	char another, choice;
  
    struct emp e; 
  
    char empname[40];
  
    long int recsize; 

  
   
    recsize = sizeof(e);
  

    while(1){
    	 system("cls");
    	    	 printf("  \n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb PROJECT NAME : EMPLOY MANAGEMENT !         \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");

    	 printf("  \n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Presented By : USAMA SALEEM FA19-BSCS-0046 \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
                printf("  \n\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Presented By : SYED TULAIB FA19-BSCS-0043  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");

    
      
        printf("\n\n\n\n");
		printf("    \xdb\xdb 1. Add Record    \xdb\xdb\n"); //  add 
        printf("    \xdb\xdb 2. List Records  \xdb\xdb\n"); // showing existing 
        printf("    \xdb\xdb 3. Modify Records\xdb\xdb\n"); //  editing 
        printf("    \xdb\xdb 4. Delete Records\xdb\xdb\n"); // deleting record
        printf("    \xdb\xdb 5. Exit          \xdb\xdb\n"); // exit 
       
        printf("\n\n\n\xdb\xdb\xdb\xdb Your Choice:  ");
		    fflush(stdin); 
        scanf("\n%c", &choice);
		   printf("\xdb\xdb"); 
       
        switch(choice)
		{
            case '1': 
                another = 'y';
                Add:
                system("cls");
                while(another == 'y')
				{ 
                    flush();
                    printf("\nEnter name: ");
                    gets(e.name);
                    printf("\nEnter age: ");
                    scanf("%d", &e.age);
                    printf("\nEnter basic salary: ");
                    scanf("%f", &e.bs);
                    fp=fopen("EMP.txt","a+");
                    fprintf(fp,"\n%s\t%d\t%f",e.name,e.age,e.bs);
				    fclose(fp);
					option:
					printf("\nAdd another record(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                    
					if(another=='y')
                    {
                    	goto Add;
					}
					else if(another=='n')
					{
						break;
					}
					else
					{
						printf("\nWrong! INPUT\n\n");
						system("pause");
						goto option;
					}
                }
                break;
            case '2':
           
                list:
                	system("cls");
				fp=fopen("EMP.txt","r");
                if(fp==NULL)
                {
                	printf("Sorry file does not exist!\n");
				}
                else
                {
                	printf("%s\t%s\t%s","Employ Name","Age of Employees","Basic Salary of Employ");
						printf("\n%s","--------------------------------------------------------------------\n");
					
					while(!feof(fp))
                	{
                		
                		fscanf(fp,"\n%s\t%d\t%f",e.name,&e.age,&e.bs);
						printf("\n%-20s\t%-10d\t\t%0.2f",e.name,e.age,e.bs);
					}
				}
                option_1:
					printf("\n\nWant to Exit(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                    
					if(another=='y')
                    {
                    	break;
					}
					else if(another=='n')
					{
						goto list;
					}
					else
					{
						printf("\nWrong! INPUT\n\n");
						system("pause");
						goto option_1;
					}
                break;
  
            case '3':  
                another = 'y';
                while(another == 'y'){
                    printf("Enter the employee name to modify: ");
                    scanf("%s", empname);
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1){ 
                        if(strcmp(e.name,empname) == 1){
                            printf("\nEnter new name: ");
                            gets(e.name);
                             printf("\nEnter age  and  bs: ");
                            scanf("%d\n",&e.age);
                               printf("\nEnter basic salary: ");
                                 scanf("%f\n",&e.bs);
                            fseek(fp,-recsize,SEEK_CUR); 
                            fwrite(&e,recsize,1,fp); 
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '4':
                another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name of employee to delete: ");
                    fgets(empname,40, stdin);
                    ft = fopen("EMP.txt","w");  
                    rewind(fp); 
                    while(fread(&e,recsize,1,fp) == 1){ 
                        if(strcmp(e.name,empname) == 1){ 
                            fwrite(&e,recsize,1,ft); 
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("EMP.txt");
                    rename("Temp.txt","EMP.txt"); 
                    fp = fopen("EMP.txt", "r");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '5':
                fclose(fp); 
                exit(0); 
           default:
             	printf("\n\n\n\n\n\n\n\n\              \xdb\xdb\xdb  wrong input!   \xdb\xdb\xdb");
            		printf("\n            \xdb\xdb\xdb  press any key to countinue!  \xdb\xdb\xdb");
             	scanf("\n%c", &choice);
             	getchar();
          	
     }
        
    }
    return 0;
}
