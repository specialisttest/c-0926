#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HalfByte {
	unsigned int lo : 4; // size in bits
	unsigned int hi : 4;
};

struct Byte {
	unsigned int b0 : 1; // size in bits
	unsigned int b1 : 1;
	unsigned int b2 : 1;
	unsigned int b3 : 1;
	unsigned int b4 : 1;
	unsigned int b5 : 1;
	unsigned int b6 : 1;
	unsigned int b7 : 1;
};


struct TwoChar {
	_Alignas(4) char c1;
	_Alignas(4) char c2;
	
};
struct TwoInt {
	_Alignas(4) int i1;
	_Alignas(4) int i2;
	_Alignas(2) short c1;
	
};

union Int2Byte {
	unsigned int i;
	unsigned char b;
	struct Byte bits;
	struct HalfByte halfByte;
};

/*struct CourseNode {
	char* title;
	int	  length;
	struct CourseNode* next;
};

typedef struct CourseNode Course;*/

typedef struct CourseNode {
	char* title;
	int	  length;
	struct CourseNode* next;
} Course;


/*struct MoneyStruct {
	int summa;
	char* currency;
};

typedef struct MoneyStruct Money;*/
typedef struct  {
	int summa;
	char* currency;
} Money;

void printCourse(const Course* c) {
	//printf("%-20s %d\n", (*c).title, (*c).length);
	printf("%-20s %d\n", c->title, c->length);
}


void printCourseList(const Course* pc)
{
	puts(" ****  All Courses (HEAP) **** ");
	while (pc) {
		printCourse(pc);
		pc = pc->next;
	}
}

Course* addCourse( Course* last, char* title, int length) {
	Course* newCourse = malloc(sizeof(Course));
	int len = strlen(title);
	newCourse->title = malloc(  (len+1)*sizeof(char));
	strcpy(newCourse->title, title);
	newCourse->length = length;
	newCourse->next = NULL;
	if (last != NULL)
		last->next = newCourse;
		
	return newCourse;
	
}

void freeCourseList(Course* pc) {
	while (pc) {
		free(pc->title);
		Course* next = pc->next;
		free(pc);
		pc = next;
	}
	
}

int main(int argc, char *argv[]) {
	struct {
		int summa;
		char* currency;
	} m1 = { 100, "RUB"}, m2;
	
	m2.summa = 100;
	m2.currency = "BTC";
	
	//struct MoneyStruct m3 = {100, "USD"};
	Money m3  = {100, "USD"};
	
	printf("%d%s\n", m1.summa, m1.currency);
	printf("%d%s\n", m2.summa, m2.currency);
	printf("%d%s\n", m3.summa, m3.currency);
	
	struct CourseNode c1 = { "c++ lang", 40};
	Course c2 = {"STL and BOOST", 24}, c3;
	c3.title = "Java 1";
	c3.length = 40;
	
	printf("%-20s %d\n", c1.title, c1.length);
	printf("%-20s %d\n", c2.title, c2.length);
	printf("%-20s %d\n", c3.title, c3.length);
	
	Course c4 = { "Spring", 40 };
	Course c5 = c4;
	c4.length++;
	printCourse(&c4);
	printCourse(&c5);
	
	c1.next = &c2;
	c2.next = &c3;
	c3.next = &c4;
	c4.next = &c5;
	//c5.next = NULL;
	
	puts(" ****  All Courses **** ");
	Course* c = &c1;
	while (c) {
		printCourse(c);
		c = c->next;
	}
	{
		Course* head = addCourse(NULL, "C lang", 48);
		Course* last = addCourse(head, "C++ lang", 40);
		last = addCourse(last, "Java lang", 40);
		last = addCourse(last, "Spring lang", 40);		
		
		printCourseList(head);

		freeCourseList(head);		
	}
	
	printf("sizeof(char*)  : %4d\n", sizeof(char*));
	printf("sizeof(int)    : %4d\n", sizeof(int));
	printf("sizeof(Course*): %4d\n", sizeof(struct CourseNode*));
	
	printf("sizeof(Course) : %4d\n", sizeof(Course));

	printf("sizeof(TwoChar) : %4d\n", sizeof(struct TwoChar));
	printf("sizeof(TwoInt) : %4d\n", sizeof(struct TwoInt));

	printf("sizeof(HalfByte) : %4d\n", sizeof(struct HalfByte));

	union Int2Byte i2b;
	
	printf("sizeof(Int2Byte) : %4d\n", sizeof(union Int2Byte));
	i2b.i = 1;
	printf("i2b.i = %d\n", i2b.i);
	i2b.b = 128;
	printf("i2b.i = %d\n", i2b.i);
	
	i2b.bits.b1 = 1;

	printf("lo    = %d\n", i2b.halfByte.lo);
	printf("hi    = %d\n", i2b.halfByte.hi);
	
	return 0;
}
