#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CursorBased.h"


Student newStudent(int studID, String studName, char sex, String program){
	Student s;
	
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex =sex;
	strcpy(s.program, program);
	
	return s;
}

VirtualHeap newVirtualHeap(){
	VirtualHeap VH;
	
	int ctr;
	
	for(ctr = 0; ctr<MAX; ctr++){
		VH.elems[ctr].elem = newStudent(0," ",' '," ");
		VH.elems[ctr].next = ctr-1;
	}
	VH.avail = MAX-1;
	
	return VH;
}
int allocSpace(VirtualHeap *VH){
	int retVal = VH->avail;
	
	if(retVal != -1){
		VH->avail = VH->elems[VH->avail].next;
	}
	
	return retVal;
}
void insertFront(VirtualHeap *VH, List *list, Student s){
	List temp = allocSpace(VH);
	
	if(temp != -1){
		VH->elems[temp].next = *list;
		*list = temp;
		VH->elems[temp].elem = s;
	}
	
}

//void displayList(VirtualHeap VH, List list);
void visualizeSpace(VirtualHeap VH){
	int ctr;
	printf("%5s | %30s | %s\n","INDEX", "ELEMENTS", "NEXT");
	printf("-------------------------------------------\n");
	
	for(ctr=0; ctr<MAX;ctr++){
		printf("%5d | ", ctr);
		if(!VH.elems[ctr].elem.studID){
			printf("%30s | ", "EMPTY");
		}else{
			printf("%4d - %23s | ", VH.elems[ctr].elem.studID,VH.elems[ctr].elem.studName);
		}
		printf("%d\n", VH.elems[ctr].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", VH.avail);
}
