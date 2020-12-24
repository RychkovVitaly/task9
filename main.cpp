#include <iostream>
#include <cmath>
using namespace std;


//9.1 +
void t1(){
    int m, n;
    cout<<"Введите размеры двумерного массива(Количество строк и столбцов): ";
    cin >> m >> n;
    int a2[m][n];
    int a[m*n];
    //чтение
    cout<<"Введите элементы двумерного массива: ";
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> a2[i][j];
        }
    }
    cout<< endl;
    //преобразование в одномерный массив
    for (int i=0; i<m; i++)
    for (int j=0; j<n; j++)
    a[i*n+j]=a2[i][j];
 
    cout<<"Полученный одномерный массив: ";
    for (int i=0; i<m*n; i++) cout << a[i] << " ";
    cout << "\n\n";
    //зануление двумерного массива
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            a2[i][j]=0;
        }
    }
    //преобразование в двумерный массив из одномерного
    for (int i=0; i<m*n; i++){
        a2[i / n][i % n]=a[i];
    }
    //вывод двумерного массива
    cout<<"Полученный двумерный массив: \n";
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << a2[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}



//9.2.1
void t2(){
    int m, n;
    cout<<"Введите размеры двумерного массива(Количество строк и столбцов): ";
    cin >> n >> m;
    int a[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            a[i][j]=abs(i-j)+1;
        }
    }
    cout<<"\nПервый массив: \n";
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
//9.2.2
    int b[n][m];
    int i=0, j, k=0, count=1;
    while (i<n*m) {
        k++;
        for (j=k-1; j<m-k+1; j++) {
            b[k-1][j]=count++;
            i++;
        }
        for (j=k; j<n-k+1; j++) {
            b[j][m-k]=count++;
            i++;
        }
        for (j=m-k-1; j>=k-1; j--){
            b[n-k][j]=count++;
            i++;
        }
        for (j=n-k-1; j>=k; j--){
            b[j][k-1]=count++;
            i++;
        }
    }

    
    cout<<"\nВторой массив: \n";
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    cout<<"\n";
}


void t3(){
    int a[9][9], count=0;
    cout<<"Введите элементы двумерного массива 9x9: \n";
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin >> a[i][j];
        }
    }
    cout<<"\nВаш массив: \n";
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if ((j>=i and j<=8-i) or (j<=i and j>=8-i)) count+=a[i][j];
        }
    }
    cout << "\nСумма элементов заштрихованной области (1 вариант) = " << count << "\n\n";
}




void t4(){
    int m, n, temp;
    cout<<"Введите размеры двумерного массива(Количество строк и столбцов): ";
    cin >> m >> n;
    int a[m][n], a1[n];
    //чтение
    cout<<"Введите элементы двумерного массива: ";
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for (int i=0; i<n; i++) a1[i]=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            a1[i]+=a[j][i];
    //сортировка
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a1[j] > a1[j + 1]) {
                for(int q=0; q<m; q++){
                    temp = a[q][j];
                    a[q][j] = a[q][j + 1];
                    a[q][j + 1] = temp;
                }
                temp = a1[j];
                a1[j] = a1[j + 1];
                a1[j + 1] = temp;
            }
        }
    }
    
    cout<<"\nВаш массив: \n";
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
        cout << a[i][j] << " ";
        cout<<endl;
    }    cout<<"***** Сумма чисел каждого столбика *****\n";
    for (int i=0; i<n; i++) cout<< a1[i] << " ";
    cout<<"\n\n";
}


void gauss(float **a,int n) {
    float del,ccc;
    for (int k=0; k<n; k++){
            if(a[k][k]==0){
                for (int ii=k+1; ii<n; ii++)
                    for (int jj=0; jj<n+1; jj++)
                        a[k][jj]+=a[ii][jj];
            }
            del=a[k][k];
            for (int j=0; j<n+1; j++) a[k][j]/=del;

        for (int lm=k+1; lm<n; lm++){
            ccc=a[lm][k]/a[k][k];
        for (int ld=0; ld<n+1; ld++){
            a[lm][ld]-=a[k][ld]*ccc;
        }
    }
        for (int ii=0; ii<n; ii++){
            for (int jj=0; jj<n+1; jj++)
            cout << a[ii][jj] << " ";
            cout<<endl;
        }
}
}





