#pragma comment(linker, "/STACK:5000000")
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const vector<int> Bit0 = {0};
const vector<int> Bit1 = {1};
const vector<int> Bit2 = {0, 1};

/*
Chuyen chuoi Hex sang chuoi Binary
Input:	1 string ( chuoi Hex ) ( strHex ).
Output: 1 vector ( chuoi Binary ).
*/
vector<int> convertHexToBinary(string strHex)
{
    vector<int> arrBit;
    for (int i = 0; i < strHex.length(); i++)
    {
        switch (strHex[i])
        {
        case '0':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '1':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '2':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '3':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '4':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case '5':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case '6':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case '7':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case '8':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case '9':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case 'A':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case 'B':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case 'C':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case 'D':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case 'E':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case 'F':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        }
    }
    while (arrBit[arrBit.size() - 1] == 0 && arrBit.size() > 1)
    {
        arrBit.pop_back();
    }
    return arrBit;
}

/*
Chuyen chuoi Binary sang chuoi Hex
Input:	1 vector ( chuoi Binary ) ( arrBit ).
Output: 1 string ( chuoi Hex ).
*/
string convertBinaryToHex(vector<int> arrBit)
{
    string strHex;
    while (arrBit.size() % 4 != 0)
    {
        arrBit.push_back(0);
    }
    for (int i = 3; i < arrBit.size(); i += 4)
    {
        if (arrBit[i] == 0 && arrBit[i - 1] == 0 && arrBit[i - 2] == 0 && arrBit[i - 3] == 0)
            strHex += "0";
        if (arrBit[i] == 0 && arrBit[i - 1] == 0 && arrBit[i - 2] == 0 && arrBit[i - 3] == 1)
            strHex += "1";
        if (arrBit[i] == 0 && arrBit[i - 1] == 0 && arrBit[i - 2] == 1 && arrBit[i - 3] == 0)
            strHex += "2";
        if (arrBit[i] == 0 && arrBit[i - 1] == 0 && arrBit[i - 2] == 1 && arrBit[i - 3] == 1)
            strHex += "3";
        if (arrBit[i] == 0 && arrBit[i - 1] == 1 && arrBit[i - 2] == 0 && arrBit[i - 3] == 0)
            strHex += "4";
        if (arrBit[i] == 0 && arrBit[i - 1] == 1 && arrBit[i - 2] == 0 && arrBit[i - 3] == 1)
            strHex += "5";
        if (arrBit[i] == 0 && arrBit[i - 1] == 1 && arrBit[i - 2] == 1 && arrBit[i - 3] == 0)
            strHex += "6";
        if (arrBit[i] == 0 && arrBit[i - 1] == 1 && arrBit[i - 2] == 1 && arrBit[i - 3] == 1)
            strHex += "7";
        if (arrBit[i] == 1 && arrBit[i - 1] == 0 && arrBit[i - 2] == 0 && arrBit[i - 3] == 0)
            strHex += "8";
        if (arrBit[i] == 1 && arrBit[i - 1] == 0 && arrBit[i - 2] == 0 && arrBit[i - 3] == 1)
            strHex += "9";
        if (arrBit[i] == 1 && arrBit[i - 1] == 0 && arrBit[i - 2] == 1 && arrBit[i - 3] == 0)
            strHex += "A";
        if (arrBit[i] == 1 && arrBit[i - 1] == 0 && arrBit[i - 2] == 1 && arrBit[i - 3] == 1)
            strHex += "B";
        if (arrBit[i] == 1 && arrBit[i - 1] == 1 && arrBit[i - 2] == 0 && arrBit[i - 3] == 0)
            strHex += "C";
        if (arrBit[i] == 1 && arrBit[i - 1] == 1 && arrBit[i - 2] == 0 && arrBit[i - 3] == 1)
            strHex += "D";
        if (arrBit[i] == 1 && arrBit[i - 1] == 1 && arrBit[i - 2] == 1 && arrBit[i - 3] == 0)
            strHex += "E";
        if (arrBit[i] == 1 && arrBit[i - 1] == 1 && arrBit[i - 2] == 1 && arrBit[i - 3] == 1)
            strHex += "F";
    }
    return strHex;
}

