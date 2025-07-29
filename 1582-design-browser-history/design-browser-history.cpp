class DoublyNode {
public:
    DoublyNode *next, *prev;
    string url;
    int size;
    DoublyNode(string str, int size) {
        url = str;
        next = nullptr;
        prev = nullptr;
        this->size = size;
    }
    DoublyNode(string str, DoublyNode* next, int size) {
        this->size = size;
        url = str;
        this->next = next;
        prev = nullptr;
    }
    DoublyNode(string str, DoublyNode* next, DoublyNode* prev, int size) {
        this->size = size;
        url = str;
        this->next = next;
        this->prev = prev;
    }
};
class BrowserHistory {
    DoublyNode *head, *curr;
    int size;

public:
    BrowserHistory(string homepage) {
        head = new DoublyNode(homepage, 1);
        curr = head;
        size = 1;
    }

    void visit(string url) {
        DoublyNode* temp = curr->next;
        while (temp) {
            DoublyNode* next = temp->next;
            delete temp;
            temp = next;
        }
        curr->next = nullptr;
        curr->next = nullptr;
        curr->next = new DoublyNode(url, nullptr, curr, curr->size + 1);
        curr = curr->next;
        size++;
    }

    string back(int steps) {
        while (curr && curr->prev && steps > 0) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }

    string forward(int steps) {
        while (curr->next && steps > 0) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */