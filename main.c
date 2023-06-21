#include <stdio.h>
#include <stdlib.h>
#include"CursorBased.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualHeap myHeap = newVirtualHeap();
	List myList = -1;
	List anotherList = -1;
	
	visualizeSpace(myHeap);
	
	insertFront(&myHeap, &myList, newStudent(101, "Jonathan", 'm', "BS IT"));
	insertFront(&myHeap, &myList, newStudent(105, "Sebastian", 'm', "BS CS"));
	insertFront(&myHeap, &myList, newStudent(100, "Khenty", 'f', "BS Math"));
	
	insertFront(&myHeap, &anotherList, newStudent(100, "Christine", 'f', "BS Math"));
	insertFront(&myHeap, &anotherList, newStudent(200, "Wayne", 'm', "BS CS"));
	insertFront(&myHeap, &anotherList, newStudent(100, "Chrissy", 'f', "BS Math"));
	visualizeSpace(myHeap);
	return 0;
}       
