#pragma comment(linker, "/STACK:5000000")
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
using namespace std;

void convertBinToDec(vector<int> arr)
{
    long long res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res = res * 2 + arr[i];
    }
    cout << res << endl;
}

string convertBinaryToHex(const vector<int> &binary)
{
    // Nếu vector nhị phân rỗng, trả về chuỗi rỗng
    if (binary.empty())
        return "";

    // Đảm bảo số lượng bit chia hết cho 4 bằng cách thêm các bit 0 ở đầu
    vector<int> paddedBinary = binary;
    while (paddedBinary.size() % 4 != 0)
    {
        paddedBinary.insert(paddedBinary.begin(), 0);
    }

    string hexResult = "";
    for (size_t i = 0; i < paddedBinary.size(); i += 4)
    {
        int decimalValue = paddedBinary[i] * 8 + paddedBinary[i + 1] * 4 + paddedBinary[i + 2] * 2 + paddedBinary[i + 3];
        if (decimalValue < 10)
        {
            hexResult += (char)('0' + decimalValue); // Chuyển số 0-9
        }
        else
        {
            hexResult += (char)('A' + decimalValue - 10); // Chuyển số 10-15 thành A-F
        }
    }

    return hexResult;
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

vector<int> multiplyBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(a.size() + b.size(), 0); // Kết quả có thể tối đa là tổng độ dài của hai số

    // Lặp qua từng bit của `a`
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int carry = 0; // Giá trị nhớ khi thực hiện nhân từng bit
        for (int j = b.size() - 1; j >= 0; j--)
        {
            // Tính tích của hai bit và cộng vào vị trí thích hợp trong `result`
            int product = a[i] * b[j] + result[i + j + 1] + carry;
            result[i + j + 1] = product % 2; // Lưu kết quả
            carry = product / 2;             // Cập nhật giá trị nhớ
        }
        result[i] += carry; // Cộng carry vào vị trí tiếp theo
    }

    // Loại bỏ các bit 0 thừa ở đầu kết quả nếu cần
    while (result.size() > 1 && result[0] == 0)
    {
        result.erase(result.begin());
    }

    return result;
}

vector<int> modMultiply(const vector<int> &num1, const vector<int> &num2, const vector<int> &mod)
{
    vector<int> product = {0};                        // Kết quả ban đầu bằng 0
    vector<int> moddedBinNum1 = modBinary(num1, mod); // num1 % mod
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

void printBinary(const vector<int> &binary)
{
    for (int bit : binary)
    {
        cout << bit;
    }
    cout << " = ";
    convertBinToDec(binary);
}

void readInputFile(const string &inputFile, vector<vector<int>> &messages, vector<vector<int>> &ciphertexts, vector<int> &N, vector<int> &e)
{
    ifstream inFile(inputFile);
    if (!inFile.is_open())
    {
        cerr << "Error: Cannot open input file." << endl;
        exit(1);
    }

    int x, y;
    string hexN, hexE;
    inFile >> x >> y;
    inFile >> hexN >> hexE;

    N = convertHexToBinary(hexN);
    e = convertHexToBinary(hexE);

    messages.resize(x);
    for (int i = 0; i < x; ++i)
    {
        string hexMessage;
        inFile >> hexMessage;
        messages[i] = convertHexToBinary(hexMessage);
    }

    ciphertexts.resize(y);
    for (int i = 0; i < y; ++i)
    {
        string hexCipher;
        inFile >> hexCipher;
        ciphertexts[i] = convertHexToBinary(hexCipher);
    }

    inFile.close();
}

// Viết kết quả ra file
void writeOutputFile(const string &outputFile, const vector<int> &results)
{
    ofstream outFile(outputFile);
    if (!outFile.is_open())
    {
        cerr << "Error: Cannot open output file." << endl;
        exit(1);
    }

    for (size_t i = 0; i < results.size(); ++i)
    {
        outFile << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    outFile.close();
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

    vector<vector<int>> messages, ciphertexts;
    vector<int> N, e;

    // Đọc dữ liệu đầu vào
    readInputFile(inputFile, messages, ciphertexts, N, e);

    vector<int> results(messages.size(), -1);

    // Xử lý từng tin nhắn
    for (size_t i = 0; i < messages.size(); ++i)
    {
        vector<int> encodedMessage = modExponentiate(messages[i], e, N);

        // Tìm bản mã tương ứng
        for (size_t j = 0; j < ciphertexts.size(); ++j)
        {
            if (compareTwoBinaryNumbers(encodedMessage, ciphertexts[j]) == 0)
            {
                results[i] = j;
                break;
            }
        }
    }

    // Ghi kết quả ra file
    writeOutputFile(outputFile, results);
    cout << "Result is written to " << outputFile << endl;

    return 0;
}
