#include <iostream>

using namespace std;

template <typename T>
class GenericArray {

	private:
		T *arr;
		//This is an array which holds the slicing funcs results
		T *sliceArr;
		int size;
	public:
		//Default constructor
		GenericArray {
			sliceArr = NULL;
			size = 0;
		}
		
		//Default destructor
		~GenericArray {
			delete arr;
			delete sliceArr;
		}

		//Add element function
		void addElement(T newElement) {
			size++;
			/*If size is one, just makes an array of size one and
			  sets it to the provided value*/
			if (size == 1) {
				arr = new T[1];
				arr[0] = newElement;
			} else {
				//Makes temp array of new size
				T *tempArr = new T[size];
				/*Sets all elements of tempArr equal to the
				  previous array's elements, and sets the last
				  element to the provided value*/
				for (int i = 0; i < size; i++) {
					if (i == size-1) {
						tempArr[i] = newElement;
					} else {
						tempArr[i] = arr[i];
					}
				}
				//Deletes the old arr
				delete arr;
				//Allocates memory to arr that is the new size
				arr = new T[size];
				//Sets arr equal to the tempArr
				arr = tempArr;
				//Deletes the tempArr
				delete tempArr;

			}
		}
		
		//Return size function
		int size() {
			return size;
		}
		
		//Return value at place function
		T at(int place) {
			//Checks if the array has values based on size variable
			//I did this for every function
			if (size == 0) {
				/*Prints error message and returns 0 if there
				  aren't any*/
				cout << "No elements in array." << endl;
				return 0;
			} else {
				/*If given place is negative or greater than the
				  size of the array, prints error message and
				  returns 0*/
				if (place < 0) {
					cout << "Invalid place number." << endl;
					return 0;
				} else if (place > size-1) {
					cout << "Invalid place number." << endl;
					return 0;
				} else {
					return arr[place];
				}
			}
		}
		
		//Sum function
		T sum() {
			if (size == 0) {
				cout << "No elements in array." << endl;
				return 0;
			} else {
				//Makes a sum variable of provided type
				T sum = 0;
				//Adds each member of the array to the sum
				for (int i = 0; i < size; i++) {
					sum += arr[i];
				}
				//Returns the sum
				return sum;
			}	
		}
		
		//Maximum function
		T max() {
			if (size == 0) {
				cout << "No elements in array." << endl;
				return 0;
			} else {
				//Makes a max variable of provided type
				T max = arr[0];
				//If the size equals one, returns max as is
				if (size == 1) {
					return max;
				} else {
					/*Compares each array member to the
					  previous member of the array and, if
					  it's bigger, sets the max to it*/
					for (int i = 1; i < size; i++) {
						if (arr[i-1] < arr[i]) {
							max = arr[i];
						}
					}
					//Returns the max
					return max;
				}
			}
		}
		
		//Minimum function
		T min() {
			if (size == 0) {
				cout << "No elements in array." << endl;
				return 0;
			} else {
				//Makes a min variable of the provided type
				T min = arr[0];
				//If the size equals one, returns min as is
				if (size == 1) {
					return min;
				} else {
					/*Compares each array member to the
					  previous member of the array and, if
					  it's smaller, sets the min to it*/
					for (int i = 1; i < size; i++) {
						if (arr[i-1] > arr[i]) {
							min = arr[i];
						}
					}
					//Returns the min
					return min;
				}
			}
		}
		
		//Slicing function
		T* slice(int begin, int end) {
			if (size == 0) {
				cout << "No elements in array." << endl;
				return 0;
			} else {
				/*If begin is negative or greater than the size,
				  prints error message and returns null*/
				if (begin < 0 || begin > size) {
					cout << "Invalid bounds." << endl;
					return NULL;
				/*If end is negative or greater than the size,
				  prints error message and returns null*/
				} else if (end < 0 || end > size) {
					cout << "Invalid bounds." << endl;
					return NULL;
				/*If begin is greater than end, prints error
				  message and returns null*/
				} else if (begin > end) {
					cout << "Invalid bounds." << endl;
					return NULL;
				}
				/*If sliceArr is not equal to null (aka this
				  isn't the first time the function was called),
				  deletes sliceArr*/
				if (sliceArr != NULL) {
					delete sliceArr;
				}
				/*Makes tempSize variable equal to the new
				  desired size*/
				int tempSize = end - begin + 1;
				/*Allocates memory to sliceArr that is the
				  tempSize*/
				sliceArr = new T[tempSize];
				/*Sets each member of the sliceArr to the
				  desired values of arr*/
				for (int i = begin-1; i < end; i++) {
					sliceArr[i] = arr[i];
				}
				//Returns sliceArr
				return sliceArr;
			}
		}

};

int main() {

	//Code goes here
	return 0;

}
