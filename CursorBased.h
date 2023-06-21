#ifndef CURSOR_BASED_H
#define CURSOR_BASED_H

#define MAX 10

typedef char String[20];
typedef int List;

typedef struct{
	int studID;
	String studName;
	String program;
	char sex;
} Student;

typedef struct{
	Student elem;
	int next;
}SType;

typedef struct{
	SType elems[MAX];
	int avail;
}VirtualHeap;

Student newStudent(int studID, String studName, char sex, String program);
VirtualHeap newVirtualHeap();
int allocSpace(VirtualHeap *VH);
void insertFront(VirtualHeap *VH, List *list, Student s);

//void displayList(VirtualHeap VH, List list);
void visualizeSpace(VirtualHeap VH);


#endif
