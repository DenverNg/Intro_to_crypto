#pragma comment(linker, "/STACK:5000000")
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
using namespace std;

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

string binaryToHex(const vector<int> &bin)
{
    const char hexDigits[] = "0123456789ABCDEF";
    string hex;
    int value = 0;
    int bits = 0;
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        value += bin[i] << bits;
        bits++;
        if (bits == 4)
        {
            hex = hexDigits[value] + hex;
            value = 0;
            bits = 0;
        }
    }
    if (bits > 0)
    {
        hex = hexDigits[value] + hex;
    }
    return hex;
}

void printBinary(const vector<int> &bin)
{
    for (int bit : bin)
    {
        cout << bit;
    }
    cout << " = ";
    // convert to decimal
    int dec = 0;
    for (int i = 0; i < bin.size(); i++)
    {
        dec += bin[i] * (1 << (bin.size() - i - 1));
    }
    cout << dec << endl;
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
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i] ? 1 : -1;
        }
    }
    return 0;
}

void divideBinaryNumbers(const vector<int> &dividend, const vector<int> &divisor,
                         vector<int> &quotient, vector<int> &remainder)
{
    // Khởi tạo giá trị ban đầu
    remainder.clear();
    quotient.clear();

    // Lặp qua từng bit của dividend
    for (size_t i = 0; i < dividend.size(); ++i)
    {
        // Đưa bit tiếp theo vào remainder
        remainder.push_back(dividend[i]);
        // Xóa các bit 0 thừa ở đầu remainder
        while (remainder.size() > 1 && remainder[0] == 0)
        {
            remainder.erase(remainder.begin());
        }

        // Kiểm tra nếu remainder >= divisor
        if (compareTwoBinaryNumbers(remainder, divisor) >= 0)
        {
            remainder = subTwoBinaryNumbers(remainder, divisor); // remainder -= divisor
            quotient.push_back(1);                               // Thêm 1 vào quotient
        }
        else
        {
            quotient.push_back(0); // Thêm 0 vào quotient
        }
    }

    // Xóa các bit 0 thừa ở đầu quotient
    while (quotient.size() > 1 && quotient[0] == 0)
    {
        quotient.erase(quotient.begin());
    }
}

vector<int> modBinary(const vector<int> &binaryNum, const vector<int> &mod)
{
    vector<int> remainder, quotient;
    divideBinaryNumbers(binaryNum, mod, quotient, remainder); // Chia lấy dư
    return remainder;
}

vector<int> modMultiply(const vector<int> &num1, const vector<int> &num2, const vector<int> &mod)
{
    vector<int> product = {0};                        // Kết quả ban đầu bằng 0
    vector<int> moddedBinNum1 = modBinary(num1, mod); // num1 % mod
                                                      // vector<int> moddedBinNum1 = num1;
    vector<int> currentMultiplier = num2;             // Sao chép num2 để xử lý

    // Lặp qua từng bit của num2
    while (!currentMultiplier.empty())
    {
        // Nếu bit cuối cùng của currentMultiplier bằng 1
        if (currentMultiplier.back() == 1)
        {
            product = addTwoBinaryNumbers(product, moddedBinNum1); // product += moddedBinNum1

            // Nếu product >= mod, thực hiện modulo
            if (compareTwoBinaryNumbers(product, mod) >= 0)
            {
                product = subTwoBinaryNumbers(product, mod);
            }
        }

        // Dịch trái moddedBinNum1 (tương đương nhân 2)
        moddedBinNum1.push_back(0);

        // Nếu moddedBinNum1 >= mod, thực hiện modulo
        if (compareTwoBinaryNumbers(moddedBinNum1, mod) >= 0)
        {
            moddedBinNum1 = subTwoBinaryNumbers(moddedBinNum1, mod);
        }

        // Loại bỏ bit cuối cùng của currentMultiplier
        currentMultiplier.pop_back();
    }

    return product;
}

// Hàm tính lũy thừa modulo
vector<int> modExponentiate(const vector<int> &base, const vector<int> &exp, const vector<int> &mod)
{
    vector<int> result = {1}; // Đại diện nhị phân cho số 1
    vector<int> temp = mod;
    for (size_t i = 0; i < exp.size(); i++)
    {
        result = modMultiply(result, result, mod);
        if (exp[i] == 1)
        {
            result = modMultiply(result, base, mod);
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
    vector<int> numMinusOne;
    for (int i = 0; i < d.size(); i++)
    {
        numMinusOne.push_back(d[i]);
    }
    int s = 0;

    // Tách num-1 thành dạng d * 2^s
    while (!d.empty() && d.back() == 0)
    {
        d.pop_back();
        ++s;
    }
    // Lặp lại kiểm tra theo số lần `iterations`
    vector<int> base;
    for (int i = 0; i < iterations; ++i)
    {
        // Sinh cơ số ngẫu nhiên
        vector<int> base = generateRandomBase(num);
        // Tính x = base^d mod num
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
    
    string p, g, a, b;
    in >> p >> g >> a >> b;

    vector<int> pBin = convertHexToBinary(p);
    vector<int> gBin = convertHexToBinary(g);
    vector<int> aBin = convertHexToBinary(a);
    vector<int> bBin = convertHexToBinary(b);
    cout << "p = "; printBinary(pBin);
    cout << "g = "; printBinary(gBin);
    cout << "a = "; printBinary(aBin);
    cout << "b = "; printBinary(bBin);

    vector<int> K = modExponentiate(modExponentiate(gBin, aBin, pBin), bBin, pBin);

    out << binaryToHex(K) << endl;

    cout << "Result is written to " << outputFile << endl;
    in.close();
    out.close();
    return 0;
}