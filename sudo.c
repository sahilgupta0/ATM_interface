#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define clear() printf("\033[H\033[J");
int pinCheck(int pin);


long int userName[100],aadharNo;
int noOfUser = 0, total,noOfDeposite,noOfWithdraw, checkbook=0, aadhar=0;
int pin[100];
char name[50];
int main(){
    int start(){
        while(1){
            printf("\t\t\t==========  WELCOME TO MOBILE BANKING SYSTEM =========\n\n");

            // mainPage
            printf("Choose to proceed :\n\t1. Log In\n\t2. New Register\n\t3. Exit\n\n\t");
            // printf("%ld %d", userName[0], pin[0]);
            int choice;
            printf("choice : ");
            scanf("%d", &choice);
            clear();
            if (choice == 1){
                long int temp_userName;
                int temp_pin,validUser=0, try=3,i=0;
                while(try>0){
                    // printf("login page");
                    printf("\n\n\t\t\t==========  LOGIN  =========\n\n\n");

                
                    int positionOfUser;
                    printf("\nEnter your User Name :\t");
                    scanf("%ld", &temp_userName);

                    printf("\nEnter your PIN : \t");
                    scanf("%d", &temp_pin);

                    for( i; i <=noOfUser;i++){
                        if(userName[i]==temp_userName){
                            if(pin[i]==temp_pin){
                                validUser=1;
                                positionOfUser = i;
                            }
                        }
                    }
                    try=try-1;
                    if(validUser==1){
                        clear();
                        printf("\nWel-Come %s \n\n", name);
                        while (1){
                            int choice, oldPIN, newPIN,tempBalance;
                            printf("\n\n\t1.Balance Check\n\t2.For Deposite\n\t3.For Withdrawl\n\t4.Change PIN \n\t5.Mobile Recharge\n\t6.CheckBook Request\n\t7.Aadhar Registration\n\t8.Exit\n\n\t");
                            scanf("%d", &choice);
                            clear();
                            if(choice==1){
                                printf("Total Balance : %d \n", total);

                            }
                            else if(choice==2){
                                printf("Enter the amount : ");
                                scanf("%d", &tempBalance);
                                total+=tempBalance;                        //we have to add dalay function (the transation is been processed)
                                printf("your Transcation is completed\n");
                                noOfDeposite +=1;

                            }
                            else if(choice==3){
                                printf("Enter the amount : ");
                                scanf("%d",&tempBalance);
                                if(tempBalance>total){
                                    printf("!!! You don't have sufficent balance !!!\n");
                                }
                                else{
                                total-=tempBalance; 
                                noOfWithdraw +=1;                              //we have to add dalay function (the transation is been processed)
                                printf("Your transaction is completed\n");
                                }
                            }
                            else if(choice == 4){
                                int reCheckPIN;
                                printf("\nEnter You Old PIN :\t");
                                scanf("%d", &oldPIN);
                                if(pin[positionOfUser]==oldPIN){
                                    
                                    int reEnterPIN(){
                                        printf("\nEnter You New PIN :\t");
                                        scanf("%d", &newPIN);

                                        reCheckPIN=pinCheck(newPIN);
                                        if(reCheckPIN!=4) {
                                            clear();
                                            printf("\n!!! Your PIN should be only 4 digits !!!\n\n");
                                        
                                            reEnterPIN();

                                        }
                                    }
                                    reEnterPIN();
                                    pin[positionOfUser]=newPIN;
                                    
                                    clear();
                                    printf("\nPIN changed succesfully\n");
                                    

                                }
                                else{
                                    printf("\nPIN don't match");
                                }
                            }
                            else if(choice==5){
                                int recharge, reCheckNum, amount;
                                int reTry(){
                                    printf("\nEnter your Phone Number : \t");
                                    scanf("%d", &recharge);
                                    reCheckNum=pinCheck(recharge);
                                    if(reCheckNum!=10) {
                                        clear();
                                        printf("\n!!! Your Phone Number should contain 10 digits !!!\n\n");
                                    
                                        reTry();
                                    }
                                    
                                }
                                reTry();
                                printf("\nEnter Amount : \t");
                                scanf("%d", &amount);

                                clear();
                                printf("Your trasaction has being successful \n");
                                total -=amount;
                                printf("Total Balance : %d\n",total );
                            }

                            else if (choice == 6){
                                char ch;
                                int password;
                                if(checkbook==0){
                                    printf("Do you wanna request for a new checkbook (y/n);\t");
                                    scanf("%s", &ch);

                                    if(ch=='Y'|| ch=='y'){
                                        int recall(){
                                            printf("\nEnter your password : \t");
                                            scanf("%d", &password);
                                            if(password==temp_pin){
                                                clear();

                                                printf("\nYour request has been submitted sucessfully\n");
                                            }
                                            else {
                                                printf("!! your PIN doesn't matched !!\n");
                                                recall();
                                            }
                                        }
                                        recall();
                                    }
                                }
                                else{
                                    printf("\nYou Checkbook is in progess :)\n");
                                }
                                checkbook=1;
                                
                            }
                            else if (choice == 7){
                                int password, reCheck;
                                int recall(){
                                    if(aadhar ==0){


                                        int reTry(){
                                            printf("\nEnter your Phone Number : \t");
                                            scanf("%ld", &aadharNo);
                                            reCheck=pinCheck(aadharNo);
                                            if(pinCheck!=12) {
                                                clear();
                                                printf("\n!!! Your Phone Number should contain 12 digits !!!\n\n");
                                            
                                                reTry();
                                            }
                                            
                                        }
                                        reTry();
                                        // int AadharNumCheck(){
                                        //     printf("Enter your Aadhar Number : ");
                                        //     scanf("%ld", &aadharNo);
                                        //     reCheck=pinCheck(aadharNo);
                                        //     if(reCheck!=12) {
                                        //         // clear();
                                        //         printf("\n!!! Your Phone Number should contain 12 digits !!!\n\n");
                                            
                                        //         AadharNumCheck();

                                        //     }
                                        //     // if(reCheck==12){
                                        //     // }
                                        //     // else{
                                        //     //     clear();
                                        //     //     printf("\n!!! Your Aadhar Number should contain 12 digits !!!\n\n");
                                            
                                        //     //     AadharNumCheck();
                                            
                                        //     // }
                                        // }
                                        // AadharNumCheck();
                                        printf("\nEnter your password : \t");
                                        scanf("%d", &password);
                                        int loopForPin(){
                                            if(password==temp_pin){
                                                clear();
                                                aadhar=1;

                                                printf("\nYour request has been submitted sucessfully\n");
                                            }
                                            else {
                                                printf("!! your PIN doesn't matched !!\n");
                                                loopForPin();
                                            }
                                        }
                                        loopForPin();
                                        
                                    }
                                    else{
                                        clear();
                                        printf("Your Aadhar number is %ld", aadharNo);
                                        
                                    }
                                    
                                }
                                recall();
                            }
                            else if (choice == 8){
                                exit(0);
                            }
                            else{
                                printf("\n!!! Inavaild INPUT !!!\n");
                            }

                        }
                    }
                    else{
                        if(try>0){
                            clear();
                            printf("you have %d try left", try);
                        }
                        else{
                            clear();
                        }
                    }
                    
                
                }


            }
            else if(choice==2){
                

                int choice, check, reCheckPIN, reCheckNo;
                // printf("register page");
                printf("\t\t\t==========  NEW USER REGISTER =========\n\n\n");

                printf("\nEnter your name :\t");
                scanf("%s", name);

                int reEnterNum(){
                    printf("\nEnter your phone number :\t");
                    scanf("%ld", &userName[noOfUser]);

                    reCheckNo=pinCheck(userName[noOfUser]);
                    if(reCheckNo!=10) {
                        // clear();
                        printf("\n!!! Your Phone Number should contain 10 digits !!!\n\n");
                    
                        reEnterNum();

                    }
                }
                reEnterNum();
                int reEnterPIN(){

                    printf("\nEnter your PIN : \t");
                    scanf("%d", &pin[noOfUser]);

                    reCheckPIN=pinCheck(pin[noOfUser]);
                    if(reCheckPIN!=4) {
                        // clear();
                        printf("\n!!! Your PIN should be only 4 digits !!!\n\n");
                    
                        reEnterPIN();

                    }
                    
                }
                reEnterPIN();


                clear();

                printf("\nYou have being register succesfully\n\nYour User name is %ld",userName[noOfUser]);
                noOfUser++;
                int loop(){
                    int choice;
                    printf("\n\nChoose to proceed :\n\t1. Go Back\n\t0. Exit\n\n\t");
                    scanf("%d", &choice);
                    if(choice=1){
                    }
                    else if(choice==0){
                        exit(0);
                    }
                    else{
                        clear();
                        printf("\n!!Invalid Input!!\n");

                        loop();
                    }
                }
                loop();
                
                clear();

            }
            else if(choice==3){
                exit(0);
            }
            else{
                printf("!!!!!!!Invalid INPUT!!!!!!!!!!\n\n\n");
                // exit(0);
            }
        }
    }
    start();

    return 0;
}




int pinCheck(int pin){
    int count=0;
    for(int i = 0; pin>0;i++){
        pin=pin/10;
        count+=1;
    }
    return count;
}