void gauss1(float **a,int n) {
    float del,ccc;
    for (int k=0; k<n; k++){
            if(a[k][k]==0){
                cout<<"***";
                for (int ii=k+1; ii<n; ii++)
                    for (int jj=0; jj<n*2; jj++)
                        a[k][jj]+=a[ii][jj];
            }
    }
    for (int k=0; k<n; k++){
            if(a[k][k]==0){
                cout<<"***";
                for (int ii=k+1; ii<n; ii++)
                    for (int jj=0; jj<n*2; jj++)
                        a[k][jj]+=a[ii][jj];
            }
            del=a[k][k];
        cout<<"del= "<<del;
            for (int j=0; j<n*2; j++) a[k][j]/=del;

        for (int lm=k+1; lm<n; lm++){
            ccc=a[lm][k]/a[k][k];
        for (int ld=0; ld<n*2; ld++){
            a[lm][ld]-=a[k][ld]*ccc;
        }
    }
        for (int ii=0; ii<n; ii++){
            for (int jj=0; jj<n*2; jj++)
            cout << a[ii][jj] << " ";
            cout<<endl;
        }
}
}









/*void gauss1(float **a,int n) {
    float del;
    for (int k=0; k<n; k++){
        for (int i=k; i<n; i++){
            del=a[i][k];
            for (int j=0; j<n*2; j++) a[i][j]/=del;
        }
        for (int lm=k+1; lm<n; lm++)
        for (int ld=0; ld<n*2; ld++){
            a[lm][ld]-=a[k][ld];
        }
    }
}*/

void gauss2(float **a,int n) {
    float del;
    for (int k=0; k<n; k++){
        for (int i=k; i<n; i++){
            del=a[i][k];
            for (int j=0; j<n; j++) a[i][j]/=del;
        }
        for (int lm=k+1; lm<n; lm++)
        for (int ld=0; ld<n; ld++){
            a[lm][ld]-=a[k][ld];
        }
    }
}

void t5(){
    int n;
    cout<<"\nВведите количество уравнений, равное количеству неизвестных: ";
    cin >> n;
    float **a = (float **) malloc(sizeof(float *)*n);
    //чтение
    cout<<"\nВведите коэффиценты неизвестных каждого уравнения и их свободные коэффиценты\n(Например для x+y=2 вписать 1 1 2):\n";
    for (int i=0; i<n; i++){
        a[i] = (float *) malloc(sizeof(float) * (n + 1));
        for (int j=0; j<n+1; j++){
            cin >> a[i][j];
        }
    }
    
    gauss(a,n);
    
    cout<<"\nМатрица верхне-треугольного вида: \n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n+1; j++)
        cout << a[i][j] << " ";
        cout<<endl;
    }
    for (int i=n-1; i>-1; i--)
    for(int k = i-1; k >-1 ; --k) {
        float del=a[k][i];
        for (int j=i; j<n+1; ++j) {
            a[k][j]-=a[i][j]*del;
            
        }
    }
    cout<<"\nКорни: \n";
    for (int i=0; i<n; i++){
        cout << "a" << i+1 << " = " << a[i][n];
        cout<<endl;
    }
    cout<<endl;
}
    
    
void t6(){
    int n;
    cout<<"\nВведите размер матрицы NxN(одно число): ";
    cin >> n;
    float **a = (float **) malloc(sizeof(float *) * n);
    //чтение
    cout<<"\nВведите значения матрицы:\n";
    for (int i=0; i<n; i++){
        a[i] = (float *) malloc(sizeof(float) * (n*2));
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for (int i=0; i<n; i++)
    for (int j=n; j<n*2; j++){
        if (i+n==j) a[i][j]=1;
        if (i+n!=j) a[i][j]=0;
    }
    
    gauss1(a,n);
    
    for (int i=n-1; i>-1; i--)
    for(int k = i-1; k >-1 ; --k) {
        float del=a[k][i];
        for (int j=i; j<n*2; ++j) {
            a[k][j]-=a[i][j]*del;
            
        }
    }
    cout<<"\nОбратная матрица равна:\n";
    for (int i=0; i<n; i++){
        for (int j=n; j<n*2; j++)
        cout << a[i][j] << " ";
        cout<<endl;

}
}

//не работает :(
void t7(){
    int n;
    cout<<"\nВведите размер матрицы NxN(одно число): ";
    cin >> n;
    float **a = (float **) malloc(sizeof(float *) * n);
    //чтение
    cout<<"\nВведите значения матрицы:\n";
    for (int i=0; i<n; i++){
        a[i] = (float *) malloc(sizeof(float) * n);
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=n; j<n; j++)
        cout << a[i][j] << " ";
        cout<<endl;
    }
    gauss2(a,n);
    double det = 1;
    for (int i=0; i<n; i++){
        for (int j=n; j<n; j++)
        cout << a[i][j] << " ";
        cout<<endl;
    }
    
    for (int i = 0; i < n; ++i) det *= a[i][i];
    cout<<"Определитель равен "<< det;
}

















int main(){
    setlocale(LC_ALL, "Russian");
    int x=1, key;
    while (x>0){
        cout << "Введите номер задачи: ";
        cin >> key;
        if (key==1) t1();
        if (key==2) t2();
        if (key==3) t3();
        if (key==4) t4();
        if (key==5) t5();
        if (key==6) t6();
        if (key==7) cout<<"Не сделал";
    }
    return 0;
}




