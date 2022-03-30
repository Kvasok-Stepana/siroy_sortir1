
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;






void puzir (int*m,int n,int q){
    for(int i = n - 1; i >= 1; i--)
        for(int j = 0; j < i; j++)
        {
            if(m[j] > m[j+1])
            {
                int foo = m[j];
                m[j] = m[j+1];
                m[j+1] = foo;
            }
        }

}
void vstavim (int*mas,int n,int q){
    int i, j, key=0, temp=0;
    for (i=0; i<n-1; i++)
    {
        key=i+1;
        temp=mas[key];
        for (j=i+1; j>0; j--)
        {
            if (temp<mas[j-1])
            {
                mas[j]=mas[j-1];
                key=j-1;
            }
        }
        mas[key]=temp;
    }

}
void vibor (int*Perestanovka,int length,int q){

    for (int j = 0; j < length; j++) {
        int temp = Perestanovka[0]; // временная переменная, храненящая значения перестановки
        for (int z = j + 1; z < length; z++) {
            if (Perestanovka[j] > Perestanovka[z]) {
                temp = Perestanovka[j];
                Perestanovka[j] = Perestanovka[z];
                Perestanovka[z] = temp;
            }
        }
    }

}
void bistro (int*mas,int size,int q) {
//Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];


    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;

        }

    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        bistro(mas, j + 1,0);
    }
    if (i < size) {
        //"Првый кусок"
        bistro(&mas[i], size - i,0);
    }



}
void slil(int *a, int n,int )
{
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int *c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
                // заполняем следующий элемент формируемой последовательности
                // меньшим из двух просматриваемых
                if (a[i] < a[j])
                {
                    c[k] = a[i];
                    i++; k++;
                }
                else {
                    c[k] = a[j];
                    j++; k++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = a[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j<n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = a[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i<n; i++)
            a[i] = c[i];
    }
}

void gnom (int*arr,int n,int q){
    int index = 0;
    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}

void chet_necheto (int* arr,int size, int null){
    size++;
    for (int i = 0; i < size; i++) {
        // (i % 2) ? 0 : 1 возвращает 1, если i четное, 0, если i не четное
        for (int j = (i % 2) ? 0 : 1; j + 1 < size; j += 2) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void (*psort[7])(int*,int,int)={puzir , chet_necheto  ,gnom ,vstavim  ,vibor ,slil,bistro};
void zapolniciferkami (int* a,int b){
    for (int i = 0; i < b; i++)
    {
        a[i]  = (rand()%10)*(-(rand()%2-1)%2);

    }
}







int main() {
    int k=100;
    ofstream fout("C:\\tyt_tekst\\file15.txt");
    int n=0;
    for (int i = 0; i < 1000; ++i) {

        if (n>5||k>10000000){break;}
        for (int j = 6; j >=n; j--)
        {

            if ((j==5||j==6)&&k>10000)
            {
                k=k*500;
            }
            fout << k<<"\t ";
            int *randcifri = new int[k];

            zapolniciferkami(randcifri, k);


            clock_t t;
            clock_t vr;
            t = clock();

            psort[j](randcifri, k,0);
            t = clock() - t;

            zapolniciferkami(randcifri, k);
            vr =clock();
            psort[j](randcifri, k,0);
            t = t + clock() - vr;
            zapolniciferkami(randcifri, k);
            vr =clock();
            psort[j](randcifri, k,0);
            t = t + clock() - vr;
            zapolniciferkami(randcifri, k);
            vr =clock();
            psort[j](randcifri, k,0);
            t = t + clock() - vr;
            zapolniciferkami(randcifri, k);
            vr =clock();
            psort[j](randcifri, k,0);
            t = t + clock() - vr;
            t=t/5;

            if (t > 10000)
            {
                n++;
            }
            int ch=0;
            for (int l = 0; l < k; ++l)
            {
                if (randcifri[l]<=randcifri[l+1]){

                }
                else
                {
                    ch++;
                }
            }
            cout << j << "  " << t << "  " << k<< "  "<< ch << endl;
            delete[] randcifri;
            fout   <<t << "\t ";
            if ((j==5||j==6)&&k>10000)
            {
                k=k/500;
            }

        }

            if (k<10000)
            k=k+100;
            if (k>=10000&&k<1000000)
                k=k+20000;
            if (k>=1000000)
                k=k+500000;

        fout  << "\n ";




    }

    fout.close();


    return 0;
}
