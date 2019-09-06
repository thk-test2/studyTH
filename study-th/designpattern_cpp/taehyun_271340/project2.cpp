#include <iostream>
#include <vector>

using namespace std;

int n=0;
class BaseItem
{
    string name_;
    int size_ = 0;
public:
    BaseItem(string name, int size) : name_(name), size_(size) {}
    string getName() { return name_; }
    virtual int getSize() { return size_; }
    void addSize(int size) { size_ += size; }

    void print() { iterPrint(n++); n--; };
    virtual void iterPrint(int n) = 0;

    virtual ~BaseItem() { }
};

class File : public BaseItem
{
public:
    File(string name, int size) : BaseItem(name, size) {}
    virtual void iterPrint(int n) {
        for (int i=0; i<n; i++) {
            cout << "   ";
        }
        cout << "(" << getName() << ", " << getSize() << ")" << endl;
    }

    virtual ~File() { }
};

class Folder : public BaseItem
{
    vector<BaseItem*> v;
public:
    Folder(string name) : BaseItem(name, 0) {}
    void add(BaseItem * p) {
        addSize(p->getSize());
        v.push_back(p);
    }
    virtual int getSize() {
        int result = 0;
        for (auto& it : v){
            result += it->getSize();
        }
        return result;
    }
    virtual void iterPrint(int n) {
        for (int i=0; i<n; i++) {
            cout << "   ";
        }
        cout << "[" << getName() << "]" << endl;
        for (auto& it : v){
            it->print();
        }
    }

    virtual ~Folder() { }
};

int main()
{
    // 조건 1. Folder와 File의 객체를 생성할 수 있어야 합니다.
    Folder* rootFolder = new Folder("ROOT"); // 폴더는 이름만 있습니다.
    Folder* aaaaFolder = new Folder("AAAA");
    Folder* bbbbFolder = new Folder("BBBB");

    File* file1 = new File("a.txt", 10); // 화일은 이름과 크기가 있습니다
    File* file2 = new File("b.txt", 20);
    File* file3 = new File("c.txt", 30);
    File* file4 = new File("d.txt", 40);

    // 조건 2. 폴더안에 파일 및 다른 폴더를 넣을 수 있어야 합니다.
    rootFolder->add(aaaaFolder);
    rootFolder->add(bbbbFolder);
    rootFolder->add(file1);

    aaaaFolder->add(file2);
    aaaaFolder->add(file3);

    bbbbFolder->add(file4);

    // 조건 3. 파일과 폴더 크기를 출력할 수 있어야 합니다.
    //    폴더는 자신만의 크기는 없지만 크기를 구할 수 는 있습니다.
    cout << file1->getSize()         << endl; // 10
    cout << aaaaFolder->getSize()    << endl; // 50
    cout << rootFolder->getSize()    << endl; // 100

    // 조건 4. 화면 출력
    file1->print();     // 파일이므로 이름과 크기만 출력해 주세요.
                        // ex) (a.txt, 10)

    rootFolder->print();
    // ROOT폴더 전체의 모양을 보기좋게 출력해 주세요
    // [ROOT]
    //          [AAAA]
    //               (b.txt, 20)
    //               (b.txt, 30)
    //          [BBBB]
    //               (d.txt, 40)
    //          (a.txt, 10)

    // 조건 5. 폴더 제거시 폴더 안에 있는 모든 파일과 폴더가 제거 되게 해주세요
    delete rootFolder;
}