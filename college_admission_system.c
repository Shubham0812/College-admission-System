
/* program for college admission system
 developed by shubham0812
 3rd Sem NMIT 2015 */


// necessary headers
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// buffer for storing the temporary data
char information[1000];
// char info1[100];


// file pointers
FILE *student_detail;
FILE *admin_id;
FILE *student_id;

// structure for storing data of the enrolling student
struct admi {
    int uniq_id;
    char Name[50];
    char dob[50];
    char Gender[50];
    char Religion[50];
    char Nationality[50];
    char Address[100];
    char City[50];
    char State[50];
    char Father_Name[50];
    char Father_Occupation[50];
    char Mother_Name[50];
    char Mother_Occupation[50];
    char father_income[50];
    char mother_income[50];
    char Name_b[50];
    char Name_school[50];
    char school_s[50];
    char maxmarks[50];
    char marksob[50];
    char perc[50];
    char yop[50];
    char Name_b1[50];
    char Name_school1[50];
    char school_s1[50];
    char maxmarks1[50];
    char marksob1[50];
    char perc1[50];
    char yop1[50];
    char mig[50];
    char tc[50];
}form;

// structure for storing the administrator id
struct adminitrator {
    float id;
}host;


// function for generating the admission form which will take the data of the student while enrolling.
void admission_form()
{
    // this id will be used to check all the existing student ids already enrolled so that student id is unique
    int check_id;
    student_detail = fopen("student_details.txt","a+");
    student_id = fopen("student_id.txt","a+");
    printf(" \t \t STUDENT ADMISSION FORM \n");
    printf("\n\t\t\t\t\tuse underscore\"_\" for space\n");
    printf("\n1.Personal Details \n \n \n");
    printf("Enter Your Unique Id\n");
    scanf("%d",&form.uniq_id);
    while(!feof(student_id)) {
        fscanf(student_id,"%d",&check_id);
        if(form.uniq_id==check_id) {
            printf("\nSorry this ID has been taken please select a different ID\n");
            return;
        }
    }
    printf("Enter Your Name \n \n");
    getchar();
    gets(form.Name);
    printf("Enter the DOB in DD/MM/YY format \n \n");
    gets(form.dob);
    printf("Enter Your Gender : \n \n");
    scanf("%s",form.Gender);
    printf("Enter Your Religion \n \n");
    scanf("%s",form.Religion);
    printf("Enter Your Nationality \n \n");
    scanf("%s",form.Nationality);
    printf("Enter Your Permanent Address \n \n");
    getchar();
    gets(form.Address);
    printf("Enter Your City:\n \n");
    gets(form.City);
    printf("Enter Your Father's Name: \n \n");
    gets(form.Father_Name);
    printf("Enter Your Father's Occupation \n \n");
    gets(form.Father_Occupation);
    printf("Enter Your Mother's Name:  \n \n");
    gets(form.Mother_Name);
    printf("Enter Your Mother's Occupation \n \n");
    gets(form.Mother_Occupation);
    printf("Enter Your Father's Income: \n \n");
    scanf("%s",form.father_income);
    printf("Enter Your Mother's Income: \n \n");
    scanf("%s",form.mother_income);
    printf("\n2.Academic Details \n \n \n");
    printf(" \t Class 10th  \n\n");
    printf("%s\n%s\n%s\n","Name of Board","Name of School","State");
    printf("\n\n");
    getchar();
    gets(form.Name_b);
    gets(form.Name_school);
    gets(form.school_s);
    printf("\n\n%s\n%s\n%s\n%s\n","Max Marks","Marks Obtained","Percentage","year of passing");
    printf("\n\n");
    gets(form.maxmarks);
    gets(form.marksob);
    gets(form.perc);
    gets(form.yop);
    printf(" \t Class 12th  \n\n");
    printf("%s\n%s\n%s\n","Name of Board","Name of School","State");
    printf("\n\n");
    gets(form.Name_b1);
    gets(form.Name_school1);
    gets(form.school_s1);
    printf("\n\n%s\n%s\n%s\n%s \n","Max Marks","Marks Obtained","Percentage","year of passing");
    printf("\n\n");
    gets(form.maxmarks1);
    gets(form.marksob1);
    gets(form.perc1);
    gets(form.yop1);
    printf("Enter If you Have a Migration Certificate or not? \n");
    gets(form.mig);
    printf("Enter If you Have a Transfer Certificate or not \n");
    gets(form.tc);
    fprintf(student_id,"\n%d",form.uniq_id);
    fclose(student_id);
    fprintf(student_detail,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",form.Name,form.dob,form.Gender,form.Religion,form.Nationality,form.Address,form.City,form.Father_Name,form.Father_Occupation,form.Mother_Name,form.Mother_Occupation,form.father_income,form.mother_income,form.Name_b,form.Name_school,form.school_s,form.maxmarks,form.marksob,form.perc,form.yop,form.Name_b1,form.Name_school1,form.school_s1,form.maxmarks1,form.marksob1,form.perc1,form.yop1,form.mig,form.tc);
    fclose(student_detail);
    printf("\n\nThankyou For Submitting the Admission form!\n\n");
}


// this function displays the academic details of the student based on branch
void show_academic_details() {

    //local variables for the function
    int adm,choice;
    int Target;
    int Found=0;

    // opening the student_id file and checking if the file contains any data
    if ((student_id=fopen("student_id.txt","r+"))==NULL){
        printf(" There is no student data present.\n\n");
    } else {
        printf("\nEnter The ID Of Student : ");
        scanf("%d",&Target);

        // scanning the student_id file for the id entered
        while(!feof(student_id)&& Found==0) {
            fscanf(student_id,"%d",&form.uniq_id);
            if(Target==form.uniq_id) {
                Found=1;
            }
        }
        
        // if the student id exists then the user is displayed the branches in college.
        if(Found) {
            printf("\n\nAcademic Details\n\n\n");
            printf("Please Select Your Branch\n\n");
            printf("1.Computer Science And Engineering\n");
            printf("2.Information Science\n");
            printf("3.Mechanical Engineering\n");
            printf("4.Civil Engineering\n");
            printf("5.Aeronautical Engineering\n");
            printf("6.Electrical And Electronics Engineering\n");
            printf("7.Electrical And Communication Engineering\n");
            printf("\nPlease Enter your Choice \n");
            scanf("%d",&choice);
            switch(choice) {
            case 1:
            case 2:
            case 3:
            case 4: printf("\t\tDetails for the First Year\n\n\n");
                    printf("\t\t\tPHY CYCLE\n\n");
                    printf("\tS.No.\tSubject Name\t\t\tSubject Credits\n");
                    printf("\t1\tBasic Electrical Engineering\t\t4\n");
                    printf("\t2\tElements Of Mechanical Engineering\t4\n");
                    printf("\t3\tEngineering Mechanics\t\t\t4\n");
                    printf("\t4\tEngineering Mathematics 1\t\t4\n");
                    printf("\t5\tEngineering Physics\t\t\t4\n");
                    printf("\t6\tPhysics Lab\t\t\t\t1.5\n");
                    printf("\t7\tWorkshop\t\t\t\t1.5\n");
                    printf("\t8\tConsitution of India\t\t\tNIL\n");
                    printf("\n\n\t\tTotal Credits = 23");
                    break;
            case 5:
            case 6:
            case 7: printf("\t\tDetails for the First Year\n\n\n");
                    printf("\n\n\t\t\tCHEM CYCLE\n\n");
                    printf("\tS.No.\tSubject Name\t\t\tSubject Credits\n");
                    printf("\t1\tBasic Electronics Engineering\t\t4\n");
                    printf("\t2\tEngineering Mathematics 2\t\t4\n");
                    printf("\t3\tConcepts of C programming\t\t4\n");
                    printf("\t4\tEngineering Chemistry\t\t\t4\n");
                    printf("\t5\tComputer Aided Drawin8g\t\t\t4\n");
                    printf("\t6\tChemistry Lab\t\t\t\t1.5\n");
                    printf("\t6\tChemistry Lab\t\t\t\t1.5\n");
                    printf("\t7\tConcepts of C programming Lab\t\t1.5\n");
                    printf("\t8\tEnglish Core\t\t\t\t2\n");
                    printf("\t9\tEnvironmental Studies\t\t\tNIL\n");
                    printf("\n\n\t\tTotal Credits = 25");
            default :break;
                        }
            }
        // student id not found
        if(!Found) {
            printf(" ! There is no student entry with the entered student ID\n");
        }

        // closing the student_id file
        fclose(student_id);
        return;
        }
    }


//fees details of the student to be seleceted by the student//
void fees_details() {
    int feec,bec;
    printf("\n\nFEES DETAILS:\n\n");
    printf("Select the Course \n\n");
    printf("\n1.B.E\n\n2.Exit\n\n");
    scanf("%d",&feec);
    switch(feec) {
    case 1:
            printf("\t\t\t\nB.E.\n");
            printf("\n\nEnter The Admission Type:-\n");
            printf("\n1.COMEDK-UGET\n\n2.CET\n\n3.Others\n\n");
            scanf("%d",&bec);
            if(bec==1) {
                printf("\n\nCOMEDK-UGET\n\n");
                printf("\n\n\t\t\t\t\tFees per Year\n");
                printf("\nTution Fees= 1,00,000/-\n");
                printf("\nCollege University Fees = 35,000/-");
                printf("\nUniversity Eligibility Fees = 1,500/- \n");
                printf("\nHostel Fees\n\n");
                printf("\nCaution Deposit = 15,000/-");
                printf("\nRoom Rent/Electricity Charges = 48,000/-");
                printf("\nTotal Hostel Fees\n\n");
                printf("\nHostel Mess Charges = 1800/- per month\n");
                } else if(bec==2) {
                printf("\n\n\t\t\tCET\n\n");
                printf("\n\n\t\t\t\t\tFees per Year\n");
                printf("\nTution Fees= 37,000/-\n");
                printf("\nCollege University Fees = 30,000/-");
                printf("\nHostel Fees\n\n");
                printf("\nCaution Deposit = 15,000/-");
                printf("\nRoom Rent/Electricity Charges = 48,000/-");
                printf("\nTotal Hostel Fees\n\n");
                printf("\nHostel Mess Charges = 1800/- per month\n");
                } else {
                printf("\n\n\t\t\tOthers\n\n");
                printf("\n\n\t\t\t\t\tFees per Year\n");
                printf("\nTution Fees= 1,37,000/-\n");
                printf("\nCollege University Fees = 30,000/-");
                printf("\nUniversity Eligibility Fees = 1,500/- \n");
                printf("\nHostel Fees\n\n");
                printf("\nCaution Deposit = 15,000/-");
                printf("\nRoom Rent/Electricity Charges = 48,000/-");
                printf("\nTotal Hostel Fees\n\n");
                printf("\nHostel Mess Charges = 1800/- per month\n");
                }


    default:    break;
    }
}

// for displaying all student details
void display()
{

    //local variables
    int i;
    float adminid;
    int Found=0;

    // opening the admin file
    if((admin_id=fopen("admin_id.txt","r"))==NULL) {
        printf(" ! The File is Empty...\n\n");
    } else {
        printf("\nEnter The Administrator ID: ");
        scanf("%f",&adminid);
        while(!feof(admin_id)&& Found==0) {
            fscanf(admin_id,"%f",&host.id);
            if(adminid==host.id) {
                Found=1;
            }
        }
        if(Found) {
            student_detail = fopen("student_details.txt","a+");
            printf("\nThe Details of Admission Form is in this Order:\n\n\nName\nDOB\nGender\nReligion\nNationality\nAddress\nCity\nFather's Name\nFather's Occupation\nMother's Name\nMother's Occupation\nFather's Income\nMother's Income\nClass 10th\nName of Board\nName of State\nState\nMax Marks\nMarks Obtained\nPercentage\nYear of passing\nClass 12th\nName of Board\nName of State\nState\nMax Marks\nMarks Obtained\nPercentage\nYear of passing\nMigration Card\nTransfer Certificate\n",information);
            do {
                fgets(information,600,student_detail);
                printf("%s\n\n",information);
                }
            while(!feof(student_detail)); {
                fclose(student_detail);
            }
        }
        else if(!Found) {
            printf("Please Enter the Correct Administrator ID\n\n");
            fclose(admin_id);
        }
    }
}

// for searching student data based on student id
void search_student()
{
    int i;
    char Target[25];
    int Found=0;
    student_id=fopen("student_id.txt","r");
    if((student_detail=fopen("student_details.txt","r"))==NULL) {
        printf(" ! The File is Empty...\n\n");
    } else {
        printf("\nEnter The Name Of Student : ");
        scanf("%s",Target);
        while(!feof(student_detail)&& Found==0) {
            fscanf(student_detail,"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",form.Name,form.dob,form.Gender,form.Religion,form.Nationality,form.Address,form.City,form.Father_Name,form.Father_Occupation,form.Mother_Name,form.Mother_Occupation,form.father_income,form.mother_income,form.Name_b,form.Name_school,form.school_s,form.maxmarks,form.marksob,form.perc,form.yop,form.Name_b1,form.Name_school1,form.school_s1,form.maxmarks1,form.marksob1,form.perc1,form.yop1,form.mig,form.tc);
            scanf(student_id,"%d",&form.uniq_id);
            if(strcmp(Target,form.Name)==0) {
                Found=1;
            }
        }
        if(Found) {
            printf("\nUnique ID:%d\n \n  The Name of Student:%s\n \n The dob of student:%s\n \n Gender of the student:%s\n \n religion of the student:%s\n \n nationality of the student:%s\n \n Address :%s\n \n City :%s\n \n Father's Name:%s\n \n Father's Occupation:%s\n \n Mother's Name:%s\n \n Mother's Occupation:%s\n \n Father's Income:%s\n \n Mother's Income:%s\n \n Name of Board of Class 10th:%s\n \n Name of School of Class 10th:%s\n \n Name of School State of Class 10th:%s\n \n Max Marks:%s\n \n Marks Obtained:%s\n \nPercentage:%s\n \nYear of Passing:%s\n \nName of Board of Class 12th:%s\n \n Name of School of Class 12th:%s\n \n Name of School State of Class 12th:%s\n \n Max Marks:%s\n \n Marks Obtained:%s\n \nPercentage:%s\n \nYear of Passing:%s\n \nMigration Card:%s\n \nTransfer Certificate:%s\n\n",form.uniq_id,form.Name,form.dob,form.Gender,form.Religion,form.Nationality,form.Address,form.City,form.Father_Name,form.Father_Occupation,form.Mother_Name,form.Mother_Occupation,form.father_income,form.mother_income,form.Name_b,form.Name_school,form.school_s,form.maxmarks,form.marksob,form.perc,form.yop,form.Name_b1,form.Name_school1,form.school_s1,form.maxmarks1,form.marksob1,form.perc1,form.yop1,form.mig,form.tc);
        }
        else if(!Found) {
            printf("!\n");
        }

        //closing the student_details file
        fclose(student_detail);
    }
}

// main function
void main()
{
    int i,j,n,choice,feec,bec,pgc,adm;
    long int m;
    for(;;) {
        printf("\n\n+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+--\n");
        printf("+ \t\t     MENU\t\t\t+\n+\t\t\t\t\t\t");
        printf("+\n+\t\t\t\t\t\t+\n+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        printf("+\t\t\t\t\t\t+\n+ 1.Admission/Registration\t\t\t+\n+\t\t\t\t\t\t+\n+ 2.Academic Details\t\t\t\t+\n+\t\t\t\t\t\t+\n+ 3.Fees Details\t\t\t\t+\n+\t\t\t\t\t\t+\n+ 4.Search Your Registration By Name\t\t+\n+\t\t\t\t\t\t+\n+ 5.Show all Registrations\t\t\t+\n+\t\t\t\t\t\t+\n+ 6.Quit\t\t\t\t\t+\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-");
        printf("\n\nEnter Your Choice? \n\n");
        scanf("%d",&choice);
        switch(choice) {
        case 1: system("cls");
                admission_form();
                break;
        case 2: show_academic_details();
                break;
        case 3: fees_details();
                break;
        case 4: search_student();
                break;
        case 5: display();
                break;
        case 6: return;

        default:break;
        }
    }
  }