/*
Kiem tra chuoi Hex co phai la 2 hoac la 3 khong ?
*	Mo rong:	Kiem tra co phai la 0 hoac 1 khong ?
Input:	1 string ( chuoi Hex ) ( strHex ).
Output:	1 trong 3 gia tri ( 0, 1, 2 ).
        *	1:	Chuoi Hex la 2 hoac la 3.
        *	2:	Chuoi Hex la 0 hoac la 1.
        *	0:	Chuoi Hex khong thuoc cac truong hop tren.
*/
int isNumber2or3(string strHex)
{
    if (strHex.length() != 1)
        return 0;
    if (strHex == "0" || strHex == "1")
        return 2;
    if (strHex == "2" || strHex == "3")
        return 1;
    return 0;
}

/*
Kiem tra chuoi Hex co phai la so chan khong ?
Input:	1 string ( chuoi Hex ) ( strHex ).
Output:	True hoac False.
        *	True:	Chuoi Hex la 1 so chan.
        *	False:	Chuoi Hex la 1 so le.
*/
bool isEvenNumber(string strHex)
{
    char tempStrHex = strHex[0];
    if (tempStrHex == '0' || tempStrHex == '2' || tempStrHex == '4' || tempStrHex == '6' || tempStrHex == '8' || tempStrHex == 'A' || tempStrHex == 'C' || tempStrHex == 'E')
        return true;
    return false;
}

/*
So sanh 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
Output:	1 trong 3 gia tri ( 0, 1, 2 ).
        *	1  :	a > b.
        *	-1 :	a < b.
        *	0  :	a = b.
*/
int compareBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
    if (arrBit1.size() != arrBit2.size())
    {
        if (arrBit1.size() > arrBit2.size())
            return 1;
        else
            return -1;
    }
    for (int i = arrBit1.size() - 1; i >= 0; i--)
    {
        if (arrBit1[i] > arrBit2[i])
            return 1;
        if (arrBit1[i] < arrBit2[i])
            return -1;
    }
    return 0;
}

/*
Tim s va r trong:
n - 1 = ( 2 ^ s ) * r. Voi r la 1 so le.

Input:	1 vector ( chuoi Binary ) ( arrBitN ), 1 so nguyen ( s )
        , 1 vector ( chuoi Binary ) ( arrBitR ).
Output:	Ket qua khong tra truc tiep ve ma thong qua 2 bien ( s ) va ( arrBitR ).
*/
void findSandR(vector<int> arrBitN, int &s, vector<int> &arrBitR)
{
    s = 0;
    vector<int> tempArrBit = arrBitN;
    tempArrBit[0] = 0;
    while (tempArrBit[0] == 0)
    {
        s++;
        tempArrBit.erase(tempArrBit.begin());
    }
    arrBitR = tempArrBit;
}

