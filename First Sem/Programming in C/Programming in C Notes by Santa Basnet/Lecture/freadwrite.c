/** fread and fwrite example */
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

/** Student type. **/
typedef struct {
	char name[50];
	char address[100];
	int age;
	char bloodGroup[4];
}Student;

/** Initialization 5 students in global scope.*/
Student students[SIZE] = {{
		"Ram Karki", "Lalitpur - 24, Lalitpur, Nepal", 20, "AB+"
	}, {
		"Shyam Kumar Kaami", "Kathmandu - 09, Kathmandu, Nepal", 18, "O+"
	}, {
		"Kishan Kushwaha", "Bhardaha - 02, Saptari, Nepal", 24, "B-"
	}, {
		"Kumar Shimkhada", "Tikapur - 10, Kailali, Nepal", 18, "O-"
	}, {
		"Sundar Bahadur Kathayat", "Lalitpur - 20, Lalitpur, Nepal", 17, "AB+"
	}}; 
	
/** Write student data in a new file and close it. **/
void writeStudents(const char *fileName){
	FILE *file = fopen(fileName, "w");
	if(file == NULL) return;
	for(int index = 0; index < SIZE; index++){
		fwrite(&students[index], sizeof(Student), 1, file);
	}
	fclose(file);
}

/** Read students data from the file. **/
Student *readStudents(const char *fileName){
	Student *students = (Student *) malloc(SIZE * sizeof(Student));	
	FILE *file = fopen(fileName, "w");
	if(file != NULL) {
		for(int index = 0; index < SIZE; index++){
			fread(&students[index], sizeof(Student), 1, file);
		}
		fclose(file);
	}	
	return students;
}

/** Display all the students from the file **/
void display(Student *students){
	printf("\n----------------------------------------");
	for(int index = 0; index < SIZE; index++){
		printf("\nName: %s", (students+index)->name);
		printf("\nAddress: %s", (students+index)->address);
		printf("\nAge: %2d", (students+index)->age);
		printf("\nBloodGroup: %2s", (students+index)->bloodGroup);
		printf("\n----------------------------------------");
	}
	printf("\n");
}

/** Main Function **/
int main(){
	const char *file = "students.dat";
	/** Perform write operations first. **/
	writeStudents(file);
	
	/** Perform read operation from the file. **/
	Student *students = readStudents(file);
	display(students);
	
	/** Seek to the beginning of the file **/
    //fseek(fptr, 0, SEEK_SET);	
	free(students);
	return 0;
}
