#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>
#define PI 3.141592654    // C���Ե�

#define  s  10 
#define  pop 0.1
#define indi 0.9  //pop����˵��Ⱥ��Ӱ�죬 indi����˵������Ӱ��
#define limi -4
#define length 1.6

float gaussrand()
{

    static float U, V, Z, q[s];
    static int phase = 0;
    float z = 0.0;
    int i = 0, j, k;

    do
    {
        if (phase == 0)
        {

            U = rand() / (RAND_MAX + 1.0);
            V = rand() / (RAND_MAX + 1.0);
            Z = sqrt(-2.0 * log(U)) * sin(2.0 * PI * V);
        }
        else
        {
            Z = sqrt(-2.0 * log(U)) * cos(2.0 * PI * V);
        }

        if (Z > limi && Z < 4)
        {
            q[i] = Z;
            i++;
            if (i == s)
            {
                for (j = 0; j < s; j++)
                {
                    z = z + q[j];
                }
                return z / s;
            }
        }
        else;
    } while (i <= s);
}

int flip(float p)
{
    float u;
    u = rand() / (RAND_MAX + 1.0);
    if (u > p)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//---------------------------------------------
//this function will use quick sort method to range
//the key will generated and range once
//by recursive the whole array will be range
//to keep the same pattern, an outer funtion was used
//2020.4.2
//---------------------------------------------

#include<stdio.h>
int partions(float* p, float* low, float* high);
int qsort(float* p, float* a, float* b);

int quicksort(float* p, int n) //p is the array, n is the number of element
{
    float* a, * b;
    a = p;
    b = (p + n - 1);
    qsort(p, a, b);
    return 0;
}

int qsort(float* p, float* a, float* b)//*p is the array needed to range, *a is the begining
{
    if ((b - a) > 0)
    {
        int k;
        k = partions(p, a, b);
        qsort(p, a, (a + k - 1));
        qsort(p, (a + k + 1), b);
    }
    return 0;
}


//an interesting model of this function, for the key have been put over each side of the array 
//and finally in the middle
int partions(float* p, float* low, float* high)//p is the array need to range, low is the lowest in one part 
{
    int l = 0, h = (high - low);
    float temp2, key, temp;
    key = *low;
    while (l < h)
    {
        while ((*(low + h) >= key) && l < h)
        {
            h--;
        }
        temp = *(low + l);
        *(low + l) = *(low + h);
        *(low + h) = temp;

        temp2 = *(low - 1000 + l);
        *(low + l - 1000) = *(low + h - 1000);
        *(low + h - 1000) = temp2;

        while (*(low + l) <= key && l < h)
        {
            l++;
        }
        temp = *(low + l);
        *(low + l) = *(low + h);
        *(low + h) = temp;

        temp2 = *(low + l - 1000);
        *(low + l - 1000) = *(low + h - 1000);
        *(low + h - 1000) = temp2;
    }
    return l; //l has divided p into two half
}

// -------------------------------------
// �����������������һ��ģ��
// ���ģ�ͽ�Ҫ������A�𽥼��ٵ�����£�������Ҳ��������
// ���ģ�͵������Ǹ������޷��ҵ��µ�ʳ����Դ��Ҳ���޷�ά����Ⱥ��ģ
// -------------------------------------

int model1()
{
    float a[2][1000], c1, c2;//C ������A��������ռ�ı��ء�
    int i, j, k, life = 0;
    for (i = 0; i < 1000; i++)
    {
        a[0][i] = 1;
        a[1][i] = 1;
    }
    for (i = 1; i < 151; i++)
    {
        c1 = 1 - i / 150.0;
        for (j = 0; j < 1000; j++)
        {
            a[0][j] = flip(c1);
            if (a[0][j] == 1)
            {
                life = life + 1;
            }
            a[1][j] = a[1][j] * (1 + gaussrand());
        }
        printf("generation:%d   life:%d\n", i, life);  //life ��������ÿһ��������ĸ���������
        life = 0;
        if (i % 50 == 0)
        {
            printf("\n--------------------------------------------\n");
            for (k = 0; k < 1000; k++)
            {
                printf(" %f ", a[1][k]);
            }
            printf("\n--------------------------------------------\n");
        }
    }
    return 0;
}

// ---------------------------------------------------
// ���ģ�Ϳ��ǵ��˵�A����������ʱ��B�������������ӡ�
// ������ʱ��һ���ֵ��������㹻��๳�����Ӧ����B�ĳ���
// ��ô����������ͻ��ö����Ӫ���������Ӷ���ø��ߵķ�ֳ��
// ���ģ�ͼ����������ȡ�öԲߡ�������ʱ����Ⱥ���ﵽ����
// ��ô��Ⱥ��������Ӧ�ñ�������ȶ�����๳�����ַֻ����߱���
// ����A���ֵĹ�Ƥ�����1��B���ֵĹ�Ƥ�����2
// ���������������ֶ������������֧����һ����
// liusj 2020 11.15
// --------------------------------------------------
int model2()
{
    float a[2][1000], a2[2][1000], blen = 0, a1, b, alen = 0, b1;
    srand(time(NULL));
    int i, j, k, l, divide, bcount = 0; // divide ��������1000��λ�����ô������  blen�������㳬��2��๳������ bcount�������㳬��2�ĸ���
    float* p;
    for (i = 0; i < 1000; i++)
    {
        a[0][i] = 1.0;
        a[1][i] = 1.0;
        a2[0][i] = 1.0;
        a2[1][i] = 1.0;
    }
    for (i = 1; i < 151; i++) //����ط�i����������˶��ٴ�
    {

        alen = 0, blen = 0;
        b = i / 150.0;

        for (k = 0; k < 1000; k++)  //��ͳ����һ����һЩ������Ȼ���ٽ�����һ�������ɡ���������һ��������������ͳ�ơ�
        {
            if (a[1][k] > length)
            {
                bcount++;
                blen = blen + a[1][k];
            }
            else
            {
                alen = alen + a[1][k];
            }
        }
        if (bcount == 0)
        {
            a1 = alen / 1000;
            p = a[1];
            quicksort(p, 1000);
            for (j = 0; j < 1000; j++)
            {
                a2[0][j] = flip(1.0 - b);
                l = rand() % 1000;
                a2[1][j] = indi * a[1][l] + pop * a1 + gaussrand();
                if (a2[1][j] < 0)
                {
                    a2[1][j] = 0;
                }
            }
            for (j = 0; j < 1000; j++)
            {
                a[0][j] = a2[0][j];
                a[1][j] = a2[1][j];
            }
        }
        else
        {
            p = a[1];
            quicksort(p, 1000);
            for (j = 0; j < 1000; j++)
            {
                a2[0][j] = flip(1 - b);
                a1 = alen / (1000 - bcount);
                b1 = blen / bcount;
                if (a2[0][j] == 1)
                {
                    l = rand() % (1000 - bcount);
                    a2[1][j] = indi * a[1][l] + pop * a1 + gaussrand();
                    if (a2[1][j] < 0)
                    {
                        a2[1][j] = 0;
                    }
                }
                else
                {
                    l = rand() % bcount;
                    a2[1][j] = indi * a[1][1000 - bcount + l] + pop * b1 + gaussrand();
                    if (a2[1][j] < 0)
                    {
                        a2[1][j] = 0;
                    }
                }
            }
            for (j = 0; j < 1000; j++)
            {
                a[0][j] = a2[0][j];
                a[1][j] = a2[1][j];
            }
        }

        bcount = 0;
        for (j = 0; j < 1000; j++)
        {
            if (a[1][j] > length)
            {
                bcount++;
            }
        }
        printf("b:%d\n", bcount);
        if (i % 40 == 0)
        {
            p = a[1];
            quicksort(p, 1000);
            for (j = 0; j < 1000; j++)
            {
                printf("%f ", a[1][j]);
            }
        }
        else if (i == 150)
        {
            p = a[1];
            quicksort(p, 1000);
            for (j = 0; j < 1000; j++)
            {
                printf("%f ", a[1][j]);
            }
        }
    }
    return 0;
}


int model3()
{
    float a[2][1000], a2[2][1000], blen = 0, a1, b, alen = 0, b1;
    srand(time(NULL));
    int i, j, k, l, divide, bcount = 0, bcount2 = 0; // divide ��������1000��λ�����ô������  blen�������㳬��2��๳������ bcount�������㳬��2�ĸ���
    float* p;
    for (i = 0; i < 1000; i++)
    {
        a[0][i] = 1.0;
        a[1][i] = 1.0;
        a2[0][i] = 1.0;
        a2[1][i] = 1.0;
    }
    for (i = 1; i < 300; i++) //����ط�i����������˶��ٴ�
    {
        if (i < 151)
        {
            alen = 0, blen = 0;
            b = i / 150.0 - (bcount2 / 1000.0) * 1;

            for (k = 0; k < 1000; k++)  //��ͳ����һ����һЩ������Ȼ���ٽ�����һ�������ɡ���������һ��������������ͳ�ơ�
            {
                if (a[1][k] > length)
                {
                    bcount++;
                    blen = blen + a[1][k];
                }
                else
                {
                    alen = alen + a[1][k];
                }
            }
            if (bcount == 0)
            {
                a1 = alen / 1000;
                p = a[1];
                quicksort(p, 1000);
                for (j = 0; j < 1000; j++)
                {
                    a2[0][j] = flip(1.0 - b);
                    l = rand() % 1000;
                    a2[1][j] = indi * a[1][l] + pop * a1 + gaussrand();
                    if (a2[1][j] < 0)
                    {
                        a2[1][j] = 0;
                    }
                }
                for (j = 0; j < 1000; j++)
                {
                    a[0][j] = a2[0][j];
                    a[1][j] = a2[1][j];
                }
            }
            else
            {
                p = a[1];
                quicksort(p, 1000);
                for (j = 0; j < 1000; j++)
                {
                    a2[0][j] = flip(1 - b);
                    a1 = alen / (1000 - bcount);
                    b1 = blen / bcount;
                    if (a2[0][j] == 1)
                    {
                        l = rand() % (1000 - bcount);
                        a2[1][j] = indi * a[1][l] + pop * a1 + gaussrand();
                        if (a2[1][j] < 0)
                        {
                            a2[1][j] = 0;
                        }
                    }
                    else
                    {
                        l = rand() % bcount;
                        a2[1][j] = indi * a[1][1000 - bcount + l] + pop * b1 + gaussrand();
                        if (a2[1][j] < 0)
                        {
                            a2[1][j] = 0;
                        }
                    }
                }
                for (j = 0; j < 1000; j++)
                {
                    a[0][j] = a2[0][j];
                    a[1][j] = a2[1][j];
                }
            }
            bcount2 = bcount;
            bcount = 0;
            for (j = 0; j < 1000; j++)
            {
                if (a[1][j] > length)
                {
                    bcount++;
                }
            }
            printf("b:%d\n", bcount);
            if (i % 40 == 0)
            {
                p = a[1];
                quicksort(p, 1000);
                for (j = 0; j < 1000; j++)
                {
                    printf("%f ", a[1][j]);
                }
            }
            else if (i == 150)
            {
                p = a[1];
                quicksort(p, 1000);
                for (j = 0; j < 1000; j++)
                {
                    printf("%f ", a[1][j]);
                }
            }
        }
        else
        {
            alen = 0, blen = 0;
            b = 1 - (bcount2 / 1000.0) * 1;

            for (k = 0; k < 1000; k++)  //��ͳ����һ����һЩ������Ȼ���ٽ�����һ�������ɡ���������һ��������������ͳ�ơ�
            {
                if (a[1][k] > length)
                {
                    bcount++;
                    blen = blen + a[1][k];
                }
                else
                {
                    alen = alen + a[1][k];
                }
            }
            if (bcount == 0)
            {
                a1 = alen / 1000;
                p = a[1];
                quicksort(p, 1000);
                for (j = 0; j < 1000; j++)
                {
                    a2[0][j] = flip(1.0 - b);
                    l = rand() % 1000;
                    a2[1][j] = indi * a[1][l] + pop * a1 + gaussrand();
                    if (a2[1][j] < 0)
                    {
                        a2[1][j] = 0;
                    }
                }
                for (j = 0; j < 1000; j++)
                {
                    a[0][j] = a2[0][j];
                    a[1][j] = a2[1][j];
                }
            }
            else
            {
                p = a[1];
                quicksort(p, 1000);
                for (j = 0; j < 1000; j++)
                {
                    a2[0][j] = flip(1 - b);
                    a1 = alen / (1000 - bcount);
                    b1 = blen / bcount;
                    if (a2[0][j] == 1)
                    {
                        l = rand() % (1000 - bcount);
                        a2[1][j] = indi * a[1][l] + pop * a1 + gaussrand();
                        if (a2[1][j] < 0)
                        {
                            a2[1][j] = 0;
                        }
                    }
                    else
                    {
                        l = rand() % bcount;
                        a2[1][j] = indi * a[1][1000 - bcount + l] + pop * b1 + gaussrand();
                        if (a2[1][j] < 0)
                        {
                            a2[1][j] = 0;
                        }
                    }
                }
                for (j = 0; j < 1000; j++)
                {
                    a[0][j] = a2[0][j];
                    a[1][j] = a2[1][j];
                }
            }
            bcount2 = bcount;
            bcount = 0;
            for (j = 0; j < 1000; j++)
            {
                if (a[1][j] > length)
                {
                    bcount++;
                }
            }
            printf("b:%d\n", bcount);
            if (i % 100 == 0)
            {
                p = a[1];
                quicksort(p, 1000);
                for (j = 0; j < 1000; j++)
                {
                    printf("%f ", a[1][j]);
                }
            }
        }

    }
    return 0;
}

int main()
{
    model3();
    return 0;
}

