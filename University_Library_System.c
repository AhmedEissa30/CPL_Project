#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choice;
void menu();
void student_Register();
void Students_Number();
void bookAdding();
void Book_Number();
void Book_Viewer();


struct student{
    char name [20][50];
    char email [20][50];
    int ID [20];
    char password [20][50];
    int studentNum;
 };

 struct books{
     char bookname [20][50];
     int bookId [20];
     int bookNum;
 };

struct books book;
struct student information;

int main(){

    book.bookNum = 0;
    information.studentNum = 0;

    memset(book.bookId,0,sizeof(book.bookId));
    memset(information.ID,0,sizeof(information.ID));



    while(1){
    printf("\n                   Welcome to the University Library System!\n\n");
    menu();
    }

    return 0;
}



void menu(){
    int rating;
    printf("     Choose the operation you want:\n");
    printf("\n    [1]Registration       [2]Number of students\n    [3]Adding books       [4]View all books\n    [5]Search for books   [6]Clear screen\n    [7]Exit\n");
    scanf("%d",&choice);


    switch(choice)
    {
    case 1:
        printf("Registration...\n");
        student_Register();
        break;
    case 2:
        printf("Number of students...\n");
        Students_Number();
        break;
    case 3:
        printf("Adding books...\n");
        bookAdding();
        break;
    case 4:
        printf("View all books...\n");
        Book_Viewer();
        break;
    case 5:
        printf("Search for books..\n");
        Book_Search();
        break;
    case 6:
        //built-in function to clear screen.
        system("cls");
        break;
    case 7:
        printf("We need your feedback to improve our library. Rate out of 5 :)  ");
        scanf("%d",&rating);
        printf("Your rating : %d/5 . Thank you for your feedback\n\n",rating);
        exit(1);

    default:
        printf("Unavailable. Please choose a valid operation\n");
        break;
    }
}


void student_Register(){

    printf ("Registration form: \n ");

    printf ("\nEnter your ID (Integers): ");
    scanf ("%d", & information.ID[information.studentNum]);
    printf ("\nEnter your name : ");
    scanf ("%s", & information.name[information.studentNum]);
    printf ("\nEnter your email : ");
    scanf ("%s" , & information.email[information.studentNum]);
    printf ("\nEnter your password : ");
    scanf ("%s" , & information.password[information.studentNum]);
    information.studentNum++;


  }


  void Students_Number(){


  //  for(int i = 0 ; i < 20 ; i++ ){
   //     if( information.password[i] != NULL ){
   //         StudentsNumber++;
   //     }
   // }

    printf("\nNumber of students registered in the system is %d students.",information.studentNum);
}

void bookAdding(){

   printf ("IMPROT YOUR BOOK\n");
   printf ("Enter book's name : ");
   scanf ("%s" , &book.bookname[book.bookNum]);
   printf("\nEnter book's ID (Integer): ");
   scanf ("%d" , &book.bookId[book.bookNum]);
   book.bookNum++;

 }


void Book_Viewer(){

for (int k = 0; k < book.bookNum; ++k){
        printf("%s", book.bookname[k]);
    printf("\n");
    }

}

void Book_Search(){
    int found = 0;
    char bookName[50];
    printf("\nEnter the name of the book you want : ");
    scanf("%s" ,&bookName);

    for(int i = 0 ; i < book.bookNum ; i++){
      int result = strcmp(bookName,book.bookname[i]);
      if( result == 0){
        found = 1;
        break;
      }
    }
    if ( found == 0 ){
        printf("\nNOT FOUND...");
    }else{
        printf("\nThis book exists in the library...\n");
    }

}
