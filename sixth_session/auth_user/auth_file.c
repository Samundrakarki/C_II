#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

//returns true if password and username matches
int check_user_name(char user_name[], long int arr[],FILE* fp_list, FILE *fp_partial_list);


int main(){

    char file_name[MAX_SIZE], line[200], user[200];
    FILE *fp, *fp1;
    long int *arr;
    int counter = 0;
    int status = 1;

    fgets(file_name, MAX_SIZE, stdin);  
    file_name[strlen(file_name) - 1] = '\0';  

    fp = fopen(file_name, "r");
    if(fp == NULL){
        exit(1);
    }

    //store the username only
    fp1 = fopen("only_username.txt", "w+");

    while(fgets(line, sizeof(line), fp)){
        if(status){ 
            counter++;
            status = 0;
        }
        else{
            status = 1;
        }
    }

    //store the pointer in the array to locate the password
    arr = (long int*) malloc(sizeof(long int) * counter);

    //again putting the cursor in the beginning of the file
    fseek(fp, 0, SEEK_SET);
    int counter1 = 0;

    //storing the username in the file and pointer setting the pointer. Here, I have read the whole file. Only user name is read and end position is stored in an array to locate.
    while(fgets(line, sizeof(line), fp)){
        if(status){  
            fputs(line, fp1);
            long int user_pos = ftell(fp);
            arr[counter1] = user_pos;
            counter1++;
            status = 0;
        }else{
            status = 1;
        }
    }

    // if you want to see the array of the positon
    // for(int i = 0; i< counter; i++){
    //     printf("%li ", arr[i]);
    // }
    // printf("\n");
    
    //closing the file which was stored in write mode
    fclose(fp1);


    //again opening the file in read mode to allocate the user
    FILE* fp3 = fopen("only_username.txt", "r");
    if(fp3 == NULL){
        exit(1);
    }

    //setting the cursor in the beginng position of the orginal file
  
    //Condiito to check
    while(1){
        fseek(fp, 0, SEEK_SET);
        fgets(user, 200, stdin);
        user[strlen(user)-1] = '\0';
        if(!strcmp(user, "exit")){
            printf("Exiting ...\n");
            break;
        }   
        if(check_user_name(user, arr,fp, fp3)){

            printf("Access to %s is granted\n", user);
        }else{
            printf("Access to %s is denied\n", user);
        }
    }
    
    free(arr);
    fclose(fp);
    fclose(fp3);
}
int check_user_name(char user_name[],long int *arr,FILE* fp_list, FILE *fp_partial_list){
    fseek(fp_list, 0, SEEK_SET);
    fseek(fp_partial_list, 0, SEEK_SET);
    char temp_var[200], temp_var2[200] ,password[200] ,ch;
    int counter = 0, i;
    long int pos = 0;
    
    fgets(password, 200, stdin);
    password[strlen(password)-1] = '\0';

    //if here pssword is read and fseek() with the help of array of position(ftell()) sets the cursor in the password and reads only the password  
    // also stores the password of the file in the temp_var2 and check if the password provided by the user and the password present in the file is same. IF true returns true else false.
    while(fgets(temp_var, 200, fp_partial_list)) {

        temp_var[strlen(temp_var)-1] = '\0';
        if(!strcmp(temp_var,user_name)){
            pos = arr[counter];
            fseek(fp_list, pos, SEEK_SET);
            i = 0;
            while((ch = fgetc(fp_list)) != '\n'){
                temp_var2[i] = ch;
                i++;
            }
            temp_var2[i+1] = '\0';
            if(!strcmp(password, temp_var2)){
                return 1;
                break;
            }else{
                return 0;
            }
        }
        counter++;
    }
    return 0;
}
