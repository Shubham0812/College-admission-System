# College-admission-system

A project written in C program which can help colleges to better facilitate and manage the admission process of students.
## Motivation
This is the first project was given to me as a part of college curriculum, while developing this project I got to know about resolving issues. This was a good starting project, I explored new concepts in C.

## Screenshots

![alt text](https://github.com/Shubham0812/College-admission-System/blob/master/assets/screenshots/home.JPG)

## Technology used
 C programming and code blocks IDE

## Features
- The project helps the student admission and registration process, and maintains a record of student's personal, academic and fee related data.
- Generates student information and generates the fees invoice
- Generates student’s academic Report.
- Generates student’s personal Report.
- Clean design and formatting.

## Code Example
```
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
```

## How to use ?
1. Download or clone the repository.
2. Run the file college_admission_system.c with a suitable C IDE.

## Credits
**©** Shubham Kumar Singh