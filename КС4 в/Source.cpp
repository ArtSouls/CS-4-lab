//������ �����
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    setlocale(0, "rus");
    srand(time(NULL));
    cout << "������ �����" << endl;
    double g = 0.18;
    int Count_Pockets = 12;
    double P = exp(-2 * g);
    int r = 15;
    int success = 0, unsuccessful = 0;
    for(int i = 0; i < Count_Pockets; i++)
    {
        double RP = (rand() % 100) / 100;
        if(RP <= P)
            success++;
        else
            while(true)
            {
                unsuccessful++;
                RP = (rand() % 100) / 100;
                if(RP <= P)
                {
                    success++;
                    break;
                }
            }
    }
    double RG = (((double)success + unsuccessful) * 2.0 * (1.0/r))/ (double)Count_Pockets;
    double S = RG * exp(-2 * RG);
    double Total_time = ((double)success + unsuccessful) * r;
    double One_time = ((double)success + unsuccessful) * r / Count_Pockets;
    double RG_Mass[15];
    double S_Mass[15];
    for(int i = 0; i < 15; i++)
    {
        RG_Mass[i] = (((double)success + unsuccessful) * 2.0 * (1.0 /((double)i+1))) / (double)Count_Pockets;
        S_Mass[i] = RG_Mass[i] * exp(-2 * RG_Mass[i]);
    }
    cout << "����� � ������ �������" << endl;
    cout << "������������� ���������� �������� " << RG << endl;
    cout << "������������������ " << S << endl;
    cout << "����� ����� �������� ������ " << Total_time << endl;
    cout << "����� �������� ������ ����� " << One_time << endl;
    cout << "�������� ��� ������� ������� G � S" << endl;
    cout << "RG" << endl;
    for(int i = 0; i < 15; i++)
    {
        cout << RG_Mass[i] << ' ';
    }
    cout << "\nS " << endl;
    for(int i = 0; i < 15; i++)
    {
        cout << S_Mass[i] << ' ';
    }

    cout << "\n���������� �����" << endl;
    RG = (((double)success + unsuccessful) * 2.0 * (1.0 / r)) / (double)Count_Pockets;
    S = RG * exp(-RG);
    Total_time = ((double)success + unsuccessful) * r;
    One_time = ((double)success + unsuccessful) * r / Count_Pockets;
    for(int i = 0; i < 15; i++)
    {
        RG_Mass[i] = (((double)success + unsuccessful) * 2.0 * (1 / ((double)i + 1.0))) / (double)Count_Pockets;
        S_Mass[i] = RG_Mass[i] * exp(-RG_Mass[i]);
    }
    cout << "����� � ������ �������" << endl;
    cout << "������������� ���������� �������� " << RG << endl;
    cout << "������������������ " << S << endl;
    cout << "����� ����� �������� ������" << Total_time << endl;
    cout << "����� �������� ������ ����� " << One_time << endl;
    cout << "�������� ��� ������� ������� G � S" << endl;
    cout << "RG" << endl;
    for(int i = 0; i < 15; i++)
    {
        cout << RG_Mass[i] << ' ';
    }
    cout << "\nS " << endl;
    for(int i = 0; i < 15; i++)
    {
        cout << S_Mass[i] << ' ';
    }
}
