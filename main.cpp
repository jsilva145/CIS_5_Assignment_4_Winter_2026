#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::string;

// Pass by values (Not modifying)
int calculateSum(const int* scores, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += scores[i];
    return sum;
 }

 // Pass by value
 double calculationAverage(int sum, int size)
 {
    if (size == 0) return 0.0;
    return static_cast<double>(sum) / size;
 }

 // Pass by pointer (Modifying)
 void addBonus(int* scores, int size, int bonus)
 {
    for (int i = 0; i < size; ++i)
    {
        scores[i] += bonus;
    }
 }

 //Pass by pointer (returns to minimum value)
 int findMinimum(const int* scores, int size)
 {
    if (size <= 0) return -1; // safety

    int minVal = scores[0];
    for (int i = 1; i < size; ++i)
    {
        if (scores[i] < minVal)
        {
            minVal = scores[i];
        }
    }
    return minVal;
 }
 // PAss by pointer outputs (min/max)
void getMinMax(const int* arr, int size, int* minOut, int* maxOut)
{
    if (size < 0) return;
    *minOut = *maxOut = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < *minOut)
        {
            *minOut = arr[i];
        }

        if (arr[i] > *maxOut)
        {
            *maxOut = arr[i];
        }    
    }


};

// Pass by reference (Not modifying)
int countHighPerformers(const int scores[], const int& size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
        if (scores[i] >= 80) 
            ++count;
    return count;
}
// Helper to print scores (conts: does not modify)
void printScores(const int scores[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << scores[i] << (i < size -1 ? " " : "");
            cout << endl;
    
}
int main()
{
    const int SIZE = 10; 
    int ary[SIZE] = {75, 88, 62, 95, 50, 82, 70, 91, 45, 78};

    // Print original scores
    cout << "Original Scores: ";
    printScores(ary, SIZE);

    // Sum and average 
    int sum = calculateSum(ary, SIZE);
    double avg = calculationAverage(sum, SIZE);

    cout << "Sum: " << sum << endl;
    cout << "Average: " << std::fixed << std::setprecision(2) << avg << endl;
    
    // Add bonus +10
    addBonus(ary, SIZE, 10);
    cout << "Scores after adding =10 bonus: ";
    printScores(ary, SIZE);

    // Minimum score
    int minimum = findMinimum(ary, SIZE);
    cout << "Minimum Score: " << minimum << endl;
    
    // high performers count
    int highPerformers = countHighPerformers(ary, SIZE);
    cout << "Number of high performers (>80): " << highPerformers << endl;

    //original min/max
    int minOut =0, maxOut =0;
    getMinMax(ary, SIZE, &minOut, &maxOut);

    return 0;
}

