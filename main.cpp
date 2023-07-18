#include <iostream>
#include <string>
using namespace std;

// Pearson Correlation Coefficient
double mean(double set[], int size);
void print(double set[], int size);
double correl(double x[], double y[], int size);

int main() {

    const int SIZE = 1000;
    double set1[SIZE];
    int index = 0;

    string input;
    // check input
    do {
        cout << "Enter a value for X set, leave blank to quit: ";
        getline(cin, input);

        if(!input.empty()) {
            if(!isdigit(input[0]) && !(input[0] == '-' && isdigit(input[1])))
                cout << "Please type numbers only." << endl;
            else {
                set1[index++] = stod(input);
                cout << "Adding " << stod(input) << "." << endl;
            }
        };


    } while (!input.empty());

    print(set1, index);

    int size = index;
    double* set2 = new double[size];

    string input2;
    for (int i = 0; i < size; i++) {
        cout << "Enter value " << (i + 1) << " of" << size << "for Y set: ";
        getline(cin, input2);

        if(input2.empty() || !isdigit(input2[0])) {
            cout << "Please enter numbers only." << endl;
            // Manually decrement
            i--;
        }
        else {
            set2[i] = stod(input2);
            cout << "Adding " << stod(input2) << " to set." << endl;
        }
    }

    print(set2, size);

    cout << "Correlation coefficient: " << correl(set1, set2, size);
    delete set2;

}

double mean(double set[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += set[i];
    };
    return total / size;
};

void print(double set[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << set[i] << "]";
    }
    cout << endl;
}

double correl(double x[], double y[], int size) {

    double meanX = mean(x, size);
    double meanY = mean(y, size);
    double numSum = 0;
    double xSquareSum = 0;
    double ySquareSum = 0;

    for (int i = 0; i < size; i++) {
      numSum += (x[i] - meanX) * (y[i] - meanY);
      xSquareSum += pow(x[i] - meanX, 2);
      ySquareSum += pow(y[i] - meanY, 2);
    };
    return numSum / sqrt(xSquareSum * ySquareSum);
}