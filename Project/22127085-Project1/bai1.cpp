#pragma comment(linker, "/STACK:5000000")
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
using namespace std;

const vector<int> Bit0 = {0};
const vector<int> Bit1 = {1};
const vector<int> Bit2 = {0, 1};

/*
Chuyen chuoi Hex sang chuoi Binary
Input:	1 string ( chuoi Hex ) ( strHex ).
Output: 1 vector ( chuoi Binary ).
*/

long long convertBinToDec(vector<int> &arr)
{
    long long res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res = res * 2 + arr[i];
    }
    return res;
}

vector<int> convertHexToBinary(string &strHex)
{
    vector<int> arrBit = {};
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
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case '2':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case '3':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case '4':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '5':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
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
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case '8':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
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
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case 'B':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case 'C':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case 'D':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case 'E':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
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
        default:
            throw "Invalid hex string";
        }
    }
    while (arrBit.size() > 1 && arrBit[0] == 0)
    {
        arrBit.erase(arrBit.begin());
    }
    return arrBit;
}

// Hàm cộng hai số nhị phân
vector<int> addTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    // Tạo bản sao của các vector để không ảnh hưởng đến tham số gốc
    vector<int> num1 = a;
    vector<int> num2 = b;

    // Bổ sung các bit 0 vào cuối để hai số có độ dài bằng nhau
    while (num1.size() < num2.size())
    {
        num1.insert(num1.begin(), 0); // Chèn bit 0 vào đầu num1
    }
    while (num2.size() < num1.size())
    {
        num2.insert(num2.begin(), 0); // Chèn bit 0 vào đầu num2
    }

    vector<int> result(num1.size() + 1, 0); // Thêm 1 để dự phòng carry
    int carry = 0;                          // Biến lưu giá trị nhớ

    // Cộng từ đáy lên
    for (int i = num1.size() - 1; i >= 0; --i)
    {
        int sum = num1[i] + num2[i] + carry; // Tổng hai bit và carry
        result[i + 1] = sum % 2;             // Lấy bit kết quả (0 hoặc 1)
        carry = sum / 2;                     // Tính carry mới
    }

    // Xử lý carry ở bit cao nhất
    result[0] = carry;

    // Loại bỏ các bit 0 thừa phía trước nếu cần
    while (result.size() > 1 && result[0] == 0)
    {
        result.erase(result.begin());
    }

    return result;
}
// Hàm trừ hai số nhị phân (a >= b)
vector<int> subTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(a.size(), 0); // Kết quả có cùng kích thước với `a`
    int borrow = 0;

    int i = a.size() - 1; // Con trỏ bit cuối của `a`
    int j = b.size() - 1; // Con trỏ bit cuối của `b`

    // Thực hiện trừ từng bit
    while (i >= 0)
    {
        int bitA = a[i];                // Bit từ `a`
        int bitB = (j >= 0) ? b[j] : 0; // Bit từ `b` (nếu vượt ngoài chỉ số thì xem như 0)

        // Tính bit kết quả và cập nhật borrow
        int diff = bitA - bitB - borrow;
        if (diff < 0)
        {
            diff += 2;  // Mượn từ bit cao hơn
            borrow = 1; // Đánh dấu mượn
        }
        else
        {
            borrow = 0;
        }

        result[i] = diff; // Lưu bit kết quả
        i--;
        j--;
    }

    // Loại bỏ các bit 0 thừa phía trước nếu cần
    while (result.size() > 1 && result[0] == 0)
    {
        result.erase(result.begin());
    }

    return result;
}

// So sánh hai số nhị phân
// Trả về 1 nếu a > b, -1 nếu a < b, 0 nếu a = b
int compareTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size())
    {
        return a.size() > b.size() ? 1 : -1;
    }
    for (int i = a.size() - 1; i >= 0; --i)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i] ? 1 : -1;
        }
    }
    return 0;
}

// vector<int> modBinaryNumber(const vector<int> &num, const vector<int> &mod)
// {
//     vector<int> remainder = num;
//     cout << "Compare: " << compareTwoBinaryNumbers(remainder, mod) << endl;
//     while (compareTwoBinaryNumbers(remainder, mod) >= 0)
//     {
//         remainder = subTwoBinaryNumbers(remainder, mod);
//     }
//     cout << "remainder = " << convertBinToDec(remainder) << endl;

