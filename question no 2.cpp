#include<iostream>
#include<math.h>

class Rectangle {
public:
    bool isOverlapping(int rec1[4], int rec2[4]) {
	return !(rec1[2] <= rec2[0] || rec1[1] >= rec2[3] || rec2[2] <= rec1[0] || rec2[1] >= rec1[3]);      
    }
};

void printArr(int (&arr)[4],std::string msg){
	std::cout << msg << ": [";
	for(int i : arr){
		std::cout << i << ",";
	}
	std::cout << "]\n";
}
int main () {
	
	int r1[] = {0,0,2,2};
	int r2[] = {1,1,3,3};

	printArr(r1,"Rectangle 1");
	printArr(r2,"Rectangle 2");

	Rectangle rec;
	bool doesOverlap = rec.isOverlapping(r1,r2);
	if (doesOverlap)
		std::cout << "IsOverlapping : True\n";
	else
		std::cout << "IsOverlapping : False\n";
	return 0;
}
