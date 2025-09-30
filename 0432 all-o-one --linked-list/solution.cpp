class AllOne {
private:
    struct Node;
public:
    AllOne():
    head_{nullptr}
    , tail_{nullptr}
    , wordFreqs_{unordered_map<string, Node*>{}} {}

    ~AllOne() {
        Node *curr = head_;
        while (curr != nullptr) {
            Node *rem = curr;
            curr = curr->next_;
            delete rem;
        }
    }
    
    void inc(string key) {
        // not seen yet
        if (wordFreqs_.count(key) == 0ULL) {
            // is there a table?
            if (head_ == nullptr) {
                insertEmpty(1, key);
            }
            // 1 in table?

            // yes?
            else if (head_->freq_ == 1) {
                // perfect just update
                head_->words_.emplace(key);
            }
            // no?
            else {
                // left insert on the head
                insertLeft(head_, 1, key);
            }
        
            wordFreqs_[key] = head_;
            return;
        }

        // seen
        Node *node = wordFreqs_[key];
        int newFreq = node->freq_ + 1;

        // no there is not a right node
        if (node->next_ == nullptr) {
            insertRight(node, newFreq, key);
        }
        // yes there is a right node

        // it's the right one
        else if (node->next_->freq_ == newFreq) {
            // just update
            node->next_->words_.emplace(key);
        }
        // no it's not the right one
        else {
            insertRight(node, newFreq, key);
        }

        node->words_.erase(key);
        wordFreqs_[key] = node->next_;

        // need to delete the old node because it's empty
        if (node->words_.empty()) {
            deleteNode(node);
        }
    }
    
    void dec(string key) {
        Node *node = wordFreqs_[key];
        int newFreq = node->freq_ - 1;

        // key should now no longer have an entry after being wiped out
        if (newFreq == 0) {
            wordFreqs_.erase(key);
        } else {
            // no left node
            if (node->prev_ == nullptr) {
                insertLeft(node, newFreq, key);
            }
            // there is a left node
    
            // it has the right value
            else if (node->prev_->freq_ == newFreq) {
                node->prev_->words_.emplace(key); 
            }
    
            // it doesn't have the right value
            else {
                insertLeft(node, newFreq, key);
            }

            wordFreqs_[key] = node->prev_;
        }

        node->words_.erase(key);

        // need to delete the old node because it's empty
        if (node->words_.empty()) {
            deleteNode(node);
        }
    }
    
    string getMaxKey() {
        if (tail_ == nullptr) {
            return "";
        }

        return *(tail_->words_.begin());
    }
    
    string getMinKey() {
        if (head_ == nullptr) {
            return "";
        }

        return *(head_->words_.begin());
    }
private:
    struct Node {
        Node *prev_;
        Node *next_;
        int freq_;
        unordered_set<string> words_;
    };

    void printList() {
        for (Node *curr = head_; curr != nullptr; curr = curr->next_) {
            cout << '(' << curr->freq_ << ',' << '|';
            for (auto& k : set<string>{curr->words_.begin(), curr->words_.end()}) {
                cout << k << ' ';
            }
            cout << '|' << " <-> ";
        }
        cout << "X\n";
    }

    void insertEmpty(int freq, string key) {
        Node *node = new Node{nullptr, nullptr, freq, unordered_set<string>{key}};
        head_ = node;
        tail_ = node;
    }

    void insertLeft(Node *node, int freq, string key) {
        // empty
        if (head_ == nullptr) {
            insertEmpty(freq, key);
            return;
        }
        // head insert
        if (node == head_) {
            Node *newHead = new Node{nullptr, head_, freq, unordered_set<string>{key}};
            head_->prev_ = newHead;
            head_ = newHead;
            return;
        }

        // middle
        // (n.prev) <-inserted-> n
        Node *inserted = new Node{node->prev_, node, freq, unordered_set<string>{key}};
        node->prev_->next_ = inserted;
        node->prev_ = inserted;
    }

    void insertRight(Node *node, int freq, string key) {
        // empty
        if (head_ == nullptr) {
            insertEmpty(freq, key);
            return;
        }
        // tail insert
        if (node == tail_) {
            Node *newTail = new Node{tail_, nullptr, freq, unordered_set<string>{key}};
            tail_->next_ = newTail;
            tail_ = newTail;
            return;
        }

        // middle
        // n <-inserted-> (n.next)
        Node *inserted = new Node{node, node->next_, freq, unordered_set<string>{key}};
        node->next_->prev_ = inserted;
        node->next_ = inserted;
    } 

    void deleteNode(Node *node) {
        // empty
        if (head_ == nullptr) {
            return;
        }
        // singleton
        if (head_ == tail_) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
            return;
        }
        // head
        if (node == head_) {
            head_->next_->prev_ = nullptr;
            head_ = head_->next_;
            delete node;
            return;
        }
        // tail
        if (node == tail_) {
            tail_->prev_->next_ = nullptr;
            tail_ = tail_->prev_;
            delete node;
            return;
        }
        // middle
        // (n.prev) <-node-> (n.next)
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
        delete node;
        
    }

    Node *head_;
    Node *tail_;
    unordered_map<string, Node*> wordFreqs_;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