//     return remainder;
// }

// // Hàm nhân hai số nhị phân với modulo
// vector<int> modMultiply(const vector<int> &num1, const vector<int> &num2, const vector<int> &mod)
// {
//     // Đặt x = num1 mod mod
//     vector<int> x = modBinaryNumber(num1, mod); // Hàm tính số dư: x = num1 % mod
//     vector<int> P = {0};                        // P ban đầu bằng 0
//     vector<int> y = num2;

//     // Xử lý trường hợp y[0] > 0 (bit thấp nhất của y)
//     if (!y.empty() && y.back() == 1)
//     {
//         P = x;
//     }

//     // Lặp qua từng bit của y
//     while (!y.empty())
//     {
//         // a. x = (2 * x) mod mod
//         x.push_back(0); // Nhân x với 2 bằng cách thêm 1 bit 0 ở cuối
//         if (compareTwoBinaryNumbers(x, mod) >= 0)
//         {
//             x = subTwoBinaryNumbers(x, mod); // Giảm x nếu x >= mod
//         }

//         // b. Tính P = (P + y_i * x) mod mod
//         y.pop_back();                    // Loại bỏ bit thấp nhất (đã xử lý)
//         if (!y.empty() && y.back() == 1) // Nếu bit tiếp theo của y là 1
//         {
//             P = addTwoBinaryNumbers(P, x);
//             if (compareTwoBinaryNumbers(P, mod) >= 0)
//             {
//                 P = subTwoBinaryNumbers(P, mod);
//             }
//         }
//     }

//     return P; // Trả về kết quả
// }

vector<int> modMultiply(const vector<int> &num1, const vector<int> &num2, const vector<int> &mod)
{
    vector<int> res = {0};
    vector<int> tempA = num1;
    vector<int> tempB = num2;
    while (!tempB.empty())
    {
        if (tempB.back() == 1)
        {
            res = addTwoBinaryNumbers(res, tempA);
            cout << "\nres + tempA = " << convertBinToDec(res) << endl;
            if (compareTwoBinaryNumbers(res, mod) >= 0)
            {
                res = subTwoBinaryNumbers(res, mod);
            }
            cout << "res mod mod = " << convertBinToDec(res) << endl;
        }
        tempA.push_back(0);
        if (compareTwoBinaryNumbers(tempA, mod) >= 0)
        {
            tempA = subTwoBinaryNumbers(tempA, mod);
        }
        tempB.pop_back();
    }
    return res;
}

// Hàm tính lũy thừa modulo
vector<int> modExponentiate(const vector<int> &base, const vector<int> &exp, const vector<int> &mod)
{
    vector<int> result = {1}; // Đại diện nhị phân cho số 1
    vector<int> temp = mod;
    for (size_t i = 0; i < exp.size(); ++i)
    {
        cout <<"(" << exp[i]<< ") "<< convertBinToDec(result) << " * " << convertBinToDec(result) << " mod " << convertBinToDec(temp) << " = ";
        result = modMultiply(result, result, mod);
        cout << convertBinToDec(result) << endl;
        if (exp[i] == 1)
        {
            result = modMultiply(result, base, mod);
        }
        if (i==2)
        {
            break;
        }
    }
    return result;
}

vector<int> generateRandomBase(const vector<int> &num)
{
    // num phải lớn hơn 3 để tồn tại giá trị ngẫu nhiên trong [2, num-2]
    if (compareTwoBinaryNumbers(num, {1, 1}) <= 0)
    {
        throw "Input number must be greater than 3 to generate a valid base.";
    }

    // Chuẩn bị giá trị min = 2 và max = num - 2
    vector<int> min = {1, 0};                           // 2
    vector<int> max = subTwoBinaryNumbers(num, {1, 0}); // num - 2

    // Sinh số ngẫu nhiên nhị phân
    vector<int> randomBase;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);

    do
    {
        randomBase.clear();
        for (size_t i = 0; i < max.size(); ++i)
        {
            randomBase.push_back(distrib(gen));
        }

        // Loại bỏ các số 0 thừa phía trước
        while (randomBase.size() > 1 && randomBase[0] == 0)
        {
            randomBase.erase(randomBase.begin());
        }

    } while (compareTwoBinaryNumbers(randomBase, min) < 0 || compareTwoBinaryNumbers(randomBase, max) > 0);

    return randomBase;
}

