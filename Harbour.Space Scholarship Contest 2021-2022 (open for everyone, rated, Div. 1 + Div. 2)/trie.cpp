#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
const int alphabet = 26;
vector<string> dictionary;
vector<string> key;
class Trie
{
public:
    bool isEndOfWord;
    Trie *children[alphabet];
    Trie()
    {
        this -> isEndOfWord = false;
        for (int i = 0; i < alphabet; i++)
            this -> children[i] = 0;
    }
    void insertToTrie(string);
    bool searchInTrie(string);
};
void Trie::insertToTrie(string key)
{
    //Bat dau tu root node(node khoi tao ban dau de luu values)
    Trie *root = this;
    for (int i = 0; i<key.size(); i++)
    {
        //tao node moi neu Trie rong
        if (root -> children[key[i] - 'a'] == 0)
            root -> children[key[i]- 'a'] = new Trie();
        //chuyen den node tiep theo cua key[i]
        root = root -> children[key[i] - 'a'];
    }
    //danh dau key da duoc luu vao trong Trie
    root -> isEndOfWord = true;
}
// Tim kiem 1 tu trong tu dien
// neu no xuat hien tra ve true nguoc lai tra ve false
bool Trie::searchInTrie(string key)
{
    // tra ve false neu Trie rong
    if (this == 0)
        return false;
    Trie *root = this;
    for (int i = 0; i<key.size(); i++)
    {
        // tro den ki tu key[i]
        root = root -> children[key[i] - 'a'];
        // chua chay het cac ki tu trong key ma xuat hien mot ki tu null tra ve false
        if (root == 0)
            return false;
    }
    //tra ve true neu node cuoi cung la isEndOfWord va ki tu cuoi cung cua key duoc tim thay
    return root -> isEndOfWord;
}
void readFromFile(string fileName, vector<string> &saveData)
{
    std::ifstream myfile(fileName.c_str());
    string cur;
    if ( myfile.is_open() )
    {
        while ( myfile.good() )
        {
            myfile >> cur;
            saveData.push_back(cur);
        }
    }
}
void addDictionary(Trie *&head, vector<string> dictionary)
{
    for (int i = 0; i<dictionary.size(); i++)
    {
        head->insertToTrie(dictionary[i]);
    }
}
void checkSpelling(Trie *head, vector<string> key)
{
    for (int i = 0; i<key.size(); i++)
    {
        if (head->searchInTrie(key[i]))
        {
            cout << key[i] << " dung chinh ta" << endl;
        }
        else
            cout << key[i] << " khong dung chinh ta" << endl;
    }
}
void menu(Trie *&head)
{
    int choose = 0;
    while(choose != 4)
    {
        cout << "1. Doc du lieu tu dien" << endl;
        cout << "2. Doc du lieu van ban" << endl;
        cout << "3. Kiem tra loi chinh ta trong van ban" << endl;
        cout << "4. Thoat" << endl;
        cout << "Moi chon: ";
        cin >> choose;
        switch(choose)
        {
        case 1:
            readFromFile("dictionary.txt", dictionary);
            addDictionary(head, dictionary);
            break;
        case 2:
            readFromFile("key.txt", key);
            break;
        case 3:
            checkSpelling(head, key);
            break;
        default:
            break;
        }
    }
}
int main()
{
    Trie* head = new Trie();
    menu(head);
}
