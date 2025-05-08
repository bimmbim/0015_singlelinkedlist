#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class LinkedList
{
    Node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;
        nodeBaru->next = NULL;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node *&previous, Node *&current)
    {
        previous = START;
        current = START;

        while ((current != NULL) && (nim != current->noMhs))
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, previous, current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
            cout << "\nList Kosong\n";
        else
        {
            cout << "\nData di dalam list adalah:\n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu";
        cout << "\n1. Menambahkan data ke dalam list" << endl;
        cout << "2. Menampilkan data dari dalam list" << endl;
        cout << "3. Menghapus satu data dalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            mhs.addNode();
            break;

        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong" << endl;
            }
            else
            {
                mhs.traverse();
            }
            break;

        case '3':
            cout << "\nMasukkan nomor mahasiswa yang akan dihapus : ";
            cin >> nim;
            if (mhs.delNode(nim) == false)
                cout << "Data tidak ditemukan" << endl;
            else
                cout << "Data dengan nomor mahasiswa " << nim << " berhasil dihapus " << endl;
            break;

        case '4':
        {
            if (mhs.listEmpty() == true)
            {
                cout << "\nList Kosong!\n";
                break;
            }
            Node *previous, *current;
            cout << "\nMasukkan No mahasiswa yang dicari : ";
            cin >> nim;
            if (mhs.Search(nim, previous, current) == false)
                cout << "Data tidak ditemukan" << endl;
            else
            {
                cout << "\nData ditemukan\n";
                cout << "\nNIM Mahasiswa: " << current->noMhs << endl;
            }
            break;
        }

        }
    } while (ch != '5');

    return 0;
}
