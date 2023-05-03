#include <iostream>

// Συνάρτηση για την αρχικοποίηση ενός πίνακα μεγέθους N και επιστροφή δείκτη προς αυτόν
float* initArray(int &N);

// Συνάρτηση για την εύρεση των δύο μεγαλύτερων τιμών σε έναν πίνακα
void findMax(float* Array, int N, float &maxValue, float &secondMaxValue);

// Συνάρτηση για την εύρεση της ελάχιστης τιμής σε έναν πίνακα και επιστροφή αναφοράς προς αυτήν
float& findMin (float* Array, int N);

// Συνάρτηση για τον διπλασιασμό της ελάχιστης τιμής σε έναν πίνακα
void doubleMin(float &min);


int main()
{
	int N;
	float max1, max2;
	std::cout << "Εισάγετε το πλήθος των αριθμών Ν: " << std::endl;
	std::cin >> N;
	std::cout << "Παρακαλώ εισάγετε " << N << " στοιχεία:" << std::endl;
	float *numbers = initArray(N);
	std::cout << "Τα στοιχεία είναι: ";
	for (int i = 0; i < N; i++) {
		std::cout << numbers[i] << " ";
	}

	std::cout << std::endl;
	findMax(numbers, N, max1, max2);
	std::cout << "Η πρώτη τιμή Max είναι: " << max1 << std::endl;
	std::cout << "Η δεύτερη τιμή Max είναι: " << max2 << std::endl;

	float& min = findMin(numbers, N);
	std::cout << "Min = " << min << std::endl; 

	doubleMin(min);
	std::cout << "Doubled Min = " << min << std::endl; 

    delete[] numbers;
	return 0;
}


float* initArray(int &N) {

	float *array = new float[N];
	for (int i = 0; i < N; i++) {
		std::cin >> array[i];
	}
	return array;

}

void findMax(float* Array, int N, float &maxValue, float &secondMaxValue) {

	maxValue = Array[0];
	secondMaxValue = Array[1];

	for (int i = 0; i < N; i++) {
        if (Array[i] > maxValue) {
            secondMaxValue = maxValue;
            maxValue = Array[i];
        }
        else if (Array[i] > secondMaxValue && Array[i] != maxValue) {
            secondMaxValue = Array[i];
        }
	}
}

float& findMin (float* Array, int N) {

	float minValue = Array[0];
	int minPos = 0;
	for (int i = 0; i < N; i++) {
		if (Array[i] < minValue) {
			minValue = Array[i];
			minPos = i;
		}

	}
	return Array[minPos];
}

void doubleMin(float &min) {
	
		min *= 2;
}