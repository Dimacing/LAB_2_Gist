#include "iostream"
using namespace std;


class Key{
public:
    int startdiap;
    int overdiap;
    int title;
    int diap;
    Key& operator=(const Key &k)
    {
        startdiap = k.startdiap;
        overdiap = k.overdiap;
        title = k.title;
        diap = k.diap;
        return *this;
    }

    bool operator <(const Key &a) const
    {
        return (title < a.title);
    }

    bool operator > (const Key &a)
    {
        return (title > a.title);
    }
};

struct razb{
    Key key;
    int value;
    int sizer;
};

template <typename T>
class Binary_tree {
private:
    struct Node {
        int value;
        T key;
        Node *left;
        Node *right;
        Node(Key k, int v) : key(k), value(v), left(nullptr), right(nullptr){}
    };
public:
    Node *root = nullptr;
    int size = 0;
    int getsize() {
        return this->size;
    }

    Binary_tree(razb* a) {
        for (int i = 0; i < a[0].sizer; i++)
        {
            insert(a[i].key, a[i].value);
        }

    }

    ~Binary_tree() {
        remove(root->key.title);
    }

    int max_value() {
        Node *cur = root;
        while (cur->right)
            cur = cur->right;

        return cur->value;
    }

    Node find(int title) {
        Node *n = root;
        while (n != nullptr && title != n->key.title) {
            if (title < n->key.title)
                n = n->left;
            else
                n = n->right;
        }
        if (n != nullptr)
            return *n;
    }

    Node *successor(Node *n) {
        Node *r = n->right;
        while (r->left != nullptr)
            r = r->left;
        return r;
    }

    void remove(Node *&n, int title) {
        if (n == nullptr)
            return;
        if (title == n->key.title) {
            if (n->left == nullptr || n->right == nullptr) {
                Node *child = (n->left != nullptr ? n->left : n->right);
                delete n;
                n = child;
            } else {
                Node *succ = successor(n);
                n->key = succ->key;
                n->value = succ->value;
                remove(n->right, succ->key.title);
            }
            return;
        }
        if (title < n->key.title)
            remove(n->left, title);
        else
            remove(n->right, title);
    }

    void remove(int title) {
        remove(root, title);
    }

    void print() {
        printel(root);
        cout << endl;
    }

    void printel(const Node *n) const {
        cout << endl;
        if (n) {
            printel(n->left);
            cout << "Age diapazon( " << n->key.startdiap  << " - " << n->key.overdiap << " ) :   ";
            cout << n->value << " " << endl;
            printel(n->right);
        }
    }

    void insert(const T key, const int value) {
        if (root == nullptr) {
            root = new Node(key, value);
            ++size;
        } else {
            Node *curr = root;
            while (curr && curr->key.title != key.title) {
                if (curr->key > key && curr->left == nullptr) {
                    curr->left = new Node(key, value);
                    ++size;
                    return;
                }
                if (curr->key < key && curr->right == nullptr) {
                    curr->right = new Node(key, value);
                    ++size;
                    return;
                }
                if (curr->key > key)
                    curr = curr->left;
                else curr = curr->right;
            }
        }
    }

};

razb *neravnrazb(person *data){
    int size = data->size;
    cout << "size of diapazons: ";
    int mn;
    cin >> mn;
    razb *a = new razb[mn];
    for (int i = 0; i < mn;i++) {
        cout << "Diapazon # " << i + 1 << endl;
        cout << "Start diapazon razbienia: ";
        cin >> a[i].key.startdiap;
        cout << "Over diapazon razbienia: ";
        cin >> a[i].key.overdiap;
        a[i].key.diap = a[i].key.overdiap - a[i].key.startdiap + 1;
        a[i].sizer = mn;
        a[i].key.title = i;
        a[i].value = 0;
        for (int j = 0; j < size; j++) {
            if (data[j].age >= a[i].key.startdiap and data[j].age <= a[i].key.overdiap) {
                a[i].value++;
            }
        }
    }
    return a;
}

razb *ravnrazb(person *data) {
    int size = data->size;
    int max = data[size - 1].age;
    int min = data[0].age;
    cout << "Diapazon razbienia: " << endl;
    int diap;
    int mn;    // количество множеств
    cin >> diap;
    if ((max - min + 1) % diap == 0) {
        mn = (max - min + 1) / diap;
    } else {
        mn = (max - min + 1) / diap + 1;
    }
    razb *a = new razb[mn];
    for (int i = 0; i < mn; i++) {
        a[i].key.diap= diap;
        a[i].sizer = mn;
        a[i].key.title = i;
        a[i].key.startdiap = data->start_age + i*diap;
        a[i].key.overdiap = data->start_age + (i + 1) * diap - 1;
        a[i].value = 0;
        for (int j = 0; j < size; j++) {
            if (data[j].age >= a[i].key.startdiap and data[j].age <= a[i].key.overdiap) {
                a[i].value++;
            }
        }
    }
    return a;
}


void printz(int size) {
    for (int i = 0; i < size; i++) {
        cout << "*";
    }

}

void gist(Binary_tree<Key> *a) {
    int max = a->find(0).value;
    for (int i =0; i < a->getsize();i++)
    {
        if (max < a->find(i).value)
            max = a->find(i).value;
    }
    double x_d = max / 50 + 1;
    int x[a->size];
    for (int i = 0; i < a->getsize(); i++) {
        x[i] = int((a->find(i).value) / (x_d));
    }
    for (int i = 0; i < a->getsize(); i++) {
        string str;
        str += to_string(a->find(i).key.startdiap) + " - " + to_string(a->find(i).key.overdiap);
        while (str.size() < 15)
            str.append(" ");
        str.append("|");
        cout << str;
        printz(x[i]);
        cout << " " << a->find(i).value;
        cout << endl;
    }
}