/*
Cong 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> addBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
    vector<int> arrBitResult;
    int carry = 0;
    if (arrBit1.size() == 0)
        return arrBit2;
    if (arrBit2.size() == 0)
        return arrBit1;

    while (arrBit1.size() != arrBit2.size())
    {
        if (arrBit1.size() > arrBit2.size())
            arrBit2.push_back(0);
        else
            arrBit1.push_back(0);
    }
    for (int i = 0; i < arrBit1.size(); i++)
    {
        arrBitResult.push_back((arrBit1[i] + arrBit2[i] + carry) % 2);
        if (arrBit1[i] + arrBit2[i] + carry >= 2)
            carry = 1;
        else
            carry = 0;
    }
    if (carry == 1)
        arrBitResult.push_back(1);
    while (arrBitResult[arrBitResult.size() - 1] == 0 && arrBitResult.size() > 1)
    {
        arrBitResult.pop_back();
    }
    return arrBitResult;
}

/*
Nhan 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> mulBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
    vector<int> arrBitResult;
    vector<int> tempArrBit2 = arrBit2;

    if (compareBigNum(Bit2, arrBit1) == 0)
    {
        arrBit2.insert(arrBit2.begin(), 0);
        return arrBit2;
    }
    else
    {
        if (compareBigNum(Bit2, arrBit2) == 0)
        {
            arrBit1.insert(arrBit1.begin(), 0);
            return arrBit1;
        }
    }

    for (int i = 0; i < arrBit1.size(); i++)
    {
        if (i != 0)
        {
            tempArrBit2.insert(tempArrBit2.begin(), 0);
        }
        if (arrBit1[i] == 1)
        {
            arrBitResult = addBigNum(arrBitResult, tempArrBit2);
        }
    }
    return arrBitResult;
}

/*
Tru 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> subBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
    vector<int> arrBitResult;
    int carry = 0;
    int tempCarry = 0;
    while (arrBit1.size() != arrBit2.size())
    {
        if (arrBit1.size() > arrBit2.size())
            arrBit2.push_back(0);
        else
            arrBit1.push_back(0);
    }
    for (int i = 0; i < arrBit1.size(); i++)
    {
        if (arrBit1[i] >= arrBit2[i] + carry)
        {
            arrBitResult.push_back(arrBit1[i] - (arrBit2[i] + carry));
            carry = 0;
        }
        else
        {
            if (arrBit1[i] - (arrBit2[i] + carry) == -1)
            {
                arrBitResult.push_back(1);
                carry = 1;
            }
            else
            {
                arrBitResult.push_back(0);
                carry = 1;
            }
        }
    }
    while (arrBitResult[arrBitResult.size() - 1] == 0 && arrBitResult.size() > 1)
    {
        arrBitResult.pop_back();
    }
    return arrBitResult;
}

/*
Chia 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 )
        , 1 vector ( chuoi Binary ) ( arrBit3 ), 1 vector ( chuoi Binary ) ( arrBit4 ).
Output:	Ket qua khong tra truc tiep ve ma thong qua 2 bien ( arrBit3 ) va ( arrBit4 ).
        *	arrBit3: Phan nguyen.
        *	arrBit4: Phan du.
*/
void divBigNum(vector<int> arrBit1, vector<int> arrBit2, vector<int> &arrBit3, vector<int> &arrBit4)
{
    arrBit3.clear();
    arrBit4.clear();
    vector<int> tempArrBit1 = arrBit1;
    vector<int> tempArrBit2 = arrBit2;
    if (compareBigNum(tempArrBit1, tempArrBit2) == -1)
    {
        arrBit3 = Bit0;
        arrBit4 = tempArrBit1;
        return;
    }
    if (compareBigNum(arrBit2, Bit2) == 0)
    {
        if (tempArrBit1[0] == 0)
        {
            tempArrBit1.erase(tempArrBit1.begin());
            arrBit3 = tempArrBit1;
            arrBit4 = Bit0;
            return;
        }
        else
        {
            tempArrBit1.erase(tempArrBit1.begin());
            arrBit3 = tempArrBit1;
            arrBit4 = Bit1;
            return;
        }
    }

    while (compareBigNum(tempArrBit1, tempArrBit2) != -1)
    {
        tempArrBit2.insert(tempArrBit2.begin(), 0);
    }
    tempArrBit2.erase(tempArrBit2.begin());
    arrBit3.push_back(1);
    tempArrBit1 = subBigNum(tempArrBit1, tempArrBit2);

    while (tempArrBit2.size() > arrBit2.size())
    {
        tempArrBit2.erase(tempArrBit2.begin());
        if (compareBigNum(tempArrBit1, tempArrBit2) == -1)
        {
            arrBit3.insert(arrBit3.begin(), 0);
        }
        else
        {
            arrBit3.insert(arrBit3.begin(), 1);
            tempArrBit1 = subBigNum(tempArrBit1, tempArrBit2);
        }
    }
    arrBit4 = tempArrBit1;
}

