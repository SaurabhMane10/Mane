#include <iostream>
#include <vector>
int R,C;

//Considering the array representation of LinkedList for ease of implementation.
class SpiralMatrix{
	public:
		// Function to form the spiral matrix
		std::vector<std::vector<int>> buildSpiralMatrix(int m,int n,int arr[]){
			std::vector<std::vector<int>> mat(m,std::vector<int>(n));
			int top = 0,
			  bottom = m - 1,
			  left = 0,
		  	  right = n - 1;
			int index = 0;

			while (1) {
				if (left > right)
					break;

				// print top row
				for (int i = left; i <= right; i++)
					mat[top][i] = arr[index++];
				top++;

				if (top > bottom)
					break;
		
				// print right column
				for (int i = top; i <= bottom; i++)
					mat[i][right] = arr[index++];
				right--;
		
				if (left > right)
					break;
	
				// print bottom row
				for (int i = right; i >= left; i--)
					mat[bottom][i] = arr[index++];
				bottom--;
		
				if (top > bottom)
					break;
	
				// print left column
				for (int i = bottom; i >= top; i--)
					mat[i][left] = arr[index++];
				left++;
			}
			return mat;
	}
};
// Function to print the spiral matrix

void printVec(const std::vector<std::vector<int>> &vec, std::string msg="V")
{
    std::cout << msg <<" = [\n";
    for (int i =0;i <vec.size();i++){
        for (int j : vec[i])
	    std::cout << j <<",";
    	std::cout<<"\n";
    }
    std::cout << "]\n";
}

// Driver code
int main()
{
	int m=5,n=4;
	int arr[] = { 1, 2, 4, 5, 6,
		      7, 8, 9, 10, 11, 12,
		      13, 14, 15, 16, 17, 18 };
	unsigned int size = (sizeof(arr)/sizeof(*arr));
	while(size!=m*n){		
		arr[size] = -1;
		size++;		
	}
	SpiralMatrix sm;
	
	std::vector<std::vector<int>> mat = sm.buildSpiralMatrix(m,n,arr);
	printVec(mat);

	return 0;
}
