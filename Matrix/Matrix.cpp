#include <iostream>
using namespace std;

class Matrix {
public:
    int** arr2;
    int rows;
    int columns;

    Matrix(int rows, int columns) {
        arr2 = new int* [rows];
        this->rows = rows;
        this->columns = columns;
        for (int i = 0; i < rows; i++) {
            arr2[i] = new int[columns];
            for (int j = 0; j < columns; j++) {
                arr2[i][j] = rand() % 100;
            }
        }
    }

    ~Matrix() {
        cout << "Destructor executed";
        for (int i = 0; i < rows; i++) {
            delete arr2[i];
        }
        delete arr2;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << arr2[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void getBelowAvg() {
        for (int i = 0; i < columns; i++) {
            int columnSumm = 0;
            int belowAvg = 0;
            for (int j = 0; j < rows; j++) {
                columnSumm += arr2[j][i];
            }
            int avg = columnSumm / rows;
            cout << columns<< endl;
            cout << i << ' ' << "Column sum = " << columnSumm << endl;
            cout << i << ' ' << "Column avg = " << avg << endl;
            for (int j = 0; j < rows; j++) {
                if (arr2[j][i] < avg) {
                    belowAvg++;
                }
            }
            cout << i << ' ' << "Column below avg =" << belowAvg << endl;
        }
    }
};

int main()
{
    int rows;
    int columns;

    cout << "Enter the number of rows"<< endl;
    cin >> rows;
    cout << "Enter the number of columns"<< endl;
    cin >> columns;

    Matrix* matrix = new Matrix(rows, columns);
    matrix->print();
    matrix->getBelowAvg();
    delete matrix;
}