/*
Tao 1 so nguyen lon tu A den B
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> genArrBit(vector<int> &arrBit1, vector<int> &arrBit2)
{
    vector<int> arrBitResult;
    srand(time(NULL));
    int len;
    if (arrBit2.size() - arrBit1.size() == 0)
        len = arrBit1.size();
    else
        len = (rand() % (arrBit2.size() - arrBit1.size())) + arrBit1.size();
    do
    {
        arrBitResult.clear();
        for (int j = 0; j < len; j++)
        {
            arrBitResult.push_back(rand() % 2);
        }
        while (arrBitResult[arrBitResult.size() - 1] == 0 && arrBitResult.size() > 1)
        {
            arrBitResult.pop_back();
        }
    } while (compareBigNum(arrBitResult, arrBit1) < 0 || compareBigNum(arrBitResult, arrBit2) > 0);
    return arrBitResult;
}

/*
Nhan binh phuong co lap:
    y = ( a ^ r ) mod n. Voi a < n
Input:	1 vector ( chuoi Binary ) ( arrBitA ), 1 vector ( chuoi Binary ) ( arrBitN )
        , 1 vector ( chuoi Binary ) ( arrBitR ), 1 vector ( chuoi Binary ) ( arrBitY ).
Output:	Ket qua khong tra truc tiep ve ma thong qua bien ( arrBitY ).
*/
void iterativeSquaring(vector<int> arrBitA, vector<int> arrBitN, vector<int> arrBitR, vector<int> &arrBitY)
{
    vector<int> tempArrBitA;
    vector<int> tempArrBitB;
    vector<int> tempArrBit;
    if (compareBigNum(arrBitA, Bit0) == 0 || compareBigNum(arrBitA, arrBitR) == 0)
    {
        arrBitY = Bit0;
        return;
    }
    if (compareBigNum(arrBitR, Bit0) == 0)
    {
        arrBitY = Bit1;
        return;
    }

    tempArrBitA = arrBitA;
    tempArrBitB.push_back(1);

    if (arrBitR[0] == 1)
        tempArrBitB = arrBitA;

    for (int i = 1; i < arrBitR.size(); i++)
    {
        divBigNum(mulBigNum(tempArrBitA, tempArrBitA), arrBitN, tempArrBit, tempArrBitA);
        if (arrBitR[i] == 1 && i != 0)
            divBigNum(mulBigNum(tempArrBitA, tempArrBitB), arrBitN, tempArrBit, tempArrBitB);
    }

    while (tempArrBitB[tempArrBitB.size() - 1] == 0 && tempArrBitB.size() > 1)
    {
        tempArrBitB.pop_back();
    }
    arrBitY = tempArrBitB;
}

/*
Kiem tra N co phai la so nguyen to khong ? ( voi so lan t nhat dinh )
Input:	1 vector ( chuoi Binary ) ( arrBit1 ),  1 so nguyen ( t ).
Output:	True hoac False.
        *	True:	La so nguyen to.
        *	False:	Khong phai so nguyen to.
*/
bool millerRabin(vector<int> arrBitN, int t)
{
    vector<int> tempArrBit;
    vector<int> tempArrBitN;
    vector<int> arrBitR;

    vector<int> tempArrBit2 = Bit2;
    vector<int> tempArrBitNSub2 = subBigNum(arrBitN, Bit2);
    int s = 0;
    tempArrBit.push_back(1);
    tempArrBitN = subBigNum(arrBitN, tempArrBit);
    findSandR(tempArrBitN, s, arrBitR);
    for (int i = 1; i <= t; i++)
    {
        vector<int> arrBitA;
        vector<int> arrBitY;
        arrBitA = genArrBit(tempArrBit2, tempArrBitNSub2);
        iterativeSquaring(arrBitA, arrBitN, arrBitR, arrBitY);
        if (compareBigNum(arrBitY, tempArrBit) != 0 && compareBigNum(arrBitY, tempArrBitN) != 0)
        {
            int j = 1;
            vector<int> tempArrBit2 = Bit2;
            while (j <= s - 1 && compareBigNum(arrBitY, tempArrBitN) != 0)
            {
                iterativeSquaring(arrBitY, arrBitN, tempArrBit2, arrBitY);
                if (compareBigNum(arrBitY, tempArrBit) == 0)
                    return false;
                j++;
            }
            if (compareBigNum(arrBitY, tempArrBitN) != 0)
                return false;
        }
    }
    return true;
}

