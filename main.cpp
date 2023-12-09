#include <iostream>
#include <vector>
using namespace std;

void print_matrix(const vector<vector<long double>> &matrix){
    cout << "Printing matrix" << endl;
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix.at(i).size(); j++){
            cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void change_rows(vector<vector<long double>> &matrix, const int row1, const int row2){
    long double temp_number;
    for (int i = 0; i < matrix.at(row1).size(); i++){
        temp_number = matrix.at(row1).at(i);
        matrix.at(row1).at(i) = matrix.at(row2).at(i);
        matrix.at(row2).at(i) = temp_number;
    }
}

int main()
{
    cout << "Please enter dimension of matrix (n): ";
    int n = 0;
    cin >> n;
    vector<vector<long double>> matrix;
    matrix.resize(n);
    for (int i = 0; i < n; i++){
        matrix.at(i).resize(n+n);
        for (int j = 0; j < n; j++){
            cout << "Please enter (" << i+1 << "," << j+1 << ") entry of matrix: ";
            cin >> matrix.at(i).at(j);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == j) {
                matrix.at(i).at(j+n) = 1;
            } else {
                matrix.at(i).at(j+n) = 0;
            }
        }
    }
    print_matrix(matrix);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(matrix.at(i).at(i) == 0){
                int org_j = j;
                int org_i = i;
                do {
                    change_rows(matrix,i,j);
                    if(j < n){
                        j++;
                    } else {
                        i++;
                    }
                } while (matrix.at(i).at(i) == 0);
                i = org_i;
                j = org_j;
            }
            long double coef=matrix.at(j).at(i)/matrix.at(i).at(i);
            for(int k=0; k<2*n; k++){
                matrix.at(j).at(k)=matrix.at(j).at(k)-coef*matrix.at(i).at(k);
            }
            print_matrix(matrix);
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            long double coef=matrix.at(j).at(i)/matrix.at(i).at(i);
            for(int k=0; k<2*n; k++){
                matrix.at(j).at(k)=matrix.at(j).at(k)-coef*matrix.at(i).at(k);
            }
            print_matrix(matrix);
        }
    }
    for(int i=0; i<n; i++){
        long double coef=matrix.at(i).at(i);
        for(int j=0; j<2*n; j++){
            matrix.at(i).at(j) = matrix.at(i).at(j)/coef;
        }
        print_matrix(matrix);
    }

    vector<vector<long double>> inv_matrix;
    inv_matrix.resize(n);
    for(int i=0; i < n; i++){
        inv_matrix.at(i).resize(n);
        for(int j = 0; j < n; j++){
            inv_matrix.at(i).at(j) = matrix.at(i).at(j+n);
        }
    }
    print_matrix(inv_matrix);
    return 0;
}