// Kiểm tra Miller-Rabin và xác định số nguyên tố
bool millerRabin(const vector<int> &num, int iterations)
{
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i];
    }
    // Nếu num < 2 thì không phải số nguyên tố
    if (compareTwoBinaryNumbers(num, {2}) < 0)
    {
        return false;
    }

    // Nếu num là 2 thì là số nguyên tố
    if (compareTwoBinaryNumbers(num, {2}) == 0)
    {
        return true;
    }

    // Nếu num chẵn thì không phải số nguyên tố
    if (num.back() == 0)
    {
        return false;
    }

    // Chuẩn bị cho kiểm tra Miller-Rabin
    vector<int> d = subTwoBinaryNumbers(num, {1}); // d = num - 1
    vector<int> numMinusOne = d;
    cout << "num - 1 = ";
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i];
    }
    cout << endl;
    int s = 0;

    // Tách num-1 thành dạng d * 2^s
    while (!d.empty() && d.back() == 0)
    {
        d.pop_back();
        ++s;
    }
    cout << "n - 1 = 2^s.d with:" << endl; 
    cout << "s = " << s << endl;
    cout << "d = ";
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i];
    }
    cout << endl;
    // Lặp lại kiểm tra theo số lần `iterations`
    vector<int> base;
    for (int i = 0; i < iterations; ++i)
    {
        // Sinh cơ số ngẫu nhiên
        vector<int> base = generateRandomBase(num);

        cout << "Iteration " << i + 1 << ": Base = ";
        for (int bit : base)
        {
            cout << bit;
        }
        cout << " = " << convertBinToDec(base) << endl;
        // Tính x = base^d mod num
        vector<int> tempNum = num;
        cout << "num = " << convertBinToDec(tempNum) << endl;
        cout << endl;
        cout << "x = base^d mod num = ";
        vector<int> x = modExponentiate(base, d, num);
        // Nếu x == 1 hoặc x == num - 1, tiếp tục kiểm tra
        if (compareTwoBinaryNumbers(x, {1}) == 0 || compareTwoBinaryNumbers(x, numMinusOne) == 0)
        {
            continue;
        }

        // Lặp qua s-1 bước để kiểm tra
        bool found = false;
        for (int j = 1; j < s; ++j)
        {
            cout << "j = " << j << endl;
            x = modMultiply(x, x, num);
            if (compareTwoBinaryNumbers(x, subTwoBinaryNumbers(num, {1})) == 0)
            {
                found = true;
                break;
            }
        }

        // Nếu không thỏa điều kiện, chắc chắn không phải số nguyên tố
        if (!found)
        {
            return false;
        }
    }

    // Nếu qua tất cả kiểm tra, là số nguyên tố
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }
    
    string inputFile = argv[1];
    string outputFile = argv[2];

    if (inputFile.empty() || outputFile.empty())
    {
        cout << "Invalid input/output file" << endl;
        return 1;
    }

    ifstream in(inputFile);
    ofstream out(outputFile);
    string hexString;
    in >> hexString;
    cout << "Hex: " << hexString << endl;

    vector<int> num = convertHexToBinary(hexString);
    cout << "Binary: ";
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i];
    }
    cout << "\n--------------------------------" << endl;
    int time = 1;
    if (num.size() <= 256)
    {
        time = 10;
    }
    else if (num.size() <= 348)
    {
        time = 3;
    }
    else
    {
        time = 2;
    }

    if (millerRabin(num, time))
    {
        out << 1;
        cout << "Prime" << endl;
    }
    else
    {
        out << 0;
        cout << "Composite" << endl;
    }
    in.close();
    out.close();
    return 0;
}