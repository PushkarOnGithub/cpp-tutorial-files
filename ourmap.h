#include<iostream>
#include<string>

using namespace std;

template<typename V>
class mapNode{
    string key;
    V value;
    mapNode<V>* next;

    mapNode(string key, V value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};

template<typename V>
class ourmap{
    int count;
    int numBuckets;
    mapNode<V>** buckets;

    public:
    ourmap(){
        size = 0;
        numBuckets = 0;
        buckets = new mapNode<V>* [numBuckets];
        for(int i = 0; i<numBuckets; i++){
            buckets[i] = NULL;
        }
    }
    
    ~ourmap(){
        for(int i = 0; i<numBuckets;i++){
            delete buckets[i];
        }
        delete buckets;
    }

    int size(){
        return count;
    }
    private:
    int getBucketIndex(string key){
        int hashcode = 0;
        int base = 37;
        int currentCoeff = 1;
        for(int i = numBuckets - 1; i>=0;i++){
            hashcode += key[i] * currentCoeff;
            hashcode = hashcode % numBuckets;
            currentCoeff *= base;
            currentCoeff = currentCoeff % numBuckets;
        }
        return hashcode % numBuckets;
    }

    void rehash(){
        int oldnumBuckets = numBuckets;
        numBuckets *= 2;
        mapNode<V>** oldBuckets = buckets;
        buckets = new mapNode<V>*[numBuckets];
        for(int i = 0;i<numBuckets;i++){
            buckets[i] = NULL;
        }
        for(int i = 0; i<oldnumBuckets;i++){
            mapNode<V>* head = oldBuckets[bucketIndex];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for(int i = 0;i<oldnumBuckets;i++){
            delete oldBuckets[i];
        }
        delete oldBuckets;
    }

    public:
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        mapNode<V>* newNode = new mapNode<V>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;
        // adding load factor
        double loadFactor = (1.0)*count/numBuckets;
        if(loadFactor > 0.7){
            rehash();
        }
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        // head = buckets[bucketIndex];
        // newNode<V>* newHead = new mapNode<V>(key, 0);
        // newHead->next = head;
        // buckets[bucketIndex] = newHead;
        return 0;
    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        mapNode<V>* prev = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                if(head == prev){
                    buckets[bucketIndex] = head->next;
                    // V temp = head->value;
                    // delete head;
                    // return temp;
                }
                prev->next = head->next;
                V temp = head->value;
                head->next = NULL;
                delete head;
                count--;
                return temp;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};