
#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(int value)
        : data(value), next(nullptr)
    {
    }
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList()
        : head(nullptr), tail(nullptr)
    {
    }

    // 소멸자: 리스트의 모든 노드 해제
    ~LinkedList()
    {
        Clear();
    }

    // Create: 맨 뒤에 추가
    void PushBack(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    // Create: 맨 앞에 추가
    void PushFront(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        if (tail == nullptr)
        {
            tail = newNode;
        }
    }

    // Create: 특정 노드 뒤에 추가
    void InsertAfter(Node* target, int value)
    {
        if (target == nullptr)
            return;

        Node* newNode = new Node(value);

        newNode->next = target->next;
        target->next = newNode;

        if (tail == target)
        {
            tail = newNode;
        }
    }

    // Read: 전체 출력
    void Print() const
    {
        Node* current = head;

        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << '\n';
    }

    // Read: 특정 값 검색
    Node* Find(int value) const
    {
        Node* current = head;

        while (current != nullptr)
        {
            if (current->data == value)
                return current;

            current = current->next;
        }

        return nullptr;
    }

    // Update: 특정 값 수정
    bool Update(int oldValue, int newValue)
    {
        Node* target = Find(oldValue);

        if (target == nullptr)
            return false;

        target->data = newValue;
        return true;
    }

    // Delete: 맨 앞 삭제
    void PopFront()
    {
        if (head == nullptr)
            return;

        Node* target = head;
        head = head->next;

        delete target;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    // Delete: 맨 뒤 삭제
    void PopBack()
    {
        if (head == nullptr)
            return;

        if (head == tail)
        {
            delete head;

            head = nullptr;
            tail = nullptr;

            return;
        }

        Node* current = head;

        while (current->next != tail)
        {
            current = current->next;
        }

        delete tail;

        tail = current;
        tail->next = nullptr;
    }

    // Delete: 특정 값 삭제
    bool Remove(int value)
    {
        if (head == nullptr)
            return false;

        if (head->data == value)
        {
            PopFront();
            return true;
        }

        Node* current = head;

        while (current->next != nullptr)
        {
            if (current->next->data == value)
            {
                Node* target = current->next;

                current->next = target->next;

                if (target == tail)
                {
                    tail = current;
                }

                delete target;
                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Delete: 전체 삭제
    void Clear()
    {
        while (head != nullptr)
        {
            Node* target = head;
            head = head->next;

            delete target;
        }

        tail = nullptr;
    }
};

int main()
{
    LinkedList list;

    // Create
    list.PushBack(10);
    list.PushBack(20);
    list.PushBack(30);

    std::cout << "Initial: ";
    list.Print();

    // 맨 앞 추가
    list.PushFront(5);

    std::cout << "PushFront: ";
    list.Print();

    // 특정 노드 뒤에 추가
    Node* target = list.Find(10);
    list.InsertAfter(target, 15);

    std::cout << "InsertAfter: ";
    list.Print();

    // Read
    Node* found = list.Find(20);

    if (found != nullptr)
    {
        std::cout << "Find: " << found->data << '\n';
    }

    // Update
    list.Update(20, 200);

    std::cout << "Update: ";
    list.Print();

    // Delete: 맨 앞
    list.PopFront();

    std::cout << "PopFront: ";
    list.Print();

    // Delete: 맨 뒤
    list.PopBack();

    std::cout << "PopBack: ";
    list.Print();

    // Delete: 특정 값
    list.Remove(15);

    std::cout << "Remove: ";
    list.Print();

    // Delete: 전체 삭제
    list.Clear();

    std::cout << "Clear: ";
    list.Print();

    return 0;
}