/*
Ham tim uoc chung lon nhat giua 2 so nguyen lon A va B theo thuat toan Euclid
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> euclidean(vector<int> arrBit1, vector<int> arrBit2)
{
    if (compareBigNum(arrBit2, Bit0) == 0)
    {
        return arrBit1;
    }
    else
    {
        vector<int> tempArrBit1;
        vector<int> tempArrBit2;
        divBigNum(arrBit1, arrBit2, tempArrBit1, tempArrBit2);
        tempArrBit1.clear();
        return euclidean(arrBit2, tempArrBit2);
    }
}

/*
Ham Euclid mo rong
    *	C = ( A ^ -1 ) mod B.
    *	D = ( B ^ -1 ) mod A.
Input:	1 vector ( chuoi Binary ) ( arrBitA ), 1 vector ( chuoi Binary ) ( arrBitB ),
        , 1 vector ( chuoi Binary ) ( arrBitC ), 1 vector ( chuoi Binary ) ( arrBitD ),
Output:	Ket qua khong tra truc tiep ve ma thong qua 2 bien ( arrBitC ) va ( arrBitD ).
*/
void extendedEuclidean(vector<int> arrBitA, vector<int> arrBitB, vector<int> &arrBitC, vector<int> &arrBitD)
{
    vector<int> tempArrBit1;
    vector<int> tempArrBit2;
    vector<vector<int>> rawDefault0 = {Bit0, Bit0, Bit0, Bit0, Bit1, Bit1};
    vector<vector<int>> rawMinus1 = {arrBitB, Bit0, Bit0, Bit1, Bit1, Bit1};
    vector<vector<vector<int>>> table;
    table.push_back({arrBitA, Bit0, Bit1, Bit0, Bit1, Bit1});

    divBigNum(arrBitB, arrBitA, tempArrBit1, tempArrBit2);
    table.push_back({tempArrBit2, tempArrBit1, Bit0, Bit0, Bit1, Bit1});
    if (compareBigNum(rawMinus1[2], mulBigNum(table[1][1], table[0][2])) == -1)
    {
        table[1][2] = subBigNum(mulBigNum(table[1][1], table[0][2]), rawMinus1[2]);
        table[1][4] = Bit0;
    }
    else
    {
        table[1][2] = subBigNum(rawMinus1[2], mulBigNum(table[1][1], table[0][2]));
    }

    if (compareBigNum(rawMinus1[3], mulBigNum(table[1][1], table[0][3])) == -1)
    {
        table[1][3] = subBigNum(mulBigNum(table[1][1], table[0][3]), rawMinus1[3]);
        table[1][5] = Bit0;
    }
    else
    {
        table[1][3] = subBigNum(rawMinus1[3], mulBigNum(table[1][1], table[0][3]));
    }

    while (compareBigNum(table[table.size() - 1][0], Bit0) != 0)
    {
        table.push_back(rawDefault0);
        divBigNum(table[table.size() - 3][0], table[table.size() - 2][0], tempArrBit1, tempArrBit2);
        table[table.size() - 1][0] = tempArrBit2;
        table[table.size() - 1][1] = tempArrBit1;
    }

    tempArrBit1.clear();
    tempArrBit2.clear();

    for (int i = 2; i < table.size(); i++)
    {
        tempArrBit1 = mulBigNum(table[i][1], table[i - 1][2]);
        tempArrBit2 = mulBigNum(table[i][1], table[i - 1][3]);

        if (compareBigNum(table[i - 2][4], Bit1) == 0 && compareBigNum(table[i - 1][4], Bit1) == 0)
        {
            if (compareBigNum(table[i - 2][2], tempArrBit1) == -1)
            {
                table[i][2] = subBigNum(tempArrBit1, table[i - 2][2]);
                table[i][4] = Bit0;
            }
            else
            {
                table[i][2] = subBigNum(table[i - 2][2], tempArrBit1);
            }
        }
        else
        {
            if (compareBigNum(table[i - 2][4], Bit1) == 0 && compareBigNum(table[i - 1][4], Bit0) == 0)
            {
                table[i][2] = addBigNum(table[i - 2][2], tempArrBit1);
            }
            else
            {
                if (compareBigNum(table[i - 2][4], Bit0) == 0 && compareBigNum(table[i - 1][4], Bit1) == 0)
                {
                    table[i][2] = addBigNum(table[i - 2][2], tempArrBit1);
                    table[i][4] = Bit0;
                }
                else
                {
                    if (compareBigNum(table[i - 2][2], tempArrBit1) == -1)
                    {
                        table[i][2] = subBigNum(tempArrBit1, table[i - 2][2]);
                    }
                    else
                    {
                        table[i][2] = subBigNum(table[i - 2][2], tempArrBit1);
                        table[i][4] = Bit0;
                    }
                }
            }
        }

        if (compareBigNum(table[i - 2][5], Bit1) == 0 && compareBigNum(table[i - 1][5], Bit1) == 0)
        {
            if (compareBigNum(table[i - 2][3], tempArrBit2) == -1)
            {
                table[i][3] = subBigNum(tempArrBit2, table[i - 2][3]);
                table[i][5] = Bit0;
            }
            else
            {
                table[i][3] = subBigNum(table[i - 2][3], tempArrBit2);
            }
        }
        else
        {
            if (compareBigNum(table[i - 2][5], Bit1) == 0 && compareBigNum(table[i - 1][5], Bit0) == 0)
            {
                table[i][3] = addBigNum(table[i - 2][3], tempArrBit2);
            }
            else
            {
                if (compareBigNum(table[i - 2][5], Bit0) == 0 && compareBigNum(table[i - 1][5], Bit1) == 0)
                {
                    table[i][3] = addBigNum(table[i - 2][3], tempArrBit2);
                    table[i][5] = Bit0;
                }
                else
                {
                    if (compareBigNum(table[i - 2][3], tempArrBit2) == -1)
                    {
                        table[i][3] = subBigNum(tempArrBit2, table[i - 2][3]);
                    }
                    else
                    {
                        table[i][3] = subBigNum(table[i - 2][3], tempArrBit2);
                        table[i][5] = Bit0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < table.size(); i++)
    {
        if (compareBigNum(table[i][0], Bit1) == 0)
        {
            if (compareBigNum(table[i][4], Bit1) == 0)
            {
                arrBitC = table[i][2];
            }
            else
            {
                arrBitC = subBigNum(arrBitB, table[i][2]);
            }

            if (compareBigNum(table[i][5], Bit1) == 0)
            {
                arrBitD = table[i][3];
            }
            else
            {
                arrBitD = subBigNum(arrBitA, table[i][3]);
            }
        }
    }
}

int main()
{
    string strHex;
    vector<int> arrBitN;
    vector<int> arrBitK;
    vector<int> arrBitX;
    vector<int> arrBitY;

    string nameFile = "test";

    ifstream in;
    in.open(nameFile + ".inp");
    ofstream out;
    out.open(nameFile + ".out");

    in >> strHex;
    arrBitN = convertHexToBinary(strHex);

    in >> strHex;
    arrBitK = convertHexToBinary(strHex);

    in >> strHex;
    arrBitX = convertHexToBinary(strHex);

    iterativeSquaring(arrBitX, arrBitN, arrBitK, arrBitY);

    strHex = convertBinaryToHex(arrBitY);

    out << strHex;

    return 0;
}