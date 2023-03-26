#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

string number[9] {"��������", "�������", "���������", "�������","�������","�����", "����", "������", "���"};
string mast[4] {"������", "�����", "����", "����"};
struct karta {
    int real_mast;
    int real_number;
};
void koloda(vector<karta>& t);
void mix_koloda(vector<karta>& t);
void find_color(vector<karta>& t);
void find_mast(vector<karta>& t);
void find_dama(vector<karta>& t);
void print_ace(vector<karta>& t);
void print_koloda(vector<karta>& t);
int main()
{
    vector<karta> koloda36(36);
    cout << "������:" << endl;
    koloda(koloda36);
    print_koloda(koloda36);
    cout << endl;
    cout << "������������� ������:" << endl;
    mix_koloda(koloda36);
    print_koloda(koloda36);
    cout << endl;
    cout << "����� � ������ ���� ������ ���� ������ �����:" << endl;
    find_color(koloda36);
    cout << endl;
    cout << "����� � ������ ���� ������ ���� ������ ��������:" << endl;
    find_mast(koloda36);
    cout << endl;
    cout << "����� � ������ ���� ���:" << endl;
    find_dama(koloda36);
    cout << endl;
    cout << "����� � ������ ���� �����:" << endl;
    print_ace(koloda36);
    return 0;
}

void koloda(vector<karta>& t)
{
    int i;
    int mast1 = 0;
    int number1 = 6;
    for(i = 0; i < 36; i++) {
        t[i].real_number = number1;
        t[i].real_mast = mast1;
        if (mast1 == 3) {
            mast1 = 0;
            number1++;
        } else
            mast1++;
    }
}

void mix_koloda(vector<karta>& t)
{
    static mt19937 rnd((uint64_t)&rnd);
    shuffle(t.begin(),t.end(),rnd);
}

void find_color(vector<karta>& t)
{
    int i;
    for(i = 1; i < 36; i++) {
        if ((t[i].real_mast == 1 && t[i - 1].real_mast == 2) || (t[i].real_mast == 0 && t[i -1].real_mast == 3) || (t[i].real_mast == 1 && t[i-1].real_mast== 1) || (t[i].real_mast == 2 &&
                t[i - 1].real_mast == 2) || (t[i].real_mast== 3 && t[i - 1].real_mast == 3) || (t[i].real_mast == 4 && t[i - 1].real_mast == 4)) {
            cout << number[t[i - 1].real_number - 6] << " " << mast[t[i - 1].real_mast] << endl;
            cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] << endl;
            cout << endl;
        }
    }
}

void find_mast(vector<karta>& t)
{
    int i;
    for(i = 1; i < 36; i++) {
        if (t[i].real_number == t[i-1].real_number) {
            cout << number[t[i - 1].real_number - 6] << " " << mast[t[i - 1].real_mast] << endl;
            cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] << endl;
            cout << endl;
        }
    }
}

void find_dama(vector<karta>& t)
{
    int i;
    for(i = 0; i < 36; i++) {
        if (t[i].real_number == 12 && t[i].real_mast == 3) {
            cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] <<"��������� � ������ �� " << i + 1 << "-�� �����" << endl;
            break;
        }
    }
}

void print_ace(vector<karta>& t)
{
    int i;
    for(i = 0; i < 36; i++) {
        if (t[i].real_number == 14 && t[i].real_mast == 0) {
            cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] <<" ��������� � ������ �� " << i + 1 << "-�� �����" << endl;
        }
        if (t[i].real_number == 14 && t[i].real_mast == 1) {
            cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] <<" ��������� � ������ �� " << i + 1 << "-�� �����" << endl;
        }
        if (t[i].real_number == 14 && t[i].real_mast == 2) {
            cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] <<" ��������� � ������ �� " << i + 1 << "-�� �����" << endl;
        }
        if (t[i].real_number == 14 && t[i].real_mast == 3) {
            cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] <<" ��������� � ������ �� " << i + 1 << "-�� �����" << endl;
        }
    }
}

void print_koloda(vector<karta>& t)
{
    int i;
    for(i = 0; i < 36; i++) {
        cout << number[t[i].real_number - 6] << " " << mast[t[i].real_mast] << endl;;
    }
}