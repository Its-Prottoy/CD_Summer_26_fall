#include <iostream>
using namespace std;
void CheckNumericConstant(string val)
{
    if (val.empty()) {
        cout << "Not numeric constant" << endl;
        return;
    }
    int count = val.length();
    bool numeric = true;
    for (int i = 0; i < count; i++)
    {
        int ascii = val[i];
        if (ascii < 48 || ascii > 57) 
        {
            numeric = false;
            break;
        }
    }
    
    if (numeric)
        cout << "Its a Numeric constant" << endl;
    else
        cout << "Its not a Numeric constant" << endl;
}
void CheckOperator(string op)
{
    bool findOP = false;
    for (size_t i = 0; i < op.length(); i++)
    {
        char c = op[i];
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||  c == '^' || c == '(' || c == ')' || c == '=' || c == '>' || c == '<' || c == '!' || c == '&') 
        {
            cout << "Found operator: '" << c << "'" << endl;
            findOP = true;
        }
    }
    if (!findOP) {
        cout << "No operators found." << endl;
    }
    
}
void CheckComentLine(string line)
{
    int len = line.length();
    if (len >= 2 && line[0] == '/' && line[1] == '/') 
    {
        cout << "This is a single line comment" << endl;
    }
    else if (len >= 4 && line[0] == '/' && line[1] == '*' && line[len - 2] == '*' && line[len - 1] == '/') 
    {
        cout << "This is a multi-line comment" << endl;
    }
    else 
    {
        cout << "There is no comment line" << endl;
    }
}
void CheckIdentifier(string id)
{
    int len = id.length();
    if (len == 0)
    {
        cout << "No identifier inputed" << endl;
        return;
    }
    char firstChar = id[0];
    int firstAscii = firstChar;
    bool isUppercase = (firstAscii >= 65 && firstAscii <= 90);
    bool isLowercase = (firstAscii >= 97 && firstAscii <= 122);
    bool isUnderscore = (firstAscii == 95);

    if (!isUppercase && !isLowercase && !isUnderscore)
    {
        cout << "The identifier is not valid (First character)." << endl;
        return; 
    }
    char SecondChar = id[1];
    int SecondAscii = SecondChar;
    
    bool isUpper = (SecondAscii >= 65 && SecondAscii <= 90);
    bool isLower = (SecondAscii >= 97 && SecondAscii <= 122);
    bool isNumber = (SecondAscii >= 48 && SecondAscii <= 57);
    bool isUnder = (SecondAscii == 95);

    if (!isUpper && !isLower && !isNumber && !isUnder)
    {
        cout << "The identifier is not valid (Second characters)." << endl;
        return;
    }
    
    cout << "The input is an identifier." << endl;
}
void FindAverage(int arr[], int size) 
{
    if (size == 0) return;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double average = (double)sum / size;
    cout << "Average value of array elements: " << average << endl;
}

void FindArrayMinMax(int arr[], int size) 
{
    if (size == 0) return;
    int minVal = arr[0];
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
}

void ConcatenateName(string first, string last) 
{
    string fullName = first + " " + last;
    cout << "output: full name = \"" << fullName << "\"" << endl;
}
int main()
{
    string numericConstant;
    cout << "1.Enter a numeric constant: ";
    cin >> numericConstant;
    CheckNumericConstant(numericConstant);

    string operatorString;
    cout << "2. Enter a string to check for operators: ";
    cin >> operatorString;
    CheckOperator(operatorString);

    string commentLine;
    cout << "3. Enter a comment line: ";
    cin.ignore();
    getline(cin, commentLine);
    CheckComentLine(commentLine);

    string identifier;
    cout << "4. Enter an identifier: ";
    cin >> identifier;
    CheckIdentifier(identifier);

    int size;
    cout << "5/6. Enter the number of elements for array to calculate average and min/max: ";
    cin >> size;
    int arr[100]; 
    cout << "Enter the " << size << " numbers one by one:" << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
    FindAverage(arr, size);
    FindArrayMinMax(arr, size);

    string firstName, lastName;
    cout << "7.Enter First name: ";
    cin >> firstName;
    cout << "Enter Last name: ";
    cin >> lastName;
    ConcatenateName(firstName, lastName);

    return 0;
}
