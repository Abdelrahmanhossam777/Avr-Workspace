/*Implement the classic method for composing secret messages called a square code.

Given an English text, output the encoded version of that text.

First, the input is normalized: the spaces and punctuation are removed from
the English text and the message is downcased.

Then, the normalized characters are broken into rows. These rows can be regarded
as forming a rectangle when printed with intervening newlines.

For example, the sentence

"If man was meant to stay on the ground god would have given us roots"
is normalized to:

"ifmanwasmeanttostayonthegroundgodwouldhavegivenusroots"
The plaintext should be organized in to a rectangle. The size of the rectangle
(r x c) should be decided by the length of the message, such that c >= r and c - r <= 1,
where c is the number of columns and r is the number of rows.

Our normalized text is 54 characters long, dictating a rectangle with c = 8 and r = 7:

"ifmanwas"
"meanttos"
"tayonthe"
"groundgo"
"dwouldha"
"vegivenu"
"sroots  "
The coded message is obtained by reading down the columns going left to right.

The message above is coded as:

"imtgdvsfearwermayoogoanouuiontnnlvtwttddesaohghnsseoau"*/

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

void GetSide(int copy_stringLength, int *c, int *r);

int main()
{
    string local_stringSentance;
    int c, r;
    cout << "Please Enter Your Sentance: ";
    getline(cin, local_stringSentance);
    string str(local_stringSentance);
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    cout << str << endl;
    GetSide(str.length(), &c, &r);
    string arr[r];
    if ((r * c) > str.length())
    {
        for (int i = 0; i < ((r * c) - str.length()); i++)
            str += " ";
    }
    for (int i = 0; i < r; i++)
    {
        arr[i] = str.substr((i * c), ((i * c) + c));
    }

    cout << "Normalized Text" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            try
            {
                cout << arr[i].at(j);
            }
            catch (...)
            {
                cout << " ";
            }
        cout << endl;
    }
    cout << "---------------------------------------\n";
    cout << "The message above is coded as:\n";
    string coded;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            try
            {
                cout << arr[j].at(i);
            }
            catch (...)
            {
            }
        cout << " ";
    }
}

void GetSide(int copy_stringLength, int *c, int *r)
{
    int side = 0;
    while (side * side < copy_stringLength)
        ++side;
    int check = side * (side - 1);
    if (check >= copy_stringLength)
    {
        *c = side;
        *r = side - 1;
    }
    else
    {
        *c = side;
        *r = side;
    }
}