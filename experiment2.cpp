/*exp-2
w=60
create a program to identify valid tokens from the following statements
statement 1 - cout<<a+b%60*2.75;  //"if cout" is not acceptable 
function(string input)
{ 
//_array1
//_array2
//_array3
}
*/
#include <iostream>
using namespace std;
bool isConstant(char text[]) 
{
    int n = 0;

    while (text[n] != '\0') 
    {
        n++;
    }

    if (n == 0) 
    {
        return false;
    }

    bool numeric = true;
    int dotCount = 0;

    for (int i = 0; i < n; i++) {
        int asciiVal = text[i];

        if (asciiVal == 46) 
        {
            dotCount++;
            if (dotCount > 1) 
            {
                numeric = false;
                break;
            }
        }
        else if (asciiVal < 48 || asciiVal > 57) 
        {
            numeric = false;
            break;
        }
    }

    return numeric;
}
void IdentifyTokens(string input)
{
    string keywords[] = {"cout", "cin", "int", "float", "double", "string", "class", "return", "if","main", "else", "while", "for", "char", "switch", "case", "break", "stack", "continue", "do", "void"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    string operators[] = {"+", "-", "*", "/", "%", "=", "<<", ">>", "^"};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    string Punctuations[] = {";", ",", "(", ")", "{", "}", "[", "]", ".", ":", "?", "!", "@", "#", "$", "&", "_"};
    int numPunctuations = sizeof(Punctuations) / sizeof(Punctuations[0]);

    char tempWord[100]; 
    int count = 0;

    cout << "Statement: " << input << endl;

    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '.')
        {
            tempWord[count] = c;
            count++;
        }
        else
        {
            if (count > 0)
            {
                tempWord[count] = '\0'; 

                bool isKeyword = false;
                
                for (int k = 0; k < numKeywords; k++) {
                    if (keywords[k] == tempWord) 
                    {
                        isKeyword = true;
                        break;
                    }
                }

                if (isKeyword) 
                {
                    cout <<"\t"<<tempWord << " - Keyword" << endl;
                }
                else if (isConstant(tempWord)) 
                { 
                    cout <<"\t"<<tempWord <<" - Constant" << endl;
                }
                else {
                    cout <<"\t"<<tempWord << " - Identifier" << endl;
                }

                count = 0; 
            }
            if (c == ' ') 
            {
                continue; 
            }
            if (i + 1 < input.length())
            {
                if ((c == '<' && input[i+1] == '<') || (c == '>' && input[i+1] == '>'))
                {
                    cout <<"\t"<<c << input[i+1] << " - Operator" << endl;
                    i++;
                    continue;
                }
            }
            string currentSymbol = "";
            currentSymbol += c;

            bool isOp = false;

            for (int k = 0; k < numOperators; k++) 
            {
                if (operators[k] == currentSymbol) 
                {
                    cout <<"\t"<<c << " - Operator" << endl;
                    isOp = true;
                    break;
                }
            }
            if (!isOp) 
            {
                for (int k = 0; k < numPunctuations; k++) 
                {
                    if (Punctuations[k] == currentSymbol) 
                    {
                        cout <<"\t"<<c << " - Punctuation" << endl;
                        break;
                    }
                }
            }
        }
    }
    cout << endl;
}
int main()
{
    string statement1 = "cout<<a+b%60*2.75;";
    IdentifyTokens(statement1);
    return 0;
}